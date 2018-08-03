#include "opcodes.h"

// Filling the opcode table
// ---------------------------------------------------
void Opcodes_init(void) {
    Opcodes[0x00] = Opcode_0x00;
    Opcodes[0x01] = Opcode_0x01;
    Opcodes[0x02] = Opcode_0x02;
    Opcodes[0x03] = Opcode_0x03;
    Opcodes[0x04] = Opcode_0x04;
    Opcodes[0x05] = Opcode_0x05;
    Opcodes[0x06] = Opcode_0x06;
    Opcodes[0x07] = Opcode_0x07;
    Opcodes[0x08] = Opcode_0x08;
    Opcodes[0x09] = Opcode_0x09;
    Opcodes[0x0A] = Opcode_0x0A;
    Opcodes[0x0B] = Opcode_0x0B;
    Opcodes[0x0C] = Opcode_0x0C;
    Opcodes[0x0D] = Opcode_0x0D;
    Opcodes[0x0E] = Opcode_0x0E;
    Opcodes[0x0F] = Opcode_0x0F;
    Opcodes[0x10] = Opcode_0x10;
    Opcodes[0x11] = Opcode_0x11;
    Opcodes[0x12] = Opcode_0x12;
    Opcodes[0x13] = Opcode_0x13;
    Opcodes[0x14] = Opcode_0x14;
    Opcodes[0x15] = Opcode_0x15;
    Opcodes[0x16] = Opcode_0x16;
    Opcodes[0x17] = Opcode_0x17;
    Opcodes[0x18] = Opcode_0x18;
    Opcodes[0x19] = Opcode_0x19;
    Opcodes[0x1A] = Opcode_0x1A;
    Opcodes[0x1B] = Opcode_0x1B;
    Opcodes[0x1C] = Opcode_0x1C;
    Opcodes[0x1D] = Opcode_0x1D;
    Opcodes[0x1E] = Opcode_0x1E;
    Opcodes[0x1F] = Opcode_0x1F;
    Opcodes[0x20] = Opcode_0x20;
    Opcodes[0x21] = Opcode_0x21;
    Opcodes[0x22] = Opcode_0x22;
    Opcodes[0x23] = Opcode_0x23;
    Opcodes[0x24] = Opcode_0x24;
    Opcodes[0x25] = Opcode_0x25;
    Opcodes[0x26] = Opcode_0x26;
    Opcodes[0x27] = Opcode_0x27;
    Opcodes[0x28] = Opcode_0x28;
    Opcodes[0x29] = Opcode_0x29;
    Opcodes[0x2A] = Opcode_0x2A;
    Opcodes[0x2B] = Opcode_0x2B;
    Opcodes[0x2C] = Opcode_0x2C;
    Opcodes[0x2D] = Opcode_0x2D;
    Opcodes[0x2E] = Opcode_0x2E;
    Opcodes[0x2F] = Opcode_0x2F;
    Opcodes[0x30] = Opcode_0x30;
    Opcodes[0x31] = Opcode_0x31;
    Opcodes[0x32] = Opcode_0x32;
    Opcodes[0x33] = Opcode_0x33;
    Opcodes[0x34] = Opcode_0x34;
    Opcodes[0x35] = Opcode_0x35;
    Opcodes[0x36] = Opcode_0x36;
    Opcodes[0x37] = Opcode_0x37;
    Opcodes[0x38] = Opcode_0x38;
    Opcodes[0x39] = Opcode_0x39;
    Opcodes[0x3A] = Opcode_0x3A;
    Opcodes[0x3B] = Opcode_0x3B;
    Opcodes[0x3C] = Opcode_0x3C;
    Opcodes[0x3D] = Opcode_0x3D;
    Opcodes[0x3E] = Opcode_0x3E;
    Opcodes[0x3F] = Opcode_0x3F;
    Opcodes[0x40] = Opcode_0x40;
    Opcodes[0x41] = Opcode_0x41;
    Opcodes[0x42] = Opcode_0x42;
    Opcodes[0x43] = Opcode_0x43;
    Opcodes[0x44] = Opcode_0x44;
    Opcodes[0x45] = Opcode_0x45;
    Opcodes[0x46] = Opcode_0x46;
    Opcodes[0x47] = Opcode_0x47;
    Opcodes[0x48] = Opcode_0x48;
    Opcodes[0x49] = Opcode_0x49;
    Opcodes[0x4A] = Opcode_0x4A;
    Opcodes[0x4B] = Opcode_0x4B;
    Opcodes[0x4C] = Opcode_0x4C;
    Opcodes[0x4D] = Opcode_0x4D;
    Opcodes[0x4E] = Opcode_0x4E;
    Opcodes[0x4F] = Opcode_0x4F;
    Opcodes[0x50] = Opcode_0x50;
    Opcodes[0x51] = Opcode_0x51;
    Opcodes[0x52] = Opcode_0x52;
    Opcodes[0x53] = Opcode_0x53;
    Opcodes[0x54] = Opcode_0x54;
    Opcodes[0x55] = Opcode_0x55;
    Opcodes[0x56] = Opcode_0x56;
    Opcodes[0x57] = Opcode_0x57;
    Opcodes[0x58] = Opcode_0x58;
    Opcodes[0x59] = Opcode_0x59;
    Opcodes[0x5A] = Opcode_0x5A;
    Opcodes[0x5B] = Opcode_0x5B;
    Opcodes[0x5C] = Opcode_0x5C;
    Opcodes[0x5D] = Opcode_0x5D;
    Opcodes[0x5E] = Opcode_0x5E;
    Opcodes[0x5F] = Opcode_0x5F;
    Opcodes[0x60] = Opcode_0x60;
    Opcodes[0x61] = Opcode_0x61;
    Opcodes[0x62] = Opcode_0x62;
    Opcodes[0x63] = Opcode_0x63;
    Opcodes[0x64] = Opcode_0x64;
    Opcodes[0x65] = Opcode_0x65;
    Opcodes[0x66] = Opcode_0x66;
    Opcodes[0x67] = Opcode_0x67;
    Opcodes[0x68] = Opcode_0x68;
    Opcodes[0x69] = Opcode_0x69;
    Opcodes[0x6A] = Opcode_0x6A;
    Opcodes[0x6B] = Opcode_0x6B;
    Opcodes[0x6C] = Opcode_0x6C;
    Opcodes[0x6D] = Opcode_0x6D;
    Opcodes[0x6E] = Opcode_0x6E;
    Opcodes[0x6F] = Opcode_0x6F;
    Opcodes[0x70] = Opcode_0x70;
    Opcodes[0x71] = Opcode_0x71;
    Opcodes[0x72] = Opcode_0x72;
    Opcodes[0x73] = Opcode_0x73;
    Opcodes[0x74] = Opcode_0x74;
    Opcodes[0x75] = Opcode_0x75;
    Opcodes[0x76] = Opcode_0x76;
    Opcodes[0x77] = Opcode_0x77;
    Opcodes[0x78] = Opcode_0x78;
    Opcodes[0x79] = Opcode_0x79;
    Opcodes[0x7A] = Opcode_0x7A;
    Opcodes[0x7B] = Opcode_0x7B;
    Opcodes[0x7C] = Opcode_0x7C;
    Opcodes[0x7D] = Opcode_0x7D;
    Opcodes[0x7E] = Opcode_0x7E;
    Opcodes[0x7F] = Opcode_0x7F;
    Opcodes[0x80] = Opcode_0x80;
    Opcodes[0x81] = Opcode_0x81;
    Opcodes[0x82] = Opcode_0x82;
    Opcodes[0x83] = Opcode_0x83;
    Opcodes[0x84] = Opcode_0x84;
    Opcodes[0x85] = Opcode_0x85;
    Opcodes[0x86] = Opcode_0x86;
    Opcodes[0x87] = Opcode_0x87;
    Opcodes[0x88] = Opcode_0x88;
    Opcodes[0x89] = Opcode_0x89;
    Opcodes[0x8A] = Opcode_0x8A;
    Opcodes[0x8B] = Opcode_0x8B;
    Opcodes[0x8C] = Opcode_0x8C;
    Opcodes[0x8D] = Opcode_0x8D;
    Opcodes[0x8E] = Opcode_0x8E;
    Opcodes[0x8F] = Opcode_0x8F;
    Opcodes[0x90] = Opcode_0x90;
    Opcodes[0x91] = Opcode_0x91;
    Opcodes[0x92] = Opcode_0x92;
    Opcodes[0x93] = Opcode_0x93;
    Opcodes[0x94] = Opcode_0x94;
    Opcodes[0x95] = Opcode_0x95;
    Opcodes[0x96] = Opcode_0x96;
    Opcodes[0x97] = Opcode_0x97;
    Opcodes[0x98] = Opcode_0x98;
    Opcodes[0x99] = Opcode_0x99;
    Opcodes[0x9A] = Opcode_0x9A;
    Opcodes[0x9B] = Opcode_0x9B;
    Opcodes[0x9C] = Opcode_0x9C;
    Opcodes[0x9D] = Opcode_0x9D;
    Opcodes[0x9E] = Opcode_0x9E;
    Opcodes[0x9F] = Opcode_0x9F;
    Opcodes[0xA0] = Opcode_0xA0;
    Opcodes[0xA1] = Opcode_0xA1;
    Opcodes[0xA2] = Opcode_0xA2;
    Opcodes[0xA3] = Opcode_0xA3;
    Opcodes[0xA4] = Opcode_0xA4;
    Opcodes[0xA5] = Opcode_0xA5;
    Opcodes[0xA6] = Opcode_0xA6;
    Opcodes[0xA7] = Opcode_0xA7;
    Opcodes[0xA8] = Opcode_0xA8;
    Opcodes[0xA9] = Opcode_0xA9;
    Opcodes[0xAA] = Opcode_0xAA;
    Opcodes[0xAB] = Opcode_0xAB;
    Opcodes[0xAC] = Opcode_0xAC;
    Opcodes[0xAD] = Opcode_0xAD;
    Opcodes[0xAE] = Opcode_0xAE;
    Opcodes[0xAF] = Opcode_0xAF;
    Opcodes[0xB0] = Opcode_0xB0;
    Opcodes[0xB1] = Opcode_0xB1;
    Opcodes[0xB2] = Opcode_0xB2;
    Opcodes[0xB3] = Opcode_0xB3;
    Opcodes[0xB4] = Opcode_0xB4;
    Opcodes[0xB5] = Opcode_0xB5;
    Opcodes[0xB6] = Opcode_0xB6;
    Opcodes[0xB7] = Opcode_0xB7;
    Opcodes[0xB8] = Opcode_0xB8;
    Opcodes[0xB9] = Opcode_0xB9;
    Opcodes[0xBA] = Opcode_0xBA;
    Opcodes[0xBB] = Opcode_0xBB;
    Opcodes[0xBC] = Opcode_0xBC;
    Opcodes[0xBD] = Opcode_0xBD;
    Opcodes[0xBE] = Opcode_0xBE;
    Opcodes[0xBF] = Opcode_0xBF;
    Opcodes[0xC0] = Opcode_0xC0;
    Opcodes[0xC1] = Opcode_0xC1;
    Opcodes[0xC2] = Opcode_0xC2;
    Opcodes[0xC3] = Opcode_0xC3;
    Opcodes[0xC4] = Opcode_0xC4;
    Opcodes[0xC5] = Opcode_0xC5;
    Opcodes[0xC6] = Opcode_0xC6;
    Opcodes[0xC7] = Opcode_0xC7;
    Opcodes[0xC8] = Opcode_0xC8;
    Opcodes[0xC9] = Opcode_0xC9;
    Opcodes[0xCA] = Opcode_0xCA;
    Opcodes[0xCB] = Opcode_0xCB;
    Opcodes[0xCC] = Opcode_0xCC;
    Opcodes[0xCD] = Opcode_0xCD;
    Opcodes[0xCE] = Opcode_0xCE;
    Opcodes[0xCF] = Opcode_0xCF;
    Opcodes[0xD0] = Opcode_0xD0;
    Opcodes[0xD1] = Opcode_0xD1;
    Opcodes[0xD2] = Opcode_0xD2;
    Opcodes[0xD3] = Opcode_0xD3;
    Opcodes[0xD4] = Opcode_0xD4;
    Opcodes[0xD5] = Opcode_0xD5;
    Opcodes[0xD6] = Opcode_0xD6;
    Opcodes[0xD7] = Opcode_0xD7;
    Opcodes[0xD8] = Opcode_0xD8;
    Opcodes[0xD9] = Opcode_0xD9;
    Opcodes[0xDA] = Opcode_0xDA;
    Opcodes[0xDB] = Opcode_0xDB;
    Opcodes[0xDC] = Opcode_0xDC;
    Opcodes[0xDD] = Opcode_0xDD;
    Opcodes[0xDE] = Opcode_0xDE;
    Opcodes[0xDF] = Opcode_0xDF;
    Opcodes[0xE0] = Opcode_0xE0;
    Opcodes[0xE1] = Opcode_0xE1;
    Opcodes[0xE2] = Opcode_0xE2;
    Opcodes[0xE3] = Opcode_0xE3;
    Opcodes[0xE4] = Opcode_0xE4;
    Opcodes[0xE5] = Opcode_0xE5;
    Opcodes[0xE6] = Opcode_0xE6;
    Opcodes[0xE7] = Opcode_0xE7;
    Opcodes[0xE8] = Opcode_0xE8;
    Opcodes[0xE9] = Opcode_0xE9;
    Opcodes[0xEA] = Opcode_0xEA;
    Opcodes[0xEB] = Opcode_0xEB;
    Opcodes[0xEC] = Opcode_0xEC;
    Opcodes[0xED] = Opcode_0xED;
    Opcodes[0xEE] = Opcode_0xEE;
    Opcodes[0xEF] = Opcode_0xEF;
    Opcodes[0xF0] = Opcode_0xF0;
    Opcodes[0xF1] = Opcode_0xF1;
    Opcodes[0xF2] = Opcode_0xF2;
    Opcodes[0xF3] = Opcode_0xF3;
    Opcodes[0xF4] = Opcode_0xF4;
    Opcodes[0xF5] = Opcode_0xF5;
    Opcodes[0xF6] = Opcode_0xF6;
    Opcodes[0xF7] = Opcode_0xF7;
    Opcodes[0xF8] = Opcode_0xF8;
    Opcodes[0xF9] = Opcode_0xF9;
    Opcodes[0xFA] = Opcode_0xFA;
    Opcodes[0xFB] = Opcode_0xFB;
    Opcodes[0xFC] = Opcode_0xFC;
    Opcodes[0xFD] = Opcode_0xFD;
    Opcodes[0xFE] = Opcode_0xFE;
    Opcodes[0xFF] = Opcode_0xFF;
}

