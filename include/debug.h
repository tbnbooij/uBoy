/**
 * @brief A set of debugging functions for testing the emulator.
 * 
 * @file debug.h
 * @author tbnbooij
 * @date 2018-08-13
 */
#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#include "memory.h"

/**
 * @brief Print the state of the emulator (registers, clock, etc.) to stdout.
 * 
 * @param clk The current CPU clock
 */
extern void Debug_print_state(uint64_t clk);

/**
 * @brief Print a slice of the currently loaded ROM to stdout with their respective addresses.
 * 
 * @param begin The 16-bit address at which the slice starts
 * @param end The 16-bit address at which the slide ends
 */
extern void Debug_print_ROM(uint16_t begin, uint16_t end);

#endif // DEBUG_H
