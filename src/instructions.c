#include "instructions.h"

void Instruction_ADD_N(uint8_t n)
{
    Flags_set(
        (Registers.A + n) == 0,
        0,
        Flag_test_H_U8_U8(Registers.A, n, 1),
        Flag_test_C_U8_U8(Registers.A, n, 1));

    Registers.A += n;
}

void Instruction_ADC_N(uint8_t n)
{
    uint8_t c = Flag_get_C();

    Flags_set(
        (Registers.A + n + c) == 0,
        0,
        Flag_test_H_U8_U8(Registers.A, (n + c), 1),
        Flag_test_C_U8_U8(Registers.A, (n + c), 1));

    Registers.A += (n + c);
}

void Instruction_SUB_N(uint8_t n)
{
    Flags_set(
        (Registers.A - n) == 0,
        1,
        Flag_test_H_U8_U8(Registers.A, n, 0),
        Flag_test_C_U8_U8(Registers.A, n, 0));

    Registers.A -= n;
}

void Instruction_SBC_N(uint8_t n)
{
    uint8_t c = Flag_get_C();

    Flags_set(
        (Registers.A - (c + n)) == 0,
        1,
        Flag_test_H_U8_U8(Registers.A, (n + c), 0),
        Flag_test_C_U8_U8(Registers.A, (n + c), 0));

    Registers.A -= (n + c);
}

void Instruction_AND_N(uint8_t n)
{
    Flags_set(
        (Registers.A & n) == 0,
        0,
        1,
        0);

    Registers.A &= n;
}

void Instruction_OR_N(uint8_t n)
{
    Flags_set(
        (Registers.A | n) == 0,
        0,
        0,
        0);

    Registers.A |= n;
}

void Instruction_XOR_N(uint8_t n)
{
    Flags_set(
        (Registers.A ^ n) == 0,
        0,
        0,
        0);

    Registers.A ^= n;
}

void Instruction_CP_N(uint8_t n)
{
    Flags_set(
        Registers.A == n,
        1,
        Flag_test_H_U8_U8(Registers.A, n, 0),
        Flag_test_C_U8_U8(Registers.A, n, 0));
}

void Instruction_INC_N(uint8_t *r)
{
    Flags_set(
        (*r + 1) == 0,
        0,
        Flag_test_H_U8_U8(*r, 1, 1),
        -1);

    *r++;
}

void Instruction_DEC_N(uint8_t *r)
{
    Flags_set(
        (*r - 1) == 0,
        1,
        Flag_test_H_U8_U8(*r, 1, 0),
        -1);

    *r--;
}

void Instruction_ADD_HL_NN(uint16_t nn)
{
    Flags_set(
        -1,
        0,
        Flag_test_H_U16_U16(Registers.HL, nn),
        Flag_test_C_U16_U16(Registers.HL, nn));

    Registers.HL += nn;
}

void Instruction_CALL_NN(uint16_t nn)
{
    Memory_store_byte(Registers.SP - 1, Extract_MSB(Registers.PC));
    Memory_store_byte(Registers.SP - 2, Extract_LSB(Registers.PC));
    Registers.PC = nn;
    Registers.SP -= 2;
}

void Instruction_RST_N(uint8_t n)
{
    Memory_store_byte(Registers.SP - 1, Extract_MSB(Registers.PC));
    Memory_store_byte(Registers.SP - 2, Extract_LSB(Registers.PC));
    Registers.SP -= 2;
    Registers.PC = n;
}

void Instruction_RET(void)
{
    uint8_t lsb = Memory_load_byte(Registers.SP);
    uint8_t msb = Memory_load_byte(Registers.SP + 1);
    Registers.SP += 2;
    Registers.PC = Combine_MSB_LSB(msb, lsb);
}

void Instruction_SET_N_R(uint8_t n, uint8_t *r)
{
    *r |= (1 << n);
}

void Instruction_SET_N_M(uint8_t n, uint16_t m)
{
    uint8_t b = Memory_load_byte(m);
    Instruction_SET_N_R(n, &b);
    Memory_store_byte(m, b);
}

void Instruction_RES_N_R(uint8_t n, uint8_t *r)
{
    *r &= (~(1 << n));
}

