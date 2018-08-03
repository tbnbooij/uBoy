#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "memory.h"
#include "opcodes.h"

// 8-bit arithmetic
void Instruction_ADD_A_N(uint8_t n);
void Instruction_ADC_A_N(uint8_t n);
void Instruction_SUB_N(uint8_t n);
void Instruction_SBC_A_N(uint8_t n);
void Instruction_AND_N(uint8_t n);
void Instruction_OR_N(uint8_t n);
void Instruction_XOR_N(uint8_t n);
void Instruction_CP_N(uint8_t n);
void Instruction_INC_N(uint8_t *r);
void Instruction_DEC_N(uint8_t *r);

// 16-bit arithmetic
void Instruction_ADD_HL_N(uint16_t n);

void Instruction_CALL_NN(uint16_t nn);

void Instruction_RST_N(uint8_t n);

void Instruction_RET(void);

#endif // INSTRUCTIONS_H
