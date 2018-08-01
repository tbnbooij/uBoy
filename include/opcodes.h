#ifndef OPCODES_H
#define OPCODES_H
#include <stdint.h>
#include "memory.h"
#include "instructions.h"

// Filling the opcode table
// ---------------------------------------------------
void Opcodes_init(void);

// Opcode groups
// ---------------------------------------------------
void Opcode_LD_8(uint8_t opcode);
void Opcode_LD_16(uint8_t opcode);
void Opcode_ALU_8(uint8_t opcode);
void Opcode_ALU_16(uint8_t opcode);
void Opcode_MISC(uint8_t opcode);
void Opcode_JP(uint8_t opcode);
void Opcode_BIT(uint8_t opcode);
void Opcode_WRONG_GROUP_ERROR(uint8_t opcode);

// Opcode Fetching & Decoding
// ---------------------------------------------------
uint8_t Opcode_fetch(void);
void Opcode_decode(uint8_t opcode);

void (*Opcodes[0xFF + 1])(uint8_t opcode);

#endif // OPCODES_H