/**
 * @brief The Central Processing Unit of the emulator, which is connected to
 * all other virtual components. 
 * 
 * @file cpu.h
 * @author tbnbooij
 * @date 2018-08-13
 */
#ifndef CPU_H
#define CPU_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "state.h"
#include "memory.h"
#include "instructions.h"
#include "debug.h"
#include "ppu.h"

/**
 * @brief Struct that contains state variables of the CPU
 * only to be accessed within CPU.c
 * 
 */
static struct 
{
    FILE *source; /**< File pointer to the .gb file that is loaded to ROM */
    uint64_t clk; /**< 64-bit unsigned clock that records the number of passed 'ticks' caused by program execution */
} CPU;

/**
 * @brief Initialize the CPU and link CPU_exit() to the 'atexit' function queue.
 * 
 */
extern void CPU_init(void);

/**
 * @brief Open the ROM-file at a given relative file path and call CPU_init_modules() and File_load_rom().
 * 
 * @param filepath The relative path to a (.gb) ROM-file
 */
extern void CPU_input(char *filepath);

/**
 * @brief Initialize the external modules of the CPU (memory, state, IO, opcodes, PPU).
 * 
 */
static void CPU_init_modules(void);

/**
 * @brief Start ROM execution. Currently returns a command-line interface for debugging purposes.
 * 
 */
extern void CPU_start(void);

/**
 * @brief Execute the opcode at the program counter.
 * 
 */
static void CPU_next(void);

/**
 * @brief Free allocated memory by calling Memory_exit() and PPU_exit() and closing all file streams.
 * 
 */
extern void CPU_exit(void);

/**
 * @brief Read a byte from CPU.source (file) at a given 16-bit address.
 * 
 * @param address An unsigned 16-bit address
 * @return uint8_t The value at the given address
 */
static uint8_t File_read_byte(uint16_t address);

/**
 * @brief Copy the contents of the file stream to the allocated memory by the Memory-module.
 * 
 */
static void File_load_rom(void);

/**
 * @brief Read the cartridge header and store the results in the Cartridge-struct (State-module).
 * 
 */
static void File_read_header(void);

/**
 * @brief Update the CPU clock by a given number of 'ticks'.
 * 
 * @param delta The number of 'ticks' by which the CPU is updated.
 */
static void CPU_clock_update(int8_t delta);

/**
 * @brief Initialize the opcode tables. 
 * 
 */
static void Opcodes_init(void);

/**
 * @brief Fetch the opcode at the memory location the program counter is pointing to.
 * 
 * @return uint8_t The opcode at the program counter
 */
static uint8_t Opcode_fetch(void);

/**
 * @brief Execute the instruction a given opcode describes.
 * 
 * @param opcode The opcode of the instruction that will be executed
 */
static void Opcode_decode(uint8_t opcode);

/**
 * @brief Execute an instruction that is prefixed by opcode 0xCB.
 * 
 * @param opcode The read opcode after 0xCB.
 */
static void CBOpcode_decode(uint8_t opcode);

/**
 * @brief The main opcode table, containing pointers to functions for each and every instruction.
 * 
 */
static void (*Opcodes[0xFF + 1])(void);

/**
 * @brief The opcode table used for instructions prefixed by 0xCB, 
 * containing pointers to functions for each and every instruction.
 * 
 */
static void (*CBOpcodes[0xFF + 1])(void);

/**
 * @brief Called by opcodes that haven't been implemented yet; used as a debugging aid.
 * 
 * @param opcode The opcode for the instruction that has not been implemented yet
 */
static void Opcode_not_implemented(uint8_t opcode);

/**
 * @brief Called by 0xCD-prefixed opcodes that haven't been implemented yet; used as a debugging aid.
 * 
 * @param opcode The opcode for the instruction that has not been implemented yet
 */
static void CBOpcode_not_implemented(uint8_t opcode);



#ifndef DOXYGEN_SHOULD_SKIP_THIS

