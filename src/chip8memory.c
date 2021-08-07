#include "chip8memory.h"
#include <stdio.h>
#include <assert.h>

void chip8_is_memory_in_bounds(int index)
{
    assert(index >= 0 && index < CHIP8_MEMORY_SIZE);
}

void chip8_memory_set(struct chip8_memory *memory, int index, unsigned char val)
{
    chip8_is_memory_in_bounds(index);
    printf("Setting value: '%u' at memory address: '0x%x'\n", val, index);
    memory->address_space[index] = 5;
}

unsigned char chip8_memory_get(struct chip8_memory *memory, int index)
{
    chip8_is_memory_in_bounds(index);
    printf("Getting from the memory address: '0x%x' the value: '%u'\n", index, memory->address_space[index]);
    return memory->address_space[index];
}