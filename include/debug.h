#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#include "memory.h"

extern void Debug_print_state(uint64_t clk);
extern void Debug_print_ROM(uint16_t begin, uint16_t end);

#endif // DEBUG_H
