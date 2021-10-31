#include <stddef.h>
#include "memory.h"

uint8_t vector_restart[0x100];
uint8_t cartridge[0x8000];
uint8_t vram[0x2000];
uint8_t sram[0x2000];
uint8_t wram[0x2000];
uint8_t echo[0x1e80];
uint8_t io_reg[0x80];
uint8_t oam[0xa0];
uint8_t hram[0x80];
uint8_t interrupt_enable_flag[0x1];

uint8_t* get_address(addr_t addr) {
    if (addr <= 0x7FFF) { // 32KB
        return &cartridge[addr];
    } else if (addr >= 0x8000 && addr <= 0x9FFF) { // 8KB
        return &vram[addr - 0x8000];
    } else if (addr >= 0xA000 && addr <= 0xBFFF) { // 8KB
        return &sram[addr - 0xA000];
    } else if (addr >= 0xC000 && addr <= 0xDFFF) { // 8KB
        return &wram[addr - 0xC000];
    } else if (addr >= 0xE000 && addr <= 0xFDFF) { // 7.68 KB
        // Reserved Echo Ram, this mirrors 0xC000 - 0xDDFF
        return &wram[addr - 0xE000];
    } else if (addr >= 0xFE00 && addr <= 0xFE9F) { // 160 bytes
        return &oam[addr - 0xFE00];
    } else if (addr >= 0xFEA0 && addr <= 0xFEFF) { // 96 bytes
        // Unusable memory.
        return &oam[addr - 0xFEA0];
    } else if (addr >= 0xFF00 && addr <= 0xFF7F) { // 128 bytes
        return &io_reg[addr - 0xFF00];
    } else if (addr >= 0xFF80 && addr <= 0xFFFE) { // 127 bytes
        return &hram[addr - 0xFF80];
    } else if (addr == 0xFFFF) { // 1 byte
        return &interrupt_enable_flag[0];
    }
    return NULL;
}

void write(addr_t address, uint8_t value) {
    if (address <= 0x7fff) {
        // We don't want the ROM to be able to write to the cartridge obviously.
        return;
    }
    *get_address(address) = value;
}

uint8_t read(addr_t address) {
    return *get_address(address);
}