#include "debug.h"

void Debug_print_state(uint64_t clk)
{
	printf("DEBUG: Print State\n================================\n");

	printf("8-bit registers:\n");
	printf("A: %hhu\t(%02X)\tF: %hhu\t(%02X)\n", Registers.A, Registers.A, Registers.F, Registers.F);
	printf("B: %hhu\t(%02X)\tC: %hhu\t(%02X)\n", Registers.B, Registers.B, Registers.C, Registers.C);
	printf("D: %hhu\t(%02X)\tE: %hhu\t(%02X)\n", Registers.D, Registers.D, Registers.E, Registers.E);
	printf("H: %hhu\t(%02X)\tL: %hhu\t(%02X)\n", Registers.H, Registers.H, Registers.L, Registers.L);

	printf("\n");
	printf("16-bit registers:\n");
	printf("SP:\t%04X\n", Registers.SP);
	printf("PC:\t%04X\n", Registers.PC);

	printf("\nFlags:\n");
	printf("Z: %hhu\nN: %hhu\nH: %hhu\nC: %hhu\n", Flag_get_Z(), Flag_get_N(), Flag_get_H(), Flag_get_C());

	printf("\n");
	printf("Timer: %lu\n", clk);
}

void Debug_print_ROM(uint16_t begin, uint16_t end)
{
	if (begin > end)
	{
		printf("ERROR: Debug print ROM begin address is after end address.\n");
	}

	printf("DEBUG: Print ROM\n================\n");
	uint16_t i = begin;

	while (i <= end)
	{
		printf("(0x%04hX) - %02hhX\n", i, Memory_load_byte(i));
		i++;
	}
}