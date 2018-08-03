#ifndef OPCODES_H
#define OPCODES_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "memory.h"
#include "instructions.h"
#include "timer.h"

// Filling the opcode table
// ---------------------------------------------------
void Opcodes_init(void);

// Opcode Fetching & Decoding
// ---------------------------------------------------
uint8_t Opcode_fetch(void);
void Opcode_decode(uint8_t opcode);

// Opcode Tables
void (*Opcodes[0xFF + 1])(void);
void Opcode_not_implemented(uint8_t opcode);

void Opcode_0x00(void);
void Opcode_0x01(void);
void Opcode_0x02(void);
void Opcode_0x03(void);
void Opcode_0x04(void);
void Opcode_0x05(void);
void Opcode_0x06(void);
void Opcode_0x07(void);
void Opcode_0x08(void);
void Opcode_0x09(void);
void Opcode_0x0A(void);
void Opcode_0x0B(void);
void Opcode_0x0C(void);
void Opcode_0x0D(void);
void Opcode_0x0E(void);
void Opcode_0x0F(void);
void Opcode_0x10(void);
void Opcode_0x11(void);
void Opcode_0x12(void);
void Opcode_0x13(void);
void Opcode_0x14(void);
void Opcode_0x15(void);
void Opcode_0x16(void);
void Opcode_0x17(void);
void Opcode_0x18(void);
void Opcode_0x19(void);
void Opcode_0x1A(void);
void Opcode_0x1B(void);
void Opcode_0x1C(void);
void Opcode_0x1D(void);
void Opcode_0x1E(void);
void Opcode_0x1F(void);
void Opcode_0x20(void);
void Opcode_0x21(void);
void Opcode_0x22(void);
void Opcode_0x23(void);
void Opcode_0x24(void);
void Opcode_0x25(void);
void Opcode_0x26(void);
void Opcode_0x27(void);
void Opcode_0x28(void);
void Opcode_0x29(void);
void Opcode_0x2A(void);
void Opcode_0x2B(void);
void Opcode_0x2C(void);
void Opcode_0x2D(void);
void Opcode_0x2E(void);
void Opcode_0x2F(void);
void Opcode_0x30(void);
void Opcode_0x31(void);
void Opcode_0x32(void);
void Opcode_0x33(void);
void Opcode_0x34(void);
void Opcode_0x35(void);
void Opcode_0x36(void);
void Opcode_0x37(void);
void Opcode_0x38(void);
void Opcode_0x39(void);
void Opcode_0x3A(void);
void Opcode_0x3B(void);
void Opcode_0x3C(void);
void Opcode_0x3D(void);
void Opcode_0x3E(void);
void Opcode_0x3F(void);
void Opcode_0x40(void);
void Opcode_0x41(void);
void Opcode_0x42(void);
void Opcode_0x43(void);
void Opcode_0x44(void);
void Opcode_0x45(void);
void Opcode_0x46(void);
void Opcode_0x47(void);
void Opcode_0x48(void);
void Opcode_0x49(void);
void Opcode_0x4A(void);
void Opcode_0x4B(void);
void Opcode_0x4C(void);
void Opcode_0x4D(void);
void Opcode_0x4E(void);
void Opcode_0x4F(void);
void Opcode_0x50(void);
void Opcode_0x51(void);
void Opcode_0x52(void);
void Opcode_0x53(void);
void Opcode_0x54(void);
void Opcode_0x55(void);
void Opcode_0x56(void);
void Opcode_0x57(void);
void Opcode_0x58(void);
void Opcode_0x59(void);
void Opcode_0x5A(void);
void Opcode_0x5B(void);
void Opcode_0x5C(void);
void Opcode_0x5D(void);
void Opcode_0x5E(void);
void Opcode_0x5F(void);
void Opcode_0x60(void);
void Opcode_0x61(void);
void Opcode_0x62(void);
void Opcode_0x63(void);
void Opcode_0x64(void);
void Opcode_0x65(void);
void Opcode_0x66(void);
void Opcode_0x67(void);
void Opcode_0x68(void);
void Opcode_0x69(void);
void Opcode_0x6A(void);
void Opcode_0x6B(void);
void Opcode_0x6C(void);
void Opcode_0x6D(void);
void Opcode_0x6E(void);
void Opcode_0x6F(void);
void Opcode_0x70(void);
void Opcode_0x71(void);
void Opcode_0x72(void);
void Opcode_0x73(void);
void Opcode_0x74(void);
void Opcode_0x75(void);
void Opcode_0x76(void);
void Opcode_0x77(void);
void Opcode_0x78(void);
void Opcode_0x79(void);
void Opcode_0x7A(void);
void Opcode_0x7B(void);
void Opcode_0x7C(void);
void Opcode_0x7D(void);
void Opcode_0x7E(void);
void Opcode_0x7F(void);
void Opcode_0x80(void);
void Opcode_0x81(void);
void Opcode_0x82(void);
void Opcode_0x83(void);
void Opcode_0x84(void);
void Opcode_0x85(void);
void Opcode_0x86(void);
void Opcode_0x87(void);
void Opcode_0x88(void);
void Opcode_0x89(void);
void Opcode_0x8A(void);
void Opcode_0x8B(void);
void Opcode_0x8C(void);
void Opcode_0x8D(void);
void Opcode_0x8E(void);
void Opcode_0x8F(void);
void Opcode_0x90(void);
void Opcode_0x91(void);
void Opcode_0x92(void);
void Opcode_0x93(void);
void Opcode_0x94(void);
void Opcode_0x95(void);
void Opcode_0x96(void);
void Opcode_0x97(void);
void Opcode_0x98(void);
void Opcode_0x99(void);
void Opcode_0x9A(void);
void Opcode_0x9B(void);
void Opcode_0x9C(void);
void Opcode_0x9D(void);
void Opcode_0x9E(void);
void Opcode_0x9F(void);
void Opcode_0xA0(void);
void Opcode_0xA1(void);
void Opcode_0xA2(void);
void Opcode_0xA3(void);
void Opcode_0xA4(void);
void Opcode_0xA5(void);
void Opcode_0xA6(void);
void Opcode_0xA7(void);
void Opcode_0xA8(void);
void Opcode_0xA9(void);
void Opcode_0xAA(void);
void Opcode_0xAB(void);
void Opcode_0xAC(void);
void Opcode_0xAD(void);
void Opcode_0xAE(void);
void Opcode_0xAF(void);
void Opcode_0xB0(void);
void Opcode_0xB1(void);
void Opcode_0xB2(void);
void Opcode_0xB3(void);
void Opcode_0xB4(void);
void Opcode_0xB5(void);
void Opcode_0xB6(void);
void Opcode_0xB7(void);
void Opcode_0xB8(void);
void Opcode_0xB9(void);
void Opcode_0xBA(void);
void Opcode_0xBB(void);
void Opcode_0xBC(void);
void Opcode_0xBD(void);
void Opcode_0xBE(void);
void Opcode_0xBF(void);
void Opcode_0xC0(void);
void Opcode_0xC1(void);
void Opcode_0xC2(void);
void Opcode_0xC3(void);
void Opcode_0xC4(void);
void Opcode_0xC5(void);
void Opcode_0xC6(void);
void Opcode_0xC7(void);
void Opcode_0xC8(void);
void Opcode_0xC9(void);
void Opcode_0xCA(void);
void Opcode_0xCB(void);
void Opcode_0xCC(void);
void Opcode_0xCD(void);
void Opcode_0xCE(void);
void Opcode_0xCF(void);
void Opcode_0xD0(void);
void Opcode_0xD1(void);
void Opcode_0xD2(void);
void Opcode_0xD3(void);
void Opcode_0xD4(void);
void Opcode_0xD5(void);
void Opcode_0xD6(void);
void Opcode_0xD7(void);
void Opcode_0xD8(void);
void Opcode_0xD9(void);
void Opcode_0xDA(void);
void Opcode_0xDB(void);
void Opcode_0xDC(void);
void Opcode_0xDD(void);
void Opcode_0xDE(void);
void Opcode_0xDF(void);
void Opcode_0xE0(void);
void Opcode_0xE1(void);
void Opcode_0xE2(void);
void Opcode_0xE3(void);
void Opcode_0xE4(void);
void Opcode_0xE5(void);
void Opcode_0xE6(void);
void Opcode_0xE7(void);
void Opcode_0xE8(void);
void Opcode_0xE9(void);
void Opcode_0xEA(void);
void Opcode_0xEB(void);
void Opcode_0xEC(void);
void Opcode_0xED(void);
void Opcode_0xEE(void);
void Opcode_0xEF(void);
void Opcode_0xF0(void);
void Opcode_0xF1(void);
void Opcode_0xF2(void);
void Opcode_0xF3(void);
void Opcode_0xF4(void);
void Opcode_0xF5(void);
void Opcode_0xF6(void);
void Opcode_0xF7(void);
void Opcode_0xF8(void);
void Opcode_0xF9(void);
void Opcode_0xFA(void);
void Opcode_0xFB(void);
void Opcode_0xFC(void);
void Opcode_0xFD(void);
void Opcode_0xFE(void);
void Opcode_0xFF(void);

#endif // OPCODES_H