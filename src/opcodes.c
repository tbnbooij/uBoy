#include "opcodes.h"

// Filling the opcode table
// ---------------------------------------------------
void Opcodes_init(void) {
	
	// 8-bit arithmetic
	for (uint8_t i = 0; i < 0xFF; i++) {
		Opcodes[i] = Opcode_ALU_8;
	}
	
	// 8-bit loads/stores/moves
	for (uint8_t i = 0x40; i <= 0x7F; i++) {
		Opcodes[i] = Opcode_LD_8;
	}

	for (uint8_t i = 0x02; i <= 0x3E; i += 4) {
		Opcodes[i] = Opcode_LD_8;
	}
	
	uint8_t LD_8[6] = {0xE0, 0xF0,
						0xE2, 0xF2,
						0xEA, 0xFA};
	
	for (uint8_t i = 0; i < 6; i++) {
		Opcodes[LD_8[i]] = Opcode_LD_8;
	}
	
	// 16-bit arithmetic
	uint8_t ALU_16[13] = {0x03, 0x13, 0x23, 0x33,
							0xE8,
							0x09, 0x19, 0x29, 0x39,
							0x0B, 0x1B, 0x2B, 0x3B};
	
	for (uint8_t i = 0; i < 13; i++) {
		Opcodes[ALU_16[i]] = Opcode_ALU_16;
	}
	
	// Miscellaneous/control instructions
	uint8_t MISC[6] = {0x00, 0x10, 0x76, 0xF3, 0xCB, 0xFB};

	for (uint8_t i = 0; i < 6; i++) {
		Opcodes[MISC[i]] = Opcode_MISC;
	}
	
	// Jumps and calls
	uint8_t JP[30] = {0x20, 0x30, 0xC0, 0xD0, 
						0xC2, 0xD2, 
						0xC3, 
						0xC4, 0xD4,
						0xC7, 0xD7, 0xE7, 0xF7,
						0x18, 0x28, 0x38, 0xC8, 0xD8,
						0xC9, 0xD9, 0xE9,
						0xCA, 0xDA,
						0xCC, 0xDC,
						0xCD,
						0xCF, 0xDF, 0xEF, 0xFF};
	
	for (uint8_t i = 0; i < 30; i++) {
		Opcodes[JP[i]] = Opcode_JP;
	}
	
	// 16-bit loads/stores/moves
	uint8_t LD_16[15] = {0x01, 0x11, 0x21, 0x31,
						0xC1, 0xD1, 0xE1, 0xF1,
						0xC5, 0xD5, 0xE5, 0xF5,
						0x08, 0xF8,
						0xF9};
	
	for (uint8_t i = 0; i < 15; i++) {
		Opcodes[LD_16[i]] = Opcode_LD_16;
	}

	// 8-bit rotations/shifts/bitwise operations
	uint8_t BIT[4] = {0x07, 0x17,
						0x0F, 0x1F};
	
	for (uint8_t i = 0; i < 4; i++) {
		Opcodes[BIT[i]] = Opcode_BIT;
	}

	// Empty cells
	uint8_t EMPTY[11] = {0xD3, 0xE3,
						0xE4, 0xF4,
						0xDB, 0xEB,
						0xEC, 0xFC,
						0xDD, 0xED, 0xFD};
	
	for (uint8_t i = 0; i < 11; i++) {
		Opcodes[EMPTY[i]] = NULL;
	}
	
}

