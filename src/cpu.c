#include "memory.h"
#include "registers.h"
#include "cpu.h"

const struct CpuInstruction instructions[255] = {
    {"NOP", 1, &cpu_nop}
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

void cpu_nop() {}