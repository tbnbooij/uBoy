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
	State_init();
	IO_init();
	Opcodes_init();
	File_read_header();
}

void CPU_start(void) {
	char buffer[20];
	while (1) {
		printf(">>> ");
		scanf(" %s", buffer);

		for (int i = 0; buffer[i] != 0; i++)
			buffer[i] = (char) tolower(buffer[i]);

		if (strcmp(buffer, "n") == 0 || strcmp(buffer, "next") == 0) {
			CPU_next();
		}
		else if (strcmp(buffer, "p") == 0 || strcmp(buffer, "print") == 0) {
			Debug_print_state();
		}
		else if (strcmp(buffer, "rom") == 0) {
			uint16_t begin, end;
			printf("Begin: ");
			scanf(" %hu", &begin);
			printf("End: ");
			scanf(" %hu", &end);
			Debug_print_ROM(begin, end);
		}
		else if (strcmp(buffer, "c") == 0 || strcmp(buffer, "current") == 0) {
			printf("Current value at PC: %02hhX\n", Memory_load_byte(Registers.PC));
		}
		else if (strcmp(buffer, "reset") == 0) {
			printf("Resetting the state of the emulator.\n");
			State_init();
			IO_init();
		}
		else if (strcmp(buffer, "pc") == 0) {
			printf("Program counter: %02hX\n", Registers.PC);
		}
		else if (strcmp(buffer, "q") == 0 || strcmp(buffer, "quit") == 0) {
			break;
		}
		else if (strcmp(buffer, "run") == 0) {
			while (1) {
				CPU_next();
			}
		}
		else {
			printf("Unrecognized command: |%s|\n", buffer);
		}
	}
}

void CPU_next(void) {
	uint16_t PC = Registers.PC;
	clock_t t1 = clock();
	uint8_t opcode = Opcode_fetch();
	Opcode_decode(opcode);
	clock_t t2 = clock();
	double func_time = (double) (t2 - t1)/CLOCKS_PER_SEC;
	printf("Fetched opcode: %02hhX at PC = 0x%04hX -> 0x%04hX (SP: %04hX)\n", opcode, PC, Registers.PC, Registers.SP);
	//Debug_print_state();
	if (PC == Registers.PC) {
		printf("ERROR: Entered an infinite loop!\n");
		exit(EXIT_FAILURE);
	}
}

void CPU_exit(void) {
    if (CPU.source)
        fclose(CPU.source);
    
	Memory_free();
}

uint8_t File_read_byte(uint16_t address) {
    uint8_t b;
    fseek(CPU.source, address, SEEK_SET);
    fread(&b, 1, 1, CPU.source);
    return b;
}

void File_load_rom(void) {
	fseek(CPU.source, 0, SEEK_SET);
	fread(Memory.ROM.bank_fixed, 16*KILO_BYTE, 1, CPU.source);

	// Deal with multiple ROM banks
	switch (Cartridge.ROM_size) {
		case 0x00:
			fread(Memory.ROM.bank_swap, 16*KILO_BYTE, 1, CPU.source);
			break;
		default:
			printf("ERROR: uBoy does not support ROM banking yet.\n");
			exit(EXIT_FAILURE);
			break;
	}
	
}

void File_read_header(void) {
	fseek(CPU.source, 0x134, SEEK_SET);
	fread(&Cartridge.name, 16, 1, CPU.source);

	Cartridge.CGB_flag = File_read_byte(0x143);
	Cartridge.cartridge_type = File_read_byte(0x147);
	Cartridge.ROM_size = File_read_byte(0x148);
	Cartridge.RAM_size = File_read_byte(0x149);
	Cartridge.destination = File_read_byte(0x14A);

	printf("ROM: %02hhX\nRAM: %02hhX\n", Cartridge.ROM_size, Cartridge.RAM_size);
}