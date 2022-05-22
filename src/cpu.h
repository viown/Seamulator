#ifndef CPU_H
#define CPU_H
#include <stdint.h>
#include <stddef.h>

struct CpuInstruction {
    const char* detail; /* We can use this later on to view the disassembly */
    int byte_length;
    void* instruction;
};

extern const struct CpuInstruction instructions[255];

void cpu_exec();

// Instructions
void cpu_nop();
void cpu_ld_bc_u16(uint16_t argument);
void cpu_ld_xbc_a();
void cpu_inc_bc();
void cpu_inc_b();
void cpu_dec_b();
void cpu_ld_b_u8(uint8_t argument);
void cpu_rlca();
void cpu_ld_u16_sp(uint16_t argument);
void cpu_add_hl_bc();
void cpu_ld_a_xbc();
void cpu_dec_bc();
void cpu_inc_c();
void cpu_dec_c();
void cpu_c_u8(uint8_t argument);
void cpu_rrca();

#endif