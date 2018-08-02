#include "memory.h"
#include "debug.h"

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
uint8_t Memory_LD_I8_ROM(void) {
	return Memory_load_byte_PC();
}

uint16_t Memory_LD_I16_ROM(void) {
	uint16_t lsb = (uint16_t) Memory_load_byte_PC();
	uint16_t msb = (uint16_t) Memory_load_byte_PC();

	return (msb << 8) | lsb;
}

// 8-bit Loads
// ---------------------------------------------------
// 8-bit Register-Register Loads
void Memory_LD_R8_R8(uint8_t *r1, uint8_t *r2) {
	*r1 = *r2;
}

void Memory_LD_R8_R16(uint8_t *r1, uint16_t *r2) {
	*r1 = (uint8_t) *r2;
}

void Memory_LD_R16_R8(uint16_t *r1, uint8_t *r2) {
	*r1 = (uint16_t) *r2;
}

// 8-bit Register-Immediate Loads
void Memory_LD_R8_I8(uint8_t *r, uint8_t i) {
	*r = i;
}

// 8-bit Register-Memory Interaction
void Memory_LD_R8_MR8(uint8_t *r1, uint8_t *r2) {
	*r1 = Memory_load_byte(0xFF00 + (int8_t) *r2);
}

void Memory_LD_MR8_R8(uint8_t *r1, uint8_t *r2) {
	Memory_store_byte(0xFF00 + (int8_t) *r1, *r2);
}

void Memory_LD_R8_MR16(uint8_t *r1, uint16_t *r2) {
	*r1 = Memory_load_byte(*r2);
}

void Memory_LD_MR16_R8(uint16_t *r1, uint8_t *r2) {
	Memory_store_byte(*r1, *r2); 
};

// 8-bit Register-Immediate-Memory Interaction
void Memory_LD_MI8_R8(uint8_t i, uint8_t *r) {
	Memory_store_byte(0xFF00 + (int8_t) i, *r);
}

void Memory_LD_R8_MI8(uint8_t *r, uint8_t i) {
	*r = Memory_load_byte(0xFF00 + (int8_t) i);
}

void Memory_LD_MR16_I8(uint16_t *r, uint8_t n) {
	Memory_store_byte(*r, n);
}

void Memory_LD_MI16_R8(uint16_t nn, uint8_t *r) {
	Memory_store_byte(nn, *r);
}

// 16-bit Loads
// ---------------------------------------------------

// 16-bit Register-Immediate Loads
void Memory_LD_R16_I16(uint16_t *r, uint16_t i) {
	*r = i;
}

// 16-bit Register-Register Loads
void Memory_LD_R16_R16(uint16_t *r1, uint16_t *r2) {
	*r1 = *r2;
}

// 16-bit Register-Register-Immediate-Sum Load
void Memory_LD_R16_R16_I8(uint16_t *r1, uint16_t *r2, uint8_t i) {
	*r1 = *r2 + i;
}
