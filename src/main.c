#include <stdio.h>
#include <stdlib.h>
#include "registers.h"
#include "cpu.h"
#include "memory.h"

int main(int argc, char* argv[]) {
    for (size_t i = 0; i < 0xffff; ++i) {
        set_byte(5, i);
        printf("%d. %d\n", i, read_byte(i));
    }
    return 0;
}
