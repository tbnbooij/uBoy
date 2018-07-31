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
	uint8_t JP[30] =   {0x20, 0x30, 0xC0, 0xD0, 
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

}

void Opcode_JP(uint8_t opcode) {

}

void Opcode_BIT(uint8_t opcode) {

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