// Opcode Fetching & Decoding
// ---------------------------------------------------
uint8_t Opcode_fetch(void) {
	return Memory_load_byte_PC();
}

void Opcode_decode(uint8_t opcode) {
	(*Opcodes[opcode])();
}

void Opcode_not_implemented(uint8_t opcode) {
    printf("ERROR: Opcode not implemented (0x%02hhX)\n", opcode);
    exit(EXIT_FAILURE);
}

void Opcode_empty(uint8_t opcode) {
	printf("ERROR: Tried to use a non-existent opcode (0x%02hhX)\n", opcode);
    exit(EXIT_FAILURE);
}

void Opcode_0x00(void) {
	// NOP
	Timer.t += 4;
}

void Opcode_0x01(void) {
	// LD BC, nn
	Registers.BC = Memory_load_word_PC();
	Timer.t += 12;
}

void Opcode_0x02(void) {
	// LD (BC), A
	Memory_store_byte(Registers.BC, Registers.A);
	Timer.t += 8;
}

void Opcode_0x03(void) {
	// INC BC
	Registers.BC++;
	Timer.t += 8;
}

void Opcode_0x04(void) {
	// INC B
	Instruction_INC_N(&Registers.B);
	Timer.t += 4;
}

void Opcode_0x05(void) {
	// DEC B
	Instruction_DEC_N(&Registers.B);
	Timer.t -= 4;
}

