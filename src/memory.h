#ifndef MEMORY_H
#define MEMORY_H

typedef unsigned short addr_t;

// Memory Map
extern unsigned char vector_restart[0x100];
extern unsigned char cartridge[0x8000]; /* gameboy cartridge */
extern unsigned char vram[0x2000]; /* video memory */
extern unsigned char wram[0x2000]; /* work ram */
extern unsigned char echo[0x1e80]; /* echo ram; not used */
extern unsigned char io_reg[0x80]; /* I/O registers */
extern unsigned char oam[0xa0]; /* sprite attribute table */
extern unsigned char hram[0x80]; /* high ram */
extern unsigned char interrupt_enable_flag[0x1]; // temporarily here, but should be moved when interrupts are implemented

// Functions
unsigned char* get_address(addr_t addr);
void set_byte(addr_t addr, unsigned char value);
unsigned char read_byte(addr_t addr);

#endif