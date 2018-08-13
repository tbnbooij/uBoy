/**
 * @brief Representation of the Game Boy's memory model and operations
 * to read and write to this memory.
 * 
 * @file memory.h
 * @author tbnbooij
 * @date 2018-08-13
 */
#ifndef MEMORY_H
#define MEMORY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "debug.h"
#include "state.h"
#define KILO_BYTE 1024 /**< Size of a kilobyte in bytes */

/**
 * @brief Struct that represents the memory model of the emulator.
 * 
 */
struct
{
	struct
	{
		uint8_t *bank_fixed; /**< 8 kB block of ROM that cannot be swapped by a memory bank controller (0x0000-0x3FFF) */
		uint8_t *bank_swap; /**< 8 kB block of ROM that may be swapped by the memory bank controller (0x4000-0x7FFF) **/
	} ROM; /**< The read-only memory as stored in the game cartrige and (potentially) controlled by a memory bank controller */

	uint8_t *VRAM; /**< The video RAM of the Game Boy (0x8000-0x9FFF) */

	uint8_t *EXTRAM; /**< External RAM that may or may not be provided by a game cartridge (0xA000-0xBFFF) */

	struct
	{
		uint8_t *bank_fixed; /**< 4 kB of internal RAM that cannot be swapped by an internal memory bank controller (0xC000-0xCFFF) */
		uint8_t *bank_swap; /**< 4 kB of internal RAM that may be swapped by an internal memory bank controller (CGB only; 0xD000-0xDFFF) */
	} RAM; /**< Internal RAM of the Game Boy (0xC000-0xDFFF) */

	uint8_t *OAM; /**< Object Attribute Memory, stores the state of the sprites (0xFE00-0xFE9F) */

	uint8_t *HRAM; /**< High RAM/Zero page (0xFF80-0xFFFE) */

	uint8_t IE; /**< Interrupt enable flag (0xFFFF) */
} Memory;

/**
 * @brief The hardware registers in the IO-section of the memory model (0xFF00-0xFF7F)
 * 
 */
