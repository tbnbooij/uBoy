#include "instructions.h"

// Atomic Memory Instructions
// ---------------------------------------------------
void Instruction_LD_R8_R8(uint8_t *r1, uint8_t *r2) {
	Memory_LD_R8_R8(r1, r2);
	Timer_update(4);
}

void Instruction_LD_R8_MR16(uint8_t *r1, uint16_t *r2) {
	Memory_LD_R8_MR16(r1, r2);
	Timer_update(8);
}

void Instruction_LD_R8_MI16(uint8_t *r) {
	uint8_t nn = Memory_LD_I16_ROM();
	Memory_LD_R8_I8(r, nn);
	Timer_update(16);
}

void Instruction_LD_MI16_R8(uint8_t *r) {
	uint16_t nn = Memory_LD_I16_ROM();
	Memory_LD_MI16_R8(nn, r);
	Timer_update(16);
}

void Instruction_LD_R8_I8(uint8_t *r) {
	uint8_t n = Memory_load_byte_PC();
	Memory_LD_R8_I8(r, n);
	Timer_update(8);
}

void Instruction_LD_MR16_R8(uint16_t *r1, uint8_t *r2) {
	Memory_LD_MR16_R8(r1, r2);
	Timer_update(8);
}

void Instruction_LD_MR16_I8(uint16_t *r) {
	uint8_t n = Memory_load_byte_PC();
	Memory_LD_MR16_I8(r, n);
	Timer_update(12);
}

void Instruction_LD_A_MC(void) {
	Memory_LD_R8_MR8(&Registers.A, &Registers.C);
	Timer_update(8);
}

void Instruction_LD_MC_A(void) {
	Memory_LD_MR8_R8(&Registers.C, &Registers.A);
	Timer_update(8);
}

void Instruction_LDD_A_HL(void) {
	Memory_LD_R8_MR16(&Registers.A, &Registers.HL);
	Registers.HL--;
	Timer_update(8);
}

void Instruction_LDD_HL_A(void) {
	Memory_LD_MR16_R8(&Registers.HL, &Registers.A);
	Registers.HL--;
	Timer_update(8);
}

void Instruction_LDI_A_HL(void) {
	Memory_LD_R8_MR16(&Registers.A, &Registers.HL);
	Registers.HL++;
	Timer_update(8);
}

void Instruction_LDI_HL_A(void) {
	Memory_LD_MR16_R8(&Registers.HL, &Registers.A);
	Registers.HL++;
	Timer_update(8);
}

void Instruction_LDH_MI8_A(void) {
	uint8_t n = Memory_load_byte_PC();
	Memory_LD_MI8_R8(n, &Registers.A);
	Timer_update(12);
}

void Instruction_LDH_A_MI8(void) {
	uint8_t n = Memory_load_byte_PC();
	Memory_LD_R8_MI8(&Registers.A, n);
	Timer_update(12);
}

// Jumps & Calls
// ---------------------------------------------------
void Instruction_JP_CC_N(uint8_t test) {
	uint8_t n = Memory_load_byte_PC();

	if (test) {
		Registers.PC += n;
	}
	else  {
		Registers.PC++;
	}	

	Timer_update(8);
}

void Instruction_RET(void) {
	// TODO: Add after dealing with PUSH AND POP
	printf("WARNING: RET has not been implemented yet!\n");
	Timer_update(8);
}

void Instruction_RET_CC(uint8_t test) {
	if (test) {
		Instruction_RET();
	}
	else {
		Timer_update(8);
	}
}