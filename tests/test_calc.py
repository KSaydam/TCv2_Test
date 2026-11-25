"""Tests for the calculator. TestCenter sets TC_AUT_PATH to the binary it built
for the run; standalone, build the release binary first (make -C app release)."""
import os
import subprocess
from pathlib import Path

AUT = Path(os.environ.get("TC_AUT_PATH")
           or Path(__file__).resolve().parent.parent / "app" / "build" / "release" / "aut")


def run(*args):
    return subprocess.run([str(AUT), *map(str, args)], capture_output=True, text=True, timeout=10)


def test_add_two_numbers():
    assert run("add", 2, 3).stdout.strip() == "5"


def test_add_negative():
    assert run("add", -7, 4).stdout.strip() == "-3"


def test_clamp_inside_range():
    assert run("clamp", 5, 0, 10).stdout.strip() == "5"


def test_clamp_below_and_above():
    assert run("clamp", -4, 0, 10).stdout.strip() == "0"
    assert run("clamp", 99, 0, 10).stdout.strip() == "10"


def test_bad_usage_exits_with_2():
    assert run("multiply", 2, 3).returncode == 2
