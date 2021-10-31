#include <stdio.h>
#include <stdlib.h>
#include "registers.h"
#include "cpu.h"
#include "memory.h"

int main(int argc, char* argv[]) {
    for (addr_t i = 0; i < ADDR_MAX; ++i) {
        write(i, 50);
        if (get_address(i) == NULL) {
            printf("Undefined memory at %x\n", i);
            exit(0);
        } else {
            printf("%d. %d\n", i, read(i));
        }
    }
    return 0;
}
