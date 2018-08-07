#ifndef STATE_H
#define STATE_H
#include <stdint.h>
#include <stdlib.h>
#define MODE_RUN  0
#define MODE_HALT 1
#define MODE_STOP 2

void State_init(void);

struct {
    uint8_t mode;
	uint8_t IME;
} State;

struct {
    uint64_t t;
} Timer;

struct {
	char name[17];
	uint8_t CGB_flag;
	uint8_t cartridge_type;
	uint8_t ROM_size;
	uint8_t RAM_size;
	uint8_t destination;
} Cartridge;

// Extraction of MSB and LSB (16-bit)
// ---------------------------------------------------
uint8_t Extract_MSB(uint16_t i);
uint8_t Extract_LSB(uint16_t i);
uint16_t Combine_MSB_LSB(uint8_t msb, uint8_t lsb);

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

// Register Initialization
// ---------------------------------------------------
void Registers_init(void);

// Flag manipulation
// --------------------------------
void Flag_set_Z(uint8_t state);
void Flag_set_N(uint8_t state);
void Flag_set_H(uint8_t state);
void Flag_set_C(uint8_t state);

void Flags_set(uint8_t Z, uint8_t N, uint8_t H, uint8_t C);

uint8_t Flag_test_H_U8_U8(uint8_t a, uint8_t b, uint8_t add);
uint8_t Flag_test_C_U8_U8(uint8_t a, uint8_t b, uint8_t add);
uint8_t Flag_test_H_U16_S8(uint16_t a, int8_t b);
uint8_t Flag_test_C_U16_S8(uint16_t a, int8_t b);
uint8_t Flag_test_H_U16_U16(uint16_t a, uint16_t b);
uint8_t Flag_test_C_U16_U16(uint16_t a, uint16_t b);

uint8_t Flag_get_Z(void);
uint8_t Flag_get_N(void);
uint8_t Flag_get_H(void);
uint8_t Flag_get_C(void);

#endif // STATE_H