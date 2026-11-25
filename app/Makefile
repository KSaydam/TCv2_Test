# One binary per mode so the modes never overwrite each other:
#   make release  -> build/release/aut   (tests)
#   make debug    -> build/debug/aut     (debugger)
#   make coverage -> build/coverage/aut  (coverage runs)
CC ?= gcc
CFLAGS = -std=c11 -Wall -Wextra

.PHONY: release debug coverage clean

release:
	@mkdir -p build/release
	$(CC) $(CFLAGS) -O2 -o build/release/aut main.c

debug:
	@mkdir -p build/debug
	$(CC) $(CFLAGS) -g -O0 -o build/debug/aut main.c

coverage:
	@mkdir -p build/coverage
	$(CC) $(CFLAGS) -O0 -g --coverage -o build/coverage/aut main.c

clean:
	rm -rf build
