#include <stdio.h>
#include <stdlib.h>
#include "registers.h"
#include "cpu.h"
#include "memory.h"
#include "load.h"

uint8_t add_u8(uint8_t* address, uint8_t number);

int main(int argc, char* argv[]) {
    uint16_t test = 0b1111111100001111;
    uint8_t* byte1 = (uint8_t*)&test;
    uint8_t firstByte = test & 0x00ff;
    uint8_t secondByte = (test & 0xff00) >> 8;
    printf("first: %d\n", firstByte);
    printf("second: %d\n", secondByte);
    /*
    load_rom("TestROMS/tetris.gb");
    for (size_t i = 0; i < 0x8000; ++i) {
        if (i == 0x100)
            printf("\n<Entry Point>\n");
        else if (i == 0x103)
            printf("\n<End of Entry Point>\n");
        else if (i == 0x104)
            printf("\n<Nintendo Logo>\n");
        else if (i == 0x133)
            printf("\n<End of Nintendo Logo>\n");
        else if (i == 0x150)
            printf("<Start of code>\n");
        printf("%x ", cartridge[i]);
        if (i % 20 == 0)
            printf("\n");
    }
    printf("\n");
    */
    return 0;
}