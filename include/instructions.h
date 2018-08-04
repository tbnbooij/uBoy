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

// Calls and jumps
void Instruction_CALL_NN(uint16_t nn);
void Instruction_RST_N(uint8_t n);
void Instruction_RET(void);

// Shifts and rotates (CB-opcodes)
void Instruction_SET_N_R(uint8_t n, uint8_t *r);
void Instruction_SET_N_M(uint8_t n, uint16_t m);
void Instruction_RES_N_R(uint8_t n, uint8_t *r);
void Instruction_RES_N_M(uint8_t n, uint16_t m);
void Instruction_BIT_N_R(uint8_t n, uint8_t r);
void Instruction_BIT_N_M(uint8_t n, uint16_t m);
void Instruction_SWAP_N_R(uint8_t *r);
void Instruction_SWAP_N_M(uint16_t m);
void Instruction_SRL_N_R(uint8_t *r);
void Instruction_SRL_N_M(uint16_t m);
void Instruction_SLA_N_R(uint8_t *r);
void Instruction_SLA_N_M(uint16_t m);
void Instruction_SRA_N_R(uint8_t *r);
void Instruction_SRA_N_M(uint16_t m);
void Instruction_RL_N_R(uint8_t *r);
void Instruction_RL_N_M(uint16_t m);
void Instruction_RR_N_R(uint8_t *r);
void Instruction_RR_N_M(uint16_t m);
void Instruction_RLC_N_R(uint8_t *r);
void Instruction_RLC_N_M(uint16_t m);
void Instruction_RRC_N_R(uint8_t *r);
void Instruction_RRC_N_M(uint16_t m);

#endif // INSTRUCTIONS_H