void Opcode_0x06(void) {
	// LD B, n
	Registers.B = Memory_load_byte_PC();
	Timer.t += 8;
}

void Opcode_0x07(void) {
	// RLCA
	uint8_t bit7 = (Registers.A & 0x40) >> 7;

	Registers.A <<= 1;
	Registers.A |= bit7;

	Flags_set(
		0,
		0,
		0,
		bit7
	);

	Timer.t += 4;
}

void Opcode_0x08(void) {
	// LD (nn), SP
	uint16_t nn = Memory_load_word_PC();

	Memory_store_byte(nn, Extract_LSB(Registers.SP));
	Memory_store_byte((nn + 1), Extract_MSB(Registers.SP));

	Timer.t += 20;
}

void Opcode_0x09(void) {
	// ADD HL, BC
	Instruction_ADD_HL_N(Registers.BC);
	Timer.t += 8;
}

void Opcode_0x0A(void) {
	// LD A, (BC)
	Registers.A = Memory_load_byte(Registers.BC);
	Timer.t += 8;
}

void Opcode_0x0B(void) {
	// DEC BC
	Registers.BC--;
	Timer.t += 8;
}

void Opcode_0x0C(void) {
	// INC C
	Instruction_INC_N(&Registers.C);
	Timer.t += 4;
}

void Opcode_0x0D(void) {
	// DEC C
	Instruction_DEC_N(&Registers.C);
	Timer.t -= 4;
}

void Opcode_0x0E(void) {
	// LD C, n
	Registers.C = Memory_load_byte_PC();
	Timer.t += 8;
}

void Opcode_0x0F(void) {
	// RRCA
	uint8_t bit0 = Registers.A & 0x01;

	Registers.A = (Registers.A >> 1) | (bit0 << 7);

	Flags_set(
		0,
		0,
		0,
		bit0
	);

	Timer.t += 4;
}

void Opcode_0x10(void) {
	// STOP
	// TODO: Add STOP system
	Opcode_not_implemented(0x10);
}

void Opcode_0x11(void) {
	// LD DE, nn
	Registers.DE = Memory_load_word_PC();
	Timer.t += 12;
}

void Opcode_0x12(void) {
	// LD (DE), A
	Memory_store_byte(Registers.DE, Registers.A);
	Timer.t += 8;
}

void Opcode_0x13(void) {
	// INC DE
	Registers.DE++;
	Timer.t += 8;
}

void Opcode_0x14(void) {
	// INC D
	Instruction_INC_N(&Registers.D);
	Timer.t += 4;
}

void Opcode_0x15(void) {
	// DEC D
	Instruction_DEC_N(&Registers.D);
	Timer.t -= 4;
}

void Opcode_0x16(void) {
	// LD D, n
	Registers.D = Memory_load_byte_PC();
	Timer.t += 8;
}

void Opcode_0x17(void) {
	// RLA
	uint8_t carry = Flag_get_C();
	uint8_t bit7 = (Registers.A & 0x40) >> 7;

	Registers.A = (Registers.A << 1) | carry;
	Flags_set(
		0,
		0,
		0,
		bit7
	);

	Timer.t += 4;
}

void Opcode_0x18(void) {
	// JR n
	int8_t n = (int8_t) Memory_load_byte_PC();
	Registers.PC += n;
	Timer.t += 12;
}

void Opcode_0x19(void) {
	// ADD HL, DE
	Instruction_ADD_HL_N(Registers.DE);
	Timer.t += 8;
}

void Opcode_0x1A(void) {
	// LD A, (DE)
	Registers.A = Memory_load_byte(Registers.DE);
	Timer.t += 8;
}

void Opcode_0x1B(void) {
	// DEC DE
	Registers.DE--;
	Timer.t += 8;
}

void Opcode_0x1C(void) {
	// INC E
	Instruction_INC_N(&Registers.E);
	Timer.t += 4;
}

void Opcode_0x1D(void) {
	// DEC E
	Instruction_DEC_N(&Registers.E);
	Timer.t -= 4;
}

void Opcode_0x1E(void) {
	// LD E, n
	Registers.E = Memory_load_byte_PC();
	Timer.t += 8;
}

