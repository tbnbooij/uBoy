#ifndef STATE_H
#define STATE_H
#include <stdint.h>
#include <stdlib.h>
#define MODE_RUN 0
#define MODE_HALT 1
#define MODE_STOP 2

struct
{
	uint8_t mode;
	uint8_t IME;
} State;

struct
{
	char name[17];
	uint8_t CGB_flag;
	uint8_t cartridge_type;
	uint8_t ROM_size;
	uint8_t RAM_size;
	uint8_t destination;
} Cartridge;

struct
{
	union {
		struct
		{
			uint8_t F;
			uint8_t A;
		};
		uint16_t AF;
	};

	union {
		struct
		{
			uint8_t C;
			uint8_t B;
		};
		uint16_t BC;
	};

	union {
		struct
		{
			uint8_t E;
			uint8_t D;
		};
		uint16_t DE;
	};

	union {
		struct
		{
			uint8_t L;
			uint8_t H;
		};
		uint16_t HL;
	};

	uint16_t SP;
	uint16_t PC;
} Registers;

extern void State_init(void);

extern uint8_t Extract_MSB(uint16_t i);
extern uint8_t Extract_LSB(uint16_t i);
extern uint16_t Combine_MSB_LSB(uint8_t msb, uint8_t lsb);

extern void Registers_init(void);

extern void Flag_set_Z(uint8_t state);
extern void Flag_set_N(uint8_t state);
extern void Flag_set_H(uint8_t state);
extern void Flag_set_C(uint8_t state);

extern void Flags_set(uint8_t Z, uint8_t N, uint8_t H, uint8_t C);

extern uint8_t Flag_test_H_U8_U8(uint8_t a, uint8_t b, uint8_t add);
extern uint8_t Flag_test_C_U8_U8(uint8_t a, uint8_t b, uint8_t add);
extern uint8_t Flag_test_H_U16_S8(uint16_t a, int8_t b);
extern uint8_t Flag_test_C_U16_S8(uint16_t a, int8_t b);
extern uint8_t Flag_test_H_U16_U16(uint16_t a, uint16_t b);
extern uint8_t Flag_test_C_U16_U16(uint16_t a, uint16_t b);

extern uint8_t Flag_get_Z(void);
extern uint8_t Flag_get_N(void);
extern uint8_t Flag_get_H(void);
extern uint8_t Flag_get_C(void);

#endif // STATE_H