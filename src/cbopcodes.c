#include "cbopcodes.h"

// Filling the opcode table
// ---------------------------------------------------
void CBOpcodes_init() {
    CBOpcodes[0x00] = CBOpcode_0x00;
    CBOpcodes[0x01] = CBOpcode_0x01;
    CBOpcodes[0x02] = CBOpcode_0x02;
    CBOpcodes[0x03] = CBOpcode_0x03;
    CBOpcodes[0x04] = CBOpcode_0x04;
    CBOpcodes[0x05] = CBOpcode_0x05;
    CBOpcodes[0x06] = CBOpcode_0x06;
    CBOpcodes[0x07] = CBOpcode_0x07;
    CBOpcodes[0x08] = CBOpcode_0x08;
    CBOpcodes[0x09] = CBOpcode_0x09;
    CBOpcodes[0x0A] = CBOpcode_0x0A;
    CBOpcodes[0x0B] = CBOpcode_0x0B;
    CBOpcodes[0x0C] = CBOpcode_0x0C;
    CBOpcodes[0x0D] = CBOpcode_0x0D;
    CBOpcodes[0x0E] = CBOpcode_0x0E;
    CBOpcodes[0x0F] = CBOpcode_0x0F;
    CBOpcodes[0x10] = CBOpcode_0x10;
    CBOpcodes[0x11] = CBOpcode_0x11;
    CBOpcodes[0x12] = CBOpcode_0x12;
    CBOpcodes[0x13] = CBOpcode_0x13;
    CBOpcodes[0x14] = CBOpcode_0x14;
    CBOpcodes[0x15] = CBOpcode_0x15;
    CBOpcodes[0x16] = CBOpcode_0x16;
    CBOpcodes[0x17] = CBOpcode_0x17;
    CBOpcodes[0x18] = CBOpcode_0x18;
    CBOpcodes[0x19] = CBOpcode_0x19;
    CBOpcodes[0x1A] = CBOpcode_0x1A;
    CBOpcodes[0x1B] = CBOpcode_0x1B;
    CBOpcodes[0x1C] = CBOpcode_0x1C;
    CBOpcodes[0x1D] = CBOpcode_0x1D;
    CBOpcodes[0x1E] = CBOpcode_0x1E;
    CBOpcodes[0x1F] = CBOpcode_0x1F;
    CBOpcodes[0x20] = CBOpcode_0x20;
    CBOpcodes[0x21] = CBOpcode_0x21;
    CBOpcodes[0x22] = CBOpcode_0x22;
    CBOpcodes[0x23] = CBOpcode_0x23;
    CBOpcodes[0x24] = CBOpcode_0x24;
    CBOpcodes[0x25] = CBOpcode_0x25;
    CBOpcodes[0x26] = CBOpcode_0x26;
    CBOpcodes[0x27] = CBOpcode_0x27;
    CBOpcodes[0x28] = CBOpcode_0x28;
    CBOpcodes[0x29] = CBOpcode_0x29;
    CBOpcodes[0x2A] = CBOpcode_0x2A;
    CBOpcodes[0x2B] = CBOpcode_0x2B;
    CBOpcodes[0x2C] = CBOpcode_0x2C;
    CBOpcodes[0x2D] = CBOpcode_0x2D;
    CBOpcodes[0x2E] = CBOpcode_0x2E;
    CBOpcodes[0x2F] = CBOpcode_0x2F;
    CBOpcodes[0x30] = CBOpcode_0x30;
    CBOpcodes[0x31] = CBOpcode_0x31;
    CBOpcodes[0x32] = CBOpcode_0x32;
    CBOpcodes[0x33] = CBOpcode_0x33;
    CBOpcodes[0x34] = CBOpcode_0x34;
    CBOpcodes[0x35] = CBOpcode_0x35;
    CBOpcodes[0x36] = CBOpcode_0x36;
    CBOpcodes[0x37] = CBOpcode_0x37;
    CBOpcodes[0x38] = CBOpcode_0x38;
    CBOpcodes[0x39] = CBOpcode_0x39;
    CBOpcodes[0x3A] = CBOpcode_0x3A;
    CBOpcodes[0x3B] = CBOpcode_0x3B;
    CBOpcodes[0x3C] = CBOpcode_0x3C;
    CBOpcodes[0x3D] = CBOpcode_0x3D;
    CBOpcodes[0x3E] = CBOpcode_0x3E;
    CBOpcodes[0x3F] = CBOpcode_0x3F;
    CBOpcodes[0x40] = CBOpcode_0x40;
    CBOpcodes[0x41] = CBOpcode_0x41;
    CBOpcodes[0x42] = CBOpcode_0x42;
    CBOpcodes[0x43] = CBOpcode_0x43;
    CBOpcodes[0x44] = CBOpcode_0x44;
    CBOpcodes[0x45] = CBOpcode_0x45;
    CBOpcodes[0x46] = CBOpcode_0x46;
    CBOpcodes[0x47] = CBOpcode_0x47;
    CBOpcodes[0x48] = CBOpcode_0x48;
    CBOpcodes[0x49] = CBOpcode_0x49;
    CBOpcodes[0x4A] = CBOpcode_0x4A;
    CBOpcodes[0x4B] = CBOpcode_0x4B;
    CBOpcodes[0x4C] = CBOpcode_0x4C;
    CBOpcodes[0x4D] = CBOpcode_0x4D;
    CBOpcodes[0x4E] = CBOpcode_0x4E;
    CBOpcodes[0x4F] = CBOpcode_0x4F;
    CBOpcodes[0x50] = CBOpcode_0x50;
    CBOpcodes[0x51] = CBOpcode_0x51;
    CBOpcodes[0x52] = CBOpcode_0x52;
    CBOpcodes[0x53] = CBOpcode_0x53;
    CBOpcodes[0x54] = CBOpcode_0x54;
    CBOpcodes[0x55] = CBOpcode_0x55;
    CBOpcodes[0x56] = CBOpcode_0x56;
    CBOpcodes[0x57] = CBOpcode_0x57;
    CBOpcodes[0x58] = CBOpcode_0x58;
    CBOpcodes[0x59] = CBOpcode_0x59;
    CBOpcodes[0x5A] = CBOpcode_0x5A;
    CBOpcodes[0x5B] = CBOpcode_0x5B;
    CBOpcodes[0x5C] = CBOpcode_0x5C;
    CBOpcodes[0x5D] = CBOpcode_0x5D;
    CBOpcodes[0x5E] = CBOpcode_0x5E;
    CBOpcodes[0x5F] = CBOpcode_0x5F;
    CBOpcodes[0x60] = CBOpcode_0x60;
    CBOpcodes[0x61] = CBOpcode_0x61;
    CBOpcodes[0x62] = CBOpcode_0x62;
    CBOpcodes[0x63] = CBOpcode_0x63;
    CBOpcodes[0x64] = CBOpcode_0x64;
    CBOpcodes[0x65] = CBOpcode_0x65;
    CBOpcodes[0x66] = CBOpcode_0x66;
    CBOpcodes[0x67] = CBOpcode_0x67;
    CBOpcodes[0x68] = CBOpcode_0x68;
    CBOpcodes[0x69] = CBOpcode_0x69;
    CBOpcodes[0x6A] = CBOpcode_0x6A;
    CBOpcodes[0x6B] = CBOpcode_0x6B;
    CBOpcodes[0x6C] = CBOpcode_0x6C;
    CBOpcodes[0x6D] = CBOpcode_0x6D;
    CBOpcodes[0x6E] = CBOpcode_0x6E;
    CBOpcodes[0x6F] = CBOpcode_0x6F;
    CBOpcodes[0x70] = CBOpcode_0x70;
    CBOpcodes[0x71] = CBOpcode_0x71;
    CBOpcodes[0x72] = CBOpcode_0x72;
    CBOpcodes[0x73] = CBOpcode_0x73;
    CBOpcodes[0x74] = CBOpcode_0x74;
    CBOpcodes[0x75] = CBOpcode_0x75;
    CBOpcodes[0x76] = CBOpcode_0x76;
    CBOpcodes[0x77] = CBOpcode_0x77;
    CBOpcodes[0x78] = CBOpcode_0x78;
    CBOpcodes[0x79] = CBOpcode_0x79;
    CBOpcodes[0x7A] = CBOpcode_0x7A;
    CBOpcodes[0x7B] = CBOpcode_0x7B;
    CBOpcodes[0x7C] = CBOpcode_0x7C;
    CBOpcodes[0x7D] = CBOpcode_0x7D;
    CBOpcodes[0x7E] = CBOpcode_0x7E;
    CBOpcodes[0x7F] = CBOpcode_0x7F;
    CBOpcodes[0x80] = CBOpcode_0x80;
    CBOpcodes[0x81] = CBOpcode_0x81;
    CBOpcodes[0x82] = CBOpcode_0x82;
    CBOpcodes[0x83] = CBOpcode_0x83;
    CBOpcodes[0x84] = CBOpcode_0x84;
    CBOpcodes[0x85] = CBOpcode_0x85;
    CBOpcodes[0x86] = CBOpcode_0x86;
    CBOpcodes[0x87] = CBOpcode_0x87;
    CBOpcodes[0x88] = CBOpcode_0x88;
    CBOpcodes[0x89] = CBOpcode_0x89;
    CBOpcodes[0x8A] = CBOpcode_0x8A;
    CBOpcodes[0x8B] = CBOpcode_0x8B;
    CBOpcodes[0x8C] = CBOpcode_0x8C;
    CBOpcodes[0x8D] = CBOpcode_0x8D;
    CBOpcodes[0x8E] = CBOpcode_0x8E;
    CBOpcodes[0x8F] = CBOpcode_0x8F;
    CBOpcodes[0x90] = CBOpcode_0x90;
    CBOpcodes[0x91] = CBOpcode_0x91;
    CBOpcodes[0x92] = CBOpcode_0x92;
    CBOpcodes[0x93] = CBOpcode_0x93;
    CBOpcodes[0x94] = CBOpcode_0x94;
    CBOpcodes[0x95] = CBOpcode_0x95;
    CBOpcodes[0x96] = CBOpcode_0x96;
    CBOpcodes[0x97] = CBOpcode_0x97;
    CBOpcodes[0x98] = CBOpcode_0x98;
    CBOpcodes[0x99] = CBOpcode_0x99;
    CBOpcodes[0x9A] = CBOpcode_0x9A;
    CBOpcodes[0x9B] = CBOpcode_0x9B;
    CBOpcodes[0x9C] = CBOpcode_0x9C;
    CBOpcodes[0x9D] = CBOpcode_0x9D;
    CBOpcodes[0x9E] = CBOpcode_0x9E;
    CBOpcodes[0x9F] = CBOpcode_0x9F;
    CBOpcodes[0xA0] = CBOpcode_0xA0;
    CBOpcodes[0xA1] = CBOpcode_0xA1;
    CBOpcodes[0xA2] = CBOpcode_0xA2;
    CBOpcodes[0xA3] = CBOpcode_0xA3;
    CBOpcodes[0xA4] = CBOpcode_0xA4;
    CBOpcodes[0xA5] = CBOpcode_0xA5;
    CBOpcodes[0xA6] = CBOpcode_0xA6;
    CBOpcodes[0xA7] = CBOpcode_0xA7;
    CBOpcodes[0xA8] = CBOpcode_0xA8;
    CBOpcodes[0xA9] = CBOpcode_0xA9;
    CBOpcodes[0xAA] = CBOpcode_0xAA;
    CBOpcodes[0xAB] = CBOpcode_0xAB;
    CBOpcodes[0xAC] = CBOpcode_0xAC;
    CBOpcodes[0xAD] = CBOpcode_0xAD;
    CBOpcodes[0xAE] = CBOpcode_0xAE;
    CBOpcodes[0xAF] = CBOpcode_0xAF;
    CBOpcodes[0xB0] = CBOpcode_0xB0;
    CBOpcodes[0xB1] = CBOpcode_0xB1;
    CBOpcodes[0xB2] = CBOpcode_0xB2;
    CBOpcodes[0xB3] = CBOpcode_0xB3;
    CBOpcodes[0xB4] = CBOpcode_0xB4;
    CBOpcodes[0xB5] = CBOpcode_0xB5;
    CBOpcodes[0xB6] = CBOpcode_0xB6;
    CBOpcodes[0xB7] = CBOpcode_0xB7;
    CBOpcodes[0xB8] = CBOpcode_0xB8;
    CBOpcodes[0xB9] = CBOpcode_0xB9;
    CBOpcodes[0xBA] = CBOpcode_0xBA;
    CBOpcodes[0xBB] = CBOpcode_0xBB;
    CBOpcodes[0xBC] = CBOpcode_0xBC;
    CBOpcodes[0xBD] = CBOpcode_0xBD;
    CBOpcodes[0xBE] = CBOpcode_0xBE;
    CBOpcodes[0xBF] = CBOpcode_0xBF;
    CBOpcodes[0xC0] = CBOpcode_0xC0;
    CBOpcodes[0xC1] = CBOpcode_0xC1;
    CBOpcodes[0xC2] = CBOpcode_0xC2;
    CBOpcodes[0xC3] = CBOpcode_0xC3;
    CBOpcodes[0xC4] = CBOpcode_0xC4;
    CBOpcodes[0xC5] = CBOpcode_0xC5;
    CBOpcodes[0xC6] = CBOpcode_0xC6;
    CBOpcodes[0xC7] = CBOpcode_0xC7;
    CBOpcodes[0xC8] = CBOpcode_0xC8;
    CBOpcodes[0xC9] = CBOpcode_0xC9;
    CBOpcodes[0xCA] = CBOpcode_0xCA;
    CBOpcodes[0xCB] = CBOpcode_0xCB;
    CBOpcodes[0xCC] = CBOpcode_0xCC;
    CBOpcodes[0xCD] = CBOpcode_0xCD;
    CBOpcodes[0xCE] = CBOpcode_0xCE;
    CBOpcodes[0xCF] = CBOpcode_0xCF;
    CBOpcodes[0xD0] = CBOpcode_0xD0;
    CBOpcodes[0xD1] = CBOpcode_0xD1;
    CBOpcodes[0xD2] = CBOpcode_0xD2;
    CBOpcodes[0xD3] = CBOpcode_0xD3;
    CBOpcodes[0xD4] = CBOpcode_0xD4;
    CBOpcodes[0xD5] = CBOpcode_0xD5;
    CBOpcodes[0xD6] = CBOpcode_0xD6;
    CBOpcodes[0xD7] = CBOpcode_0xD7;
    CBOpcodes[0xD8] = CBOpcode_0xD8;
    CBOpcodes[0xD9] = CBOpcode_0xD9;
    CBOpcodes[0xDA] = CBOpcode_0xDA;
    CBOpcodes[0xDB] = CBOpcode_0xDB;
    CBOpcodes[0xDC] = CBOpcode_0xDC;
    CBOpcodes[0xDD] = CBOpcode_0xDD;
    CBOpcodes[0xDE] = CBOpcode_0xDE;
    CBOpcodes[0xDF] = CBOpcode_0xDF;
    CBOpcodes[0xE0] = CBOpcode_0xE0;
    CBOpcodes[0xE1] = CBOpcode_0xE1;
    CBOpcodes[0xE2] = CBOpcode_0xE2;
    CBOpcodes[0xE3] = CBOpcode_0xE3;
    CBOpcodes[0xE4] = CBOpcode_0xE4;
    CBOpcodes[0xE5] = CBOpcode_0xE5;
    CBOpcodes[0xE6] = CBOpcode_0xE6;
    CBOpcodes[0xE7] = CBOpcode_0xE7;
    CBOpcodes[0xE8] = CBOpcode_0xE8;
    CBOpcodes[0xE9] = CBOpcode_0xE9;
    CBOpcodes[0xEA] = CBOpcode_0xEA;
    CBOpcodes[0xEB] = CBOpcode_0xEB;
    CBOpcodes[0xEC] = CBOpcode_0xEC;
    CBOpcodes[0xED] = CBOpcode_0xED;
    CBOpcodes[0xEE] = CBOpcode_0xEE;
    CBOpcodes[0xEF] = CBOpcode_0xEF;
    CBOpcodes[0xF0] = CBOpcode_0xF0;
    CBOpcodes[0xF1] = CBOpcode_0xF1;
    CBOpcodes[0xF2] = CBOpcode_0xF2;
    CBOpcodes[0xF3] = CBOpcode_0xF3;
    CBOpcodes[0xF4] = CBOpcode_0xF4;
    CBOpcodes[0xF5] = CBOpcode_0xF5;
    CBOpcodes[0xF6] = CBOpcode_0xF6;
    CBOpcodes[0xF7] = CBOpcode_0xF7;
    CBOpcodes[0xF8] = CBOpcode_0xF8;
    CBOpcodes[0xF9] = CBOpcode_0xF9;
    CBOpcodes[0xFA] = CBOpcode_0xFA;
    CBOpcodes[0xFB] = CBOpcode_0xFB;
    CBOpcodes[0xFC] = CBOpcode_0xFC;
    CBOpcodes[0xFD] = CBOpcode_0xFD;
    CBOpcodes[0xFE] = CBOpcode_0xFE;
    CBOpcodes[0xFF] = CBOpcode_0xFF;
}