static void Opcode_0x00(void);
static void Opcode_0x01(void);
static void Opcode_0x02(void);
static void Opcode_0x03(void);
static void Opcode_0x04(void);
static void Opcode_0x05(void);
static void Opcode_0x06(void);
static void Opcode_0x07(void);
static void Opcode_0x08(void);
static void Opcode_0x09(void);
static void Opcode_0x0A(void);
static void Opcode_0x0B(void);
static void Opcode_0x0C(void);
static void Opcode_0x0D(void);
static void Opcode_0x0E(void);
static void Opcode_0x0F(void);
static void Opcode_0x10(void);
static void Opcode_0x11(void);
static void Opcode_0x12(void);
static void Opcode_0x13(void);
static void Opcode_0x14(void);
static void Opcode_0x15(void);
static void Opcode_0x16(void);
static void Opcode_0x17(void);
static void Opcode_0x18(void);
static void Opcode_0x19(void);
static void Opcode_0x1A(void);
static void Opcode_0x1B(void);
static void Opcode_0x1C(void);
static void Opcode_0x1D(void);
static void Opcode_0x1E(void);
static void Opcode_0x1F(void);
static void Opcode_0x20(void);
static void Opcode_0x21(void);
static void Opcode_0x22(void);
static void Opcode_0x23(void);
static void Opcode_0x24(void);
static void Opcode_0x25(void);
static void Opcode_0x26(void);
static void Opcode_0x27(void);
static void Opcode_0x28(void);
static void Opcode_0x29(void);
static void Opcode_0x2A(void);
static void Opcode_0x2B(void);
static void Opcode_0x2C(void);
static void Opcode_0x2D(void);
static void Opcode_0x2E(void);
static void Opcode_0x2F(void);
static void Opcode_0x30(void);
static void Opcode_0x31(void);
static void Opcode_0x32(void);
static void Opcode_0x33(void);
static void Opcode_0x34(void);
static void Opcode_0x35(void);
static void Opcode_0x36(void);
static void Opcode_0x37(void);
static void Opcode_0x38(void);
static void Opcode_0x39(void);
static void Opcode_0x3A(void);
static void Opcode_0x3B(void);
static void Opcode_0x3C(void);
static void Opcode_0x3D(void);
static void Opcode_0x3E(void);
static void Opcode_0x3F(void);
static void Opcode_0x40(void);
static void Opcode_0x41(void);
static void Opcode_0x42(void);
static void Opcode_0x43(void);
static void Opcode_0x44(void);
static void Opcode_0x45(void);
static void Opcode_0x46(void);
static void Opcode_0x47(void);
static void Opcode_0x48(void);
static void Opcode_0x49(void);
static void Opcode_0x4A(void);
static void Opcode_0x4B(void);
static void Opcode_0x4C(void);
static void Opcode_0x4D(void);
static void Opcode_0x4E(void);
static void Opcode_0x4F(void);
static void Opcode_0x50(void);
static void Opcode_0x51(void);
static void Opcode_0x52(void);
static void Opcode_0x53(void);
static void Opcode_0x54(void);
static void Opcode_0x55(void);
static void Opcode_0x56(void);
static void Opcode_0x57(void);
static void Opcode_0x58(void);
static void Opcode_0x59(void);
static void Opcode_0x5A(void);
static void Opcode_0x5B(void);
static void Opcode_0x5C(void);
static void Opcode_0x5D(void);
static void Opcode_0x5E(void);
static void Opcode_0x5F(void);
static void Opcode_0x60(void);
static void Opcode_0x61(void);
static void Opcode_0x62(void);
static void Opcode_0x63(void);
static void Opcode_0x64(void);
static void Opcode_0x65(void);
static void Opcode_0x66(void);
static void Opcode_0x67(void);
static void Opcode_0x68(void);
static void Opcode_0x69(void);
static void Opcode_0x6A(void);
static void Opcode_0x6B(void);
static void Opcode_0x6C(void);
static void Opcode_0x6D(void);
static void Opcode_0x6E(void);
static void Opcode_0x6F(void);
static void Opcode_0x70(void);
static void Opcode_0x71(void);
static void Opcode_0x72(void);
static void Opcode_0x73(void);
static void Opcode_0x74(void);
static void Opcode_0x75(void);
static void Opcode_0x76(void);
static void Opcode_0x77(void);
static void Opcode_0x78(void);
static void Opcode_0x79(void);
static void Opcode_0x7A(void);
static void Opcode_0x7B(void);
static void Opcode_0x7C(void);
static void Opcode_0x7D(void);
static void Opcode_0x7E(void);
static void Opcode_0x7F(void);
static void Opcode_0x80(void);
static void Opcode_0x81(void);
static void Opcode_0x82(void);
static void Opcode_0x83(void);
static void Opcode_0x84(void);
static void Opcode_0x85(void);
static void Opcode_0x86(void);
static void Opcode_0x87(void);
static void Opcode_0x88(void);
static void Opcode_0x89(void);
static void Opcode_0x8A(void);
static void Opcode_0x8B(void);
static void Opcode_0x8C(void);
static void Opcode_0x8D(void);
static void Opcode_0x8E(void);
static void Opcode_0x8F(void);
static void Opcode_0x90(void);
static void Opcode_0x91(void);
static void Opcode_0x92(void);
static void Opcode_0x93(void);
static void Opcode_0x94(void);
static void Opcode_0x95(void);
static void Opcode_0x96(void);
static void Opcode_0x97(void);
static void Opcode_0x98(void);
static void Opcode_0x99(void);
static void Opcode_0x9A(void);
static void Opcode_0x9B(void);
static void Opcode_0x9C(void);
static void Opcode_0x9D(void);
static void Opcode_0x9E(void);
static void Opcode_0x9F(void);
static void Opcode_0xA0(void);
static void Opcode_0xA1(void);
static void Opcode_0xA2(void);
static void Opcode_0xA3(void);
static void Opcode_0xA4(void);
static void Opcode_0xA5(void);
static void Opcode_0xA6(void);
static void Opcode_0xA7(void);
static void Opcode_0xA8(void);
static void Opcode_0xA9(void);
static void Opcode_0xAA(void);
static void Opcode_0xAB(void);
static void Opcode_0xAC(void);
static void Opcode_0xAD(void);
static void Opcode_0xAE(void);
static void Opcode_0xAF(void);
static void Opcode_0xB0(void);
static void Opcode_0xB1(void);
static void Opcode_0xB2(void);
static void Opcode_0xB3(void);
static void Opcode_0xB4(void);
static void Opcode_0xB5(void);
static void Opcode_0xB6(void);
static void Opcode_0xB7(void);
static void Opcode_0xB8(void);
static void Opcode_0xB9(void);
static void Opcode_0xBA(void);
static void Opcode_0xBB(void);
static void Opcode_0xBC(void);
static void Opcode_0xBD(void);
static void Opcode_0xBE(void);
static void Opcode_0xBF(void);
static void Opcode_0xC0(void);
static void Opcode_0xC1(void);
static void Opcode_0xC2(void);
static void Opcode_0xC3(void);
static void Opcode_0xC4(void);
static void Opcode_0xC5(void);
static void Opcode_0xC6(void);
static void Opcode_0xC7(void);
static void Opcode_0xC8(void);
static void Opcode_0xC9(void);
static void Opcode_0xCA(void);
static void Opcode_0xCB(void);
static void Opcode_0xCC(void);
static void Opcode_0xCD(void);
static void Opcode_0xCE(void);
static void Opcode_0xCF(void);
static void Opcode_0xD0(void);
static void Opcode_0xD1(void);
static void Opcode_0xD2(void);
static void Opcode_0xD3(void);
static void Opcode_0xD4(void);
static void Opcode_0xD5(void);
static void Opcode_0xD6(void);
static void Opcode_0xD7(void);
static void Opcode_0xD8(void);
static void Opcode_0xD9(void);
static void Opcode_0xDA(void);
static void Opcode_0xDB(void);
static void Opcode_0xDC(void);
static void Opcode_0xDD(void);
static void Opcode_0xDE(void);
static void Opcode_0xDF(void);
static void Opcode_0xE0(void);
static void Opcode_0xE1(void);
static void Opcode_0xE2(void);
static void Opcode_0xE3(void);
static void Opcode_0xE4(void);
static void Opcode_0xE5(void);
static void Opcode_0xE6(void);
static void Opcode_0xE7(void);
static void Opcode_0xE8(void);
static void Opcode_0xE9(void);
static void Opcode_0xEA(void);
static void Opcode_0xEB(void);
static void Opcode_0xEC(void);
static void Opcode_0xED(void);
static void Opcode_0xEE(void);
static void Opcode_0xEF(void);
static void Opcode_0xF0(void);
static void Opcode_0xF1(void);
static void Opcode_0xF2(void);
static void Opcode_0xF3(void);
static void Opcode_0xF4(void);
static void Opcode_0xF5(void);
static void Opcode_0xF6(void);
static void Opcode_0xF7(void);
static void Opcode_0xF8(void);
static void Opcode_0xF9(void);
static void Opcode_0xFA(void);
static void Opcode_0xFB(void);
static void Opcode_0xFC(void);
static void Opcode_0xFD(void);
static void Opcode_0xFE(void);
static void Opcode_0xFF(void);

