#include "cpu.h"

void CPU_init(void) {
    atexit(&CPU_exit);
}

void CPU_input(char *filepath) {
	CPU.source = fopen(filepath, "rb");

	if (!CPU.source) {
		printf("ERROR: Received ROM-path does not exist.\n");
		exit(EXIT_FAILURE);
	}

    CPU_init_modules();
	File_load_rom();
}

void CPU_init_modules(void) {
    Memory_init();
	Registers_init();
	Timer.t = 0;
	State.mode = MODE_RUN;
	Opcodes_init();
}

void CPU_start(void) {
    printf("start cpu\n");
	Debug_print_ROM(0x0100, 0x010F);
}

void CPU_exit(void) {
    if (CPU.source)
        fclose(CPU.source);
    
	Memory_free();
}

uint8_t File_read_byte(FILE *fp, uint16_t address) {
    uint8_t b;
    fseek(fp, address, SEEK_SET);
    fread(&b, 1, 1, fp);
    return b;
}

void File_load_rom(void) {
	fread(Memory.ROM.bank_fixed, 8*KILO_BYTE, 1, CPU.source);
}