#ifndef CHIP8REGISTERS_H
#define CHIP8REGISTERS_H

#include "config.h"

// storage areas inside the processor
// used for temporary information outside of RAM
// the diff is that registers are much faster than RAM
struct chip8_registers
{
    unsigned char V[CHIP8_TOTAL_DATA_REGISTERS]; // 8-bit
    unsigned short I;                            // 16-bit
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned short PC; // points to the memory addr of the instruction that should be executed
    unsigned char SP;
};

// We are not going to create any functions to access these registers.
// We are going to access them manually (by the variable name) as it's cleaner.
// There is no need to put any restrictions.

#endif