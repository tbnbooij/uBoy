#ifndef MEMORY_H
#define MEMORY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "debug.h"
#define KILO_BYTE 1024

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

// Memory Initialization & Freeing
// ---------------------------------------------------
void Memory_init(void);
void Memory_free(void);

// Atomic Load & Store
// ---------------------------------------------------
uint8_t Memory_load_byte(uint16_t address);
void Memory_store_byte(uint16_t address, uint8_t data);

// Loading immediate operands from ROM
// ---------------------------------------------------
uint8_t Memory_load_byte_PC(void);
uint16_t Memory_load_word_PC(void);

#endif // MEMORY_H