void Opcode_0x1F(void) {
	// RRA
	uint8_t carry = Flag_get_C();
	uint8_t bit0 = Registers.A & 0x01;

	Registers.A = (Registers.A >> 1) | (carry << 7);

	Flags_set(
		0,
		0,
		0,
		bit0
	);

	Timer.t += 4;
}

void Opcode_0x20(void) {
	// JR NZ, n
	int8_t n = (int8_t) Memory_load_byte_PC();

	if (Flag_get_Z() == 0) {
		Registers.PC += n;
		Timer.t += 12;
	}
	else {
		Timer.t += 8;
	}
}

void Opcode_0x21(void) {
	// LD HL, nn
	Registers.HL = Memory_load_word_PC();
	Timer.t += 12;
}

void Opcode_0x22(void) {
	// LD (HL+), A
	Memory_store_byte(Registers.HL, Registers.A);
	Registers.HL++;
	Timer.t += 8;
}

void Opcode_0x23(void) {
	// INC HL
	Registers.HL++;
	Timer.t += 8;
}

void Opcode_0x24(void) {
	// INC H
	Instruction_INC_N(&Registers.H);
	Timer.t += 4;
}

void Opcode_0x25(void) {
	// DEC H
	Instruction_DEC_N(&Registers.H);
	Timer.t -= 4;
}

void Opcode_0x26(void) {
	// LD E, n
	Registers.E = Memory_load_byte_PC();
	Timer.t += 8;
}

void Opcode_0x27(void) {
	// DAA
	// TODO: WHAT THE HELL IS DAA?!
	Opcode_not_implemented(0x27);
}

void Opcode_0x28(void) {
	// JR Z, n
	int8_t n = (int8_t) Memory_load_byte_PC();

	if (Flag_get_Z() == 1) {
		Registers.PC += n;
		Timer.t += 12;
	}
	else {
		Timer.t += 8;
	}
}

void Opcode_0x29(void) {
	// ADD HL, HL
	Instruction_ADD_HL_N(Registers.HL);
	Timer.t += 8;
}

void Opcode_0x2A(void) {
	// LD A, (HL+)
	Registers.A = Memory_load_byte(Registers.HL);
	Registers.HL++;
	Timer.t += 8;
}

void Opcode_0x2B(void) {
	// DEC HL
	Registers.HL--;
	Timer.t += 8;
}

void Opcode_0x2C(void) {
	// INC L
	Instruction_INC_N(&Registers.A);
	Timer.t += 4;
}

void Opcode_0x2D(void) {
	// DEC L
	Instruction_DEC_N(&Registers.L);
	Timer.t -= 4;
}

void Opcode_0x2E(void) {
	// LD L, n
	Registers.L = Memory_load_byte_PC();
	Timer.t += 8;
}

void Opcode_0x2F(void) {
	// CPL
	Flags_set(-1, 1, 1, -1);
	Registers.A = ~Registers.A;
	Timer.t += 4;
}

void Opcode_0x30(void) {
	// JR NC, n
	int8_t n = (int8_t) Memory_load_byte_PC();

	if (Flag_get_C() == 0) {
		Registers.PC += n;
		Timer.t += 12;
	}
	else {
		Timer.t += 8;
	}
}

void Opcode_0x31(void) {
	// LD SP, nn
	Registers.SP = Memory_load_word_PC();
	Timer.t += 12;
}

void Opcode_0x32(void) {
	// LD (HL-), A
	Memory_store_byte(Registers.HL, Registers.A);
	Registers.HL--;
	Timer.t += 8;
}

void Opcode_0x33(void) {
	// INC SP
	Registers.SP++;
	Timer.t += 8;
}

void Opcode_0x34(void) {
	// INC (HL)
	uint8_t n = Memory_load_byte(Registers.HL);

	Flags_set(
		(n + 1) == 0,
		0,
		Flag_test_H_U8_U8(n, 1, 1),
		-1
	);

	Memory_store_byte(Registers.HL, (n + 1));
	Timer.t += 12;
}

void Opcode_0x35(void) {
	// DEC (HL)
	uint8_t n = Memory_load_byte(Registers.HL);

	Flags_set(
		(n - 1) == 0,
		1,
		Flag_test_H_U8_U8(n, 1, 0),
		-1
	);

	Memory_store_byte(Registers.HL, (n - 1));
	Timer.t += 12;
}

void Opcode_0x36(void) {
	// LD (HL), n
	Memory_store_byte(Registers.HL, Memory_load_byte_PC());
	Timer.t += 12;
}

void Opcode_0x37(void) {
	// SCF
	Flags_set(-1, 0, 0, 1);
	Timer.t += 4;
}

void Opcode_0x38(void) {
	// JR C, n
	int8_t n = (int8_t) Memory_load_byte_PC();

	if (Flag_get_C() == 1) {
		Registers.PC += n;
		Timer.t += 12;
	}
	else {
		Timer.t += 8;
	}
}

void Opcode_0x39(void) {
	// ADD HL, SP
	Instruction_ADD_HL_N(Registers.SP);
	Timer.t += 8;
}

void Opcode_0x3A(void) {
	// LD A, (HL-)
	Registers.A = Memory_load_byte(Registers.HL);
	Registers.HL--;
	Timer.t += 8;
}

void Opcode_0x3B(void) {
	// DEC SP
	Registers.SP--;
	Timer.t += 8;
}

void Opcode_0x3C(void) {
	// INC A
	Instruction_INC_N(&Registers.A);
	Timer.t += 4;
}

void Opcode_0x3D(void) {
	// DEC A
	Instruction_DEC_N(&Registers.A);
	Timer.t -= 4;
}

void Opcode_0x3E(void) {
	// LD A, n
	Registers.A = Memory_load_byte_PC();
	Timer.t += 8;
}

void Opcode_0x3F(void) {
	// CCF
	uint8_t c = 0;

	if (!Flag_get_C())
		c = 1;

	Flags_set(-1, 0, 0, c);

	Timer.t += 4;
}

void Opcode_0x40(void) {
	// LD B, B
	Registers.B = Registers.B;
	Timer.t += 4;
}

void Opcode_0x41(void) {
	// LD B, C
	Registers.B = Registers.C;
	Timer.t += 4;
}

void Opcode_0x42(void) {
	// LD B, D
	Registers.B = Registers.D;
	Timer.t += 4;
}

void Opcode_0x43(void) {
	// LD B, E
	Registers.B = Registers.E;
	Timer.t += 4;
}

void Opcode_0x44(void) {
	// LD B, H
	Registers.B = Registers.H;
	Timer.t += 4;
}

void Opcode_0x45(void) {
	// LD B, L
	Registers.B = Registers.L;
	Timer.t += 4;
}

void Opcode_0x46(void) {
	// LD B, (HL)
	Registers.B = Memory_load_byte(Registers.HL);
	Timer.t += 8;
}

