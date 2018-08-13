/**
 * @brief Representation of the state of the emulator (registers, CPU mode, flags) 
 * and a set of utility functions.
 * 
 * @file state.h
 * @author tbnbooij
 * @date 2018-08-13
 */
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

/**
 * @brief Initialize the state of the emulator (registers, CPU mode, flags).
 * 
 */
extern void State_init(void);

/**
 * @brief Extract the most significant byte of an unsigned 16-bit constant.
 * 
 * @param i Unsigned 16-bit constant
 * @return uint8_t The most significant byte of i
 */
extern uint8_t Extract_MSB(uint16_t i);

/**
 * @brief Extract the least significant byte of an unsigned 16-bit constant.
 * 
 * @param i Unsigned 16-bit constant
 * @return uint8_t The least significant byte of i
 */
extern uint8_t Extract_LSB(uint16_t i);

/**
 * @brief Combine two unsigned bytes into an unsigned 16-bit value.
 * 
 * @param msb The most significant byte
 * @param lsb The least significant byte
 * @return uint16_t The combination of the two input bytes
 */
extern uint16_t Combine_MSB_LSB(uint8_t msb, uint8_t lsb);

/**
 * @brief Initialize the values of the CPU registers.
 * 
 */
extern void Registers_init(void);

/**
 * @brief Set the Z-flag to a given value (0 or 1). 
 * 
 * @param state The state (0 or 1) that the Z-flag is set to
 */
extern void Flag_set_Z(uint8_t state);

/**
 * @brief Set the N-flag to a given value (0 or 1). 
 * 
 * @param state The state (0 or 1) that the N-flag is set to
 */
extern void Flag_set_N(uint8_t state);

/**
 * @brief Set the H-flag to a given value (0 or 1). 
 * 
 * @param state The state (0 or 1) that the H-flag is set to
 */
extern void Flag_set_H(uint8_t state);

/**
 * @brief Set the C-flag to a given value (0 or 1). 
 * 
 * @param state The state (0 or 1) that the C-flag is set to
 */
extern void Flag_set_C(uint8_t state);

/**
 * @brief Set the flags in the F-register to given values (0 = reset, 1 = set, -1 = don't care).
 * 
 * @param Z The state (0/1/-1) that the Z-flag is set to
 * @param N The state (0/1/-1) that the N-flag is set to
 * @param H The state (0/1/-1) that the H-flag is set to
 * @param C The state (0/1/-1) that the C-flag is set to
 */
extern void Flags_set(uint8_t Z, uint8_t N, uint8_t H, uint8_t C);

/**
 * @brief Test for a halfcarry in the addition or substraction of two unsigned 8-bit constants.
 * 
 * @param a Unsigned 8-bit constant
 * @param b Unsigned 8-bit constant
 * @param add The operation that is applied to the two constants (subtraction = 0, addition = 1)
 * @return uint8_t Boolean that represents whether a halfcarry occurs or not
 */
extern uint8_t Flag_test_H_U8_U8(uint8_t a, uint8_t b, uint8_t add);

/**
 * @brief Test for a carry in the addition or substraction of two unsigned 8-bit constants.
 * 
 * @param a Unsigned 8-bit constant
 * @param b Unsigned 8-bit constant
 * @param add The operation that is applied to the two constants (subtraction = 0, addition = 1)
 * @return uint8_t Boolean that represents whether a carry occurs or not
 */
extern uint8_t Flag_test_C_U8_U8(uint8_t a, uint8_t b, uint8_t add);

/**
 * @brief Test for a halfcarry (bit 11 to 12) in the addition an unsigned 16-bit constant and a signed 8-bit constant.
 * 
 * @param a Unsigned 16-bit constant
 * @param b Signed 8-bit constant
 * @return uint8_t Boolean that represents whether a halfcarry occurs or not
 */
extern uint8_t Flag_test_H_U16_S8(uint16_t a, int8_t b);

/**
 * @brief Test for a carry (bit 15 to "16") in the addition an unsigned 16-bit constant and a signed 8-bit constant.
 * 
 * @param a Unsigned 16-bit constant
 * @param b Signed 8-bit constant
 * @return uint8_t Boolean that represents whether a carry occurs or not
 */
extern uint8_t Flag_test_C_U16_S8(uint16_t a, int8_t b);

/**
 * @brief Test for a halfcarry in the addition of two unsigned 16-bit constants.
 * 
 * @param a Unsigned 16-bit constant
 * @param b Unsigned 16-bit constant
 * @return uint8_t Boolean that represents whether a halfcarry occurs or not
 */
extern uint8_t Flag_test_H_U16_U16(uint16_t a, uint16_t b);

/**
 * @brief Test for a carry in the addition of two unsigned 16-bit constants.
 * 
 * @param a Unsigned 16-bit constant
 * @param b Unsigned 16-bit constant
 * @return uint8_t Boolean that represents whether a carry occurs or not
 */
extern uint8_t Flag_test_C_U16_U16(uint16_t a, uint16_t b);

/**
 * @brief Return the value of the Z-flag.
 * 
 * @return uint8_t The value of the Z-flag
 */
extern uint8_t Flag_get_Z(void);

/**
 * @brief Return the value of the N-flag.
 * 
 * @return uint8_t The value of the N-flag
 */
extern uint8_t Flag_get_N(void);

/**
 * @brief Return the value of the H-flag.
 * 
 * @return uint8_t The value of the H-flag
 */
extern uint8_t Flag_get_H(void);

/**
 * @brief Return the value of the C-flag.
 * 
 * @return uint8_t The value of the C-flag
 */
extern uint8_t Flag_get_C(void);

#endif // STATE_H