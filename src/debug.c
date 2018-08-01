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

void Debug_print_opcode_table(void) {
	printf("DEBUG: Print Opcode Table\n================================\n");
	char c = 'x';
	for (uint8_t i = 0; i <= 0xF; i++) {
		for (uint8_t j = 0; j <= 0xF; j++) {
			void (*cell)(uint8_t opcode) = Opcodes[16*i + j];
			if (cell == Opcode_ALU_8) {
				printf("\033[0;33m");
				printf("A8");
			}
			else if (cell == Opcode_MISC) {
				printf("\033[0;31m");
				printf("MI");
			}
			else if (cell == Opcode_ALU_16) {
				printf("\033[0;35m");
				printf("A1");
			}
			else if (cell == Opcode_JP) {
				printf("\033[0;36m");
				printf("JP");
			}
			else if (cell == Opcode_BIT) {
				printf("\033[1;36m");
				printf("BI");
			}
			else if (cell == Opcode_LD_8) {
				printf("\033[0;34m");
				printf("L8");
			}
			else if (cell == Opcode_LD_16) {
				printf("\033[0;32m");
				printf("L1");
			}
			else {
				printf("XX");
			}
			printf("\033[0m");
			printf(" ");
		}
		printf("\n");
	}
}