// Opcode groups
// ---------------------------------------------------
void Opcode_LD_8(uint8_t opcode) {
	switch (opcode) {
		// LD nn, n
		case 0x06:
			// LD B, n
			Instruction_LD_R8_I8(&Registers.B);
			break;
		case 0x0E:
			// LD C, n
			Instruction_LD_R8_I8(&Registers.C);
			break;
		case 0x16:
			// LD D, n
			Instruction_LD_R8_I8(&Registers.D);
			break;
		case 0x1E:
			// LD E, n
			Instruction_LD_R8_I8(&Registers.E);
			break;
		case 0x26:
			// LD H, n
			Instruction_LD_R8_I8(&Registers.H);
			break;
		case 0x2E:
			// LD L, n
			Instruction_LD_R8_I8(&Registers.L);
			break;

		// LD r1, r2
		case 0x7F:
			// LD A, A
			Instruction_LD_R8_R8(&Registers.A, &Registers.A);
			break;
		case 0x78:
			// LD A, B
			Instruction_LD_R8_R8(&Registers.A, &Registers.B);
			break;
		case 0x79:
			// LD A, C
			Instruction_LD_R8_R8(&Registers.A, &Registers.C);
			break;
		case 0x7A:
			// LD A, D
			Instruction_LD_R8_R8(&Registers.A, &Registers.D);
			break;
		case 0x7B:
			// LD A, E
			Instruction_LD_R8_R8(&Registers.A, &Registers.E);
			break;
		case 0x7C:
			// LD A, H
			Instruction_LD_R8_R8(&Registers.A, &Registers.H);
			break;
		case 0x7D:
			// LD A, L
			Instruction_LD_R8_R8(&Registers.A, &Registers.L);
			break;
		case 0x40:
			// LD B, B
			Instruction_LD_R8_R8(&Registers.B, &Registers.B);
			break;
		case 0x41:
			// LD B, C
			Instruction_LD_R8_R8(&Registers.B, &Registers.C);
			break;
		case 0x42:
			// LD B, D
			Instruction_LD_R8_R8(&Registers.B, &Registers.D);
			break;
		case 0x43:
			// LD B, E
			Instruction_LD_R8_R8(&Registers.B, &Registers.E);
			break;
		case 0x44:
			// LD B, H
			Instruction_LD_R8_R8(&Registers.B, &Registers.H);
			break;
		case 0x45:
			// LD B, L
			Instruction_LD_R8_R8(&Registers.B, &Registers.L);
			break;
		case 0x48:
			// LD C, B
			Instruction_LD_R8_R8(&Registers.C, &Registers.B);
			break;
		case 0x49:
			// LD C, C
			Instruction_LD_R8_R8(&Registers.C, &Registers.C);
			break;
		case 0x4A:
			// LD C, D
			Instruction_LD_R8_R8(&Registers.C, &Registers.D);
			break;
		case 0x4B:
			// LD C, E
			Instruction_LD_R8_R8(&Registers.C, &Registers.E);
			break;
		case 0x4C:
			// LD C, H
			Instruction_LD_R8_R8(&Registers.C, &Registers.H);
			break;
		case 0x4D:
			// LD C, L
			Instruction_LD_R8_R8(&Registers.C, &Registers.L);
			break;
		case 0x50:
			// LD D, B
			Instruction_LD_R8_R8(&Registers.D, &Registers.B);
			break;
		case 0x51:
			// LD D, C
			Instruction_LD_R8_R8(&Registers.D, &Registers.C);
			break;
		case 0x52:
			// LD D, D
			Instruction_LD_R8_R8(&Registers.D, &Registers.D);
			break;
		case 0x53:
			// LD D, E
			Instruction_LD_R8_R8(&Registers.D, &Registers.E);
			break;
		case 0x54:
			// LD D, H
			Instruction_LD_R8_R8(&Registers.D, &Registers.H);
			break;
		case 0x55:
			// LD D, L
			Instruction_LD_R8_R8(&Registers.D, &Registers.L);
			break;
		case 0x58:
			// LD E, B
			Instruction_LD_R8_R8(&Registers.E, &Registers.B);
			break;
		case 0x59:
			// LD E, C
			Instruction_LD_R8_R8(&Registers.E, &Registers.C);
			break;
		case 0x5A:
			// LD E, D
			Instruction_LD_R8_R8(&Registers.E, &Registers.D);
			break;
		case 0x5B:
			// LD E, E
			Instruction_LD_R8_R8(&Registers.E, &Registers.E);
			break;
		case 0x5C:
			// LD E, H
			Instruction_LD_R8_R8(&Registers.E, &Registers.H);
			break;
		case 0x5D:
			// LD E, L
			Instruction_LD_R8_R8(&Registers.E, &Registers.L);
			break;
		case 0x60:
			// LD H, B
			Instruction_LD_R8_R8(&Registers.H, &Registers.B);
			break;
		case 0x61:
			// LD H, C
			Instruction_LD_R8_R8(&Registers.H, &Registers.C);
			break;
		case 0x62:
			// LD H, D
			Instruction_LD_R8_R8(&Registers.H, &Registers.D);
			break;
		case 0x63:
			// LD H, E
			Instruction_LD_R8_R8(&Registers.H, &Registers.E);
			break;
		case 0x64:
			// LD H, H
			Instruction_LD_R8_R8(&Registers.H, &Registers.H);
			break;
		case 0x65:
			// LD H, L
			Instruction_LD_R8_R8(&Registers.H, &Registers.L);
			break;
		case 0x68:
			// LD L, B
			Instruction_LD_R8_R8(&Registers.L, &Registers.B);
			break;
		case 0x69:
			// LD L, C
			Instruction_LD_R8_R8(&Registers.H, &Registers.C);
			break;
		case 0x6A:
			// LD L, D
			Instruction_LD_R8_R8(&Registers.H, &Registers.D);
			break;
		case 0x6B:
			// LD L, E
			Instruction_LD_R8_R8(&Registers.H, &Registers.E);
			break;
		case 0x6C:
			// LD L, H
			Instruction_LD_R8_R8(&Registers.H, &Registers.H);
			break;
		case 0x6D:
			// LD L, L
			Instruction_LD_R8_R8(&Registers.H, &Registers.L);
			break;
		case 0x7E:
			// LD A, (HL)
			Instruction_LD_R8_MR16(&Registers.A, &Registers.HL);
			break;
		case 0x46:
			// LD B, (HL)
			Instruction_LD_R8_MR16(&Registers.B, &Registers.HL);
			break;
		case 0x4E:
			// LD C, (HL)
			Instruction_LD_R8_MR16(&Registers.C, &Registers.HL);
			break;
		case 0x56:
			// LD D, (HL)
			Instruction_LD_R8_MR16(&Registers.D, &Registers.HL);
			break;
		case 0x5E:
			// LD E, (HL)
			Instruction_LD_R8_MR16(&Registers.E, &Registers.HL);
			break;
		case 0x66:
			// LD H, (HL)
			Instruction_LD_R8_MR16(&Registers.H, &Registers.HL);
			break;
		case 0x6E:
			// LD L, (HL)
			Instruction_LD_R8_MR16(&Registers.L, &Registers.HL);
			break;
		case 0x70:
			// LD (HL), B
			Instruction_LD_MR16_R8(&Registers.HL, &Registers.B);
			break;
		case 0x71:
			// LD (HL), C
			Instruction_LD_MR16_R8(&Registers.HL, &Registers.C);
			break;
		case 0x72:
			// LD (HL), D
			Instruction_LD_MR16_R8(&Registers.HL, &Registers.D);
			break;
		case 0x73:
			// LD (HL), E
			Instruction_LD_MR16_R8(&Registers.HL, &Registers.E);
			break;
		case 0x74:
			// LD (HL), H
			Instruction_LD_MR16_R8(&Registers.HL, &Registers.H);
			break;
		case 0x75:
			// LD (HL), L
			Instruction_LD_MR16_R8(&Registers.HL, &Registers.L);
			break;
		case 0x36:
			// LD (HL), n
			Instruction_LD_MR16_I8(&Registers.HL);
			break;
		
		// LD A, n
		case 0x0A:
			// LD A, (BC)
			Instruction_LD_R8_MR16(&Registers.A, &Registers.BC);
			break;
		case 0x1A:
			// LD A, (DE)
			Instruction_LD_R8_MR16(&Registers.A, &Registers.DE);
			break;
		case 0xFA:
			// LD A, (nn)
			Instruction_LD_R8_MI16(&Registers.A);
			break;
		case 0x3E:
			// LD A, n
			Instruction_LD_R8_I8(&Registers.A);
			break;
		
		// LD n, A
		case 0x02:
			// LD (BC), A
			Instruction_LD_MR16_R8(&Registers.BC, &Registers.A);
			break;
		case 0x12:
			// LD (DE), A
			Instruction_LD_MR16_R8(&Registers.DE, &Registers.A);
			break;
		case 0x77:
			// LD (HL), A
			Instruction_LD_MR16_R8(&Registers.HL, &Registers.A);
			break;
		case 0xEA:
			// LD (nn), A
			Instruction_LD_MI16_R8(&Registers.A);
			break;
		
		// LD instructions with few or hardly any copies
		case 0xF2:
			// LD A, (C)
			Instruction_LD_A_MC();
			break;
		case 0xE2:
			// LD (C), A
			Instruction_LD_MC_A();
			break;
		case 0x3A:
			// LDD A, (HL)
			Instruction_LDD_A_HL();
			break;
		case 0x32:
			// LDD (HL), A
			Instruction_LDD_HL_A();
			break;
		case 0x2A:
			// LDI A, (HL)
			Instruction_LDI_A_HL();
			break;
		case 0x22:
			// LDI (HL), A
			Instruction_LDI_HL_A();
			break;
		case 0xE0:
			// LDH (n), A
			Instruction_LDH_MI8_A();
			break;
		case 0xF0:
			// LDH A, (n)
			Instruction_LDH_A_MI8();
			break;
		default:
			Opcode_WRONG_GROUP_ERROR(opcode);
			break;
	}
}

