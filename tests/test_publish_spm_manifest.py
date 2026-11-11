import os
from pathlib import Path
import re
import subprocess
import tempfile
import textwrap
import unittest


WORKFLOW = (
    Path(__file__).resolve().parents[1]
    / ".github/workflows/publish-spm-manifest.yml"
).read_text()


def step_script(name):
    step = WORKFLOW.split(f"      - name: {name}\n", 1)[1]
    script = step.split("        run: |\n", 1)[1]
    return textwrap.dedent(re.split(r"(?m)^      - ", script, maxsplit=1)[0])


class PublishManifestTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        root = Path(self.temp.name)
        self.remote = root / "remote.git"
        self.repo = root / "checkout"
        self.repo.mkdir()
        self.git("init", "--bare", str(self.remote))
        self.git("init", "-b", "main")
        self.git("config", "user.name", "Test")
        self.git("config", "user.email", "test@example.com")
        self.git("remote", "add", "origin", str(self.remote))
        (self.repo / "Package.swift").write_text("old manifest\n")
        self.git("add", ".")
        self.git("commit", "-m", "Original release")
        self.git("tag", "-a", "6.0.0", "-m", "Release 6.0.0")
        original_tag = self.git("rev-parse", "refs/tags/6.0.0")
        (self.repo / "main-only.txt").write_text("Unreleased changes\n")
        self.git("add", ".")
        self.git("commit", "-m", "Unreleased changes")
        self.git("push", "origin", "main", "refs/tags/6.0.0")
        rendered = root / "Package.swift"
        rendered.write_text("correct release manifest\n")
        self.env = {
            **os.environ,
            "TAG": "6.0.0",
            "VERSION": "6.0.0",
            "BRANCH": "release/6.0.0",
            "RENDERED_PACKAGE": str(rendered),
            "ORIGINAL_TAG": original_tag,
        }

    def git(self, *args):
        return subprocess.run(
            ["git", *args], cwd=self.repo, check=True, capture_output=True, text=True
        ).stdout.strip()

    def run_step(self, name, check=True):
        return subprocess.run(
            ["bash", "-c", step_script(name)],
            cwd=self.repo,
            env=self.env,
            check=check,
            capture_output=True,
            text=True,
        )

    def commit_manifest(self):
        self.run_step("Commit manifest changes to release branch")

    def update_tag(self, check=True):
        return self.run_step("Update release tag to the manifest commit", check)

    def remote_tag(self):
        return self.git("ls-remote", "origin", "refs/tags/6.0.0").split()[0]

    def test_tag_points_to_manifest_without_unreleased_main_changes(self):
        self.commit_manifest()
        self.update_tag()
        self.assertEqual(self.remote_tag(), self.git("rev-parse", "HEAD"))
        self.assertEqual(
            self.git("show", "HEAD:Package.swift"), "correct release manifest"
        )
        self.assertNotIn("main-only.txt", self.git("ls-tree", "--name-only", "HEAD"))

    def test_rerun_reuses_existing_manifest_commit(self):
        self.commit_manifest()
        self.update_tag()
        manifest_commit = self.git("rev-parse", "HEAD")
        self.env["ORIGINAL_TAG"] = manifest_commit
        self.git("fetch", "--force", "origin", "refs/tags/6.0.0:refs/tags/6.0.0")
        self.git("checkout", "main")
        self.commit_manifest()
        self.update_tag()
        self.assertEqual(self.remote_tag(), manifest_commit)
        self.assertEqual(self.git("rev-parse", "HEAD"), manifest_commit)

    def test_concurrent_tag_change_is_not_overwritten(self):
        self.commit_manifest()
        concurrent_commit = self.git("rev-parse", "main")
        self.git("push", "--force", "origin", "main:refs/tags/6.0.0")
        result = self.update_tag(check=False)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("stale info", result.stderr)
        self.assertEqual(self.remote_tag(), concurrent_commit)


if __name__ == "__main__":
    unittest.main()
