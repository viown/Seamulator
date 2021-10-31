#include "memory.h"
#include "registers.h"
#include "cpu.h"

const struct CpuInstruction instructions[255] = {
    {"NOP", 1, &cpu_nop},
    {"LD BC, %hu", 3, &cpu_ld_bc_u16},
    {"LD (BC), A", 1, &cpu_ld_xbc_a},
    {"INC BC", 1, &cpu_inc_bc}
};

void cpu_exec() {
    struct CpuInstruction instruction = instructions[registers.PC];
    if (instruction.byte_length == 1) {
        // TODO
    } else if (instruction.byte_length == 2) {
        // TODO
    } else if (instruction.byte_length == 3) {
        // TODO
    }
    registers.PC++;
}

uint8_t add_u8(uint8_t* address, uint8_t number) {
    unsigned int temp = *address + number;
    clear_flag(N);
    if ((((*address & 0xF) + (number & 0xF)) & 0x10) == 0x10) {
        set_flag(H);
    } else {
        clear_flag(H);
    }
    if (temp > 0xFF) {
        set_flag(C);
    } else {
        clear_flag(C);
    }

    *address = *address + number;

    if (*address) {
        clear_flag(Z);
    } else {
        set_flag(Z);
    }
}

void cpu_nop() {}

void cpu_ld_bc_u16(uint16_t argument) {
    registers.BC = argument;
}

void cpu_ld_xbc_a() {
    write(registers.BC, registers.A);
}

void cpu_inc_bc() {
    registers.BC++;
}