void Opcode_LD_16(uint8_t opcode) {

}

void Opcode_ALU_8(uint8_t opcode) {

}

void Opcode_ALU_16(uint8_t opcode) {

}

void Opcode_MISC(uint8_t opcode) {
	switch (opcode) {
		case 0x00:
			// NOP
			Timer_update(4);
			break;
		case 0x10:
			// STOP 0

			break;
		case 0x76:
			// HALT

			break;
		case 0xF3:
			// DI

			break;
		case 0xCB:
			// PREFIX CB

			break;
		case 0xFB:
			// EI

			break;
		default:
			Opcode_WRONG_GROUP_ERROR(opcode);
			break;
	}
}

void Opcode_JP(uint8_t opcode) {
	switch (opcode) {
		case 0x20:
			// JR NZ, r8
			Instruction_JP_CC_N(!Flag_get_Z());
			break;
		case 0x30:
			// JR NC, r8
			Instruction_JP_CC_N(!Flag_get_C());
			break;
		case 0x28:
			// JR Z, r8
			Instruction_JP_CC_N(Flag_get_Z());
			break;
		case 0x38:
			// JR C, r8
			Instruction_JP_CC_N(Flag_get_C());
			break;
		case 0xC9:
			// RET
			Instruction_RET();
			break;
		case 0xC0:
			// RET NZ
			Instruction_RET_CC(!Flag_get_Z());
			break;
		case 0xD0:
			// RET NC
			Instruction_RET_CC(!Flag_get_C());
			break;
		case 0xC8:
			// RET Z
			Instruction_RET_CC(Flag_get_Z());
			break;
		case 0xD8:
			// RET C
			Instruction_RET_CC(Flag_get_C());
			break;
		case 0xC2:
			// JP NZ, a16

			break;
		case 0xD2:
			// JP NC, a16

			break;
		case 0xC3:
			// JP a16

			break;
		case 0xC4:
			// CALL NZ, a16

			break;
		case 0xD4:
			// CALL NC, a16

			break;
		case 0xC7:
			// RST 00H

			break;
		case 0xD7:
			// RST 10H

			break;
		case 0xE7:
			// RST 20H

			break;
		case 0xF7:
			// RST 30H

			break;
		case 0x18:
			// JR r8

			break;
		case 0xD9:
			// RETI

			break;
		case 0xE9:
			// JP (HL)

			break;
		case 0xCA:
			// JP Z, a16

			break;
		case 0xDA:
			// JP C, a16

			break;
		case 0xCC:
			// CALL Z, a16

			break;
		case 0xDC:
			// CALL C, a16

			break;
		case 0xCD:
			// CALL a16

			break;
		case 0xCF:
			// RST 08H

			break;
		case 0xDF:
			// RST 18H

			break;
		case 0xEF:
			// RST 28H

			break;
		case 0xFF:
			// RST 38H

			break;
		default:
			Opcode_WRONG_GROUP_ERROR(opcode);
			break;
	}
}

void Opcode_BIT(uint8_t opcode) {

}

void Opcode_WRONG_GROUP_ERROR(uint8_t opcode) {
	printf("ERROR: Opcode (0x%02hhX) was detected in wrong group.\n", opcode);
}

// Opcode Fetching & Decoding
// ---------------------------------------------------
uint8_t Opcode_fetch(void) {
	uint8_t result = Memory_load_byte(Registers.PC);
	Registers.PC++;
	return result;
}

void Opcode_decode(uint8_t opcode) {

}