/**
 * @brief A set of reusable instructions that are called by the
 * opcode functions.
 * 
 * @file instructions.h
 * @author tbnbooij
 * @date 2018-08-13
 */
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "memory.h"
#include "state.h"

/**
 * @brief Add unsigned 8-bit constant to register A.
 * 
 * @param n Unsigned 8-bit constant
 */
extern void Instruction_ADD_N(uint8_t n);

/**
 * @brief Add unsigned 8-bit constant and carry flag to register A.
 * 
 * @param n Unsigned 8-bit constant
 */
extern void Instruction_ADC_N(uint8_t n);

/**
 * @brief Subtract unsigned 8-bit constant from register A.
 * 
 * @param n Unsigned 8-bit constant
 */
extern void Instruction_SUB_N(uint8_t n);

/**
 * @brief Subtract unsigned 8-bit constant and carry flag from register A.
 * 
 * @param n Unsigned 8-bit constant
 */
extern void Instruction_SBC_N(uint8_t n);

/**
 * @brief Apply bitwise AND operation on register A and an unsigned 8-bit constant.
 * 
 * @param n Unsigned 8-bit constant
 */
extern void Instruction_AND_N(uint8_t n);

/**
 * @brief Apply bitwise OR operation on register A and an unsigned 8-bit constant.
 * 
 * @param n Unsigned 8-bit constant
 */
extern void Instruction_OR_N(uint8_t n);

/**
 * @brief Apply bitwise XOR operation on register A and an unsigned 8-bit constant.
 * 
 * @param n Unsigned 8-bit constant
 */
extern void Instruction_XOR_N(uint8_t n);

/**
 * @brief Compare the value in register A with an unsigned 8-bit constant. Essentially, this 
 * function subtracts the constant from the register value, sets the flags accordingly
 * and throws away the result of the substraction.
 * 
 * @param n Unsigned 8-bit constant
 */
extern void Instruction_CP_N(uint8_t n);

/**
 * @brief Increment the value in a given register.
 * 
 * @param *r Pointer to an unsigned 8-bit register
 */
extern void Instruction_INC_N(uint8_t *r);

/**
 * @brief Decrement the value in a given register.
 * 
 * @param *r Pointer to an unsigned 8-bit register
 */
extern void Instruction_DEC_N(uint8_t *r);

/**
 * @brief Add an unsigned 16-bit constant to register HL.
 * 
 * @param nn Unsigned 16-bit constant
 */
extern void Instruction_ADD_HL_NN(uint16_t nn);

/**
 * @brief Push the current program counter on the stack and set the program counter
 * to an unsigned 16-bit constant (address).
 * 
 * @param nn 16-bit address the PC is set to
 */
extern void Instruction_CALL_NN(uint16_t nn);

/**
 * @brief Push the current program counter on the stack and set the program counter
 * to an unsigned 8-bit constant (address). 
 * 
 * @param n 8-bit address the PC is set to
 */
extern void Instruction_RST_N(uint8_t n);

/**
 * @brief Pop two bytes from the stack and set the program counter to the 16-bit
 * address these bytes form.
 * 
 */
extern void Instruction_RET(void);

/**
 * @brief Set the nth bit of a given register.
 * 
 * @param n The index of the bit that will be set (little-endian, indexed from 0)
 * @param *r Pointer to an unsigned 8-bit register 
 */
extern void Instruction_SET_N_R(uint8_t n, uint8_t *r);

/**
 * @brief Set the nth bit of a byte in memory.
 * 
 * @param n The index of the bit that will be set (little-endian, indexed from 0)
 * @param m The 16-bit address of the modified byte
 */
extern void Instruction_SET_N_M(uint8_t n, uint16_t m);

/**
 * @brief Reset the nth bit of a given register.
 * 
 * @param n The index of the bit that will be reset (little-endian, indexed from 0)
 * @param *r Pointer to an unsigned 8-bit register 
 */
extern void Instruction_RES_N_R(uint8_t n, uint8_t *r);

/**
 * @brief Reset the nth bit of a byte in memory.
 * 
 * @param n The index of the bit that will be reset (little-endian, indexed from 0)
 * @param m The 16-bit address of the modified byte
 */
extern void Instruction_RES_N_M(uint8_t n, uint16_t m);

