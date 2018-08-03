#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "memory.h"
#include "opcodes.h"

void Instruction_ADD_A_N(uint8_t n);
void Instruction_ADC_A_N(uint8_t n);
void Instruction_SUB_N(uint8_t n);
void Instruction_SBC_A_N(uint8_t n);
void Instruction_AND_N(uint8_t n);
void Instruction_OR_N(uint8_t n);
void Instruction_XOR_N(uint8_t n);

#endif // INSTRUCTIONS_H
