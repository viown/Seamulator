#ifndef MEMORY_H
#define MEMORY_H
#include <stdint.h>

typedef unsigned short addr_t;

// Memory Map
extern uint8_t vector_restart[0x100];
extern uint8_t cartridge[0x8000]; /* gameboy cartridge */
extern uint8_t vram[0x2000]; /* video memory */
extern uint8_t wram[0x2000]; /* work ram */
extern uint8_t echo[0x1e80]; /* echo ram; not used */
extern uint8_t io_reg[0x80]; /* I/O registers */
extern uint8_t oam[0xa0]; /* sprite attribute table */
extern uint8_t hram[0x80]; /* high ram */
extern uint8_t interrupt_enable_flag[0x1]; // temporarily here, but should be moved when interrupts are implemented

// Functions
uint8_t* get_address(addr_t address);
void set_byte(addr_t addr, unsigned char value);
uint8_t read_byte(addr_t address);

#endif