struct
{
    uint8_t P1; /**< (0xFF00) Register for reading joy pad info and determining system type (R/W) */
    uint8_t SB; /**< (0xFF01) Serial transfer data (R/W) */
    uint8_t SC; /**< (0xFF02) SIO control (R/W) */
    uint8_t DIV; /**< (0xFF03) Divider register (R/W) */
    uint8_t TIMA; /**< (0xFF05) Timer counter (R/W) */
    uint8_t TMA; /**< (0xFF06) Timer modulo (R/W) */
    uint8_t TAC; /**< (0xFF07) Timer control (R/W) */
    uint8_t IF; /**< (0xFF0F) Interrupt flag (R/W) */
    uint8_t IE; /**< (0xFFFF) Interrupt enable flag (R/W) */
    uint8_t NR10; /**< (0xFF10) Sound mode 1 register; sweep register (R/W) */
    uint8_t NR11; /**< (0xFF11) Sound mode 1 register; sound length/wave pattern duty (R/W) */
    uint8_t NR12; /**< (0xFF12) Sound mode 1 register; envelope (R/W) */
    uint8_t NR13; /**< (0xFF13) Sound mode 1 register; frequency lo (W) */
    uint8_t NR14; /**< (0xFF14) Sound mode 1 register; frequency hi (W) */
    uint8_t NR21; /**< (0xFF16) Sound mode 2 register; sound length/wave pattern duty (R/W) */
    uint8_t NR22; /**< (0xFF17) Sound mode 2 register; envelope (R/W) */
    uint8_t NR23; /**< (0xFF18) Sound mode 2 register; frequency lo (W) */
    uint8_t NR24; /**< (0xFF19) Sound mode 2 register; frequency hi (R/W) */
    uint8_t NR30; /**< (0xFF1A) Sound mode 3 register; sound on/off (R/W) */
    uint8_t NR31; /**< (0xFF1B) Sound mode 3 register; sound length (R/W) */
    uint8_t NR32; /**< (0xFF1C) Sound mode 3 register, select output level (R/W) */
    uint8_t NR33; /**< (0xFF1D) Sound mode 3 register; frequency lo (W) */
    uint8_t NR34; /**< (0xFF1E) Sound mode 3 register; frequency hi (R/W) */
    uint8_t NR41; /**< (0xFF20) Sound mode 4 register; sound length (R/W) */
    uint8_t NR42; /**< (0xFF21) Sound mode 4 register; envelope (R/W) */
    uint8_t NR43; /**< (0xFF22) Sound mode 4 register; polynomial counter (R/W) */
    uint8_t NR44; /**< (0xFF23) Sound mode 4 register; counter/consecutive; initial (R/W) */
    uint8_t NR50; /**< (0xFF24) Channel control / ON-OFF / volume (R/W) */
    uint8_t NR51; /**< (0xFF25) Selection of sound output terminal (R/W) */
    uint8_t NR52; /**< (0xFF26) Sound on/off (R/W) */
    uint8_t WAVE[16]; /**< (0xFF30-0xFF3F) Waveform storage for arbitrary sound data */
    uint8_t LCDC; /**< (0xFF40) LCD control (R/W) */
    uint8_t STAT; /**< (0xFF41) LCDC status (R/W) */
    uint8_t SCY; /**< (0xFF42) Scroll Y (R/W) */
    uint8_t SCX; /**< (0xFF43) Scroll X (R/W) */
    uint8_t LY; /**< (0xFF44) LCDC Y-coordinate (R/W) */
    uint8_t LYC; /**< (0xFF45) LY compare (R/W) */
    uint8_t DMA; /**< (0xFF46) DMA transfer and start address (W) */
    uint8_t BGP; /**< (0xFF47) Background and window palette data (R/W) */
    uint8_t OBP0; /**< (0xFF48) Object palette 0 data (R/W) */
    uint8_t OBP1; /**< (0xFF49) Object palette 1 data (R/W) */
    uint8_t WY; /**< (0xFF4A) Window Y position (R/W) */
    uint8_t WX; /**< (0xFF4B) Window X position (R/W) */
} IO_Registers; 

/**
 * @brief Allocate the emulator's memory and initialize special registers.
 * 
 */
extern void Memory_init(void);

/**
 * @brief Free the allocated memory.
 * 
 */
extern void Memory_exit(void);

/**
 * @brief Load a byte from the emulator's memory.
 * 
 * @param address The 16-bit address of the read byte
 * @return uint8_t The value at the given address
 */
extern uint8_t Memory_load_byte(uint16_t address);

/**
 * @brief Store a byte in the emulator's memory.
 * 
 * @param address The 16-bit address where the byte will be stored
 * @param data The value that will be stored
 */
extern void Memory_store_byte(uint16_t address, uint8_t data);

/**
 * @brief Load the byte at the program counter and increment the program counter.
 * 
 * @return uint8_t The value at the program counter
 */
extern uint8_t Memory_load_byte_PC(void);

/**
 * @brief Load the 16-bit word (LSB first) at the program counter and increment the program counter accordingly.
 * 
 * @return uint16_t The 16-bit value read at the program counter
 */
extern uint16_t Memory_load_word_PC(void);

/**
 * @brief Initialize the special registers in the IO-section (0xFF00-0xFF7F) of the memory model.
 * 
 */
extern void IO_init(void);

/**
 * @brief Store a byte in the IO-section (0xFF00-0xFF7F) of the memory model.
 * 
 * @param address The address of a byte in the IO-section 
 * @param data The value to be stored
 */
static void IO_store_byte(uint16_t address, uint8_t data);

/**
 * @brief Load a byte from the IO-section (0xFF00-0xFF7F) of the memory model.
 * 
 * @param address The address of a byte in the IO-section
 * @return uint8_t The value at the given address
 */
static uint8_t IO_load_byte(uint16_t address);

#endif // MEMORY_H
