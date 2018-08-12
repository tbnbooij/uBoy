#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "memory.h"
#include "state.h"

extern void Instruction_ADD_A_N(uint8_t n);
extern void Instruction_ADC_A_N(uint8_t n);
extern void Instruction_SUB_N(uint8_t n);
extern void Instruction_SBC_A_N(uint8_t n);
extern void Instruction_AND_N(uint8_t n);
extern void Instruction_OR_N(uint8_t n);
extern void Instruction_XOR_N(uint8_t n);
extern void Instruction_CP_N(uint8_t n);
extern void Instruction_INC_N(uint8_t *r);
extern void Instruction_DEC_N(uint8_t *r);

extern void Instruction_ADD_HL_N(uint16_t n);

extern void Instruction_CALL_NN(uint16_t nn);
extern void Instruction_RST_N(uint8_t n);
extern void Instruction_RET(void);

extern void Instruction_SET_N_R(uint8_t n, uint8_t *r);
extern void Instruction_SET_N_M(uint8_t n, uint16_t m);
extern void Instruction_RES_N_R(uint8_t n, uint8_t *r);
extern void Instruction_RES_N_M(uint8_t n, uint16_t m);
extern void Instruction_BIT_N_R(uint8_t n, uint8_t r);
extern void Instruction_BIT_N_M(uint8_t n, uint16_t m);
extern void Instruction_SWAP_N_R(uint8_t *r);
extern void Instruction_SWAP_N_M(uint16_t m);
extern void Instruction_SRL_N_R(uint8_t *r);
extern void Instruction_SRL_N_M(uint16_t m);
extern void Instruction_SLA_N_R(uint8_t *r);
extern void Instruction_SLA_N_M(uint16_t m);
extern void Instruction_SRA_N_R(uint8_t *r);
extern void Instruction_SRA_N_M(uint16_t m);
extern void Instruction_RL_N_R(uint8_t *r);
extern void Instruction_RL_N_M(uint16_t m);
extern void Instruction_RR_N_R(uint8_t *r);
extern void Instruction_RR_N_M(uint16_t m);
extern void Instruction_RLC_N_R(uint8_t *r);
extern void Instruction_RLC_N_M(uint16_t m);
extern void Instruction_RRC_N_R(uint8_t *r);
extern void Instruction_RRC_N_M(uint16_t m);

#endif // INSTRUCTIONS_H
