#include "memory.h"

unsigned char vector_restart[0x100];
unsigned char cartridge[0x8000];
unsigned char vram[0x2000];
unsigned char wram[0x2000];
unsigned char echo[0x1e80];
unsigned char io_reg[0x80];
unsigned char oam[0xa0];
unsigned char hram[0x80];
unsigned char interrupt_enable_flag[0x1];

unsigned char* get_address(addr_t addr) {
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
}

void set_byte(addr_t addr, unsigned char value) {
    *get_address(addr) = value;
}

unsigned char read_byte(addr_t addr) {
    return *get_address(addr);
}