/**
 * @brief Test the nth bit of an unsigned 8-bit register (set flags accordingly).
 * 
 * @param n The index of the bit that will be tested (little-endian, indexed from 0)
 * @param r The value in an unsigned 8-bit register
 */
extern void Instruction_BIT_N_R(uint8_t n, uint8_t r);

/**
 * @brief Test the nth bit of a byte in memory (set flags accordingly).
 * 
 * @param n The index of the bit that will be tested (little-endian, indexed from 0)
 * @param m The 16-bit address of the tested byte
 */
extern void Instruction_BIT_N_M(uint8_t n, uint16_t m);

/**
 * @brief Swap the order of the two nibbles in an unsigned 8-bit register.
 * 
 * @param *r Pointer to an unsigned 8-bit register 
 */
extern void Instruction_SWAP_N_R(uint8_t *r);

/**
 * @brief Swap the order of the two nibbles of a byte in memory.
 * 
 * @param m The 16-bit address of the modified byte
 */
extern void Instruction_SWAP_N_M(uint16_t m);

/**
 * @brief Shift an unsigned 8-bit register to the right. The LSB is pushed into
 * the carry flag and the MSB is set to 0.
 * 
 * 
 * @param *r Pointer to an unsigned 8-bit register
 */
extern void Instruction_SRL_N_R(uint8_t *r);

/**
 * @brief Shift a byte in memory to the right. The LSB is pushed into the carry flag
 * and the MSB is set to 0.
 * 
 * @param m The 16-bit address of the modified byte
 */
extern void Instruction_SRL_N_M(uint16_t m);

/**
 * @brief Shift an unsigned 8-bit register to the left. The MSB is pushed into
 * the carry flag and the LSB is set to 0. 
 * 
 * @param *r Pointer to an unsigned 8-bit register 
 */
extern void Instruction_SLA_N_R(uint8_t *r);

/**
 * @brief Shift a byte in memory to the left. The MSB is pushed into the carry flag
 * and the LSB is set to 0.
 * 
 * @param m The 16-bit address of the modified byte
 */
extern void Instruction_SLA_N_M(uint16_t m);

/**
 * @brief Shift an unsigned 8-bit register to the right. The LSB is pushed into
 * the carry flag and the MSB remains the value it had before the shift.
 * 
 * @param *r Pointer to an unsigned 8-bit register
 */
extern void Instruction_SRA_N_R(uint8_t *r);

/**
 * @brief Shift a byte in memory to the right. The LSB is pushed into the carry flag
 * and the MSB remains the value it has before the shift.
 * 
 * @param m The 16-bit address of the modified byte
 */
extern void Instruction_SRA_N_M(uint16_t m);

/**
 * @brief Rotate an unsigned 8-bit register to the left through the carry flag.
 * 
 * @param *r Pointer to an unsigned 8-bit register 
 */
extern void Instruction_RL_N_R(uint8_t *r);

/**
 * @brief Rotate a byte in memory to the left through the carry flag.
 * 
 * @param m The 16-bit address of the modified byte
 */
extern void Instruction_RL_N_M(uint16_t m);

/**
 * @brief Rotate an unsigned 8-bit register to the right through the carry flag.
 * 
 * @param *r Pointer to an unsigned 8-bit register 
 */
extern void Instruction_RR_N_R(uint8_t *r);

/**
 * @brief Rotate a byte in memory to the right through the carry flag.
 * 
 * @param m The 16-bit address of the modified byte
 */
extern void Instruction_RR_N_M(uint16_t m);

/**
 * @brief Rotate an unsigned 8-bit register to the left and store the former MSB in
 * the carry flag.
 * 
 * @param *r Pointer to an unsigned 8-bit register 
 */
extern void Instruction_RLC_N_R(uint8_t *r);

/**
 * @brief Rotate a byte in memory to the left and store the former MSB in the carry flag.
 * 
 * @param m The 16-bit address of the modified byte
 */
extern void Instruction_RLC_N_M(uint16_t m);

/**
 * @brief Rotate an unsigned 8-bit register to the right and store the former LSB in
 * the carry flag.
 * 
 * @param *r Pointer to an unsigned 8-bit register 
 */
extern void Instruction_RRC_N_R(uint8_t *r);

/**
 * @brief Rotate a byte in memory to the right and store the former LSB in the carry flag.
 * 
 * @param m The 16-bit address of the modified byte
 */
extern void Instruction_RRC_N_M(uint16_t m);

#endif // INSTRUCTIONS_H
