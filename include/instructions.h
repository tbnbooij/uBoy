#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "memory.h"
#include "opcodes.h"

// Loading immediate operands from ROM
// ---------------------------------------------------
uint8_t Instruction_LD_I8_ROM(void);
uint16_t Instruction_LD_I16_ROM(void);

// 8-bit Loads
// ---------------------------------------------------
// 8-bit Register-Register Loads
void Instruction_LD_R8_R8(uint8_t *r1, uint8_t *r2);
void Instruction_LD_R8_R16(uint8_t *r1, uint16_t *r2);
void Instruction_LD_R16_R8(uint16_t *r1, uint8_t *r2);

// 8-bit Register-Immediate Loads
void Instruction_LD_R8_I8(uint8_t *r, uint8_t i);

// 8-bit Register-Memory Interaction
void Instruction_LD_R8_MR8(uint8_t *r1, uint8_t *r2);
void Instruction_LD_MR8_R8(uint8_t *r1, uint8_t *r2);
void Instruction_LD_R8_MR16(uint8_t *r1, uint16_t *r2);
void Instruction_LD_MR16_R8(uint16_t *r1, uint8_t *r2);

// 8-bit Register-Immediate-Memory Interaction
void Instruction_LD_MI8_R8(uint8_t i, uint8_t *r);
void Instruction_LD_R8_MI8(uint8_t *r, uint8_t i);

// 16-bit Loads
// ---------------------------------------------------
// 16-bit Register-Immediate Loads
void Instruction_LD_R16_I16(uint16_t *r, uint16_t i);

// 16-bit Register-Register Loads
void Instruction_LD_R16_R16(uint16_t *r1, uint16_t *r2);

// 16-bit Register-Register-Immediate-Sum Load
void Instruction_LD_R16_R16_I8(uint16_t *r1, uint16_t *r2, uint8_t i);



#endif // INSTRUCTIONS_H
