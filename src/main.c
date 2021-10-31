#include <stdio.h>
#include <stdlib.h>
#include "registers.h"
#include "cpu.h"
#include "memory.h"

uint8_t add_u8(uint8_t* address, uint8_t number);

int main(int argc, char* argv[]) {
    registers.A = 100;
    add_u8(&registers.A, 250);
    add_u8(&registers.A, 3);
    printf("%d\n", flag_isset(C)); // half carry flag gets set.
    return 0;
}