#ifndef CPU_H
#define CPU_H

struct CpuInstruction {
    const char* detail;
    int byte_length;
    void* instruction;
};

static const struct CpuInstruction instructions[] = {
    {"NOP", 1, NULL}
};

void cpu_nop();

#endif