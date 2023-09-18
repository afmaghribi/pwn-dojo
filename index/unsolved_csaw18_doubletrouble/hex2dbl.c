#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
    // char *string = "0xc059000000000000";

    //  Set errno to zero before using strtoull.
    errno = 0;
    char *end;
    unsigned long long t = strtoull(argv[1], &end, 16);

    //  Test whether stroull did not accept all characters.
    if (*end)
    {
        fprintf(stderr,
            "Error, string \"%s\", is not a proper hexadecimal numeral.\n",
            argv[1]);
        exit(EXIT_FAILURE);
    }

    //  Move the value to a 64-bit unsigned integer.
    uint64_t encoding = t;

    /*  Test whether the number is too large, either because strtoull reported
        an error or because it does not fit in a uint64_t.
    */
    if ((t == ULLONG_MAX && errno) || t != encoding)
    {
        fprintf(stderr, "Error, string \"%s\", is bigger than expected.\n",
            argv[1]);
        exit(EXIT_FAILURE);
    }

    //  Copy the bytes into a double.
    double x;
    memcpy(&x, &encoding, sizeof x);
    printf("%.9999g\n", x);
}