void Opcode_0x47(void) {
	// LD B, A
	Registers.B = Registers.A;
	Timer.t += 4;
}

void Opcode_0x48(void) {
	// LD C, B
	Registers.C = Registers.B;
	Timer.t += 4;
}

void Opcode_0x49(void) {
	// LD C, C
	Registers.C = Registers.C;
	Timer.t += 4;
}

void Opcode_0x4A(void) {
	// LD C, D
	Registers.C = Registers.D;
	Timer.t += 4;
}

void Opcode_0x4B(void) {
	// LD C, E
	Registers.C = Registers.E;
	Timer.t += 4;
}

void Opcode_0x4C(void) {
	// LD C, H
	Registers.C = Registers.H;
	Timer.t += 4;
}

void Opcode_0x4D(void) {
	// LD C, L
	Registers.C = Registers.L;
	Timer.t += 4;
}

void Opcode_0x4E(void) {
	// LD C, (HL)
	Registers.C = Memory_load_byte(Registers.HL);
	Timer.t += 8;
}

void Opcode_0x4F(void) {
	// LD C, A
	Registers.C = Registers.A;
	Timer.t += 4;
}

void Opcode_0x50(void) {
	// LD D, B
	Registers.D = Registers.B;
	Timer.t += 4;
}

void Opcode_0x51(void) {
	// LD D, C
	Registers.D = Registers.C;
	Timer.t += 4;
}

void Opcode_0x52(void) {
	// LD D, D
	Registers.D = Registers.D;
	Timer.t += 4;
}

void Opcode_0x53(void) {
	// LD D, E
	Registers.D = Registers.E;
	Timer.t += 4;
}

void Opcode_0x54(void) {
	// LD D, H
	Registers.D = Registers.H;
	Timer.t += 4;
}

void Opcode_0x55(void) {
	// LD D, L
	Registers.D = Registers.L;
	Timer.t += 4;
}

void Opcode_0x56(void) {
	// LD D, (HL)
	Registers.D = Memory_load_byte(Registers.HL);
	Timer.t += 8;
}

void Opcode_0x57(void) {
	// LD D, A
	Registers.D = Registers.A;
	Timer.t += 4;
}

void Opcode_0x58(void) {
	// LD E, B
	Registers.E = Registers.B;
	Timer.t += 4;
}

void Opcode_0x59(void) {
	// LD E, C
	Registers.E = Registers.C;
	Timer.t += 4;
}

void Opcode_0x5A(void) {
	// LD E, D
	Registers.E = Registers.D;
	Timer.t += 4;
}

void Opcode_0x5B(void) {
	// LD E, E
	Registers.E = Registers.E;
	Timer.t += 4;
}

void Opcode_0x5C(void) {
	// LD E, H
	Registers.E = Registers.H;
	Timer.t += 4;
}

void Opcode_0x5D(void) {
	// LD E, L
	Registers.E = Registers.L;
	Timer.t += 4;
}

void Opcode_0x5E(void) {
	// LD E, (HL)
	Registers.E = Memory_load_byte(Registers.HL);
	Timer.t += 8;
}

void Opcode_0x5F(void) {
	// #
	Opcode_not_implemented(0x5F);
}

void Opcode_0x60(void) {
	// LD H, B
	Registers.H = Registers.B;
	Timer.t += 4;
}

void Opcode_0x61(void) {
	// LD H, C
	Registers.H = Registers.C;
	Timer.t += 4;
}

void Opcode_0x62(void) {
	// LD H, D
	Registers.H = Registers.D;
	Timer.t += 4;
}

void Opcode_0x63(void) {
	// LD H, E
	Registers.H = Registers.E;
	Timer.t += 4;
}

void Opcode_0x64(void) {
	// LD H, H
	Registers.H = Registers.H;
	Timer.t += 4;
}

void Opcode_0x65(void) {
	// LD H, L
	Registers.H = Registers.L;
	Timer.t += 4;
}

void Opcode_0x66(void) {
	// LD H, (HL)
	Registers.H = Memory_load_byte(Registers.HL);
	Timer.t += 8;
}

void Opcode_0x67(void) {
	// LD H, A
	Registers.H = Registers.A;
	Timer.t += 4;
}

void Opcode_0x68(void) {
	// LD L, B
	Registers.L = Registers.B;
	Timer.t += 4;
}

void Opcode_0x69(void) {
	// LD L, C
	Registers.L = Registers.C;
	Timer.t += 4;
}

void Opcode_0x6A(void) {
	// LD L, D
	Registers.L = Registers.D;
	Timer.t += 4;
}

void Opcode_0x6B(void) {
	// LD L, E
	Registers.L = Registers.E;
	Timer.t += 4;
}

void Opcode_0x6C(void) {
	// LD L, H
	Registers.L = Registers.H;
	Timer.t += 4;
}

void Opcode_0x6D(void) {
	// LD L, L
	Registers.L = Registers.L;
	Timer.t += 4;
}

void Opcode_0x6E(void) {
	// LD L, (HL)
	Registers.L = Memory_load_byte(Registers.HL);
	Timer.t += 8;
}

void Opcode_0x6F(void) {
	// LD L, A
	Registers.L = Registers.A;
	Timer.t += 4;
}

void Opcode_0x70(void) {
	// LD (HL), B
	Memory_store_byte(Registers.HL, Registers.B);
	Timer.t += 8;
}

void Opcode_0x71(void) {
	// LD (HL), C
	Memory_store_byte(Registers.HL, Registers.C);
	Timer.t += 8;
}

void Opcode_0x72(void) {
	// LD (HL), D
	Memory_store_byte(Registers.HL, Registers.D);
	Timer.t += 8;
}

void Opcode_0x73(void) {
	// LD (HL), E
	Memory_store_byte(Registers.HL, Registers.E);
	Timer.t += 8;
}

void Opcode_0x74(void) {
	// LD (HL), H
	Memory_store_byte(Registers.HL, Registers.H);
	Timer.t += 8;
}

void Opcode_0x75(void) {
	// LD (HL), L
	Memory_store_byte(Registers.HL, Registers.L);
	Timer.t += 8;
}

void Opcode_0x76(void) {
	// HALT
	// TODO: Add infrastructure for HALTing
	Opcode_not_implemented(0x76);
}

void Opcode_0x77(void) {
	// LD (HL), A
	Memory_store_byte(Registers.HL, Registers.A);
	Timer.t += 8;
}

void Opcode_0x78(void) {
	// LD A, B
	Registers.A = Registers.B;
	Timer.t += 4;
}

void Opcode_0x79(void) {
	// LD A, C
	Registers.A = Registers.C;
	Timer.t += 4;
}

void Opcode_0x7A(void) {
	// LD A, D
	Registers.A = Registers.D;
	Timer.t += 4;
}

void Opcode_0x7B(void) {
	// LD A, E
	Registers.A = Registers.E;
	Timer.t += 4;
}

