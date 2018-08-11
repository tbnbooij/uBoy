#include "state.h"

void State_init(void) {
	Registers_init();
	State.mode = MODE_RUN;
	State.IME = 1;
}

// MSB and LSB Manipulation (16-bit)
// ---------------------------------------------------
uint8_t Extract_MSB(uint16_t i) {
	return i >> 8;	
}

uint8_t Extract_LSB(uint16_t i) {
	return (i & 0x00FF);
}

uint16_t Combine_MSB_LSB(uint8_t msb, uint8_t lsb) {
	uint16_t _msb = (uint16_t) msb;
	uint16_t _lsb = (uint16_t) lsb;

	return (_msb << 8) | _lsb;
}

// Register Initialization
// ---------------------------------------------------
void Registers_init(void) {
	Registers.AF = 0x01B0;
	Registers.BC = 0x0013;
	Registers.DE = 0x00D8;
	Registers.HL = 0x014D;
	Registers.PC = 0x100;
	Registers.SP = 0xFFFE;
}

// Flag manipulation
// --------------------------------
void Flag_set_Z(uint8_t state) {
	Registers.F = (state << 7) | Registers.F;
}

void Flag_set_N(uint8_t state) {
	Registers.F = (state << 6) | Registers.F;
}

void Flag_set_H(uint8_t state) {
	Registers.F = (state << 5) | Registers.F;
}

void Flag_set_C(uint8_t state) {
	Registers.F = (state << 4) | Registers.F;
}

void Flags_set(uint8_t Z, uint8_t N, uint8_t H, uint8_t C) {
	if (Z != -1) Flag_set_Z(Z);
	if (N != -1) Flag_set_N(N);
	if (H != -1) Flag_set_H(H);
	if (C != -1) Flag_set_C(C);
}

uint8_t Flag_test_H_U8_U8(uint8_t a, uint8_t b, uint8_t add) {
	if (add == 1)
		return (uint8_t) ((((a & 0xF) + (b & 0xF)) & 0x10) == 0x10);
	else
		return (uint8_t) ((a & 0xF) > (b & 0xF));
}

uint8_t Flag_test_C_U8_U8(uint8_t a, uint8_t b, uint8_t add) {
	if (add == 1)
		return (uint8_t) (((uint16_t) (a + b)) > 0xFF);
	else 
		return (uint8_t) (a > b);
}


uint8_t Flag_test_H_U16_S8(uint16_t a, int8_t b) {
	if (b >= 0) {
		return (uint8_t) ((((a & 0xF) + (b & 0xF)) & 0x10) == 0x10);
	}
	else {
		return (uint8_t) ((a & 0xF) < abs(b & 0xF));
	}
}

uint8_t Flag_test_C_U16_S8(uint16_t a, int8_t b) {
	if (b >= 0) {
		return 0;
	}
	else {
		return (uint8_t) (Extract_LSB(a) < abs(b));
	}
}

uint8_t Flag_test_H_U16_U16(uint16_t a, uint16_t b) {
	return (uint8_t) ((((a & 0x0FFF) + (b & 0x0FFF)) & 0x1000) == 0x1000);
}

uint8_t Flag_test_C_U16_U16(uint16_t a, uint16_t b) {
	return (uint8_t) ((((uint32_t) a) + ((uint32_t) b)) > 0xFFFF);
}


uint8_t Flag_get_Z(void) {
	return (Registers.F & 0x80) >> 7;
}

uint8_t Flag_get_N(void) {
	return (Registers.F & 0x40) >> 6;
}

uint8_t Flag_get_H(void) {
	return (Registers.F & 0x20) >> 5;
}

uint8_t Flag_get_C(void) {
	return (Registers.F & 0x10) >> 4;
}