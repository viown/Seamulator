#ifndef LOAD_H
#define LOAD_H

// The actual entry point is 0x100, but that usually just contains a jump to 0x150
#define ENTRY_POINT 0x150

void load_rom(const char* path);
void disassemble(const char* path); /* ROM must be loaded */

#endif