void Opcode_0x7C(void) {
	// LD A, H
	Registers.A = Registers.H;
	Timer.t += 4;
}

void Opcode_0x7D(void) {
	// LD A, L
	Registers.A = Registers.L;
	Timer.t += 4;
}

void Opcode_0x7E(void) {
	// LD A, (HL)
	Registers.A = Memory_load_byte(Registers.HL);
	Timer.t += 8;
}

void Opcode_0x7F(void) {
	// LD A, A
	Registers.A = Registers.A;
	Timer.t += 4;
}

void Opcode_0x80(void) {
	// ADD A, B
	Instruction_ADD_A_N(Registers.B);
	Timer.t += 4;
}

void Opcode_0x81(void) {
	// ADD A, C
	Instruction_ADD_A_N(Registers.C);
	Timer.t += 4;
}

void Opcode_0x82(void) {
	// ADD A, D
	Instruction_ADD_A_N(Registers.D);
	Timer.t += 4;
}

void Opcode_0x83(void) {
	// ADD A, E
	Instruction_ADD_A_N(Registers.E);
	Timer.t += 4;
}

void Opcode_0x84(void) {
	// ADD A, H
	Instruction_ADD_A_N(Registers.H);
	Timer.t += 4;
}

void Opcode_0x85(void) {
	// ADD A, L
	Instruction_ADD_A_N(Registers.L);
	Timer.t += 4;
}

void Opcode_0x86(void) {
	// ADD A, (HL)
	Instruction_ADD_A_N(Memory_load_byte(Registers.HL));
	Timer.t += 8;
}

void Opcode_0x87(void) {
	// ADD A, A
	Instruction_ADD_A_N(Registers.A);
	Timer.t += 4;
}

void Opcode_0x88(void) {
	// ADC A, B
	Instruction_ADC_A_N(Registers.B);
	Timer.t += 4;
}

void Opcode_0x89(void) {
	// ADC A, C
	Instruction_ADC_A_N(Registers.C);
	Timer.t += 4;
}

void Opcode_0x8A(void) {
	// ADC A, D
	Instruction_ADC_A_N(Registers.D);
	Timer.t += 4;
}

void Opcode_0x8B(void) {
	// ADC A, E
	Instruction_ADC_A_N(Registers.E);
	Timer.t += 4;
}

void Opcode_0x8C(void) {
	// ADC A, H
	Instruction_ADC_A_N(Registers.H);
	Timer.t += 4;
}

void Opcode_0x8D(void) {
	// ADC A, L
	Instruction_ADC_A_N(Registers.L);
	Timer.t += 4;
}

void Opcode_0x8E(void) {
	// ADC A, (HL)
	Instruction_ADC_A_N(Memory_load_byte(Registers.HL));
	Timer.t += 8;
}

void Opcode_0x8F(void) {
	// ADC A, A
	Instruction_ADC_A_N(Registers.A);
	Timer.t += 4;
}

void Opcode_0x90(void) {
	// SUB B
	Instruction_SUB_N(Registers.B);
	Timer.t += 4;
}

void Opcode_0x91(void) {
	// SUB C
	Instruction_SUB_N(Registers.C);
	Timer.t += 4;
}

void Opcode_0x92(void) {
	// SUB D
	Instruction_SUB_N(Registers.D);
	Timer.t += 4;
}

void Opcode_0x93(void) {
	// SUB E
	Instruction_SUB_N(Registers.E);
	Timer.t += 4;
}

void Opcode_0x94(void) {
	// SUB H
	Instruction_SUB_N(Registers.H);
	Timer.t += 4;
}

void Opcode_0x95(void) {
	// SUB L
	Instruction_SUB_N(Registers.L);
	Timer.t += 4;
}

void Opcode_0x96(void) {
	// SUB (HL)
	Instruction_SUB_N(Memory_load_byte(Registers.HL));
	Timer.t += 8;
}

void Opcode_0x97(void) {
	// SUB A
	Instruction_SUB_N(Registers.A);
	Timer.t += 4;
}

void Opcode_0x98(void) {
	// SBC A, B
	Instruction_SBC_A_N(Registers.B);
	Timer.t += 4;
}

void Opcode_0x99(void) {
	// SBC A, C
	Instruction_SBC_A_N(Registers.C);
	Timer.t += 4;
}

void Opcode_0x9A(void) {
	// SBC A, D
	Instruction_SBC_A_N(Registers.D);
	Timer.t += 4;
}

void Opcode_0x9B(void) {
	// SBC A, E
	Instruction_SBC_A_N(Registers.E);
	Timer.t += 4;
}

void Opcode_0x9C(void) {
	// SBC A, H
	Instruction_SBC_A_N(Registers.H);
	Timer.t += 4;
}

void Opcode_0x9D(void) {
	// SBC A, L
	Instruction_SBC_A_N(Registers.L);
	Timer.t += 4;
}

void Opcode_0x9E(void) {
	// SBC A, (HL)
	Instruction_SBC_A_N(Memory_load_byte(Registers.HL));
	Timer.t += 8;
}

void Opcode_0x9F(void) {
	// SBC A, A
	Instruction_SBC_A_N(Registers.A);
	Timer.t += 4;
}

void Opcode_0xA0(void) {
	// AND B
	Instruction_AND_N(Registers.B);
	Timer.t += 4;
}

void Opcode_0xA1(void) {
	// AND C
	Instruction_AND_N(Registers.C);
	Timer.t += 4;
}

void Opcode_0xA2(void) {
	// AND D
	Instruction_AND_N(Registers.D);
	Timer.t += 4;
}

void Opcode_0xA3(void) {
	// AND E
	Instruction_AND_N(Registers.E);
	Timer.t += 4;
}

void Opcode_0xA4(void) {
	// AND H
	Instruction_AND_N(Registers.H);
	Timer.t += 4;
}

void Opcode_0xA5(void) {
	// AND L
	Instruction_AND_N(Registers.L);
	Timer.t += 4;
}

void Opcode_0xA6(void) {
	// AND (HL)
	Instruction_AND_N(Memory_load_byte(Registers.HL));
	Timer.t += 8;
}

void Opcode_0xA7(void) {
	// AND A
	Instruction_AND_N(Registers.A);
	Timer.t += 4;
}

void Opcode_0xA8(void) {
	// XOR B
	Instruction_XOR_N(Registers.B);
	Timer.t += 4;
}

void Opcode_0xA9(void) {
	// XOR C
	Instruction_XOR_N(Registers.C);
	Timer.t += 4;
}

void Opcode_0xAA(void) {
	// XOR D
	Instruction_XOR_N(Registers.D);
	Timer.t += 4;
}

void Opcode_0xAB(void) {
	// XOR E
	Instruction_XOR_N(Registers.E);
	Timer.t += 4;
}

