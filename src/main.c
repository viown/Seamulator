#include <stdio.h>
#include "registers.h"

int main(int argc, char* argv[]) {
    struct registers x;
    x.A = 100;
    x.F = 200;
    // x.AF is 25800 because 1100100(100) + 11001000(200) = 110010011001000(25800)
    // We never had to perform bitwise here thanks to unions.
    printf("%d", x.AF);
    return 0;
}
