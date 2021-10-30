#include <stdio.h>
#include <stdlib.h>
#include "registers.h"
#include "cpu.h"
#include "memory.h"

int main(int argc, char* argv[]) {
    unsigned char v = 0;
    v |= (1 << 7);
    v |= (1 << 6);
    //v |= (1 << 5);
    v |= (1 << 4);
    printf("%d", v);
    return 0;
}
