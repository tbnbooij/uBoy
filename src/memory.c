#include "memory.h"
#include "debug.h"

// MSB and LSB Manipulation (16-bit)
// ---------------------------------------------------
uint8_t Extract_MSB(uint16_t i) {
	return (uint8_t) (i & 0xFF00) >> 8;	
}

uint8_t Extract_LSB(uint16_t i) {
	return (uint8_t) (i & 0x00FF);
}

uint16_t Combine_MSB_LSB(uint8_t msb, uint8_t lsb) {
	uint16_t _msb = (uint16_t) msb;
	uint16_t _lsb = (uint16_t) lsb;

	return (_msb << 8) | _lsb;
}

// Register Initialization
// ---------------------------------------------------
void Registers_init(void) {
	Registers.AF = 0;
	Registers.BC = 0;
	Registers.DE = 0;
	Registers.HL = 0;
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

// Memory Initialization & Freeing
// ---------------------------------------------------
void Memory_init(void) {
	Memory.ROM.bank_fixed = (uint8_t*) malloc(16*KILO_BYTE);
	Memory.ROM.bank_swap = (uint8_t*) malloc(16*KILO_BYTE);
	
	Memory.VRAM = (uint8_t*) malloc(8*KILO_BYTE);

	Memory.EXTRAM = (uint8_t*) malloc(8*KILO_BYTE);
	
	Memory.RAM.bank_fixed = (uint8_t*) malloc(4*KILO_BYTE);
	Memory.RAM.bank_swap = (uint8_t*) malloc(4*KILO_BYTE);

	Memory.OAM = (uint8_t*) malloc(160);

	Memory.IO = (uint8_t*) malloc(128);

	Memory.HRAM = (uint8_t*) malloc(127);

	Memory.IE = 0;
}

void Memory_free(void) {
	free(Memory.ROM.bank_fixed);
	free(Memory.ROM.bank_swap);

	free(Memory.VRAM);

	free(Memory.EXTRAM);

	free(Memory.RAM.bank_fixed);
	free(Memory.RAM.bank_swap);

	free(Memory.OAM);

	free(Memory.IO);

	free(Memory.HRAM);
}

// Atomic Load & Store
// ---------------------------------------------------
uint8_t Memory_load_byte(uint16_t address) {
	if (address <= 0x3FFF) {
		return *(Memory.ROM.bank_fixed + address);
	}
	else if (address <= 0x7FFF) {
		return *(Memory.ROM.bank_swap - 0x4000 + address);
	}
	else if (address <= 0x9FFF) {
		return *(Memory.VRAM - 0x8000 + address);
	}
	else if (address <= 0xBFFF) {
		return *(Memory.EXTRAM - 0xA000 + address);
	}
	else if (address <= 0xCFFF) {
		return *(Memory.RAM.bank_fixed - 0xC000 + address);
	}
	else if (address <= 0xDFFF) {
		return *(Memory.RAM.bank_swap - 0xD000 + address);
	}
	else if (address <= 0xEFFF) {
		return *(Memory.RAM.bank_fixed - 0xE000 + address);
	}
	else if (address <= 0xFDFF) {
		return *(Memory.RAM.bank_fixed - 0xF000 + address);
	}
	else if (address <= 0xFE9F) {
		return *(Memory.OAM - 0xFE00 + address);
	}
	else if (address <= 0xFEFF) {
		printf("ERROR: Trying to read from unusable memory.\n");
		exit(EXIT_FAILURE);
	}
	else if (address <= 0xFF7F) {
		return *(Memory.IO - 0xFF00 + address);
	}
	else if (address <= 0xFFFE) {
		return *(Memory.HRAM - 0xFF80 + address);
	}
	else {
		return Memory.IE;
	}
}	

uint8_t Memory_load_byte_PC(void) {
	uint8_t result = Memory_load_byte(Registers.PC);
	Registers.PC++;
	return result;
}

void Memory_store_byte(uint16_t address, uint8_t data) {
	if (address <= 0x7FFF) {
		printf("ERROR: Trying to write to ROM.\n");
		exit(EXIT_FAILURE);
	}
	else if (address <= 0x9FFF) {
		*(Memory.VRAM - 0x8000 + address) = data;
	}
	else if (address <= 0xBFFF) {
		*(Memory.EXTRAM - 0xA000 + address) = data;
	}
	else if (address <= 0xCFFF) {
		*(Memory.RAM.bank_fixed - 0xC000 + address) = data;
	}
	else if (address <= 0xDFFF) {
		*(Memory.RAM.bank_swap - 0xD000 + address) = data;
	}
	else if (address <= 0xEFFF) {
		*(Memory.RAM.bank_fixed - 0xE000 + address) = data;
	}
	else if (address <= 0xFDFF) {
		*(Memory.RAM.bank_fixed - 0xF000 + address) = data;
	}
	else if (address <= 0xFE9F) {
		*(Memory.OAM - 0xFE00 + address) = data;
	}
	else if (address <= 0xFEFF) {
		printf("ERROR: Trying to write to unusable memory.\n");
		exit(EXIT_FAILURE);
	}
	else if (address <= 0xFF7F) {
		*(Memory.IO - 0xFF00 + address) = data;
	}
	else if (address <= 0xFFFE) {
		*(Memory.HRAM - 0xFF80 + address) = data;
	}
	else {
		Memory.IE = data;
	}
}

// Loading immediate operands from ROM
// ---------------------------------------------------
uint16_t Memory_load_word_PC(void) {
	uint16_t lsb = (uint16_t) Memory_load_byte_PC();
	uint16_t msb = (uint16_t) Memory_load_byte_PC();

	return (msb << 8) | lsb;
}