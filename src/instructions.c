#include "instructions.h"

// 8-bit arithmetic
void Instruction_ADD_A_N(uint8_t n) {
    Flags_set(
        (Registers.A + n) == 0,
        0,
        Flag_test_H_U8_U8(Registers.A, n, 1),
        Flag_test_C_U8_U8(Registers.A, n, 1)
    );

    Registers.A += n;
}

void Instruction_ADC_A_N(uint8_t n) {
    uint8_t c = Flag_get_C();

    Flags_set(
        (Registers.A + n + c) == 0,
        0,
        Flag_test_H_U8_U8(Registers.A, (n + c), 1),
        Flag_test_C_U8_U8(Registers.A, (n + c), 1)
    );

    Registers.A += (n + c);
}

void Instruction_SUB_N(uint8_t n) {
    Flags_set(
        (Registers.A - n) == 0,
        1,
        Flag_test_H_U8_U8(Registers.A, n, 0),
        Flag_test_C_U8_U8(Registers.A, n, 0)
    );

    Registers.A -= n;
}

void Instruction_SBC_A_N(uint8_t n) {
    uint8_t c = Flag_get_C();

    Flags_set(
        (Registers.A - (c + n)) == 0,
        1,
        Flag_test_H_U8_U8(Registers.A, (n + c), 0),
        Flag_test_C_U8_U8(Registers.A, (n + c), 0)
    );
    
    Registers.A -= (n + c);
}

void Instruction_AND_N(uint8_t n) {
    Flags_set(
        (Registers.A & n) == 0,
        0,
        1,
        0
    );

    Registers.A &= n;
}

void Instruction_OR_N(uint8_t n) {
    Flags_set(
        (Registers.A | n) == 0,
        0,
        0,
        0
    );

    Registers.A |= n;
}

void Instruction_XOR_N(uint8_t n) {
    Flags_set(
        (Registers.A ^ n) == 0,
        0,
        0,
        0
    );

    Registers.A ^= n;
}

void Instruction_CP_N(uint8_t n) {
    Flags_set(
        Registers.A == n,
        1,
        Flag_test_H_U8_U8(Registers.A, n, 0),
        Flag_test_C_U8_U8(Registers.A, n, 0)
    );
}

void Instruction_INC_N(uint8_t *r) {
    Flags_set(
        (*r + 1) == 0,
        0,
        Flag_test_H_U8_U8(*r, 1, 1),
        -1
    );

    *r++;
}

void Instruction_DEC_N(uint8_t *r) {
    Flags_set(
        (*r - 1) == 0,
        1,
        Flag_test_H_U8_U8(*r, 1, 0),
        -1
    );

    *r--;
}

// 16-bit arithmetic
void Instruction_ADD_HL_N(uint16_t n) {
    Flags_set(
        -1,
        0,
        Flag_test_H_U16_U16(Registers.HL, n),
        Flag_test_C_U16_U16(Registers.HL, n)
    );

    Registers.HL += n;
}

void Instruction_CALL_NN(uint16_t nn) {
    Memory_store_byte(Registers.SP - 1, Extract_MSB(Registers.PC));
    Memory_store_byte(Registers.SP - 2, Extract_LSB(Registers.PC));
    Registers.PC = nn;
    Registers.SP -= 2;
}

void Instruction_RST_N(uint8_t n) {
    Memory_store_byte(Registers.SP - 1, Extract_MSB(Registers.PC));
    Memory_store_byte(Registers.SP - 2, Extract_LSB(Registers.PC));
    Registers.SP -= 2;
    Registers.PC = n;
}

void Instruction_RET(void) {
    uint8_t lsb = Memory_load_byte(Registers.SP);
    uint8_t msb = Memory_load_byte(Registers.SP + 1);
    Registers.SP += 2;
    Registers.PC = Combine_MSB_LSB(msb, lsb);
}