void Opcode_0xAC(void) {
	// XOR H
	Instruction_XOR_N(Registers.H);
	Timer.t += 4;
}

void Opcode_0xAD(void) {
	// XOR L
	Instruction_XOR_N(Registers.L);
	Timer.t += 4;
}

void Opcode_0xAE(void) {
	// XOR (HL)
	Instruction_XOR_N(Memory_load_byte(Registers.HL));
	Timer.t += 8;
}

void Opcode_0xAF(void) {
	// XOR A
	Instruction_XOR_N(Registers.A);
	Timer.t += 4;
}

void Opcode_0xB0(void) {
	// OR B
	Instruction_OR_N(Registers.B);
	Timer.t += 4;
}

void Opcode_0xB1(void) {
	// OR C
	Instruction_OR_N(Registers.C);
	Timer.t += 4;
}

void Opcode_0xB2(void) {
	// OR D
	Instruction_OR_N(Registers.D);
	Timer.t += 4;
}

void Opcode_0xB3(void) {
	// OR E
	Instruction_OR_N(Registers.E);
	Timer.t += 4;
}

void Opcode_0xB4(void) {
	// OR H
	Instruction_OR_N(Registers.H);
	Timer.t += 4;
}

void Opcode_0xB5(void) {
	// OR L
	Instruction_OR_N(Registers.L);
	Timer.t += 4;
}

void Opcode_0xB6(void) {
	// OR (HL)
	Instruction_OR_N(Memory_load_byte(Registers.HL));
	Timer.t += 8;
}

void Opcode_0xB7(void) {
	// OR A
	Instruction_OR_N(Registers.A);
	Timer.t += 4;
}

void Opcode_0xB8(void) {
	// CP B
	Instruction_CP_N(Registers.B);
	Timer.t += 4;
}

void Opcode_0xB9(void) {
	// CP C
	Instruction_CP_N(Registers.C);
	Timer.t += 4;
}

void Opcode_0xBA(void) {
	// CP D
	Instruction_CP_N(Registers.D);
	Timer.t += 4;
}

void Opcode_0xBB(void) {
	// CP E
	Instruction_CP_N(Registers.E);
	Timer.t += 4;
}

void Opcode_0xBC(void) {
	// CP H
	Instruction_CP_N(Registers.H);
	Timer.t += 4;
}

void Opcode_0xBD(void) {
	// CP L
	Instruction_CP_N(Registers.L);
	Timer.t += 4;
}

void Opcode_0xBE(void) {
	// CP (HL)
	Instruction_CP_N(Memory_load_byte(Registers.HL));
	Timer.t += 8;
}

void Opcode_0xBF(void) {
	// CP A
	Instruction_CP_N(Registers.A);
	Timer.t += 4;
}

void Opcode_0xC0(void) {
	// RET NZ
	
	if (Flag_get_Z() == 0) {
		Instruction_RET();
		Timer.t += 20;
	}
	else {
		Timer.t += 8;
	}
}

void Opcode_0xC1(void) {
	// POP BC
	Registers.C = Memory_load_byte(Registers.SP);
	Registers.B = Memory_load_byte(Registers.SP + 1);
	Registers.SP += 2;
	Timer.t += 12;
}

void Opcode_0xC2(void) {
	// JP NZ, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_Z() == 0) {
		Registers.PC = nn;
		Timer.t += 16;
	}
	else {
		Timer.t += 12;
	}
}

void Opcode_0xC3(void) {
	// JP nn
	Registers.PC = Memory_load_word_PC();
	Timer.t += 16;
}

void Opcode_0xC4(void) {
	// CALL NZ, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_Z() == 0) {
		Instruction_CALL_NN(nn);
		Timer.t += 24;
	}
	else {
		Timer.t += 12;
	}
}

void Opcode_0xC5(void) {
	// PUSH BC
	Memory_store_byte(Registers.SP - 1, Registers.B);
	Memory_store_byte(Registers.SP - 2, Registers.C);
	Registers.SP -= 2;
	Timer.t += 16;
}

void Opcode_0xC6(void) {
	// ADD A, n
	Instruction_ADD_A_N(Memory_load_byte_PC());
	Timer.t += 8;
}

void Opcode_0xC7(void) {
	// RST 00H
	Instruction_RST_N(0x00);
	Timer.t += 16;
}

void Opcode_0xC8(void) {
	// RET Z

	if (Flag_get_Z() == 1) {
		Instruction_RET();
		Timer.t += 20;
	}
	else {
		Timer.t += 8;
	}
}

void Opcode_0xC9(void) {
	// RET
	Instruction_RET();
	Timer.t += 16;
}

void Opcode_0xCA(void) {
	// JP Z, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_Z() == 1) {
		Registers.PC = nn;
		Timer.t += 16;
	}
	else {
		Timer.t += 12;
	}
}

void Opcode_0xCB(void) {
	// PREFIX CB
	// TODO: Start working on this madness
	Opcode_not_implemented(0xCB);
}

void Opcode_0xCC(void) {
	// CALL Z, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_Z() == 1) {
		Instruction_CALL_NN(nn);
		Timer.t += 24;
	}
	else {
		Timer.t += 12;
	}
}

void Opcode_0xCD(void) {
	// CALL nn
	Instruction_CALL_NN(Memory_load_word_PC());
	Timer.t += 24;
}

void Opcode_0xCE(void) {
	// ADC A, n
	Instruction_ADC_A_N(Memory_load_byte_PC());
	Timer.t += 8;
}

void Opcode_0xCF(void) {
	// RST 08H
	Instruction_RST_N(0x08);
	Timer.t += 16;
}

void Opcode_0xD0(void) {
	// RET NC

	if (Flag_get_C() == 0) {
		Instruction_RET();
		Timer.t += 20;
	}
	else {
		Timer.t += 8;
	}
}

void Opcode_0xD1(void) {
	// POP DE
	Registers.E = Memory_load_byte(Registers.SP);
	Registers.D = Memory_load_byte(Registers.SP + 1);
	Registers.SP += 2;
	Timer.t += 12;
}

void Opcode_0xD2(void) {
	// JP NC, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_C() == 0) {
		Registers.PC = nn;
		Timer.t += 16;
	}
	else {
		Timer.t += 12;
	}
}

void Opcode_0xD3(void) {
	// EMPTY
	Opcode_empty(0xD3);
}

void Opcode_0xD4(void) {
	// CALL NC, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_C() == 0) {
		Instruction_CALL_NN(nn);
		Timer.t += 24;
	}
	else {
		Timer.t += 12;
	}
}

void Opcode_0xD5(void) {
	// PUSH DE
	Memory_store_byte(Registers.SP - 1, Registers.D);
	Memory_store_byte(Registers.SP - 2, Registers.E);
	Registers.SP -= 2;
	Timer.t += 16;
}

