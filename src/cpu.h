#ifndef CPU_H
#define CPU_H
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

#endif