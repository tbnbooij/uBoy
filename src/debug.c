#include "debug.h"

void Debug_print_registers(void) {
	printf("DEBUG: Print Registers\n================================\n");

	printf("8-bit registers:\n");
	printf("A: %hhu\t(%02x)\tF: %hhu\t(%02x)\n", Registers.A, Registers.A, Registers.F, Registers.F);
	printf("B: %hhu\t(%02x)\tC: %hhu\t(%02x)\n", Registers.B, Registers.B, Registers.C, Registers.C);
	printf("D: %hhu\t(%02x)\tE: %hhu\t(%02x)\n", Registers.D, Registers.D, Registers.E, Registers.E);
	printf("H: %hhu\t(%02x)\tL: %hhu\t(%02x)\n", Registers.H, Registers.H, Registers.L, Registers.L);

	printf("\n");
	printf("16-bit registers:\n");
	printf("AF: %hu\t\t(%04x)\n", Registers.AF, Registers.AF);
	printf("BC: %hu\t\t(%04x)\n", Registers.BC, Registers.BC);
	printf("DE: %hu\t\t(%04x)\n", Registers.DE, Registers.DE);
	printf("SP: %hu\t\t(%04x)\n", Registers.SP, Registers.SP);
	printf("PC: %hu\t\t(%04x)\n", Registers.PC, Registers.PC);
}

