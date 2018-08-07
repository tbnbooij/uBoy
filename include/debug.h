#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#include "memory.h"
#include "opcodes.h"

void Debug_print_state(void);
void Debug_print_ROM(uint16_t begin, uint16_t end);

#endif // DEBUG_H
