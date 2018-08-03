#include "instructions.h"

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