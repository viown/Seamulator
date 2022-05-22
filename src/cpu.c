#include "memory.h"
#include "registers.h"
#include "cpu.h"

const struct CpuInstruction instructions[255] = {
    {"NOP", 1, &cpu_nop},
    {"LD BC, %hu", 3, &cpu_ld_bc_u16},
    {"LD (BC), A", 1, &cpu_ld_xbc_a},
    {"INC BC", 1, &cpu_inc_bc},
    {"INC B", 1, &cpu_inc_b},
    {"DEC B", 1, &cpu_dec_b},
    {"LD B, %d", 1, &cpu_ld_b_u8},
    {"RLCA", 1, &cpu_rlca},
    {"LD %hu, SP", 3, &cpu_ld_u16_sp}
};

void cpu_exec() {
    struct CpuInstruction instruction = instructions[registers.PC];
    switch (instruction.byte_length) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
    registers.PC++;
}

void add_u8(uint8_t* address, uint8_t number) {
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

    *address = (uint8_t)temp;

    if (*address) {
        clear_flag(Z);
    } else {
        set_flag(Z);
    }
}

void add_u16(uint16_t* address, uint16_t number) {
    unsigned int temp = *address + number;
    clear_flag(N);
    if ((((*address & 0xF) + (number & 0xF)) & 0x10) == 0x10) {
        set_flag(H);
    } else {
        clear_flag(H);
    }
    if (temp >= 0x10000) {
        set_flag(C);
    } else {
        clear_flag(C);
    }

    *address = (uint16_t)temp;

    if (*address) {
        clear_flag(Z);
    } else {
        set_flag(Z);
    }
}

uint8_t increment(uint8_t number) {
    if ((((number & 0xF) + (1 & 0xF)) & 0x10) == 0x10) {
        set_flag(H);
    } else {
        clear_flag(H);
    }

    number++;

    if (registers.B) {
        clear_flag(Z);
    } else {
        set_flag(Z);
    }

    clear_flag(N);
    return number;
}

uint8_t decrement(uint8_t number) {
    if ((((number & 0xF) - (1 & 0xF)) & 0x10) == 0x10) {
        set_flag(H);
    } else {
        clear_flag(H);
    }

    number--;

    if (registers.B) {
        clear_flag(Z);
    } else {
        set_flag(Z);
    }

    set_flag(N);
    return number;
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

void cpu_inc_b() {
    registers.B = increment(registers.B);
}

void cpu_dec_b() {
    registers.B = decrement(registers.B);
}

void cpu_ld_b_u8(uint8_t argument) {
    registers.B = argument;
}

void cpu_rlca() {
    unsigned char carry = 0;
    if (registers.A >= 0x80) {
        set_flag(H);
        carry = 1;
    } else {
        clear_flag(H);
    }

    registers.A = registers.A << 1;
    registers.A += carry;

    clear_flag(N);
    clear_flag(Z);
    clear_flag(H);
}

void cpu_ld_u16_sp(uint16_t argument) {
    uint8_t* s = (uint8_t*)&registers.SP;
    write(argument, *s);
    write(argument + 1, *(s + 1));
}

void cpu_add_hl_bc() {
    add_u16(&registers.HL, registers.BC);
}

void cpu_ld_a_xbc() {
    registers.A = read(registers.BC);
}

void cpu_dec_bc() {
    registers.BC--;
}

void cpu_inc_c() {
    registers.C = increment(registers.C);
}

void cpu_dec_c() {
    registers.C = decrement(registers.C);
}

void cpu_ld_c_u8(uint8_t argument) {
    registers.C = argument;
}

void cpu_rrca() {
    registers.A = registers.A >> 1;
}

void cpu_stop() {
    // TODO
}

void cpu_ld_de_u16(uint16_t argument) {
    registers.DE = argument;
}

void cpu_ld_xde_a() {
    write(registers.DE, registers.A);
}

void cpu_inc_de() {
    registers.DE++;
}

void cpu_inc_d() {
    registers.D = increment(registers.D);
}

void cpu_dec_d() {
    registers.D = decrement(registers.D);
}

void cpu_ld_d_u8(uint8_t argument) {
    registers.D = argument;
}

void cpu_rla() {
    registers.A <<= 1;
}

void cpu_jr_i8(uint8_t argument) {
    registers.PC += argument;
}

void cpu_add_hl_de() {
    add_u16(&registers.HL, registers.DE);
}

void cpu_ld_a_xde() {
    registers.A = read(registers.DE);
}

void cpu_dec_de() {
    registers.DE--;
}

void cpu_inc_e() {
    registers.E = increment(registers.E);
}

void cpu_dec_e() {
    registers.E = decrement(registers.E);
}

void cpu_ld_e_u8(uint8_t argument) {
    registers.E = argument;
}

void cpu_rra() {
    registers.A >>= 1;
}

void cpu_jr_nz_i8(uint8_t argument) {

}