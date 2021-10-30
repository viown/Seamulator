#include <stddef.h>
#include "memory.h"

uint8_t vector_restart[0x100];
uint8_t cartridge[0x8000];
uint8_t vram[0x2000];
uint8_t wram[0x2000];
uint8_t echo[0x1e80];
uint8_t io_reg[0x80];
uint8_t oam[0xa0];
uint8_t hram[0x80];
uint8_t interrupt_enable_flag[0x1];

uint8_t* get_address(addr_t addr) {
    if (addr <= 0x7fff) {
        return &cartridge[addr];
    } else if (addr >= 0x8000 && addr <= 0x9fff) {
        return &vram[addr - 0x8000];
    } else if (addr >= 0xa000 && addr <= 0xcfff) {
        return &wram[addr - 0xa000];
    } else if (addr >= 0xd000 && addr <= 0xdfff) {
        // Switchable Bank 1-7
        return &wram[addr - 0xd000]; 
    } else if (addr >= 0xe000 && addr <= 0xfdff) {
        // Reserved Echo Ram
        return &echo[addr - 0xe000];
    } else if (addr >= 0xfe00 && addr <= 0xfe9f) {
        return &oam[addr - 0xfe00];
    } else if (addr >= 0xfea0 && addr <= 0xfeff) {
        // Unusable memory.
        return &oam[addr - 0xfea0];
    } else if (addr >= 0xff00 && addr <= 0xff7f) {
        return &io_reg[addr - 0xff00];
    } else if (addr >= 0xff80 && addr <= 0xfffe) {
        return &hram[addr - 0xff80];
    } else if (addr == 0xFFFF) {
        return &interrupt_enable_flag[0];
    }
    return NULL;
}

void set_byte(addr_t address, uint8_t value) {
    if (address <= 0x7fff) {
        // We don't want the ROM to be able to write to the cartridge obviously.
        return;
    }
    *get_address(address) = value;
}

uint8_t read_byte(addr_t address) {
    return *get_address(address);
}