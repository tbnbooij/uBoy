#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "memory.h"
#include "opcodes.h"

// Atomic Memory Instructions
// ---------------------------------------------------
void Instruction_LD_R8_R8(uint8_t *r1, uint8_t *r2);
void Instruction_LD_R8_I8(uint8_t *r);

void Instruction_LD_MR16_R8(uint16_t *r1, uint8_t *r2);
void Instruction_LD_MR16_I8(uint16_t *r);
void Instruction_LD_MI16_R8(uint8_t *r);
void Instruction_LD_R8_MR16(uint8_t *r1, uint16_t *r2);
void Instruction_LD_R8_MI16(uint8_t *r);

void Instruction_LD_A_MC(void);
void Instruction_LD_MC_A(void);

void Instruction_LDD_A_HL(void);
void Instruction_LDD_HL_A(void);

void Instruction_LDI_A_HL(void);
void Instruction_LDI_HL_A(void);

void Instruction_LDH_MI8_A(void);
void Instruction_LDH_A_MI8(void);


// Jumps & Calls
// ---------------------------------------------------
void Instruction_JP_CC_N(uint8_t test);
void Instruction_RET(void);
void Instruction_RET_CC(uint8_t test);

#endif // INSTRUCTIONS_H