static void CBOpcode_0x00(void);
static void CBOpcode_0x01(void);
static void CBOpcode_0x02(void);
static void CBOpcode_0x03(void);
static void CBOpcode_0x04(void);
static void CBOpcode_0x05(void);
static void CBOpcode_0x06(void);
static void CBOpcode_0x07(void);
static void CBOpcode_0x08(void);
static void CBOpcode_0x09(void);
static void CBOpcode_0x0A(void);
static void CBOpcode_0x0B(void);
static void CBOpcode_0x0C(void);
static void CBOpcode_0x0D(void);
static void CBOpcode_0x0E(void);
static void CBOpcode_0x0F(void);
static void CBOpcode_0x10(void);
static void CBOpcode_0x11(void);
static void CBOpcode_0x12(void);
static void CBOpcode_0x13(void);
static void CBOpcode_0x14(void);
static void CBOpcode_0x15(void);
static void CBOpcode_0x16(void);
static void CBOpcode_0x17(void);
static void CBOpcode_0x18(void);
static void CBOpcode_0x19(void);
static void CBOpcode_0x1A(void);
static void CBOpcode_0x1B(void);
static void CBOpcode_0x1C(void);
static void CBOpcode_0x1D(void);
static void CBOpcode_0x1E(void);
static void CBOpcode_0x1F(void);
static void CBOpcode_0x20(void);
static void CBOpcode_0x21(void);
static void CBOpcode_0x22(void);
static void CBOpcode_0x23(void);
static void CBOpcode_0x24(void);
static void CBOpcode_0x25(void);
static void CBOpcode_0x26(void);
static void CBOpcode_0x27(void);
static void CBOpcode_0x28(void);
static void CBOpcode_0x29(void);
static void CBOpcode_0x2A(void);
static void CBOpcode_0x2B(void);
static void CBOpcode_0x2C(void);
static void CBOpcode_0x2D(void);
static void CBOpcode_0x2E(void);
static void CBOpcode_0x2F(void);
static void CBOpcode_0x30(void);
static void CBOpcode_0x31(void);
static void CBOpcode_0x32(void);
static void CBOpcode_0x33(void);
static void CBOpcode_0x34(void);
static void CBOpcode_0x35(void);
static void CBOpcode_0x36(void);
static void CBOpcode_0x37(void);
static void CBOpcode_0x38(void);
static void CBOpcode_0x39(void);
static void CBOpcode_0x3A(void);
static void CBOpcode_0x3B(void);
static void CBOpcode_0x3C(void);
static void CBOpcode_0x3D(void);
static void CBOpcode_0x3E(void);
static void CBOpcode_0x3F(void);
static void CBOpcode_0x40(void);
static void CBOpcode_0x41(void);
static void CBOpcode_0x42(void);
static void CBOpcode_0x43(void);
static void CBOpcode_0x44(void);
static void CBOpcode_0x45(void);
static void CBOpcode_0x46(void);
static void CBOpcode_0x47(void);
static void CBOpcode_0x48(void);
static void CBOpcode_0x49(void);
static void CBOpcode_0x4A(void);
static void CBOpcode_0x4B(void);
static void CBOpcode_0x4C(void);
static void CBOpcode_0x4D(void);
static void CBOpcode_0x4E(void);
static void CBOpcode_0x4F(void);
static void CBOpcode_0x50(void);
static void CBOpcode_0x51(void);
static void CBOpcode_0x52(void);
static void CBOpcode_0x53(void);
static void CBOpcode_0x54(void);
static void CBOpcode_0x55(void);
static void CBOpcode_0x56(void);
static void CBOpcode_0x57(void);
static void CBOpcode_0x58(void);
static void CBOpcode_0x59(void);
static void CBOpcode_0x5A(void);
static void CBOpcode_0x5B(void);
static void CBOpcode_0x5C(void);
static void CBOpcode_0x5D(void);
static void CBOpcode_0x5E(void);
static void CBOpcode_0x5F(void);
static void CBOpcode_0x60(void);
static void CBOpcode_0x61(void);
static void CBOpcode_0x62(void);
static void CBOpcode_0x63(void);
static void CBOpcode_0x64(void);
static void CBOpcode_0x65(void);
static void CBOpcode_0x66(void);
static void CBOpcode_0x67(void);
static void CBOpcode_0x68(void);
static void CBOpcode_0x69(void);
static void CBOpcode_0x6A(void);
static void CBOpcode_0x6B(void);
static void CBOpcode_0x6C(void);
static void CBOpcode_0x6D(void);
static void CBOpcode_0x6E(void);
static void CBOpcode_0x6F(void);
static void CBOpcode_0x70(void);
static void CBOpcode_0x71(void);
static void CBOpcode_0x72(void);
static void CBOpcode_0x73(void);
static void CBOpcode_0x74(void);
static void CBOpcode_0x75(void);
static void CBOpcode_0x76(void);
static void CBOpcode_0x77(void);
static void CBOpcode_0x78(void);
static void CBOpcode_0x79(void);
static void CBOpcode_0x7A(void);
static void CBOpcode_0x7B(void);
static void CBOpcode_0x7C(void);
static void CBOpcode_0x7D(void);
static void CBOpcode_0x7E(void);
static void CBOpcode_0x7F(void);
static void CBOpcode_0x80(void);
static void CBOpcode_0x81(void);
static void CBOpcode_0x82(void);
static void CBOpcode_0x83(void);
static void CBOpcode_0x84(void);
static void CBOpcode_0x85(void);
static void CBOpcode_0x86(void);
static void CBOpcode_0x87(void);
static void CBOpcode_0x88(void);
static void CBOpcode_0x89(void);
static void CBOpcode_0x8A(void);
static void CBOpcode_0x8B(void);
static void CBOpcode_0x8C(void);
static void CBOpcode_0x8D(void);
static void CBOpcode_0x8E(void);
static void CBOpcode_0x8F(void);
static void CBOpcode_0x90(void);
static void CBOpcode_0x91(void);
static void CBOpcode_0x92(void);
static void CBOpcode_0x93(void);
static void CBOpcode_0x94(void);
static void CBOpcode_0x95(void);
static void CBOpcode_0x96(void);
static void CBOpcode_0x97(void);
static void CBOpcode_0x98(void);
static void CBOpcode_0x99(void);
static void CBOpcode_0x9A(void);
static void CBOpcode_0x9B(void);
static void CBOpcode_0x9C(void);
static void CBOpcode_0x9D(void);
static void CBOpcode_0x9E(void);
static void CBOpcode_0x9F(void);
static void CBOpcode_0xA0(void);
static void CBOpcode_0xA1(void);
static void CBOpcode_0xA2(void);
static void CBOpcode_0xA3(void);
static void CBOpcode_0xA4(void);
static void CBOpcode_0xA5(void);
static void CBOpcode_0xA6(void);
static void CBOpcode_0xA7(void);
static void CBOpcode_0xA8(void);
static void CBOpcode_0xA9(void);
static void CBOpcode_0xAA(void);
static void CBOpcode_0xAB(void);
static void CBOpcode_0xAC(void);
static void CBOpcode_0xAD(void);
static void CBOpcode_0xAE(void);
static void CBOpcode_0xAF(void);
static void CBOpcode_0xB0(void);
static void CBOpcode_0xB1(void);
static void CBOpcode_0xB2(void);
static void CBOpcode_0xB3(void);
static void CBOpcode_0xB4(void);
static void CBOpcode_0xB5(void);
static void CBOpcode_0xB6(void);
static void CBOpcode_0xB7(void);
static void CBOpcode_0xB8(void);
static void CBOpcode_0xB9(void);
static void CBOpcode_0xBA(void);
static void CBOpcode_0xBB(void);
static void CBOpcode_0xBC(void);
static void CBOpcode_0xBD(void);
static void CBOpcode_0xBE(void);
static void CBOpcode_0xBF(void);
static void CBOpcode_0xC0(void);
static void CBOpcode_0xC1(void);
static void CBOpcode_0xC2(void);
static void CBOpcode_0xC3(void);
static void CBOpcode_0xC4(void);
static void CBOpcode_0xC5(void);
static void CBOpcode_0xC6(void);
static void CBOpcode_0xC7(void);
static void CBOpcode_0xC8(void);
static void CBOpcode_0xC9(void);
static void CBOpcode_0xCA(void);
static void CBOpcode_0xCB(void);
static void CBOpcode_0xCC(void);
static void CBOpcode_0xCD(void);
static void CBOpcode_0xCE(void);
static void CBOpcode_0xCF(void);
static void CBOpcode_0xD0(void);
static void CBOpcode_0xD1(void);
static void CBOpcode_0xD2(void);
static void CBOpcode_0xD3(void);
static void CBOpcode_0xD4(void);
static void CBOpcode_0xD5(void);
static void CBOpcode_0xD6(void);
static void CBOpcode_0xD7(void);
static void CBOpcode_0xD8(void);
static void CBOpcode_0xD9(void);
static void CBOpcode_0xDA(void);
static void CBOpcode_0xDB(void);
static void CBOpcode_0xDC(void);
static void CBOpcode_0xDD(void);
static void CBOpcode_0xDE(void);
static void CBOpcode_0xDF(void);
static void CBOpcode_0xE0(void);
static void CBOpcode_0xE1(void);
static void CBOpcode_0xE2(void);
static void CBOpcode_0xE3(void);
static void CBOpcode_0xE4(void);
static void CBOpcode_0xE5(void);
static void CBOpcode_0xE6(void);
static void CBOpcode_0xE7(void);
static void CBOpcode_0xE8(void);
static void CBOpcode_0xE9(void);
static void CBOpcode_0xEA(void);
static void CBOpcode_0xEB(void);
static void CBOpcode_0xEC(void);
static void CBOpcode_0xED(void);
static void CBOpcode_0xEE(void);
static void CBOpcode_0xEF(void);
static void CBOpcode_0xF0(void);
static void CBOpcode_0xF1(void);
static void CBOpcode_0xF2(void);
static void CBOpcode_0xF3(void);
static void CBOpcode_0xF4(void);
static void CBOpcode_0xF5(void);
static void CBOpcode_0xF6(void);
static void CBOpcode_0xF7(void);
static void CBOpcode_0xF8(void);
static void CBOpcode_0xF9(void);
static void CBOpcode_0xFA(void);
static void CBOpcode_0xFB(void);
static void CBOpcode_0xFC(void);
static void CBOpcode_0xFD(void);
static void CBOpcode_0xFE(void);
static void CBOpcode_0xFF(void);

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif // CPU_H