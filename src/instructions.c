#include "instructions.h"

// Loading immediate operands from ROM
// ---------------------------------------------------

uint8_t Instruction_LD_I8_ROM(void) {
	Registers.PC++;
	uint8_t result = Memory_load_byte(Registers.PC);
	return result;
}

uint16_t Instruction_LD_I16_ROM(void) {
	Registers.PC++;
	uint16_t msb = (uint16_t) Memory_load_byte(Registers.PC);

	Registers.PC++;
	uint16_t lsb = (uint16_t) Memory_load_byte(Registers.PC);

	return (msb << 8) | lsb;
}

// 8-bit Loads
// ---------------------------------------------------

// 8-bit Register-Register Loads
void Instruction_LD_R8_R8(uint8_t *r1, uint8_t *r2) {
	*r1 = *r2;
}

void Instruction_LD_R8_R16(uint8_t *r1, uint16_t *r2) {
	*r1 = (uint8_t) *r2;
}

void Instruction_LD_R16_R8(uint16_t *r1, uint8_t *r2) {
	*r1 = (uint16_t) *r2;
}

// 8-bit Register-Immediate Loads
void Instruction_LD_R8_I8(uint8_t *r, uint8_t i) {
	*r = i;
}

// 8-bit Register-Memory Interaction
void Instruction_LD_R8_MR8(uint8_t *r1, uint8_t *r2) {
	*r1 = Memory_load_byte(0xFF00 + (uint16_t) *r2);
}

void Instruction_LD_MR8_R8(uint8_t *r1, uint8_t *r2) {
	Memory_store_byte(0xFF00 + (uint16_t) *r1, *r2);
}

void Instruction_LD_R8_MR16(uint8_t *r1, uint16_t *r2) {
	*r1 = Memory_load_byte(*r2);
}

void Instruction_LD_MR16_R8(uint16_t *r1, uint8_t *r2) {
	Memory_store_byte(*r1, *r2); 
};

// 8-bit Register-Immediate-Memory Interaction
void Instruction_LD_MI8_R8(uint8_t i, uint8_t *r) {
	Memory_store_byte(0xFF00 + (uint16_t) i, *r);
}

void Instruction_LD_R8_MI8(uint8_t *r, uint8_t i) {
	*r = Memory_load_byte(0xFF00 + (uint16_t) i);
}

// 16-bit Loads
// ---------------------------------------------------

// 16-bit Register-Immediate Loads
void Instruction_LD_R16_I16(uint16_t *r, uint16_t i) {
	*r = i;
}

// 16-bit Register-Register Loads
void Instruction_LD_R16_R16(uint16_t *r1, uint16_t *r2) {
	*r1 = *r2;
}

// 16-bit Register-Register-Immediate-Sum Load
void Instruction_LD_R16_R16_I8(uint16_t *r1, uint16_t *r2, uint8_t i) {
	*r1 = *r2 + i;
}

// Jumps & Calls
// ---------------------------------------------------
void Instruction_JP_CC_N(uint8_t test) {
	uint8_t n = Instruction_LD_I8_ROM();

	if (test) {
		Registers.PC += n;
	}
	else  {
		Registers.PC++;
	}	

	Timer_update(2);
}

void Instruction_RET(void) {
	// TODO: Add after dealing with PUSH AND POP
	printf("WARNING: RET has not been implemented yet!\n");
	Timer_update(2);
}

void Instruction_RET_CC(uint8_t test) {
	if (test) {
		Instruction_RET();
	}
	else {
		Timer_update(2);
	}
}