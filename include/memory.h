#ifndef MEMORY_H
#define MEMORY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "timer.h"
#define KILO_BYTE 1024

// Register set
// --------------------------------
//
// 8-bit registers
// --------------------------------
// A: Accumulator
// F: Flags register
// B, C, D, E, H & L: General purpose
//
// 16-bit registers
// --------------------------------
// AF, BC, DE, HL: General purpose (combination of two 8-bit registers)
// SP: Stack pointer
// PC: Program counter
//
// Flags register
// --------------------------------
// 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0
// Z   N   H   C   0   0   0   0 
//
// Z: Zero flag
// N: Subtract flag
// H: Half carry flag
// C: Carry flag

struct {
	union {
		struct {
			uint8_t F;
			uint8_t A;
		};
		uint16_t AF;
	};

	union {
		struct {
			uint8_t C;
			uint8_t B;
		};
		uint16_t BC;
	};

	union {
		struct {
			uint8_t E;
			uint8_t D;
		};
		uint16_t DE;
	};

	union {
		struct {
			uint8_t L;
			uint8_t H;
		};
		uint16_t HL;
	};

	uint16_t SP;
	uint16_t PC;
} Registers;

void Registers_init(void);

// Flag manipulation
// --------------------------------
void Flag_set_Z(uint8_t state);
void Flag_set_N(uint8_t state);
void Flag_set_H(uint8_t state);
void Flag_set_C(uint8_t state);

uint8_t Flag_get_Z(void);
uint8_t Flag_get_N(void);
uint8_t Flag_get_H(void);
uint8_t Flag_get_C(void);


// Memory map
// --------------------------------
// 0000 - 3FFF: 16 kB ROM bank 00
// 4000 - 7FFF: 16 kB ROM bank 01 ~ NN
// 8000 - 9FFF: 8 kB video RAM
// A000 - BFFF: 8 kB external RAM (if any)
// C000 - CFFF: 4 kB work RAM bank 0
// D000 - DFFF: 4 kB work RAM bank 1 ~ N
// E000 - FDFF: Mirror of C000 ~ DDFF (Echo RAM)
// FE00 - FE9F: Sprite attribute table (OAM)
// FEA0 - FEFF: Not usable
// FF00 - FF7F: I/O registers
// FF80 - FFFE: High RAM (HRAM)
// FFFF - FFFF: Interrupts enable register (IE)

struct {	
	struct {
		uint8_t *bank_fixed;
		uint8_t *bank_swap;
	} ROM;

	uint8_t *VRAM;

	uint8_t *EXTRAM;

	struct {
		uint8_t *bank_fixed;
		uint8_t *bank_swap;
	} RAM;

	uint8_t *OAM;

	uint8_t *IO;

	uint8_t *HRAM;

	uint8_t IE;
} Memory;

void Memory_init(void);
void Memory_free(void);

uint8_t Memory_load_byte(uint16_t address);
void Memory_store_byte(uint16_t address, uint8_t data);

#endif // MEMORY_H
