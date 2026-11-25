# tc-push-demo

Dummy repository for trying TestCenter's push-triggered runs: a small C
application (`app/`) and pytest tests that drive it (`tests/`).

    make -C app release && python -m pytest tests

Pushing to this repository starts the TestCenter suite.
