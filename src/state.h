#ifndef STATE_H
#define STATE_H

// Dumps/restores registers, ram, program counter, stack pointer, etc

void restore_state(const char* filename);
void dump_state(const char* filename);

#endif