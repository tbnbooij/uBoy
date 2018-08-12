#ifndef MEMORY_H
#define MEMORY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "debug.h"
#include "state.h"
#define KILO_BYTE 1024

struct
{
	struct
	{
		uint8_t *bank_fixed;
		uint8_t *bank_swap;
	} ROM;

	uint8_t *VRAM;

	uint8_t *EXTRAM;

	struct
	{
		uint8_t *bank_fixed;
		uint8_t *bank_swap;
	} RAM;

	uint8_t *OAM;

	uint8_t *IO;

	uint8_t *HRAM;

	uint8_t IE;
} Memory;

struct
{
    uint8_t P1;
    uint8_t SB;
    uint8_t SC;
    uint8_t DIV;
    uint8_t TIMA;
    uint8_t TMA;
    uint8_t TAC;
    uint8_t IF;
    uint8_t IE;
    uint8_t NR10;
    uint8_t NR11;
    uint8_t NR12;
    uint8_t NR13;
    uint8_t NR14;
    uint8_t NR21;
    uint8_t NR22;
    uint8_t NR23;
    uint8_t NR24;
    uint8_t NR30;
    uint8_t NR31;
    uint8_t NR32;
    uint8_t NR33;
    uint8_t NR34;
    uint8_t NR41;
    uint8_t NR42;
    uint8_t NR43;
    uint8_t NR44;
    uint8_t NR50;
    uint8_t NR51;
    uint8_t NR52;
    uint8_t WAVE[16];
    uint8_t LCDC;
    uint8_t STAT;
    uint8_t SCY;
    uint8_t SCX;
    uint8_t LY;
    uint8_t LYC;
    uint8_t DMA;
    uint8_t BGP;
    uint8_t OBP0;
    uint8_t OBP1;
    uint8_t WY;
    uint8_t WX;
} IO_Registers;

extern void Memory_init(void);
extern void Memory_exit(void);

extern uint8_t Memory_load_byte(uint16_t address);
extern void Memory_store_byte(uint16_t address, uint8_t data);

extern uint8_t Memory_load_byte_PC(void);
extern uint16_t Memory_load_word_PC(void);

extern void IO_init(void);
static void IO_store_byte(uint16_t address, uint8_t data);
static uint8_t IO_read_byte(uint16_t address);

#endif // MEMORY_H
