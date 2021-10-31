#include "registers.h"

struct registers registers;

unsigned char get_flag_value(enum flag_t flag) {
    switch (flag) {
        case Z:
            return 1 << 7;
        case N:
            return 1 << 6;
        case H:
            return 1 << 5;
        case C:
            return 1 << 4;
    }
}

void set_flag(enum flag_t flag) {
    registers.F |= get_flag_value(flag);
}

void clear_flag(enum flag_t flag) {
    registers.F &= ~(get_flag_value(flag));
}

bool flag_isset(enum flag_t flag) {
    return registers.F & get_flag_value(flag);
}

void reset_registers() {
    // According to a redditor, these are what the registers are set to when the gameboy boots up.
    registers.A = 0x01;
    registers.F = 0xb0;
    registers.B = 0x0;
    registers.C = 0x13;
    registers.D = 0x0;
    registers.E = 0xd8;
    registers.H = 0x01;
    registers.L = 0x4d;
    registers.PC = 0x100;
    registers.SP = 0xfffe;
}