void Instruction_RES_N_M(uint8_t n, uint16_t m)
{
    uint8_t b = Memory_load_byte(m);
    Instruction_RES_N_R(n, &b);
    Memory_store_byte(m, b);
}

void Instruction_BIT_N_R(uint8_t n, uint8_t r)
{
    Flags_set(
        (~((r & (1 << n)) >> n)) & 1,
        0,
        1,
        -1);
}

void Instruction_BIT_N_M(uint8_t n, uint16_t m)
{
    Instruction_BIT_N_R(n, Memory_load_byte(m));
}

void Instruction_SWAP_N_R(uint8_t *r)
{
    *r = ((*r & 0x0F) << 4) | ((*r & 0xF0) >> 4);

    Flags_set(
        *r == 0,
        0,
        0,
        0);
}

void Instruction_SWAP_N_M(uint16_t m)
{
    uint8_t b = Memory_load_byte(m);
    Instruction_SWAP_N_R(&b);
    Memory_store_byte(m, b);
}

void Instruction_SRL_N_R(uint8_t *r)
{
    uint8_t bit0 = *r & 1;
    *r >>= 1;

    Flags_set(
        *r == 0,
        0,
        0,
        bit0);
}

void Instruction_SRL_N_M(uint16_t m)
{
    uint8_t b = Memory_load_byte(m);
    Instruction_SRL_N_R(&b);
    Memory_store_byte(m, b);
}

void Instruction_SLA_N_R(uint8_t *r)
{
    uint8_t bit7 = (*r & 0x80) >> 7;
    *r <<= 1;

    Flags_set(
        *r == 0,
        0,
        0,
        bit7);
}

void Instruction_SLA_N_M(uint16_t m)
{
    uint8_t b = Memory_load_byte(m);
    Instruction_SLA_N_R(&b);
    Memory_store_byte(m, b);
}

void Instruction_SRA_N_R(uint8_t *r)
{
    uint8_t bit0 = *r & 1;
    uint8_t bit7 = *r & 0x80;
    *r = (*r >> 1) | bit7;

    Flags_set(
        *r == 0,
        0,
        0,
        bit0);
}

void Instruction_SRA_N_M(uint16_t m)
{
    uint8_t b = Memory_load_byte(m);
    Instruction_SRA_N_R(&b);
    Memory_store_byte(m, b);
}

void Instruction_RL_N_R(uint8_t *r)
{
    uint8_t bit7 = (*r & 0x80) >> 7;
    uint8_t bit0 = Flag_get_C();

    *r = (*r << 1) | bit0;

    Flags_set(
        *r == 0,
        0,
        0,
        bit7);
}

void Instruction_RL_N_M(uint16_t m)
{
    uint8_t b = Memory_load_byte(m);
    Instruction_RL_N_R(&b);
    Memory_store_byte(m, b);
}

void Instruction_RR_N_R(uint8_t *r)
{
    uint8_t bit0 = *r & 1;
    uint8_t bit7 = Flag_get_C() << 7;

    *r = (*r >> 1) | bit7;

    Flags_set(
        *r == 0,
        0,
        0,
        bit0);
}

void Instruction_RR_N_M(uint16_t m)
{
    uint8_t b = Memory_load_byte(m);
    Instruction_RR_N_R(&b);
    Memory_store_byte(m, b);
}

void Instruction_RLC_N_R(uint8_t *r)
{
    uint8_t b = (*r & 0x80) >> 0;

    *r = (*r << 1) | b;

    Flags_set(
        *r == 0,
        0,
        0,
        b);
}

void Instruction_RLC_N_M(uint16_t m)
{
    uint8_t b = Memory_load_byte(m);
    Instruction_RLC_N_R(&b);
    Memory_store_byte(m, b);
}

void Instruction_RRC_N_R(uint8_t *r)
{
    uint8_t b = *r & 1;

    *r = (*r >> 1) | (b << 7);

    Flags_set(
        *r == 0,
        0,
        0,
        b);
}

void Instruction_RRC_N_M(uint16_t m)
{
    uint8_t b = Memory_load_byte(m);
    Instruction_RRC_N_R(&b);
    Memory_store_byte(m, b);
}
