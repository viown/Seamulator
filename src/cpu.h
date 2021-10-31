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

#endif