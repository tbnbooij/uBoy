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
			Timer_update(1);
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