void Opcode_0xD6(void) {
	// SUB n
	Instruction_SUB_N(Memory_load_byte_PC());
	Timer.t += 8;
}

void Opcode_0xD7(void) {
	// RST 10H
	Instruction_RST_N(0x10);
	Timer.t += 16;
}

void Opcode_0xD8(void) {
	// RET C

	if (Flag_get_C() == 1) {
		Instruction_RET();
		Timer.t += 20;
	}
	else {
		Timer.t += 8;
	}
}

void Opcode_0xD9(void) {
	// RETI
	Instruction_RET();
	// TODO: Enable interrupts
	Timer.t += 16;
	Opcode_not_implemented(0xD9);
}

void Opcode_0xDA(void) {
	// JP C, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_C() == 1) {
		Registers.PC = nn;
		Timer.t += 16;
	}
	else {
		Timer.t += 12;
	}
}

void Opcode_0xDB(void) {
	// EMPTY
	Opcode_empty(0xDB);
}

void Opcode_0xDC(void) {
	// CALL C, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_C() == 0) {
		Instruction_CALL_NN(nn);
		Timer.t += 24;
	}
	else {
		Timer.t += 12;
	}
}

void Opcode_0xDD(void) {
	// EMPTY
	Opcode_empty(0xDD);
}

void Opcode_0xDE(void) {
	// SBC A, n
	Instruction_SBC_A_N(Memory_load_byte_PC());
	Timer.t += 8;
}

void Opcode_0xDF(void) {
	// RST 18H
	Instruction_RST_N(0x18);
	Timer.t += 16;
}

void Opcode_0xE0(void) {
	// LDH (n), A
	Memory_store_byte(((uint16_t) 0xFF) + Memory_load_byte_PC(), Registers.A);
	Timer.t += 12;
}

void Opcode_0xE1(void) {
	// POP HL
	Registers.L = Memory_load_byte(Registers.SP);
	Registers.H = Memory_load_byte(Registers.SP + 1);
	Registers.SP += 2;
	Timer.t += 12;
}

void Opcode_0xE2(void) {
	// LD (C), A
	Memory_store_byte(((uint16_t) 0xFF00) + Registers.C, Registers.A);
	Timer.t += 8;
}

void Opcode_0xE3(void) {
	// EMPTY
	Opcode_empty(0xE3);
}

void Opcode_0xE4(void) {
	// EMPTY
	Opcode_empty(0xE4);
}

void Opcode_0xE5(void) {
	// PUSH HL
	Memory_store_byte(Registers.SP - 1, Registers.H);
	Memory_store_byte(Registers.SP - 2, Registers.L);
	Registers.SP -= 2;
	Timer.t += 16;
}

void Opcode_0xE6(void) {
	// AND n
	Instruction_AND_N(Memory_load_byte_PC());
	Timer.t += 8;
}

void Opcode_0xE7(void) {
	// RST 20H
	Instruction_RST_N(0x20);
	Timer.t += 16;
}

void Opcode_0xE8(void) {
	// ADD SP, n
	int8_t n = (int8_t) Memory_load_byte_PC();

	Flags_set(
		0,
		0,
		Flag_test_H_U16_S8(Registers.SP, n),
		Flag_test_C_U16_S8(Registers.SP, n)
	);

	Registers.SP += n;
	Timer.t += 16;
}

void Opcode_0xE9(void) {
	// JP (HL)
	Registers.PC = Registers.HL;
	Timer.t += 4;
}

void Opcode_0xEA(void) {
	// LD (nn), A
	Memory_store_byte(Memory_load_word_PC(), Registers.A);
	Timer.t += 16;
}

void Opcode_0xEB(void) {
	// EMPTY
	Opcode_empty(0xEB);
}

void Opcode_0xEC(void) {
	// EMPTY
	Opcode_empty(0xEC);
}

void Opcode_0xED(void) {
	// EMPTY
	Opcode_empty(0xED);
}

void Opcode_0xEE(void) {
	// XOR n
	Instruction_XOR_N(Memory_load_byte_PC());
	Timer.t += 8;
}

void Opcode_0xEF(void) {
	// RST 28H
	Instruction_RST_N(0x28);
	Timer.t += 16;
}

void Opcode_0xF0(void) {
	// LDH A, (n)
	Registers.A = Memory_load_byte(((uint16_t) 0xFF00) + Memory_load_byte_PC());
	Timer.t += 12;
}

void Opcode_0xF1(void) {
	// POP AF
	Registers.F = Memory_load_byte(Registers.SP);
	Registers.A = Memory_load_byte(Registers.SP + 1);
	Registers.SP += 2;
	Timer.t += 12;
}

void Opcode_0xF2(void) {
	// LD A, (C)
	Registers.A = Memory_load_byte(((uint16_t) 0xFF00) + Registers.C);
	Timer.t += 8;
}

void Opcode_0xF3(void) {
	// DI
	// TODO: Implement Interrupt architecture
	Opcode_not_implemented(0xF3);
}

void Opcode_0xF4(void) {
	// EMPTY
	Opcode_empty(0xF4);
}

void Opcode_0xF5(void) {
	// PUSH AF
	Memory_store_byte(Registers.SP - 1, Registers.A);
	Memory_store_byte(Registers.SP - 2, Registers.F);
	Registers.SP -= 2;
	Timer.t += 16;
}

void Opcode_0xF6(void) {
	// OR n
	Instruction_OR_N(Memory_load_byte_PC());
	Timer.t += 8;
}

void Opcode_0xF7(void) {
	// RST 30H
	Instruction_RST_N(0x30);
	Timer.t += 16;
}

void Opcode_0xF8(void) {
	// LDHL SP, n
	int8_t n = (int8_t) Memory_load_byte_PC();
	Flags_set(0, 
			  0, 
			  Flag_test_H_U16_S8(Registers.SP, n), 
			  Flag_test_C_U16_S8(Registers.SP, n));
	
	Registers.HL = Registers.SP + n;
	Timer.t += 12;
}

void Opcode_0xF9(void) {
	// LD SP, HL
	Registers.SP = Registers.HL;
	Timer.t += 8;
}

void Opcode_0xFA(void) {
	// LD A, (nn)
	Registers.A = Memory_load_byte(Memory_load_word_PC());
	Timer.t += 16;
}

void Opcode_0xFB(void) {
	// EI
	// TODO: Implement Interrupt architecture
	Opcode_not_implemented(0xFB);
}

void Opcode_0xFC(void) {
	// EMPTY
	Opcode_empty(0xFC);
}

void Opcode_0xFD(void) {
	// EMPTY
	Opcode_empty(0xFD);
}

void Opcode_0xFE(void) {
	// CP n
	Instruction_CP_N(Memory_load_byte_PC());
	Timer.t += 8;
}

void Opcode_0xFF(void) {
	// RST 38H
	Instruction_RST_N(0x38);
	Timer.t += 16;
}
