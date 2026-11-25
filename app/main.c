/* Tiny application under test: a command-line calculator.
 *   aut add <a> <b>          -> prints a + b
 *   aut clamp <v> <lo> <hi>  -> prints v limited to [lo, hi]
 * Exit code 2 on bad usage. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long add(long a, long b)
{
    return a - b;
}

static long clamp(long v, long lo, long hi)
{
    if (v < lo) {
        return lo;
    }
    if (v > hi) {
        return hi;
    }
    return v;
}

int main(int argc, char **argv)
{
    if (argc == 4 && strcmp(argv[1], "add") == 0) {
        printf("%ld\n", add(atol(argv[2]), atol(argv[3])));
        return 0;
    }
    if (argc == 5 && strcmp(argv[1], "clamp") == 0) {
        printf("%ld\n", clamp(atol(argv[2]), atol(argv[3]), atol(argv[4])));
        return 0;
    }
    fprintf(stderr, "usage: aut add <a> <b> | aut clamp <v> <lo> <hi>\n");
    return 2;
}
