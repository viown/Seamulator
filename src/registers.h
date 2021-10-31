#ifndef REGISTERS_H
#define REGISTERS_H
#include <stdbool.h>
#include <stdint.h>

// Gameboy 8-bit registers are A, B, C, D, E, H, L
// These registers can be combined to form 16-bit registers: AF, BC, DE, HL
// So to save us from having to do (X << 8) | Y everytime we wanted to combine these, I instead decided to take advantage of unions to do this.

enum flag_t {
    Z,
    N,
    H,
    C
};

struct registers {
    struct {
        union {
            struct {
                uint8_t F;
                uint8_t A;
            };
            uint16_t AF;
        };
    };
    struct {
        union {
            struct {
                uint8_t C;
                uint8_t B;
            };
            uint16_t BC;
        };
    };
    struct {
        union {
            struct {
                uint8_t E;
                uint8_t D;
            };
            uint16_t DE;
        };
    };
    struct {
        union {
            struct {
                uint8_t L;
                uint8_t H;
            };
            uint16_t HL;
        };
    };
    uint16_t SP;
    uint16_t PC;
} extern registers;

void reset_registers();
void set_flag(enum flag_t flag);
void clear_flag(enum flag_t flag);
bool flag_isset(enum flag_t flag);

#endif // REGISTERS_H
