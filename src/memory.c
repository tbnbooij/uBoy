#include "memory.h"

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
	else if (address <= 0xFF7F || address == 0xFFFF) {
		return IO_read_byte(address);
	}
	else {
		return *(Memory.HRAM - 0xFF80 + address);
	}
}	

void Memory_store_byte(uint16_t address, uint8_t data) {
	if (address <= 0x7FFF) {
		MBC_store_byte(address, data);
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
		//printf("WARNING: Trying to write to unusable memory. (0x%04hX)\n", address);
	}
	else if (address <= 0xFF7F) {
		IO_store_byte(address, data);
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
uint8_t Memory_load_byte_PC(void) {
	uint8_t result = Memory_load_byte(Registers.PC);
	Registers.PC++;
	return result;
}

uint16_t Memory_load_word_PC(void) {
	uint16_t lsb = (uint16_t) Memory_load_byte_PC();
	uint16_t msb = (uint16_t) Memory_load_byte_PC();

	return (msb << 8) | lsb;
}

// Memory Bank Controller
// ---------------------------------------------------
void MBC_init(void) {

}

void MBC_store_byte(uint16_t address, uint8_t data) {

}