void CBOpcode_not_implemented(uint8_t opcode) {
    printf("ERROR: CB-Opcode not implemented (0x%02hhX)\n", opcode);
    exit(EXIT_FAILURE);
}

void CBOpcode_decode(uint8_t opcode) {
    (*CBOpcodes[opcode])();
}

void CBOpcode_0x00(void) {
	// RLC B
	Instruction_RLC_N_R(&Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x01(void) {
	// RLC C
	Instruction_RLC_N_R(&Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x02(void) {
	// RLC D
	Instruction_RLC_N_R(&Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x03(void) {
	// RLC E
	Instruction_RLC_N_R(&Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x04(void) {
	// RLC H
	Instruction_RLC_N_R(&Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x05(void) {
	// RLC L
	Instruction_RLC_N_R(&Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x06(void) {
	// RLC (HL)
	Instruction_RLC_N_M(Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x07(void) {
	// RLC A
	Instruction_RLC_N_R(&Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x08(void) {
	// RRC B
	Instruction_RRC_N_R(&Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x09(void) {
	// RRC C
	Instruction_RRC_N_R(&Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x0A(void) {
	// RRC D
	Instruction_RRC_N_R(&Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x0B(void) {
	// RRC E
	Instruction_RRC_N_R(&Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x0C(void) {
	// RRC H
	Instruction_RRC_N_R(&Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x0D(void) {
	// RRC L
	Instruction_RRC_N_R(&Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x0E(void) {
	// RRC (HL)
	Instruction_RRC_N_M(Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x0F(void) {
	// RRC A
	Instruction_RRC_N_R(&Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x10(void) {
	// RL B
	Instruction_RL_N_R(&Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x11(void) {
	// RL C
	Instruction_RL_N_R(&Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x12(void) {
	// RL D
	Instruction_RL_N_R(&Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x13(void) {
	// RL E
	Instruction_RL_N_R(&Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x14(void) {
	// RL H
	Instruction_RL_N_R(&Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x15(void) {
	// RL L
	Instruction_RL_N_R(&Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x16(void) {
	// RL (HL)
	Instruction_RL_N_M(Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x17(void) {
	// RL A
	Instruction_RL_N_R(&Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x18(void) {
	// RR B
	Instruction_RR_N_R(&Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x19(void) {
	// RR C
	Instruction_RR_N_R(&Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x1A(void) {
	// RR D
	Instruction_RR_N_R(&Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x1B(void) {
	// RR E
	Instruction_RR_N_R(&Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x1C(void) {
	// RR H
	Instruction_RR_N_R(&Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x1D(void) {
	// RR L
	Instruction_RR_N_R(&Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x1E(void) {
	// RR (HL)
	Instruction_RR_N_M(Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x1F(void) {
	// RR A
	Instruction_RR_N_R(&Registers.A);
	Timer.t += 8;
}


void CBOpcode_0x20(void) {
	// SLA B
	Instruction_SLA_N_R(&Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x21(void) {
	// SLA C
	Instruction_SLA_N_R(&Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x22(void) {
	// SLA D
	Instruction_SLA_N_R(&Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x23(void) {
	// SLA E
	Instruction_SLA_N_R(&Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x24(void) {
	// SLA H
	Instruction_SLA_N_R(&Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x25(void) {
	// SLA L
	Instruction_SLA_N_R(&Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x26(void) {
	// SLA (HL)
	Instruction_SLA_N_M(Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x27(void) {
	// SLA A
	Instruction_SLA_N_R(&Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x28(void) {
	// SRA B
	Instruction_SRA_N_R(&Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x29(void) {
	// SRA C
	Instruction_SRA_N_R(&Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x2A(void) {
	// SRA D
	Instruction_SRA_N_R(&Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x2B(void) {
	// SRA E
	Instruction_SRA_N_R(&Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x2C(void) {
	// SRA H
	Instruction_SRA_N_R(&Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x2D(void) {
	// SRA L
	Instruction_SRA_N_R(&Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x2E(void) {
	// SRA (HL)
	Instruction_SRA_N_M(Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x2F(void) {
	// SRA A
	Instruction_SRA_N_R(&Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x30(void) {
	// SWAP B
	Instruction_SWAP_N_R(&Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x31(void) {
	// SWAP C
	Instruction_SWAP_N_R(&Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x32(void) {
	// SWAP D
	Instruction_SWAP_N_R(&Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x33(void) {
	// SWAP E
	Instruction_SWAP_N_R(&Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x34(void) {
	// SWAP H
	Instruction_SWAP_N_R(&Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x35(void) {
	// SWAP L
	Instruction_SWAP_N_R(&Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x36(void) {
	// SWAP (HL)
	Instruction_SWAP_N_M(Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x37(void) {
	// SWAP A
	Instruction_SWAP_N_R(&Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x38(void) {
	// SRL B
	Instruction_SRL_N_R(&Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x39(void) {
	// SRL C
	Instruction_SRL_N_R(&Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x3A(void) {
	// SRL D
	Instruction_SRL_N_R(&Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x3B(void) {
	// SRL E
	Instruction_SRL_N_R(&Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x3C(void) {
	// SRL H
	Instruction_SRL_N_R(&Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x3D(void) {
	// SRL L
	Instruction_SRL_N_R(&Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x3E(void) {
	// SRL (HL)
	Instruction_SRL_N_M(Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x3F(void) {
	// SRL A
	Instruction_SRL_N_R(&Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x40(void) {
	// BIT 0, B
	Instruction_BIT_N_R(0, Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x41(void) {
	// BIT 0, C
	Instruction_BIT_N_R(0, Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x42(void) {
	// BIT 0, D
	Instruction_BIT_N_R(0, Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x43(void) {
	// BIT 0, E
	Instruction_BIT_N_R(0, Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x44(void) {
	// BIT 0, H
	Instruction_BIT_N_R(0, Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x45(void) {
	// BIT 0, L
	Instruction_BIT_N_R(0, Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x46(void) {
	// BIT 0, (HL)
	Instruction_BIT_N_M(0, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x47(void) {
	// BIT 0, A
	Instruction_BIT_N_R(0, Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x48(void) {
	// BIT 1, B
	Instruction_BIT_N_R(1, Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x49(void) {
	// BIT 1, C
	Instruction_BIT_N_R(1, Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x4A(void) {
	// BIT 1, D
	Instruction_BIT_N_R(1, Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x4B(void) {
	// BIT 1, E
	Instruction_BIT_N_R(1, Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x4C(void) {
	// BIT 1, H
	Instruction_BIT_N_R(1, Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x4D(void) {
	// BIT 1, L
	Instruction_BIT_N_R(1, Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x4E(void) {
	// BIT 1, (HL)
	Instruction_BIT_N_M(1, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x4F(void) {
	// BIT 1, A
	Instruction_BIT_N_R(1, Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x50(void) {
	// BIT 2, B
	Instruction_BIT_N_R(2, Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x51(void) {
	// BIT 2, C
	Instruction_BIT_N_R(2, Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x52(void) {
	// BIT 2, D
	Instruction_BIT_N_R(2, Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x53(void) {
	// BIT 2, E
	Instruction_BIT_N_R(2, Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x54(void) {
	// BIT 2, H
	Instruction_BIT_N_R(2, Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x55(void) {
	// BIT 2, L
	Instruction_BIT_N_R(2, Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x56(void) {
	// BIT 2, (HL)
	Instruction_BIT_N_M(2, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x57(void) {
	// BIT 2, A
	Instruction_BIT_N_R(2, Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x58(void) {
	// BIT 3, B
	Instruction_BIT_N_R(3, Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x59(void) {
	// BIT 3, C
	Instruction_BIT_N_R(3, Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x5A(void) {
	// BIT 3, D
	Instruction_BIT_N_R(3, Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x5B(void) {
	// BIT 3, E
	Instruction_BIT_N_R(3, Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x5C(void) {
	// BIT 3, H
	Instruction_BIT_N_R(3, Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x5D(void) {
	// BIT 3, L
	Instruction_BIT_N_R(3, Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x5E(void) {
	// BIT 3, (HL)
	Instruction_BIT_N_M(3, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x5F(void) {
	// BIT 3, A
	Instruction_BIT_N_R(3, Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x60(void) {
	// BIT 4, B
	Instruction_BIT_N_R(4, Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x61(void) {
	// BIT 4, C
	Instruction_BIT_N_R(4, Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x62(void) {
	// BIT 4, D
	Instruction_BIT_N_R(4, Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x63(void) {
	// BIT 4, E
	Instruction_BIT_N_R(4, Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x64(void) {
	// BIT 4, H
	Instruction_BIT_N_R(4, Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x65(void) {
	// BIT 4, L
	Instruction_BIT_N_R(4, Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x66(void) {
	// BIT 4, (HL)
	Instruction_BIT_N_M(4, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x67(void) {
	// BIT 4, A
	Instruction_BIT_N_R(4, Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x68(void) {
	// BIT 5, B
	Instruction_BIT_N_R(5, Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x69(void) {
	// BIT 5, C
	Instruction_BIT_N_R(5, Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x6A(void) {
	// BIT 5, D
	Instruction_BIT_N_R(5, Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x6B(void) {
	// BIT 5, E
	Instruction_BIT_N_R(5, Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x6C(void) {
	// BIT 5, H
	Instruction_BIT_N_R(5, Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x6D(void) {
	// BIT 5, L
	Instruction_BIT_N_R(5, Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x6E(void) {
	// BIT 5, (HL)
	Instruction_BIT_N_M(5, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x6F(void) {
	// BIT 5, A
	Instruction_BIT_N_R(5, Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x70(void) {
	// BIT 6, B
	Instruction_BIT_N_R(6, Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x71(void) {
	// BIT 6, C
	Instruction_BIT_N_R(6, Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x72(void) {
	// BIT 6, D
	Instruction_BIT_N_R(6, Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x73(void) {
	// BIT 6, E
	Instruction_BIT_N_R(6, Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x74(void) {
	// BIT 6, H
	Instruction_BIT_N_R(6, Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x75(void) {
	// BIT 6, L
	Instruction_BIT_N_R(6, Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x76(void) {
	// BIT 6, (HL)
	Instruction_BIT_N_M(6, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x77(void) {
	// BIT 6, A
	Instruction_BIT_N_R(6, Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x78(void) {
	// BIT 7, B
	Instruction_BIT_N_R(7, Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x79(void) {
	// BIT 7, C
	Instruction_BIT_N_R(7, Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x7A(void) {
	// BIT 7, D
	Instruction_BIT_N_R(7, Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x7B(void) {
	// BIT 7, E
	Instruction_BIT_N_R(7, Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x7C(void) {
	// BIT 7, H
	Instruction_BIT_N_R(7, Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x7D(void) {
	// BIT 7, L
	Instruction_BIT_N_R(7, Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x7E(void) {
	// BIT 7, (HL)
	Instruction_BIT_N_M(7, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x7F(void) {
	// BIT 7, A
	Instruction_BIT_N_R(7, Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x80(void) {
	// RES 0, B
	Instruction_RES_N_R(0, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x81(void) {
	// RES 0, C
	Instruction_RES_N_R(0, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x82(void) {
	// RES 0, D
	Instruction_RES_N_R(0, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x83(void) {
	// RES 0, E
	Instruction_RES_N_R(0, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x84(void) {
	// RES 0, H
	Instruction_RES_N_R(0, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x85(void) {
	// RES 0, L
	Instruction_RES_N_R(0, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x86(void) {
	// RES 0, (HL)
	Instruction_RES_N_M(0, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x87(void) {
	// RES 0, A
	Instruction_RES_N_R(0, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x88(void) {
	// RES 1, B
	Instruction_RES_N_R(1, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x89(void) {
	// RES 1, C
	Instruction_RES_N_R(1, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x8A(void) {
	// RES 1, D
	Instruction_RES_N_R(1, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x8B(void) {
	// RES 1, E
	Instruction_RES_N_R(1, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x8C(void) {
	// RES 1, H
	Instruction_RES_N_R(1, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x8D(void) {
	// RES 1, L
	Instruction_RES_N_R(1, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x8E(void) {
	// RES 1, (HL)
	Instruction_RES_N_M(1, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x8F(void) {
	// RES 1, A
	Instruction_RES_N_R(1, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x90(void) {
	// RES 2, B
	Instruction_RES_N_R(2, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x91(void) {
	// RES 2, C
	Instruction_RES_N_R(2, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x92(void) {
	// RES 2, D
	Instruction_RES_N_R(2, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x93(void) {
	// RES 2, E
	Instruction_RES_N_R(2, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x94(void) {
	// RES 2, H
	Instruction_RES_N_R(2, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x95(void) {
	// RES 2, L
	Instruction_RES_N_R(2, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x96(void) {
	// RES 2, (HL)
	Instruction_RES_N_M(2, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x97(void) {
	// RES 2, A
	Instruction_RES_N_R(2, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0x98(void) {
	// RES 3, B
	Instruction_RES_N_R(3, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0x99(void) {
	// RES 3, C
	Instruction_RES_N_R(3, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0x9A(void) {
	// RES 3, D
	Instruction_RES_N_R(3, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0x9B(void) {
	// RES 3, E
	Instruction_RES_N_R(3, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0x9C(void) {
	// RES 3, H
	Instruction_RES_N_R(3, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0x9D(void) {
	// RES 3, L
	Instruction_RES_N_R(3, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0x9E(void) {
	// RES 3, (HL)
	Instruction_RES_N_M(3, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0x9F(void) {
	// RES 3, A
	Instruction_RES_N_R(3, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xA0(void) {
	// RES 4, B
	Instruction_RES_N_R(4, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xA1(void) {
	// RES 4, C
	Instruction_RES_N_R(4, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xA2(void) {
	// RES 4, D
	Instruction_RES_N_R(4, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xA3(void) {
	// RES 4, E
	Instruction_RES_N_R(4, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xA4(void) {
	// RES 4, H
	Instruction_RES_N_R(4, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xA5(void) {
	// RES 4, L
	Instruction_RES_N_R(4, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xA6(void) {
	// RES 4, (HL)
	Instruction_RES_N_M(4, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xA7(void) {
	// RES 4, A
	Instruction_RES_N_R(4, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xA8(void) {
	// RES 5, B
	Instruction_RES_N_R(5, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xA9(void) {
	// RES 5, C
	Instruction_RES_N_R(5, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xAA(void) {
	// RES 5, D
	Instruction_RES_N_R(5, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xAB(void) {
	// RES 5, E
	Instruction_RES_N_R(5, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xAC(void) {
	// RES 5, H
	Instruction_RES_N_R(5, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xAD(void) {
	// RES 5, L
	Instruction_RES_N_R(5, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xAE(void) {
	// RES 5, (HL)
	Instruction_RES_N_M(5, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xAF(void) {
	// RES 5, A
	Instruction_RES_N_R(5, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xB0(void) {
	// RES 6, B
	Instruction_RES_N_R(6, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xB1(void) {
	// RES 6, C
	Instruction_RES_N_R(6, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xB2(void) {
	// RES 6, D
	Instruction_RES_N_R(6, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xB3(void) {
	// RES 6, E
	Instruction_RES_N_R(6, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xB4(void) {
	// RES 6, H
	Instruction_RES_N_R(6, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xB5(void) {
	// RES 6, L
	Instruction_RES_N_R(6, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xB6(void) {
	// RES 6, (HL)
	Instruction_RES_N_M(6, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xB7(void) {
	// RES 6, A
	Instruction_RES_N_R(6, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xB8(void) {
	// RES 7, B
	Instruction_RES_N_R(7, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xB9(void) {
	// RES 7, C
	Instruction_RES_N_R(7, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xBA(void) {
	// RES 7, D
	Instruction_RES_N_R(7, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xBB(void) {
	// RES 7, E
	Instruction_RES_N_R(7, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xBC(void) {
	// RES 7, H
	Instruction_RES_N_R(7, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xBD(void) {
	// RES 7, L
	Instruction_RES_N_R(7, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xBE(void) {
	// RES 7, (HL)
	Instruction_RES_N_M(7, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xBF(void) {
	// RES 7, A
	Instruction_RES_N_R(7, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xC0(void) {
	// SET 0, B
	Instruction_SET_N_R(0, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xC1(void) {
	// SET 0, C
	Instruction_SET_N_R(0, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xC2(void) {
	// SET 0, D
	Instruction_SET_N_R(0, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xC3(void) {
	// SET 0, E
	Instruction_SET_N_R(0, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xC4(void) {
	// SET 0, H
	Instruction_SET_N_R(0, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xC5(void) {
	// SET 0, L
	Instruction_SET_N_R(0, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xC6(void) {
	// SET 0, (HL)
	Instruction_SET_N_M(0, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xC7(void) {
	// SET 0, A
	Instruction_SET_N_R(0, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xC8(void) {
	// SET 1, B
	Instruction_SET_N_R(1, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xC9(void) {
	// SET 1, C
	Instruction_SET_N_R(1, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xCA(void) {
	// SET 1, D
	Instruction_SET_N_R(1, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xCB(void) {
	// SET 1, E
	Instruction_SET_N_R(1, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xCC(void) {
	// SET 1, H
	Instruction_SET_N_R(1, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xCD(void) {
	// SET 1, L
	Instruction_SET_N_R(1, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xCE(void) {
	// SET 1, (HL)
	Instruction_SET_N_M(1, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xCF(void) {
	// SET 1, A
	Instruction_SET_N_R(1, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xD0(void) {
	// SET 2, B
	Instruction_SET_N_R(2, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xD1(void) {
	// SET 2, C
	Instruction_SET_N_R(2, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xD2(void) {
	// SET 2, D
	Instruction_SET_N_R(2, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xD3(void) {
	// SET 2, E
	Instruction_SET_N_R(2, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xD4(void) {
	// SET 2, H
	Instruction_SET_N_R(2, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xD5(void) {
	// SET 2, L
	Instruction_SET_N_R(2, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xD6(void) {
	// SET 2, (HL)
	Instruction_SET_N_M(2, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xD7(void) {
	// SET 2, A
	Instruction_SET_N_R(2, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xD8(void) {
	// SET 3, B
	Instruction_SET_N_R(3, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xD9(void) {
	// SET 3, C
	Instruction_SET_N_R(3, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xDA(void) {
	// SET 3, D
	Instruction_SET_N_R(3, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xDB(void) {
	// SET 3, E
	Instruction_SET_N_R(3, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xDC(void) {
	// SET 3, H
	Instruction_SET_N_R(3, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xDD(void) {
	// SET 3, L
	Instruction_SET_N_R(3, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xDE(void) {
	// SET 3, (HL)
	Instruction_SET_N_M(3, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xDF(void) {
	// SET 3, A
	Instruction_SET_N_R(3, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xE0(void) {
	// SET 4, B
	Instruction_SET_N_R(4, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xE1(void) {
	// SET 4, C
	Instruction_SET_N_R(4, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xE2(void) {
	// SET 4, D
	Instruction_SET_N_R(4, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xE3(void) {
	// SET 4, E
	Instruction_SET_N_R(4, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xE4(void) {
	// SET 4, H
	Instruction_SET_N_R(4, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xE5(void) {
	// SET 4, L
	Instruction_SET_N_R(4, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xE6(void) {
	// SET 4, (HL)
	Instruction_SET_N_M(4, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xE7(void) {
	// SET 4, A
	Instruction_SET_N_R(4, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xE8(void) {
	// SET 5, B
	Instruction_SET_N_R(5, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xE9(void) {
	// SET 5, C
	Instruction_SET_N_R(5, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xEA(void) {
	// SET 5, D
	Instruction_SET_N_R(5, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xEB(void) {
	// SET 5, E
	Instruction_SET_N_R(5, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xEC(void) {
	// SET 5, H
	Instruction_SET_N_R(5, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xED(void) {
	// SET 5, L
	Instruction_SET_N_R(5, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xEE(void) {
	// SET 5, (HL)
	Instruction_SET_N_M(5, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xEF(void) {
	// SET 5, A
	Instruction_SET_N_R(5, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xF0(void) {
	// SET 6, B
	Instruction_SET_N_R(6, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xF1(void) {
	// SET 6, C
	Instruction_SET_N_R(6, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xF2(void) {
	// SET 6, D
	Instruction_SET_N_R(6, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xF3(void) {
	// SET 6, E
	Instruction_SET_N_R(6, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xF4(void) {
	// SET 6, H
	Instruction_SET_N_R(6, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xF5(void) {
	// SET 6, L
	Instruction_SET_N_R(6, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xF6(void) {
	// SET 6, (HL)
	Instruction_SET_N_M(6, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xF7(void) {
	// SET 6, A
	Instruction_SET_N_R(6, &Registers.A);
	Timer.t += 8;
}

void CBOpcode_0xF8(void) {
	// SET 7, B
	Instruction_SET_N_R(7, &Registers.B);
	Timer.t += 8;
}

void CBOpcode_0xF9(void) {
	// SET 7, C
	Instruction_SET_N_R(7, &Registers.C);
	Timer.t += 8;
}

void CBOpcode_0xFA(void) {
	// SET 7, D
	Instruction_SET_N_R(7, &Registers.D);
	Timer.t += 8;
}

void CBOpcode_0xFB(void) {
	// SET 7, E
	Instruction_SET_N_R(7, &Registers.E);
	Timer.t += 8;
}

void CBOpcode_0xFC(void) {
	// SET 7, H
	Instruction_SET_N_R(7, &Registers.H);
	Timer.t += 8;
}

void CBOpcode_0xFD(void) {
	// SET 7, L
	Instruction_SET_N_R(7, &Registers.L);
	Timer.t += 8;
}

void CBOpcode_0xFE(void) {
	// SET 7, (HL)
	Instruction_SET_N_M(7, Registers.HL);
	Timer.t += 16;
}

void CBOpcode_0xFF(void) {
	// SET 7, A
	Instruction_SET_N_R(7, &Registers.A);
	Timer.t += 8;
}
