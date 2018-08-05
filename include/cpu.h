#ifndef CPU_H
#define CPU_H
#include <stdlib.h>
#include "state.h"
#include "memory.h"
#include "opcodes.h"
#include "instructions.h"
#include "debug.h"

struct {
    FILE *source;
} CPU;

void CPU_init(void);
void CPU_input(char *filepath);
void CPU_init_modules(void);
void CPU_start(void);
void CPU_exit(void);

uint8_t File_read_byte(FILE *fp, uint16_t address);
void File_load_rom(void);

#endif // CPU_H