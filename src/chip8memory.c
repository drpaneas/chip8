#include "chip8memory.h"

void chip8_memory_set(struct chip8_memory *memory, int index, unsigned char val)
{
    memory->address_space[index] = val;
}

unsigned char chip8_memory_get(struct chip8_memory *memory, int index)
{
    return memory->address_space[index];
}