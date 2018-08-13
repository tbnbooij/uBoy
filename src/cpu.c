#include "cpu.h"

void CPU_init(void)
{
	atexit(&CPU_exit);
}

void CPU_input(char *filepath)
{
	CPU.source = fopen(filepath, "rb");

	if (!CPU.source)
	{
		printf("ERROR: Received ROM-path does not exist.\n");
		exit(EXIT_FAILURE);
	}

	CPU_init_modules();
	File_load_rom();
}

void CPU_init_modules(void)
{
	Memory_init();
	State_init();
	IO_init();
	Opcodes_init();
	File_read_header();
	PPU_init();
	PPU_randomize();
}

void CPU_start(void)
{
	char buffer[20];
	while (1)
	{
		printf(">>> ");
		scanf(" %s", buffer);

		for (int i = 0; buffer[i] != 0; i++)
			buffer[i] = (char)tolower(buffer[i]);

		if (strcmp(buffer, "n") == 0 || strcmp(buffer, "next") == 0)
		{
			CPU_next();
		}
		else if (strcmp(buffer, "p") == 0 || strcmp(buffer, "print") == 0)
		{
			Debug_print_state(CPU.clk);
		}
		else if (strcmp(buffer, "rom") == 0)
		{
			uint16_t begin, end;
			printf("Begin: ");
			scanf(" %hu", &begin);
			printf("End: ");
			scanf(" %hu", &end);
			Debug_print_ROM(begin, end);
		}
		else if (strcmp(buffer, "c") == 0 || strcmp(buffer, "current") == 0)
		{
			printf("Current value at PC: %02hhX\n", Memory_load_byte(Registers.PC));
		}
		else if (strcmp(buffer, "reset") == 0)
		{
			printf("Resetting the state of the emulator.\n");
			State_init();
			IO_init();
		}
		else if (strcmp(buffer, "pc") == 0)
		{
			printf("Program counter: %02hX\n", Registers.PC);
		}
		else if (strcmp(buffer, "q") == 0 || strcmp(buffer, "quit") == 0)
		{
			break;
		}
		else if (strcmp(buffer, "run") == 0)
		{
			while (1)
			{
				CPU_next();
			}
		}
		else if (strcmp(buffer, "rand") == 0)
		{
			PPU_randomize();
			PPU_draw();
		}
		else if (strcmp(buffer, "h") == 0 | strcmp(buffer, "help") == 0)
		{
			printf("n/next\t\tStep to next instruction\n");
			printf("p/print\t\tPrint the state of the emulator\n");
			printf("rom\t\tPrint the contents of the ROM file\n");
			printf("c/current\tPrint value at PC\n");
			printf("pc\t\tPrint PC\n");
			printf("q/quit\t\tShut down the emulator\n");
			printf("run\t\tRun the emulator\n");
			printf("rand\t\tRandomize the window output (SDL)\n");
		}
		else
		{
			printf("Unrecognized command: |%s|\n", buffer);
		}
	}
}

void CPU_next(void)
{
	uint16_t PC = Registers.PC;
	uint8_t opcode = Opcode_fetch();
	Opcode_decode(opcode);
	printf("0x%04hX/%02hhX: -> 0x%04hX (SP: %04hX - PPU Mode: %d - %d)\n", PC,
		   opcode, Registers.PC, Registers.SP, PPU.mode, PPU.modeclk);

	if (PC == Registers.PC)
	{
		printf("ERROR: Entered an infinite loop!\n");
		exit(EXIT_FAILURE);
	}
}

void CPU_exit(void)
{
	if (CPU.source)
		fclose(CPU.source);

	PPU_exit();
	Memory_exit();
}

uint8_t File_read_byte(uint16_t address)
{
	uint8_t b;
	fseek(CPU.source, address, SEEK_SET);
	fread(&b, 1, 1, CPU.source);
	return b;
}

void File_load_rom(void)
{
	fseek(CPU.source, 0, SEEK_SET);
	fread(Memory.ROM.bank_fixed, 16 * KILO_BYTE, 1, CPU.source);

	// Deal with multiple ROM banks
	switch (Cartridge.ROM_size)
	{
	case 0x00:
		fread(Memory.ROM.bank_swap, 16 * KILO_BYTE, 1, CPU.source);
		break;
	default:
		printf("ERROR: uBoy does not support ROM banking yet.\n");
		exit(EXIT_FAILURE);
		break;
	}
}

void File_read_header(void)
{
	fseek(CPU.source, 0x134, SEEK_SET);
	fread(&Cartridge.name, 16, 1, CPU.source);

	Cartridge.CGB_flag = File_read_byte(0x143);
	Cartridge.cartridge_type = File_read_byte(0x147);
	Cartridge.ROM_size = File_read_byte(0x148);
	Cartridge.RAM_size = File_read_byte(0x149);
	Cartridge.destination = File_read_byte(0x14A);

	printf("ROM: %02hhX\nRAM: %02hhX\n", Cartridge.ROM_size, Cartridge.RAM_size);
}

void CPU_clock_update(int8_t delta)
{
	CPU.clk += delta;
	PPU_clock_update(delta);
}

void Opcodes_init(void)
{
	Opcodes[0x00] = Opcode_0x00;
	Opcodes[0x01] = Opcode_0x01;
	Opcodes[0x02] = Opcode_0x02;
	Opcodes[0x03] = Opcode_0x03;
	Opcodes[0x04] = Opcode_0x04;
	Opcodes[0x05] = Opcode_0x05;
	Opcodes[0x06] = Opcode_0x06;
	Opcodes[0x07] = Opcode_0x07;
	Opcodes[0x08] = Opcode_0x08;
	Opcodes[0x09] = Opcode_0x09;
	Opcodes[0x0A] = Opcode_0x0A;
	Opcodes[0x0B] = Opcode_0x0B;
	Opcodes[0x0C] = Opcode_0x0C;
	Opcodes[0x0D] = Opcode_0x0D;
	Opcodes[0x0E] = Opcode_0x0E;
	Opcodes[0x0F] = Opcode_0x0F;
	Opcodes[0x10] = Opcode_0x10;
	Opcodes[0x11] = Opcode_0x11;
	Opcodes[0x12] = Opcode_0x12;
	Opcodes[0x13] = Opcode_0x13;
	Opcodes[0x14] = Opcode_0x14;
	Opcodes[0x15] = Opcode_0x15;
	Opcodes[0x16] = Opcode_0x16;
	Opcodes[0x17] = Opcode_0x17;
	Opcodes[0x18] = Opcode_0x18;
	Opcodes[0x19] = Opcode_0x19;
	Opcodes[0x1A] = Opcode_0x1A;
	Opcodes[0x1B] = Opcode_0x1B;
	Opcodes[0x1C] = Opcode_0x1C;
	Opcodes[0x1D] = Opcode_0x1D;
	Opcodes[0x1E] = Opcode_0x1E;
	Opcodes[0x1F] = Opcode_0x1F;
	Opcodes[0x20] = Opcode_0x20;
	Opcodes[0x21] = Opcode_0x21;
	Opcodes[0x22] = Opcode_0x22;
	Opcodes[0x23] = Opcode_0x23;
	Opcodes[0x24] = Opcode_0x24;
	Opcodes[0x25] = Opcode_0x25;
	Opcodes[0x26] = Opcode_0x26;
	Opcodes[0x27] = Opcode_0x27;
	Opcodes[0x28] = Opcode_0x28;
	Opcodes[0x29] = Opcode_0x29;
	Opcodes[0x2A] = Opcode_0x2A;
	Opcodes[0x2B] = Opcode_0x2B;
	Opcodes[0x2C] = Opcode_0x2C;
	Opcodes[0x2D] = Opcode_0x2D;
	Opcodes[0x2E] = Opcode_0x2E;
	Opcodes[0x2F] = Opcode_0x2F;
	Opcodes[0x30] = Opcode_0x30;
	Opcodes[0x31] = Opcode_0x31;
	Opcodes[0x32] = Opcode_0x32;
	Opcodes[0x33] = Opcode_0x33;
	Opcodes[0x34] = Opcode_0x34;
	Opcodes[0x35] = Opcode_0x35;
	Opcodes[0x36] = Opcode_0x36;
	Opcodes[0x37] = Opcode_0x37;
	Opcodes[0x38] = Opcode_0x38;
	Opcodes[0x39] = Opcode_0x39;
	Opcodes[0x3A] = Opcode_0x3A;
	Opcodes[0x3B] = Opcode_0x3B;
	Opcodes[0x3C] = Opcode_0x3C;
	Opcodes[0x3D] = Opcode_0x3D;
	Opcodes[0x3E] = Opcode_0x3E;
	Opcodes[0x3F] = Opcode_0x3F;
	Opcodes[0x40] = Opcode_0x40;
	Opcodes[0x41] = Opcode_0x41;
	Opcodes[0x42] = Opcode_0x42;
	Opcodes[0x43] = Opcode_0x43;
	Opcodes[0x44] = Opcode_0x44;
	Opcodes[0x45] = Opcode_0x45;
	Opcodes[0x46] = Opcode_0x46;
	Opcodes[0x47] = Opcode_0x47;
	Opcodes[0x48] = Opcode_0x48;
	Opcodes[0x49] = Opcode_0x49;
	Opcodes[0x4A] = Opcode_0x4A;
	Opcodes[0x4B] = Opcode_0x4B;
	Opcodes[0x4C] = Opcode_0x4C;
	Opcodes[0x4D] = Opcode_0x4D;
	Opcodes[0x4E] = Opcode_0x4E;
	Opcodes[0x4F] = Opcode_0x4F;
	Opcodes[0x50] = Opcode_0x50;
	Opcodes[0x51] = Opcode_0x51;
	Opcodes[0x52] = Opcode_0x52;
	Opcodes[0x53] = Opcode_0x53;
	Opcodes[0x54] = Opcode_0x54;
	Opcodes[0x55] = Opcode_0x55;
	Opcodes[0x56] = Opcode_0x56;
	Opcodes[0x57] = Opcode_0x57;
	Opcodes[0x58] = Opcode_0x58;
	Opcodes[0x59] = Opcode_0x59;
	Opcodes[0x5A] = Opcode_0x5A;
	Opcodes[0x5B] = Opcode_0x5B;
	Opcodes[0x5C] = Opcode_0x5C;
	Opcodes[0x5D] = Opcode_0x5D;
	Opcodes[0x5E] = Opcode_0x5E;
	Opcodes[0x5F] = Opcode_0x5F;
	Opcodes[0x60] = Opcode_0x60;
	Opcodes[0x61] = Opcode_0x61;
	Opcodes[0x62] = Opcode_0x62;
	Opcodes[0x63] = Opcode_0x63;
	Opcodes[0x64] = Opcode_0x64;
	Opcodes[0x65] = Opcode_0x65;
	Opcodes[0x66] = Opcode_0x66;
	Opcodes[0x67] = Opcode_0x67;
	Opcodes[0x68] = Opcode_0x68;
	Opcodes[0x69] = Opcode_0x69;
	Opcodes[0x6A] = Opcode_0x6A;
	Opcodes[0x6B] = Opcode_0x6B;
	Opcodes[0x6C] = Opcode_0x6C;
	Opcodes[0x6D] = Opcode_0x6D;
	Opcodes[0x6E] = Opcode_0x6E;
	Opcodes[0x6F] = Opcode_0x6F;
	Opcodes[0x70] = Opcode_0x70;
	Opcodes[0x71] = Opcode_0x71;
	Opcodes[0x72] = Opcode_0x72;
	Opcodes[0x73] = Opcode_0x73;
	Opcodes[0x74] = Opcode_0x74;
	Opcodes[0x75] = Opcode_0x75;
	Opcodes[0x76] = Opcode_0x76;
	Opcodes[0x77] = Opcode_0x77;
	Opcodes[0x78] = Opcode_0x78;
	Opcodes[0x79] = Opcode_0x79;
	Opcodes[0x7A] = Opcode_0x7A;
	Opcodes[0x7B] = Opcode_0x7B;
	Opcodes[0x7C] = Opcode_0x7C;
	Opcodes[0x7D] = Opcode_0x7D;
	Opcodes[0x7E] = Opcode_0x7E;
	Opcodes[0x7F] = Opcode_0x7F;
	Opcodes[0x80] = Opcode_0x80;
	Opcodes[0x81] = Opcode_0x81;
	Opcodes[0x82] = Opcode_0x82;
	Opcodes[0x83] = Opcode_0x83;
	Opcodes[0x84] = Opcode_0x84;
	Opcodes[0x85] = Opcode_0x85;
	Opcodes[0x86] = Opcode_0x86;
	Opcodes[0x87] = Opcode_0x87;
	Opcodes[0x88] = Opcode_0x88;
	Opcodes[0x89] = Opcode_0x89;
	Opcodes[0x8A] = Opcode_0x8A;
	Opcodes[0x8B] = Opcode_0x8B;
	Opcodes[0x8C] = Opcode_0x8C;
	Opcodes[0x8D] = Opcode_0x8D;
	Opcodes[0x8E] = Opcode_0x8E;
	Opcodes[0x8F] = Opcode_0x8F;
	Opcodes[0x90] = Opcode_0x90;
	Opcodes[0x91] = Opcode_0x91;
	Opcodes[0x92] = Opcode_0x92;
	Opcodes[0x93] = Opcode_0x93;
	Opcodes[0x94] = Opcode_0x94;
	Opcodes[0x95] = Opcode_0x95;
	Opcodes[0x96] = Opcode_0x96;
	Opcodes[0x97] = Opcode_0x97;
	Opcodes[0x98] = Opcode_0x98;
	Opcodes[0x99] = Opcode_0x99;
	Opcodes[0x9A] = Opcode_0x9A;
	Opcodes[0x9B] = Opcode_0x9B;
	Opcodes[0x9C] = Opcode_0x9C;
	Opcodes[0x9D] = Opcode_0x9D;
	Opcodes[0x9E] = Opcode_0x9E;
	Opcodes[0x9F] = Opcode_0x9F;
	Opcodes[0xA0] = Opcode_0xA0;
	Opcodes[0xA1] = Opcode_0xA1;
	Opcodes[0xA2] = Opcode_0xA2;
	Opcodes[0xA3] = Opcode_0xA3;
	Opcodes[0xA4] = Opcode_0xA4;
	Opcodes[0xA5] = Opcode_0xA5;
	Opcodes[0xA6] = Opcode_0xA6;
	Opcodes[0xA7] = Opcode_0xA7;
	Opcodes[0xA8] = Opcode_0xA8;
	Opcodes[0xA9] = Opcode_0xA9;
	Opcodes[0xAA] = Opcode_0xAA;
	Opcodes[0xAB] = Opcode_0xAB;
	Opcodes[0xAC] = Opcode_0xAC;
	Opcodes[0xAD] = Opcode_0xAD;
	Opcodes[0xAE] = Opcode_0xAE;
	Opcodes[0xAF] = Opcode_0xAF;
	Opcodes[0xB0] = Opcode_0xB0;
	Opcodes[0xB1] = Opcode_0xB1;
	Opcodes[0xB2] = Opcode_0xB2;
	Opcodes[0xB3] = Opcode_0xB3;
	Opcodes[0xB4] = Opcode_0xB4;
	Opcodes[0xB5] = Opcode_0xB5;
	Opcodes[0xB6] = Opcode_0xB6;
	Opcodes[0xB7] = Opcode_0xB7;
	Opcodes[0xB8] = Opcode_0xB8;
	Opcodes[0xB9] = Opcode_0xB9;
	Opcodes[0xBA] = Opcode_0xBA;
	Opcodes[0xBB] = Opcode_0xBB;
	Opcodes[0xBC] = Opcode_0xBC;
	Opcodes[0xBD] = Opcode_0xBD;
	Opcodes[0xBE] = Opcode_0xBE;
	Opcodes[0xBF] = Opcode_0xBF;
	Opcodes[0xC0] = Opcode_0xC0;
	Opcodes[0xC1] = Opcode_0xC1;
	Opcodes[0xC2] = Opcode_0xC2;
	Opcodes[0xC3] = Opcode_0xC3;
	Opcodes[0xC4] = Opcode_0xC4;
	Opcodes[0xC5] = Opcode_0xC5;
	Opcodes[0xC6] = Opcode_0xC6;
	Opcodes[0xC7] = Opcode_0xC7;
	Opcodes[0xC8] = Opcode_0xC8;
	Opcodes[0xC9] = Opcode_0xC9;
	Opcodes[0xCA] = Opcode_0xCA;
	Opcodes[0xCB] = Opcode_0xCB;
	Opcodes[0xCC] = Opcode_0xCC;
	Opcodes[0xCD] = Opcode_0xCD;
	Opcodes[0xCE] = Opcode_0xCE;
	Opcodes[0xCF] = Opcode_0xCF;
	Opcodes[0xD0] = Opcode_0xD0;
	Opcodes[0xD1] = Opcode_0xD1;
	Opcodes[0xD2] = Opcode_0xD2;
	Opcodes[0xD3] = Opcode_0xD3;
	Opcodes[0xD4] = Opcode_0xD4;
	Opcodes[0xD5] = Opcode_0xD5;
	Opcodes[0xD6] = Opcode_0xD6;
	Opcodes[0xD7] = Opcode_0xD7;
	Opcodes[0xD8] = Opcode_0xD8;
	Opcodes[0xD9] = Opcode_0xD9;
	Opcodes[0xDA] = Opcode_0xDA;
	Opcodes[0xDB] = Opcode_0xDB;
	Opcodes[0xDC] = Opcode_0xDC;
	Opcodes[0xDD] = Opcode_0xDD;
	Opcodes[0xDE] = Opcode_0xDE;
	Opcodes[0xDF] = Opcode_0xDF;
	Opcodes[0xE0] = Opcode_0xE0;
	Opcodes[0xE1] = Opcode_0xE1;
	Opcodes[0xE2] = Opcode_0xE2;
	Opcodes[0xE3] = Opcode_0xE3;
	Opcodes[0xE4] = Opcode_0xE4;
	Opcodes[0xE5] = Opcode_0xE5;
	Opcodes[0xE6] = Opcode_0xE6;
	Opcodes[0xE7] = Opcode_0xE7;
	Opcodes[0xE8] = Opcode_0xE8;
	Opcodes[0xE9] = Opcode_0xE9;
	Opcodes[0xEA] = Opcode_0xEA;
	Opcodes[0xEB] = Opcode_0xEB;
	Opcodes[0xEC] = Opcode_0xEC;
	Opcodes[0xED] = Opcode_0xED;
	Opcodes[0xEE] = Opcode_0xEE;
	Opcodes[0xEF] = Opcode_0xEF;
	Opcodes[0xF0] = Opcode_0xF0;
	Opcodes[0xF1] = Opcode_0xF1;
	Opcodes[0xF2] = Opcode_0xF2;
	Opcodes[0xF3] = Opcode_0xF3;
	Opcodes[0xF4] = Opcode_0xF4;
	Opcodes[0xF5] = Opcode_0xF5;
	Opcodes[0xF6] = Opcode_0xF6;
	Opcodes[0xF7] = Opcode_0xF7;
	Opcodes[0xF8] = Opcode_0xF8;
	Opcodes[0xF9] = Opcode_0xF9;
	Opcodes[0xFA] = Opcode_0xFA;
	Opcodes[0xFB] = Opcode_0xFB;
	Opcodes[0xFC] = Opcode_0xFC;
	Opcodes[0xFD] = Opcode_0xFD;
	Opcodes[0xFE] = Opcode_0xFE;
	Opcodes[0xFF] = Opcode_0xFF;

	// CB-opcodes
	CBOpcodes[0x00] = CBOpcode_0x00;
	CBOpcodes[0x01] = CBOpcode_0x01;
	CBOpcodes[0x02] = CBOpcode_0x02;
	CBOpcodes[0x03] = CBOpcode_0x03;
	CBOpcodes[0x04] = CBOpcode_0x04;
	CBOpcodes[0x05] = CBOpcode_0x05;
	CBOpcodes[0x06] = CBOpcode_0x06;
	CBOpcodes[0x07] = CBOpcode_0x07;
	CBOpcodes[0x08] = CBOpcode_0x08;
	CBOpcodes[0x09] = CBOpcode_0x09;
	CBOpcodes[0x0A] = CBOpcode_0x0A;
	CBOpcodes[0x0B] = CBOpcode_0x0B;
	CBOpcodes[0x0C] = CBOpcode_0x0C;
	CBOpcodes[0x0D] = CBOpcode_0x0D;
	CBOpcodes[0x0E] = CBOpcode_0x0E;
	CBOpcodes[0x0F] = CBOpcode_0x0F;
	CBOpcodes[0x10] = CBOpcode_0x10;
	CBOpcodes[0x11] = CBOpcode_0x11;
	CBOpcodes[0x12] = CBOpcode_0x12;
	CBOpcodes[0x13] = CBOpcode_0x13;
	CBOpcodes[0x14] = CBOpcode_0x14;
	CBOpcodes[0x15] = CBOpcode_0x15;
	CBOpcodes[0x16] = CBOpcode_0x16;
	CBOpcodes[0x17] = CBOpcode_0x17;
	CBOpcodes[0x18] = CBOpcode_0x18;
	CBOpcodes[0x19] = CBOpcode_0x19;
	CBOpcodes[0x1A] = CBOpcode_0x1A;
	CBOpcodes[0x1B] = CBOpcode_0x1B;
	CBOpcodes[0x1C] = CBOpcode_0x1C;
	CBOpcodes[0x1D] = CBOpcode_0x1D;
	CBOpcodes[0x1E] = CBOpcode_0x1E;
	CBOpcodes[0x1F] = CBOpcode_0x1F;
	CBOpcodes[0x20] = CBOpcode_0x20;
	CBOpcodes[0x21] = CBOpcode_0x21;
	CBOpcodes[0x22] = CBOpcode_0x22;
	CBOpcodes[0x23] = CBOpcode_0x23;
	CBOpcodes[0x24] = CBOpcode_0x24;
	CBOpcodes[0x25] = CBOpcode_0x25;
	CBOpcodes[0x26] = CBOpcode_0x26;
	CBOpcodes[0x27] = CBOpcode_0x27;
	CBOpcodes[0x28] = CBOpcode_0x28;
	CBOpcodes[0x29] = CBOpcode_0x29;
	CBOpcodes[0x2A] = CBOpcode_0x2A;
	CBOpcodes[0x2B] = CBOpcode_0x2B;
	CBOpcodes[0x2C] = CBOpcode_0x2C;
	CBOpcodes[0x2D] = CBOpcode_0x2D;
	CBOpcodes[0x2E] = CBOpcode_0x2E;
	CBOpcodes[0x2F] = CBOpcode_0x2F;
	CBOpcodes[0x30] = CBOpcode_0x30;
	CBOpcodes[0x31] = CBOpcode_0x31;
	CBOpcodes[0x32] = CBOpcode_0x32;
	CBOpcodes[0x33] = CBOpcode_0x33;
	CBOpcodes[0x34] = CBOpcode_0x34;
	CBOpcodes[0x35] = CBOpcode_0x35;
	CBOpcodes[0x36] = CBOpcode_0x36;
	CBOpcodes[0x37] = CBOpcode_0x37;
	CBOpcodes[0x38] = CBOpcode_0x38;
	CBOpcodes[0x39] = CBOpcode_0x39;
	CBOpcodes[0x3A] = CBOpcode_0x3A;
	CBOpcodes[0x3B] = CBOpcode_0x3B;
	CBOpcodes[0x3C] = CBOpcode_0x3C;
	CBOpcodes[0x3D] = CBOpcode_0x3D;
	CBOpcodes[0x3E] = CBOpcode_0x3E;
	CBOpcodes[0x3F] = CBOpcode_0x3F;
	CBOpcodes[0x40] = CBOpcode_0x40;
	CBOpcodes[0x41] = CBOpcode_0x41;
	CBOpcodes[0x42] = CBOpcode_0x42;
	CBOpcodes[0x43] = CBOpcode_0x43;
	CBOpcodes[0x44] = CBOpcode_0x44;
	CBOpcodes[0x45] = CBOpcode_0x45;
	CBOpcodes[0x46] = CBOpcode_0x46;
	CBOpcodes[0x47] = CBOpcode_0x47;
	CBOpcodes[0x48] = CBOpcode_0x48;
	CBOpcodes[0x49] = CBOpcode_0x49;
	CBOpcodes[0x4A] = CBOpcode_0x4A;
	CBOpcodes[0x4B] = CBOpcode_0x4B;
	CBOpcodes[0x4C] = CBOpcode_0x4C;
	CBOpcodes[0x4D] = CBOpcode_0x4D;
	CBOpcodes[0x4E] = CBOpcode_0x4E;
	CBOpcodes[0x4F] = CBOpcode_0x4F;
	CBOpcodes[0x50] = CBOpcode_0x50;
	CBOpcodes[0x51] = CBOpcode_0x51;
	CBOpcodes[0x52] = CBOpcode_0x52;
	CBOpcodes[0x53] = CBOpcode_0x53;
	CBOpcodes[0x54] = CBOpcode_0x54;
	CBOpcodes[0x55] = CBOpcode_0x55;
	CBOpcodes[0x56] = CBOpcode_0x56;
	CBOpcodes[0x57] = CBOpcode_0x57;
	CBOpcodes[0x58] = CBOpcode_0x58;
	CBOpcodes[0x59] = CBOpcode_0x59;
	CBOpcodes[0x5A] = CBOpcode_0x5A;
	CBOpcodes[0x5B] = CBOpcode_0x5B;
	CBOpcodes[0x5C] = CBOpcode_0x5C;
	CBOpcodes[0x5D] = CBOpcode_0x5D;
	CBOpcodes[0x5E] = CBOpcode_0x5E;
	CBOpcodes[0x5F] = CBOpcode_0x5F;
	CBOpcodes[0x60] = CBOpcode_0x60;
	CBOpcodes[0x61] = CBOpcode_0x61;
	CBOpcodes[0x62] = CBOpcode_0x62;
	CBOpcodes[0x63] = CBOpcode_0x63;
	CBOpcodes[0x64] = CBOpcode_0x64;
	CBOpcodes[0x65] = CBOpcode_0x65;
	CBOpcodes[0x66] = CBOpcode_0x66;
	CBOpcodes[0x67] = CBOpcode_0x67;
	CBOpcodes[0x68] = CBOpcode_0x68;
	CBOpcodes[0x69] = CBOpcode_0x69;
	CBOpcodes[0x6A] = CBOpcode_0x6A;
	CBOpcodes[0x6B] = CBOpcode_0x6B;
	CBOpcodes[0x6C] = CBOpcode_0x6C;
	CBOpcodes[0x6D] = CBOpcode_0x6D;
	CBOpcodes[0x6E] = CBOpcode_0x6E;
	CBOpcodes[0x6F] = CBOpcode_0x6F;
	CBOpcodes[0x70] = CBOpcode_0x70;
	CBOpcodes[0x71] = CBOpcode_0x71;
	CBOpcodes[0x72] = CBOpcode_0x72;
	CBOpcodes[0x73] = CBOpcode_0x73;
	CBOpcodes[0x74] = CBOpcode_0x74;
	CBOpcodes[0x75] = CBOpcode_0x75;
	CBOpcodes[0x76] = CBOpcode_0x76;
	CBOpcodes[0x77] = CBOpcode_0x77;
	CBOpcodes[0x78] = CBOpcode_0x78;
	CBOpcodes[0x79] = CBOpcode_0x79;
	CBOpcodes[0x7A] = CBOpcode_0x7A;
	CBOpcodes[0x7B] = CBOpcode_0x7B;
	CBOpcodes[0x7C] = CBOpcode_0x7C;
	CBOpcodes[0x7D] = CBOpcode_0x7D;
	CBOpcodes[0x7E] = CBOpcode_0x7E;
	CBOpcodes[0x7F] = CBOpcode_0x7F;
	CBOpcodes[0x80] = CBOpcode_0x80;
	CBOpcodes[0x81] = CBOpcode_0x81;
	CBOpcodes[0x82] = CBOpcode_0x82;
	CBOpcodes[0x83] = CBOpcode_0x83;
	CBOpcodes[0x84] = CBOpcode_0x84;
	CBOpcodes[0x85] = CBOpcode_0x85;
	CBOpcodes[0x86] = CBOpcode_0x86;
	CBOpcodes[0x87] = CBOpcode_0x87;
	CBOpcodes[0x88] = CBOpcode_0x88;
	CBOpcodes[0x89] = CBOpcode_0x89;
	CBOpcodes[0x8A] = CBOpcode_0x8A;
	CBOpcodes[0x8B] = CBOpcode_0x8B;
	CBOpcodes[0x8C] = CBOpcode_0x8C;
	CBOpcodes[0x8D] = CBOpcode_0x8D;
	CBOpcodes[0x8E] = CBOpcode_0x8E;
	CBOpcodes[0x8F] = CBOpcode_0x8F;
	CBOpcodes[0x90] = CBOpcode_0x90;
	CBOpcodes[0x91] = CBOpcode_0x91;
	CBOpcodes[0x92] = CBOpcode_0x92;
	CBOpcodes[0x93] = CBOpcode_0x93;
	CBOpcodes[0x94] = CBOpcode_0x94;
	CBOpcodes[0x95] = CBOpcode_0x95;
	CBOpcodes[0x96] = CBOpcode_0x96;
	CBOpcodes[0x97] = CBOpcode_0x97;
	CBOpcodes[0x98] = CBOpcode_0x98;
	CBOpcodes[0x99] = CBOpcode_0x99;
	CBOpcodes[0x9A] = CBOpcode_0x9A;
	CBOpcodes[0x9B] = CBOpcode_0x9B;
	CBOpcodes[0x9C] = CBOpcode_0x9C;
	CBOpcodes[0x9D] = CBOpcode_0x9D;
	CBOpcodes[0x9E] = CBOpcode_0x9E;
	CBOpcodes[0x9F] = CBOpcode_0x9F;
	CBOpcodes[0xA0] = CBOpcode_0xA0;
	CBOpcodes[0xA1] = CBOpcode_0xA1;
	CBOpcodes[0xA2] = CBOpcode_0xA2;
	CBOpcodes[0xA3] = CBOpcode_0xA3;
	CBOpcodes[0xA4] = CBOpcode_0xA4;
	CBOpcodes[0xA5] = CBOpcode_0xA5;
	CBOpcodes[0xA6] = CBOpcode_0xA6;
	CBOpcodes[0xA7] = CBOpcode_0xA7;
	CBOpcodes[0xA8] = CBOpcode_0xA8;
	CBOpcodes[0xA9] = CBOpcode_0xA9;
	CBOpcodes[0xAA] = CBOpcode_0xAA;
	CBOpcodes[0xAB] = CBOpcode_0xAB;
	CBOpcodes[0xAC] = CBOpcode_0xAC;
	CBOpcodes[0xAD] = CBOpcode_0xAD;
	CBOpcodes[0xAE] = CBOpcode_0xAE;
	CBOpcodes[0xAF] = CBOpcode_0xAF;
	CBOpcodes[0xB0] = CBOpcode_0xB0;
	CBOpcodes[0xB1] = CBOpcode_0xB1;
	CBOpcodes[0xB2] = CBOpcode_0xB2;
	CBOpcodes[0xB3] = CBOpcode_0xB3;
	CBOpcodes[0xB4] = CBOpcode_0xB4;
	CBOpcodes[0xB5] = CBOpcode_0xB5;
	CBOpcodes[0xB6] = CBOpcode_0xB6;
	CBOpcodes[0xB7] = CBOpcode_0xB7;
	CBOpcodes[0xB8] = CBOpcode_0xB8;
	CBOpcodes[0xB9] = CBOpcode_0xB9;
	CBOpcodes[0xBA] = CBOpcode_0xBA;
	CBOpcodes[0xBB] = CBOpcode_0xBB;
	CBOpcodes[0xBC] = CBOpcode_0xBC;
	CBOpcodes[0xBD] = CBOpcode_0xBD;
	CBOpcodes[0xBE] = CBOpcode_0xBE;
	CBOpcodes[0xBF] = CBOpcode_0xBF;
	CBOpcodes[0xC0] = CBOpcode_0xC0;
	CBOpcodes[0xC1] = CBOpcode_0xC1;
	CBOpcodes[0xC2] = CBOpcode_0xC2;
	CBOpcodes[0xC3] = CBOpcode_0xC3;
	CBOpcodes[0xC4] = CBOpcode_0xC4;
	CBOpcodes[0xC5] = CBOpcode_0xC5;
	CBOpcodes[0xC6] = CBOpcode_0xC6;
	CBOpcodes[0xC7] = CBOpcode_0xC7;
	CBOpcodes[0xC8] = CBOpcode_0xC8;
	CBOpcodes[0xC9] = CBOpcode_0xC9;
	CBOpcodes[0xCA] = CBOpcode_0xCA;
	CBOpcodes[0xCB] = CBOpcode_0xCB;
	CBOpcodes[0xCC] = CBOpcode_0xCC;
	CBOpcodes[0xCD] = CBOpcode_0xCD;
	CBOpcodes[0xCE] = CBOpcode_0xCE;
	CBOpcodes[0xCF] = CBOpcode_0xCF;
	CBOpcodes[0xD0] = CBOpcode_0xD0;
	CBOpcodes[0xD1] = CBOpcode_0xD1;
	CBOpcodes[0xD2] = CBOpcode_0xD2;
	CBOpcodes[0xD3] = CBOpcode_0xD3;
	CBOpcodes[0xD4] = CBOpcode_0xD4;
	CBOpcodes[0xD5] = CBOpcode_0xD5;
	CBOpcodes[0xD6] = CBOpcode_0xD6;
	CBOpcodes[0xD7] = CBOpcode_0xD7;
	CBOpcodes[0xD8] = CBOpcode_0xD8;
	CBOpcodes[0xD9] = CBOpcode_0xD9;
	CBOpcodes[0xDA] = CBOpcode_0xDA;
	CBOpcodes[0xDB] = CBOpcode_0xDB;
	CBOpcodes[0xDC] = CBOpcode_0xDC;
	CBOpcodes[0xDD] = CBOpcode_0xDD;
	CBOpcodes[0xDE] = CBOpcode_0xDE;
	CBOpcodes[0xDF] = CBOpcode_0xDF;
	CBOpcodes[0xE0] = CBOpcode_0xE0;
	CBOpcodes[0xE1] = CBOpcode_0xE1;
	CBOpcodes[0xE2] = CBOpcode_0xE2;
	CBOpcodes[0xE3] = CBOpcode_0xE3;
	CBOpcodes[0xE4] = CBOpcode_0xE4;
	CBOpcodes[0xE5] = CBOpcode_0xE5;
	CBOpcodes[0xE6] = CBOpcode_0xE6;
	CBOpcodes[0xE7] = CBOpcode_0xE7;
	CBOpcodes[0xE8] = CBOpcode_0xE8;
	CBOpcodes[0xE9] = CBOpcode_0xE9;
	CBOpcodes[0xEA] = CBOpcode_0xEA;
	CBOpcodes[0xEB] = CBOpcode_0xEB;
	CBOpcodes[0xEC] = CBOpcode_0xEC;
	CBOpcodes[0xED] = CBOpcode_0xED;
	CBOpcodes[0xEE] = CBOpcode_0xEE;
	CBOpcodes[0xEF] = CBOpcode_0xEF;
	CBOpcodes[0xF0] = CBOpcode_0xF0;
	CBOpcodes[0xF1] = CBOpcode_0xF1;
	CBOpcodes[0xF2] = CBOpcode_0xF2;
	CBOpcodes[0xF3] = CBOpcode_0xF3;
	CBOpcodes[0xF4] = CBOpcode_0xF4;
	CBOpcodes[0xF5] = CBOpcode_0xF5;
	CBOpcodes[0xF6] = CBOpcode_0xF6;
	CBOpcodes[0xF7] = CBOpcode_0xF7;
	CBOpcodes[0xF8] = CBOpcode_0xF8;
	CBOpcodes[0xF9] = CBOpcode_0xF9;
	CBOpcodes[0xFA] = CBOpcode_0xFA;
	CBOpcodes[0xFB] = CBOpcode_0xFB;
	CBOpcodes[0xFC] = CBOpcode_0xFC;
	CBOpcodes[0xFD] = CBOpcode_0xFD;
	CBOpcodes[0xFE] = CBOpcode_0xFE;
	CBOpcodes[0xFF] = CBOpcode_0xFF;
}

// Opcode Fetching & Decoding
// ---------------------------------------------------
uint8_t Opcode_fetch(void)
{
	return Memory_load_byte_PC();
}

void Opcode_decode(uint8_t opcode)
{
	(*Opcodes[opcode])();
}

void CBOpcode_decode(uint8_t opcode)
{
	(*CBOpcodes[opcode])();
}

void Opcode_not_implemented(uint8_t opcode)
{
	printf("ERROR: Opcode not implemented (0x%02hhX)\n", opcode);
	exit(EXIT_FAILURE);
}

void CBOpcode_not_implemented(uint8_t opcode)
{
	printf("ERROR: CB-Opcode not implemented (0x%02hhX)\n", opcode);
	exit(EXIT_FAILURE);
}

void Opcode_empty(uint8_t opcode)
{
	printf("ERROR: Tried to use a non-existent opcode (0x%02hhX)\n", opcode);
	exit(EXIT_FAILURE);
}

void Opcode_0x00(void)
{
	// NOP
	CPU_clock_update(4);
}

void Opcode_0x01(void)
{
	// LD BC, nn
	Registers.BC = Memory_load_word_PC();
	CPU_clock_update(12);
}

void Opcode_0x02(void)
{
	// LD (BC), A
	Memory_store_byte(Registers.BC, Registers.A);
	CPU_clock_update(8);
}

void Opcode_0x03(void)
{
	// INC BC
	Registers.BC++;
	CPU_clock_update(8);
}

void Opcode_0x04(void)
{
	// INC B
	Instruction_INC_N(&Registers.B);
	CPU_clock_update(4);
}

void Opcode_0x05(void)
{
	// DEC B
	Instruction_DEC_N(&Registers.B);
	CPU_clock_update(4);
}

void Opcode_0x06(void)
{
	// LD B, n
	Registers.B = Memory_load_byte_PC();
	CPU_clock_update(8);
}

void Opcode_0x07(void)
{
	// RLCA
	uint8_t bit7 = (Registers.A & 0x40) >> 7;

	Registers.A <<= 1;
	Registers.A |= bit7;

	Flags_set(0, 0, 0, bit7);

	CPU_clock_update(4);
}

void Opcode_0x08(void)
{
	// LD (nn), SP
	uint16_t nn = Memory_load_word_PC();

	Memory_store_byte(nn, Extract_LSB(Registers.SP));
	Memory_store_byte((nn + 1), Extract_MSB(Registers.SP));

	CPU_clock_update(20);
}

void Opcode_0x09(void)
{
	// ADD HL, BC
	Instruction_ADD_HL_NN(Registers.BC);
	CPU_clock_update(8);
}

void Opcode_0x0A(void)
{
	// LD A, (BC)
	Registers.A = Memory_load_byte(Registers.BC);
	CPU_clock_update(8);
}

void Opcode_0x0B(void)
{
	// DEC BC
	Registers.BC--;
	CPU_clock_update(8);
}

void Opcode_0x0C(void)
{
	// INC C
	Instruction_INC_N(&Registers.C);
	CPU_clock_update(4);
}

void Opcode_0x0D(void)
{
	// DEC C
	Instruction_DEC_N(&Registers.C);
	CPU_clock_update(4);
}

void Opcode_0x0E(void)
{
	// LD C, n
	Registers.C = Memory_load_byte_PC();
	CPU_clock_update(8);
}

void Opcode_0x0F(void)
{
	// RRCA
	uint8_t bit0 = Registers.A & 0x01;

	Registers.A = (Registers.A >> 1) | (bit0 << 7);

	Flags_set(0, 0, 0, bit0);

	CPU_clock_update(4);
}

void Opcode_0x10(void)
{
	// STOP
	uint8_t n = Memory_load_byte_PC();

	if (n == 0x00)
	{
		State.mode = MODE_STOP;
	}
	else
	{
		Registers.PC--;
	}

	CPU_clock_update(4);
}

void Opcode_0x11(void)
{
	// LD DE, nn
	Registers.DE = Memory_load_word_PC();
	CPU_clock_update(12);
}

void Opcode_0x12(void)
{
	// LD (DE), A
	Memory_store_byte(Registers.DE, Registers.A);
	CPU_clock_update(8);
}

void Opcode_0x13(void)
{
	// INC DE
	Registers.DE++;
	CPU_clock_update(8);
}

void Opcode_0x14(void)
{
	// INC D
	Instruction_INC_N(&Registers.D);
	CPU_clock_update(4);
}

void Opcode_0x15(void)
{
	// DEC D
	Instruction_DEC_N(&Registers.D);
	CPU_clock_update(4);
}

void Opcode_0x16(void)
{
	// LD D, n
	Registers.D = Memory_load_byte_PC();
	CPU_clock_update(8);
}

void Opcode_0x17(void)
{
	// RLA
	uint8_t carry = Flag_get_C();
	uint8_t bit7 = (Registers.A & 0x40) >> 7;

	Registers.A = (Registers.A << 1) | carry;
	Flags_set(0, 0, 0, bit7);

	CPU_clock_update(4);
}

void Opcode_0x18(void)
{
	// JR n
	int8_t n = (int8_t)Memory_load_byte_PC();
	Registers.PC += n;
	CPU_clock_update(12);
}

void Opcode_0x19(void)
{
	// ADD HL, DE
	Instruction_ADD_HL_NN(Registers.DE);
	CPU_clock_update(8);
}

void Opcode_0x1A(void)
{
	// LD A, (DE)
	Registers.A = Memory_load_byte(Registers.DE);
	CPU_clock_update(8);
}

void Opcode_0x1B(void)
{
	// DEC DE
	Registers.DE--;
	CPU_clock_update(8);
}

void Opcode_0x1C(void)
{
	// INC E
	Instruction_INC_N(&Registers.E);
	CPU_clock_update(4);
}

void Opcode_0x1D(void)
{
	// DEC E
	Instruction_DEC_N(&Registers.E);
	CPU_clock_update(4);
}

void Opcode_0x1E(void)
{
	// LD E, n
	Registers.E = Memory_load_byte_PC();
	CPU_clock_update(8);
}

void Opcode_0x1F(void)
{
	// RRA
	uint8_t carry = Flag_get_C();
	uint8_t bit0 = Registers.A & 0x01;

	Registers.A = (Registers.A >> 1) | (carry << 7);

	Flags_set(0, 0, 0, bit0);

	CPU_clock_update(4);
}

void Opcode_0x20(void)
{
	// JR NZ, n
	int8_t n = (int8_t)Memory_load_byte_PC();

	if (Flag_get_Z() == 0)
	{
		Registers.PC += n;
		CPU_clock_update(12);
	}
	else
	{
		CPU_clock_update(8);
	}
}

void Opcode_0x21(void)
{
	// LD HL, nn
	Registers.HL = Memory_load_word_PC();
	CPU_clock_update(12);
}

void Opcode_0x22(void)
{
	// LD (HL+), A
	Memory_store_byte(Registers.HL, Registers.A);
	Registers.HL++;
	CPU_clock_update(8);
}

void Opcode_0x23(void)
{
	// INC HL
	Registers.HL++;
	CPU_clock_update(8);
}

void Opcode_0x24(void)
{
	// INC H
	Instruction_INC_N(&Registers.H);
	CPU_clock_update(4);
}

void Opcode_0x25(void)
{
	// DEC H
	Instruction_DEC_N(&Registers.H);
	CPU_clock_update(4);
}

void Opcode_0x26(void)
{
	// LD E, n
	Registers.E = Memory_load_byte_PC();
	CPU_clock_update(8);
}

void Opcode_0x27(void)
{
	// DAA
	// TODO: WHAT THE HELL IS DAA?!
	Opcode_not_implemented(0x27);
}

void Opcode_0x28(void)
{
	// JR Z, n
	int8_t n = (int8_t)Memory_load_byte_PC();

	if (Flag_get_Z() == 1)
	{
		Registers.PC += n;
		CPU_clock_update(12);
	}
	else
	{
		CPU_clock_update(8);
	}
}

void Opcode_0x29(void)
{
	// ADD HL, HL
	Instruction_ADD_HL_NN(Registers.HL);
	CPU_clock_update(8);
}

void Opcode_0x2A(void)
{
	// LD A, (HL+)
	Registers.A = Memory_load_byte(Registers.HL);
	Registers.HL++;
	CPU_clock_update(8);
}

void Opcode_0x2B(void)
{
	// DEC HL
	Registers.HL--;
	CPU_clock_update(8);
}

void Opcode_0x2C(void)
{
	// INC L
	Instruction_INC_N(&Registers.A);
	CPU_clock_update(4);
}

void Opcode_0x2D(void)
{
	// DEC L
	Instruction_DEC_N(&Registers.L);
	CPU_clock_update(4);
}

void Opcode_0x2E(void)
{
	// LD L, n
	Registers.L = Memory_load_byte_PC();
	CPU_clock_update(8);
}

void Opcode_0x2F(void)
{
	// CPL
	Flags_set(-1, 1, 1, -1);
	Registers.A = ~Registers.A;
	CPU_clock_update(4);
}

void Opcode_0x30(void)
{
	// JR NC, n
	int8_t n = (int8_t)Memory_load_byte_PC();

	if (Flag_get_C() == 0)
	{
		Registers.PC += n;
		CPU_clock_update(12);
	}
	else
	{
		CPU_clock_update(8);
	}
}

void Opcode_0x31(void)
{
	// LD SP, nn
	Registers.SP = Memory_load_word_PC();
	CPU_clock_update(12);
}

void Opcode_0x32(void)
{
	// LD (HL-), A
	Memory_store_byte(Registers.HL, Registers.A);
	Registers.HL--;
	CPU_clock_update(8);
}

void Opcode_0x33(void)
{
	// INC SP
	Registers.SP++;
	CPU_clock_update(8);
}

void Opcode_0x34(void)
{
	// INC (HL)
	uint8_t n = Memory_load_byte(Registers.HL);

	Flags_set((n + 1) == 0, 0, Flag_test_H_U8_U8(n, 1, 1), -1);

	Memory_store_byte(Registers.HL, (n + 1));
	CPU_clock_update(12);
}

void Opcode_0x35(void)
{
	// DEC (HL)
	uint8_t n = Memory_load_byte(Registers.HL);

	Flags_set((n - 1) == 0, 1, Flag_test_H_U8_U8(n, 1, 0), -1);

	Memory_store_byte(Registers.HL, (n - 1));
	CPU_clock_update(12);
}

void Opcode_0x36(void)
{
	// LD (HL), n
	Memory_store_byte(Registers.HL, Memory_load_byte_PC());
	CPU_clock_update(12);
}

void Opcode_0x37(void)
{
	// SCF
	Flags_set(-1, 0, 0, 1);
	CPU_clock_update(4);
}

void Opcode_0x38(void)
{
	// JR C, n
	int8_t n = (int8_t)Memory_load_byte_PC();

	if (Flag_get_C() == 1)
	{
		Registers.PC += n;
		CPU_clock_update(12);
	}
	else
	{
		CPU_clock_update(8);
	}
}

void Opcode_0x39(void)
{
	// ADD HL, SP
	Instruction_ADD_HL_NN(Registers.SP);
	CPU_clock_update(8);
}

void Opcode_0x3A(void)
{
	// LD A, (HL-)
	Registers.A = Memory_load_byte(Registers.HL);
	Registers.HL--;
	CPU_clock_update(8);
}

void Opcode_0x3B(void)
{
	// DEC SP
	Registers.SP--;
	CPU_clock_update(8);
}

void Opcode_0x3C(void)
{
	// INC A
	Instruction_INC_N(&Registers.A);
	CPU_clock_update(4);
}

void Opcode_0x3D(void)
{
	// DEC A
	Instruction_DEC_N(&Registers.A);
	CPU_clock_update(4);
}

void Opcode_0x3E(void)
{
	// LD A, n
	Registers.A = Memory_load_byte_PC();
	CPU_clock_update(8);
}

void Opcode_0x3F(void)
{
	// CCF
	uint8_t c = 0;

	if (!Flag_get_C())
		c = 1;

	Flags_set(-1, 0, 0, c);

	CPU_clock_update(4);
}

void Opcode_0x40(void)
{
	// LD B, B
	Registers.B = Registers.B;
	CPU_clock_update(4);
}

void Opcode_0x41(void)
{
	// LD B, C
	Registers.B = Registers.C;
	CPU_clock_update(4);
}

void Opcode_0x42(void)
{
	// LD B, D
	Registers.B = Registers.D;
	CPU_clock_update(4);
}

void Opcode_0x43(void)
{
	// LD B, E
	Registers.B = Registers.E;
	CPU_clock_update(4);
}

void Opcode_0x44(void)
{
	// LD B, H
	Registers.B = Registers.H;
	CPU_clock_update(4);
}

void Opcode_0x45(void)
{
	// LD B, L
	Registers.B = Registers.L;
	CPU_clock_update(4);
}

void Opcode_0x46(void)
{
	// LD B, (HL)
	Registers.B = Memory_load_byte(Registers.HL);
	CPU_clock_update(8);
}

void Opcode_0x47(void)
{
	// LD B, A
	Registers.B = Registers.A;
	CPU_clock_update(4);
}

void Opcode_0x48(void)
{
	// LD C, B
	Registers.C = Registers.B;
	CPU_clock_update(4);
}

void Opcode_0x49(void)
{
	// LD C, C
	Registers.C = Registers.C;
	CPU_clock_update(4);
}

void Opcode_0x4A(void)
{
	// LD C, D
	Registers.C = Registers.D;
	CPU_clock_update(4);
}

void Opcode_0x4B(void)
{
	// LD C, E
	Registers.C = Registers.E;
	CPU_clock_update(4);
}

void Opcode_0x4C(void)
{
	// LD C, H
	Registers.C = Registers.H;
	CPU_clock_update(4);
}

void Opcode_0x4D(void)
{
	// LD C, L
	Registers.C = Registers.L;
	CPU_clock_update(4);
}

void Opcode_0x4E(void)
{
	// LD C, (HL)
	Registers.C = Memory_load_byte(Registers.HL);
	CPU_clock_update(8);
}

void Opcode_0x4F(void)
{
	// LD C, A
	Registers.C = Registers.A;
	CPU_clock_update(4);
}

void Opcode_0x50(void)
{
	// LD D, B
	Registers.D = Registers.B;
	CPU_clock_update(4);
}

void Opcode_0x51(void)
{
	// LD D, C
	Registers.D = Registers.C;
	CPU_clock_update(4);
}

void Opcode_0x52(void)
{
	// LD D, D
	Registers.D = Registers.D;
	CPU_clock_update(4);
}

void Opcode_0x53(void)
{
	// LD D, E
	Registers.D = Registers.E;
	CPU_clock_update(4);
}

void Opcode_0x54(void)
{
	// LD D, H
	Registers.D = Registers.H;
	CPU_clock_update(4);
}

void Opcode_0x55(void)
{
	// LD D, L
	Registers.D = Registers.L;
	CPU_clock_update(4);
}

void Opcode_0x56(void)
{
	// LD D, (HL)
	Registers.D = Memory_load_byte(Registers.HL);
	CPU_clock_update(8);
}

void Opcode_0x57(void)
{
	// LD D, A
	Registers.D = Registers.A;
	CPU_clock_update(4);
}

void Opcode_0x58(void)
{
	// LD E, B
	Registers.E = Registers.B;
	CPU_clock_update(4);
}

void Opcode_0x59(void)
{
	// LD E, C
	Registers.E = Registers.C;
	CPU_clock_update(4);
}

void Opcode_0x5A(void)
{
	// LD E, D
	Registers.E = Registers.D;
	CPU_clock_update(4);
}

void Opcode_0x5B(void)
{
	// LD E, E
	Registers.E = Registers.E;
	CPU_clock_update(4);
}

void Opcode_0x5C(void)
{
	// LD E, H
	Registers.E = Registers.H;
	CPU_clock_update(4);
}

void Opcode_0x5D(void)
{
	// LD E, L
	Registers.E = Registers.L;
	CPU_clock_update(4);
}

void Opcode_0x5E(void)
{
	// LD E, (HL)
	Registers.E = Memory_load_byte(Registers.HL);
	CPU_clock_update(8);
}

void Opcode_0x5F(void)
{
	// LD E, A
	Registers.E = Registers.A;
	CPU_clock_update(4);
}

void Opcode_0x60(void)
{
	// LD H, B
	Registers.H = Registers.B;
	CPU_clock_update(4);
}

void Opcode_0x61(void)
{
	// LD H, C
	Registers.H = Registers.C;
	CPU_clock_update(4);
}

void Opcode_0x62(void)
{
	// LD H, D
	Registers.H = Registers.D;
	CPU_clock_update(4);
}

void Opcode_0x63(void)
{
	// LD H, E
	Registers.H = Registers.E;
	CPU_clock_update(4);
}

void Opcode_0x64(void)
{
	// LD H, H
	Registers.H = Registers.H;
	CPU_clock_update(4);
}

void Opcode_0x65(void)
{
	// LD H, L
	Registers.H = Registers.L;
	CPU_clock_update(4);
}

void Opcode_0x66(void)
{
	// LD H, (HL)
	Registers.H = Memory_load_byte(Registers.HL);
	CPU_clock_update(8);
}

void Opcode_0x67(void)
{
	// LD H, A
	Registers.H = Registers.A;
	CPU_clock_update(4);
}

void Opcode_0x68(void)
{
	// LD L, B
	Registers.L = Registers.B;
	CPU_clock_update(4);
}

void Opcode_0x69(void)
{
	// LD L, C
	Registers.L = Registers.C;
	CPU_clock_update(4);
}

void Opcode_0x6A(void)
{
	// LD L, D
	Registers.L = Registers.D;
	CPU_clock_update(4);
}

void Opcode_0x6B(void)
{
	// LD L, E
	Registers.L = Registers.E;
	CPU_clock_update(4);
}

void Opcode_0x6C(void)
{
	// LD L, H
	Registers.L = Registers.H;
	CPU_clock_update(4);
}

void Opcode_0x6D(void)
{
	// LD L, L
	Registers.L = Registers.L;
	CPU_clock_update(4);
}

void Opcode_0x6E(void)
{
	// LD L, (HL)
	Registers.L = Memory_load_byte(Registers.HL);
	CPU_clock_update(8);
}

void Opcode_0x6F(void)
{
	// LD L, A
	Registers.L = Registers.A;
	CPU_clock_update(4);
}

void Opcode_0x70(void)
{
	// LD (HL), B
	Memory_store_byte(Registers.HL, Registers.B);
	CPU_clock_update(8);
}

void Opcode_0x71(void)
{
	// LD (HL), C
	Memory_store_byte(Registers.HL, Registers.C);
	CPU_clock_update(8);
}

void Opcode_0x72(void)
{
	// LD (HL), D
	Memory_store_byte(Registers.HL, Registers.D);
	CPU_clock_update(8);
}

void Opcode_0x73(void)
{
	// LD (HL), E
	Memory_store_byte(Registers.HL, Registers.E);
	CPU_clock_update(8);
}

void Opcode_0x74(void)
{
	// LD (HL), H
	Memory_store_byte(Registers.HL, Registers.H);
	CPU_clock_update(8);
}

void Opcode_0x75(void)
{
	// LD (HL), L
	Memory_store_byte(Registers.HL, Registers.L);
	CPU_clock_update(8);
}

void Opcode_0x76(void)
{
	// HALT
	State.mode = MODE_HALT;
	CPU_clock_update(4);
}

void Opcode_0x77(void)
{
	// LD (HL), A
	Memory_store_byte(Registers.HL, Registers.A);
	CPU_clock_update(8);
}

void Opcode_0x78(void)
{
	// LD A, B
	Registers.A = Registers.B;
	CPU_clock_update(4);
}

void Opcode_0x79(void)
{
	// LD A, C
	Registers.A = Registers.C;
	CPU_clock_update(4);
}

void Opcode_0x7A(void)
{
	// LD A, D
	Registers.A = Registers.D;
	CPU_clock_update(4);
}

void Opcode_0x7B(void)
{
	// LD A, E
	Registers.A = Registers.E;
	CPU_clock_update(4);
}

void Opcode_0x7C(void)
{
	// LD A, H
	Registers.A = Registers.H;
	CPU_clock_update(4);
}

void Opcode_0x7D(void)
{
	// LD A, L
	Registers.A = Registers.L;
	CPU_clock_update(4);
}

void Opcode_0x7E(void)
{
	// LD A, (HL)
	Registers.A = Memory_load_byte(Registers.HL);
	CPU_clock_update(8);
}

void Opcode_0x7F(void)
{
	// LD A, A
	Registers.A = Registers.A;
	CPU_clock_update(4);
}

void Opcode_0x80(void)
{
	// ADD A, B
	Instruction_ADD_N(Registers.B);
	CPU_clock_update(4);
}

void Opcode_0x81(void)
{
	// ADD A, C
	Instruction_ADD_N(Registers.C);
	CPU_clock_update(4);
}

void Opcode_0x82(void)
{
	// ADD A, D
	Instruction_ADD_N(Registers.D);
	CPU_clock_update(4);
}

void Opcode_0x83(void)
{
	// ADD A, E
	Instruction_ADD_N(Registers.E);
	CPU_clock_update(4);
}

void Opcode_0x84(void)
{
	// ADD A, H
	Instruction_ADD_N(Registers.H);
	CPU_clock_update(4);
}

void Opcode_0x85(void)
{
	// ADD A, L
	Instruction_ADD_N(Registers.L);
	CPU_clock_update(4);
}

void Opcode_0x86(void)
{
	// ADD A, (HL)
	Instruction_ADD_N(Memory_load_byte(Registers.HL));
	CPU_clock_update(8);
}

void Opcode_0x87(void)
{
	// ADD A, A
	Instruction_ADD_N(Registers.A);
	CPU_clock_update(4);
}

void Opcode_0x88(void)
{
	// ADC A, B
	Instruction_ADC_N(Registers.B);
	CPU_clock_update(4);
}

void Opcode_0x89(void)
{
	// ADC A, C
	Instruction_ADC_N(Registers.C);
	CPU_clock_update(4);
}

void Opcode_0x8A(void)
{
	// ADC A, D
	Instruction_ADC_N(Registers.D);
	CPU_clock_update(4);
}

void Opcode_0x8B(void)
{
	// ADC A, E
	Instruction_ADC_N(Registers.E);
	CPU_clock_update(4);
}

void Opcode_0x8C(void)
{
	// ADC A, H
	Instruction_ADC_N(Registers.H);
	CPU_clock_update(4);
}

void Opcode_0x8D(void)
{
	// ADC A, L
	Instruction_ADC_N(Registers.L);
	CPU_clock_update(4);
}

void Opcode_0x8E(void)
{
	// ADC A, (HL)
	Instruction_ADC_N(Memory_load_byte(Registers.HL));
	CPU_clock_update(8);
}

void Opcode_0x8F(void)
{
	// ADC A, A
	Instruction_ADC_N(Registers.A);
	CPU_clock_update(4);
}

void Opcode_0x90(void)
{
	// SUB B
	Instruction_SUB_N(Registers.B);
	CPU_clock_update(4);
}

void Opcode_0x91(void)
{
	// SUB C
	Instruction_SUB_N(Registers.C);
	CPU_clock_update(4);
}

void Opcode_0x92(void)
{
	// SUB D
	Instruction_SUB_N(Registers.D);
	CPU_clock_update(4);
}

void Opcode_0x93(void)
{
	// SUB E
	Instruction_SUB_N(Registers.E);
	CPU_clock_update(4);
}

void Opcode_0x94(void)
{
	// SUB H
	Instruction_SUB_N(Registers.H);
	CPU_clock_update(4);
}

void Opcode_0x95(void)
{
	// SUB L
	Instruction_SUB_N(Registers.L);
	CPU_clock_update(4);
}

void Opcode_0x96(void)
{
	// SUB (HL)
	Instruction_SUB_N(Memory_load_byte(Registers.HL));
	CPU_clock_update(8);
}

void Opcode_0x97(void)
{
	// SUB A
	Instruction_SUB_N(Registers.A);
	CPU_clock_update(4);
}

void Opcode_0x98(void)
{
	// SBC A, B
	Instruction_SBC_N(Registers.B);
	CPU_clock_update(4);
}

void Opcode_0x99(void)
{
	// SBC A, C
	Instruction_SBC_N(Registers.C);
	CPU_clock_update(4);
}

void Opcode_0x9A(void)
{
	// SBC A, D
	Instruction_SBC_N(Registers.D);
	CPU_clock_update(4);
}

void Opcode_0x9B(void)
{
	// SBC A, E
	Instruction_SBC_N(Registers.E);
	CPU_clock_update(4);
}

void Opcode_0x9C(void)
{
	// SBC A, H
	Instruction_SBC_N(Registers.H);
	CPU_clock_update(4);
}

void Opcode_0x9D(void)
{
	// SBC A, L
	Instruction_SBC_N(Registers.L);
	CPU_clock_update(4);
}

void Opcode_0x9E(void)
{
	// SBC A, (HL)
	Instruction_SBC_N(Memory_load_byte(Registers.HL));
	CPU_clock_update(8);
}

void Opcode_0x9F(void)
{
	// SBC A, A
	Instruction_SBC_N(Registers.A);
	CPU_clock_update(4);
}

void Opcode_0xA0(void)
{
	// AND B
	Instruction_AND_N(Registers.B);
	CPU_clock_update(4);
}

void Opcode_0xA1(void)
{
	// AND C
	Instruction_AND_N(Registers.C);
	CPU_clock_update(4);
}

void Opcode_0xA2(void)
{
	// AND D
	Instruction_AND_N(Registers.D);
	CPU_clock_update(4);
}

void Opcode_0xA3(void)
{
	// AND E
	Instruction_AND_N(Registers.E);
	CPU_clock_update(4);
}

void Opcode_0xA4(void)
{
	// AND H
	Instruction_AND_N(Registers.H);
	CPU_clock_update(4);
}

void Opcode_0xA5(void)
{
	// AND L
	Instruction_AND_N(Registers.L);
	CPU_clock_update(4);
}

void Opcode_0xA6(void)
{
	// AND (HL)
	Instruction_AND_N(Memory_load_byte(Registers.HL));
	CPU_clock_update(8);
}

void Opcode_0xA7(void)
{
	// AND A
	Instruction_AND_N(Registers.A);
	CPU_clock_update(4);
}

void Opcode_0xA8(void)
{
	// XOR B
	Instruction_XOR_N(Registers.B);
	CPU_clock_update(4);
}

void Opcode_0xA9(void)
{
	// XOR C
	Instruction_XOR_N(Registers.C);
	CPU_clock_update(4);
}

void Opcode_0xAA(void)
{
	// XOR D
	Instruction_XOR_N(Registers.D);
	CPU_clock_update(4);
}

void Opcode_0xAB(void)
{
	// XOR E
	Instruction_XOR_N(Registers.E);
	CPU_clock_update(4);
}

void Opcode_0xAC(void)
{
	// XOR H
	Instruction_XOR_N(Registers.H);
	CPU_clock_update(4);
}

void Opcode_0xAD(void)
{
	// XOR L
	Instruction_XOR_N(Registers.L);
	CPU_clock_update(4);
}

void Opcode_0xAE(void)
{
	// XOR (HL)
	Instruction_XOR_N(Memory_load_byte(Registers.HL));
	CPU_clock_update(8);
}

void Opcode_0xAF(void)
{
	// XOR A
	Instruction_XOR_N(Registers.A);
	CPU_clock_update(4);
}

void Opcode_0xB0(void)
{
	// OR B
	Instruction_OR_N(Registers.B);
	CPU_clock_update(4);
}

void Opcode_0xB1(void)
{
	// OR C
	Instruction_OR_N(Registers.C);
	CPU_clock_update(4);
}

void Opcode_0xB2(void)
{
	// OR D
	Instruction_OR_N(Registers.D);
	CPU_clock_update(4);
}

void Opcode_0xB3(void)
{
	// OR E
	Instruction_OR_N(Registers.E);
	CPU_clock_update(4);
}

void Opcode_0xB4(void)
{
	// OR H
	Instruction_OR_N(Registers.H);
	CPU_clock_update(4);
}

void Opcode_0xB5(void)
{
	// OR L
	Instruction_OR_N(Registers.L);
	CPU_clock_update(4);
}

void Opcode_0xB6(void)
{
	// OR (HL)
	Instruction_OR_N(Memory_load_byte(Registers.HL));
	CPU_clock_update(8);
}

void Opcode_0xB7(void)
{
	// OR A
	Instruction_OR_N(Registers.A);
	CPU_clock_update(4);
}

void Opcode_0xB8(void)
{
	// CP B
	Instruction_CP_N(Registers.B);
	CPU_clock_update(4);
}

void Opcode_0xB9(void)
{
	// CP C
	Instruction_CP_N(Registers.C);
	CPU_clock_update(4);
}

void Opcode_0xBA(void)
{
	// CP D
	Instruction_CP_N(Registers.D);
	CPU_clock_update(4);
}

void Opcode_0xBB(void)
{
	// CP E
	Instruction_CP_N(Registers.E);
	CPU_clock_update(4);
}

void Opcode_0xBC(void)
{
	// CP H
	Instruction_CP_N(Registers.H);
	CPU_clock_update(4);
}

void Opcode_0xBD(void)
{
	// CP L
	Instruction_CP_N(Registers.L);
	CPU_clock_update(4);
}

void Opcode_0xBE(void)
{
	// CP (HL)
	Instruction_CP_N(Memory_load_byte(Registers.HL));
	CPU_clock_update(8);
}

void Opcode_0xBF(void)
{
	// CP A
	Instruction_CP_N(Registers.A);
	CPU_clock_update(4);
}

void Opcode_0xC0(void)
{
	// RET NZ

	if (Flag_get_Z() == 0)
	{
		Instruction_RET();
		CPU_clock_update(20);
	}
	else
	{
		CPU_clock_update(8);
	}
}

void Opcode_0xC1(void)
{
	// POP BC
	Registers.C = Memory_load_byte(Registers.SP);
	Registers.B = Memory_load_byte(Registers.SP + 1);
	Registers.SP += 2;
	CPU_clock_update(12);
}

void Opcode_0xC2(void)
{
	// JP NZ, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_Z() == 0)
	{
		Registers.PC = nn;
		CPU_clock_update(16);
	}
	else
	{
		CPU_clock_update(12);
	}
}

void Opcode_0xC3(void)
{
	// JP nn
	Registers.PC = Memory_load_word_PC();
	CPU_clock_update(16);
}

void Opcode_0xC4(void)
{
	// CALL NZ, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_Z() == 0)
	{
		Instruction_CALL_NN(nn);
		CPU_clock_update(24);
	}
	else
	{
		CPU_clock_update(12);
	}
}

void Opcode_0xC5(void)
{
	// PUSH BC
	Memory_store_byte(Registers.SP - 1, Registers.B);
	Memory_store_byte(Registers.SP - 2, Registers.C);
	Registers.SP -= 2;
	CPU_clock_update(16);
}

void Opcode_0xC6(void)
{
	// ADD A, n
	Instruction_ADD_N(Memory_load_byte_PC());
	CPU_clock_update(8);
}

void Opcode_0xC7(void)
{
	// RST 00H
	Instruction_RST_N(0x00);
	CPU_clock_update(16);
}

void Opcode_0xC8(void)
{
	// RET Z

	if (Flag_get_Z() == 1)
	{
		Instruction_RET();
		CPU_clock_update(20);
	}
	else
	{
		CPU_clock_update(8);
	}
}

void Opcode_0xC9(void)
{
	// RET
	Instruction_RET();
	CPU_clock_update(16);
}

void Opcode_0xCA(void)
{
	// JP Z, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_Z() == 1)
	{
		Registers.PC = nn;
		CPU_clock_update(16);
	}
	else
	{
		CPU_clock_update(12);
	}
}

void Opcode_0xCB(void)
{
	// PREFIX CB
	CBOpcode_decode(Memory_load_byte_PC());
}

void Opcode_0xCC(void)
{
	// CALL Z, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_Z() == 1)
	{
		Instruction_CALL_NN(nn);
		CPU_clock_update(24);
	}
	else
	{
		CPU_clock_update(12);
	}
}

void Opcode_0xCD(void)
{
	// CALL nn
	Instruction_CALL_NN(Memory_load_word_PC());
	CPU_clock_update(24);
}

void Opcode_0xCE(void)
{
	// ADC A, n
	Instruction_ADC_N(Memory_load_byte_PC());
	CPU_clock_update(8);
}

void Opcode_0xCF(void)
{
	// RST 08H
	Instruction_RST_N(0x08);
	CPU_clock_update(16);
}

void Opcode_0xD0(void)
{
	// RET NC

	if (Flag_get_C() == 0)
	{
		Instruction_RET();
		CPU_clock_update(20);
	}
	else
	{
		CPU_clock_update(8);
	}
}

void Opcode_0xD1(void)
{
	// POP DE
	Registers.E = Memory_load_byte(Registers.SP);
	Registers.D = Memory_load_byte(Registers.SP + 1);
	Registers.SP += 2;
	CPU_clock_update(12);
}

void Opcode_0xD2(void)
{
	// JP NC, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_C() == 0)
	{
		Registers.PC = nn;
		CPU_clock_update(16);
	}
	else
	{
		CPU_clock_update(12);
	}
}

void Opcode_0xD3(void)
{
	// EMPTY
	Opcode_empty(0xD3);
}

void Opcode_0xD4(void)
{
	// CALL NC, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_C() == 0)
	{
		Instruction_CALL_NN(nn);
		CPU_clock_update(24);
	}
	else
	{
		CPU_clock_update(12);
	}
}

void Opcode_0xD5(void)
{
	// PUSH DE
	Memory_store_byte(Registers.SP - 1, Registers.D);
	Memory_store_byte(Registers.SP - 2, Registers.E);
	Registers.SP -= 2;
	CPU_clock_update(16);
}

void Opcode_0xD6(void)
{
	// SUB n
	Instruction_SUB_N(Memory_load_byte_PC());
	CPU_clock_update(8);
}

void Opcode_0xD7(void)
{
	// RST 10H
	Instruction_RST_N(0x10);
	CPU_clock_update(16);
}

void Opcode_0xD8(void)
{
	// RET C

	if (Flag_get_C() == 1)
	{
		Instruction_RET();
		CPU_clock_update(20);
	}
	else
	{
		CPU_clock_update(8);
	}
}

void Opcode_0xD9(void)
{
	// RETI
	Instruction_RET();
	State.IME = 1;
	CPU_clock_update(16);
}

void Opcode_0xDA(void)
{
	// JP C, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_C() == 1)
	{
		Registers.PC = nn;
		CPU_clock_update(16);
	}
	else
	{
		CPU_clock_update(12);
	}
}

void Opcode_0xDB(void)
{
	// EMPTY
	Opcode_empty(0xDB);
}

void Opcode_0xDC(void)
{
	// CALL C, nn
	uint16_t nn = Memory_load_word_PC();

	if (Flag_get_C() == 0)
	{
		Instruction_CALL_NN(nn);
		CPU_clock_update(24);
	}
	else
	{
		CPU_clock_update(12);
	}
}

void Opcode_0xDD(void)
{
	// EMPTY
	Opcode_empty(0xDD);
}

void Opcode_0xDE(void)
{
	// SBC A, n
	Instruction_SBC_N(Memory_load_byte_PC());
	CPU_clock_update(8);
}

void Opcode_0xDF(void)
{
	// RST 18H
	Instruction_RST_N(0x18);
	CPU_clock_update(16);
}

void Opcode_0xE0(void)
{
	// LDH (n), A
	Memory_store_byte(((uint16_t)0xFF) + Memory_load_byte_PC(), Registers.A);
	CPU_clock_update(12);
}

void Opcode_0xE1(void)
{
	// POP HL
	Registers.L = Memory_load_byte(Registers.SP);
	Registers.H = Memory_load_byte(Registers.SP + 1);
	Registers.SP += 2;
	CPU_clock_update(12);
}

void Opcode_0xE2(void)
{
	// LD (C), A
	Memory_store_byte(((uint16_t)0xFF00) + Registers.C, Registers.A);
	CPU_clock_update(8);
}

void Opcode_0xE3(void)
{
	// EMPTY
	Opcode_empty(0xE3);
}

void Opcode_0xE4(void)
{
	// EMPTY
	Opcode_empty(0xE4);
}

void Opcode_0xE5(void)
{
	// PUSH HL
	Memory_store_byte(Registers.SP - 1, Registers.H);
	Memory_store_byte(Registers.SP - 2, Registers.L);
	Registers.SP -= 2;
	CPU_clock_update(16);
}

void Opcode_0xE6(void)
{
	// AND n
	Instruction_AND_N(Memory_load_byte_PC());
	CPU_clock_update(8);
}

void Opcode_0xE7(void)
{
	// RST 20H
	Instruction_RST_N(0x20);
	CPU_clock_update(16);
}

void Opcode_0xE8(void)
{
	// ADD SP, n
	int8_t n = (int8_t)Memory_load_byte_PC();

	Flags_set(0, 0, Flag_test_H_U16_S8(Registers.SP, n),
			  Flag_test_C_U16_S8(Registers.SP, n));

	Registers.SP += n;
	CPU_clock_update(16);
}

void Opcode_0xE9(void)
{
	// JP (HL)
	Registers.PC = Registers.HL;
	CPU_clock_update(4);
}

void Opcode_0xEA(void)
{
	// LD (nn), A
	Memory_store_byte(Memory_load_word_PC(), Registers.A);
	CPU_clock_update(16);
}

void Opcode_0xEB(void)
{
	// EMPTY
	Opcode_empty(0xEB);
}

void Opcode_0xEC(void)
{
	// EMPTY
	Opcode_empty(0xEC);
}

void Opcode_0xED(void)
{
	// EMPTY
	Opcode_empty(0xED);
}

void Opcode_0xEE(void)
{
	// XOR n
	Instruction_XOR_N(Memory_load_byte_PC());
	CPU_clock_update(8);
}

void Opcode_0xEF(void)
{
	// RST 28H
	Instruction_RST_N(0x28);
	CPU_clock_update(16);
}

void Opcode_0xF0(void)
{
	// LDH A, (n)
	Registers.A = Memory_load_byte(((uint16_t)0xFF00) + Memory_load_byte_PC());
	CPU_clock_update(12);
}

void Opcode_0xF1(void)
{
	// POP AF
	Registers.F = Memory_load_byte(Registers.SP);
	Registers.A = Memory_load_byte(Registers.SP + 1);
	Registers.SP += 2;
	CPU_clock_update(12);
}

void Opcode_0xF2(void)
{
	// LD A, (C)
	Registers.A = Memory_load_byte(((uint16_t)0xFF00) + Registers.C);
	CPU_clock_update(8);
}

void Opcode_0xF3(void)
{
	// DI
	State.IME = 0;
	CPU_clock_update(4);
}

void Opcode_0xF4(void)
{
	// EMPTY
	Opcode_empty(0xF4);
}

void Opcode_0xF5(void)
{
	// PUSH AF
	Memory_store_byte(Registers.SP - 1, Registers.A);
	Memory_store_byte(Registers.SP - 2, Registers.F);
	Registers.SP -= 2;
	CPU_clock_update(16);
}

void Opcode_0xF6(void)
{
	// OR n
	Instruction_OR_N(Memory_load_byte_PC());
	CPU_clock_update(8);
}

void Opcode_0xF7(void)
{
	// RST 30H
	Instruction_RST_N(0x30);
	CPU_clock_update(16);
}

void Opcode_0xF8(void)
{
	// LDHL SP, n
	int8_t n = (int8_t)Memory_load_byte_PC();
	Flags_set(0, 0, Flag_test_H_U16_S8(Registers.SP, n),
			  Flag_test_C_U16_S8(Registers.SP, n));

	Registers.HL = Registers.SP + n;
	CPU_clock_update(12);
}

void Opcode_0xF9(void)
{
	// LD SP, HL
	Registers.SP = Registers.HL;
	CPU_clock_update(8);
}

void Opcode_0xFA(void)
{
	// LD A, (nn)
	Registers.A = Memory_load_byte(Memory_load_word_PC());
	CPU_clock_update(16);
}

void Opcode_0xFB(void)
{
	// EI
	State.IME = 1;
	CPU_clock_update(4);
}

void Opcode_0xFC(void)
{
	// EMPTY
	Opcode_empty(0xFC);
}

void Opcode_0xFD(void)
{
	// EMPTY
	Opcode_empty(0xFD);
}

void Opcode_0xFE(void)
{
	// CP n
	Instruction_CP_N(Memory_load_byte_PC());
	CPU_clock_update(8);
}

void Opcode_0xFF(void)
{
	// RST 38H
	Instruction_RST_N(0x38);
	CPU_clock_update(16);
}

// CB-opcodes
void CBOpcode_0x00(void)
{
	// RLC B
	Instruction_RLC_N_R(&Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x01(void)
{
	// RLC C
	Instruction_RLC_N_R(&Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x02(void)
{
	// RLC D
	Instruction_RLC_N_R(&Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x03(void)
{
	// RLC E
	Instruction_RLC_N_R(&Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x04(void)
{
	// RLC H
	Instruction_RLC_N_R(&Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x05(void)
{
	// RLC L
	Instruction_RLC_N_R(&Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x06(void)
{
	// RLC (HL)
	Instruction_RLC_N_M(Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x07(void)
{
	// RLC A
	Instruction_RLC_N_R(&Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x08(void)
{
	// RRC B
	Instruction_RRC_N_R(&Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x09(void)
{
	// RRC C
	Instruction_RRC_N_R(&Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x0A(void)
{
	// RRC D
	Instruction_RRC_N_R(&Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x0B(void)
{
	// RRC E
	Instruction_RRC_N_R(&Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x0C(void)
{
	// RRC H
	Instruction_RRC_N_R(&Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x0D(void)
{
	// RRC L
	Instruction_RRC_N_R(&Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x0E(void)
{
	// RRC (HL)
	Instruction_RRC_N_M(Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x0F(void)
{
	// RRC A
	Instruction_RRC_N_R(&Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x10(void)
{
	// RL B
	Instruction_RL_N_R(&Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x11(void)
{
	// RL C
	Instruction_RL_N_R(&Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x12(void)
{
	// RL D
	Instruction_RL_N_R(&Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x13(void)
{
	// RL E
	Instruction_RL_N_R(&Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x14(void)
{
	// RL H
	Instruction_RL_N_R(&Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x15(void)
{
	// RL L
	Instruction_RL_N_R(&Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x16(void)
{
	// RL (HL)
	Instruction_RL_N_M(Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x17(void)
{
	// RL A
	Instruction_RL_N_R(&Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x18(void)
{
	// RR B
	Instruction_RR_N_R(&Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x19(void)
{
	// RR C
	Instruction_RR_N_R(&Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x1A(void)
{
	// RR D
	Instruction_RR_N_R(&Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x1B(void)
{
	// RR E
	Instruction_RR_N_R(&Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x1C(void)
{
	// RR H
	Instruction_RR_N_R(&Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x1D(void)
{
	// RR L
	Instruction_RR_N_R(&Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x1E(void)
{
	// RR (HL)
	Instruction_RR_N_M(Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x1F(void)
{
	// RR A
	Instruction_RR_N_R(&Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x20(void)
{
	// SLA B
	Instruction_SLA_N_R(&Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x21(void)
{
	// SLA C
	Instruction_SLA_N_R(&Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x22(void)
{
	// SLA D
	Instruction_SLA_N_R(&Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x23(void)
{
	// SLA E
	Instruction_SLA_N_R(&Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x24(void)
{
	// SLA H
	Instruction_SLA_N_R(&Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x25(void)
{
	// SLA L
	Instruction_SLA_N_R(&Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x26(void)
{
	// SLA (HL)
	Instruction_SLA_N_M(Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x27(void)
{
	// SLA A
	Instruction_SLA_N_R(&Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x28(void)
{
	// SRA B
	Instruction_SRA_N_R(&Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x29(void)
{
	// SRA C
	Instruction_SRA_N_R(&Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x2A(void)
{
	// SRA D
	Instruction_SRA_N_R(&Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x2B(void)
{
	// SRA E
	Instruction_SRA_N_R(&Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x2C(void)
{
	// SRA H
	Instruction_SRA_N_R(&Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x2D(void)
{
	// SRA L
	Instruction_SRA_N_R(&Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x2E(void)
{
	// SRA (HL)
	Instruction_SRA_N_M(Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x2F(void)
{
	// SRA A
	Instruction_SRA_N_R(&Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x30(void)
{
	// SWAP B
	Instruction_SWAP_N_R(&Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x31(void)
{
	// SWAP C
	Instruction_SWAP_N_R(&Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x32(void)
{
	// SWAP D
	Instruction_SWAP_N_R(&Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x33(void)
{
	// SWAP E
	Instruction_SWAP_N_R(&Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x34(void)
{
	// SWAP H
	Instruction_SWAP_N_R(&Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x35(void)
{
	// SWAP L
	Instruction_SWAP_N_R(&Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x36(void)
{
	// SWAP (HL)
	Instruction_SWAP_N_M(Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x37(void)
{
	// SWAP A
	Instruction_SWAP_N_R(&Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x38(void)
{
	// SRL B
	Instruction_SRL_N_R(&Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x39(void)
{
	// SRL C
	Instruction_SRL_N_R(&Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x3A(void)
{
	// SRL D
	Instruction_SRL_N_R(&Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x3B(void)
{
	// SRL E
	Instruction_SRL_N_R(&Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x3C(void)
{
	// SRL H
	Instruction_SRL_N_R(&Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x3D(void)
{
	// SRL L
	Instruction_SRL_N_R(&Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x3E(void)
{
	// SRL (HL)
	Instruction_SRL_N_M(Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x3F(void)
{
	// SRL A
	Instruction_SRL_N_R(&Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x40(void)
{
	// BIT 0, B
	Instruction_BIT_N_R(0, Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x41(void)
{
	// BIT 0, C
	Instruction_BIT_N_R(0, Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x42(void)
{
	// BIT 0, D
	Instruction_BIT_N_R(0, Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x43(void)
{
	// BIT 0, E
	Instruction_BIT_N_R(0, Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x44(void)
{
	// BIT 0, H
	Instruction_BIT_N_R(0, Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x45(void)
{
	// BIT 0, L
	Instruction_BIT_N_R(0, Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x46(void)
{
	// BIT 0, (HL)
	Instruction_BIT_N_M(0, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x47(void)
{
	// BIT 0, A
	Instruction_BIT_N_R(0, Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x48(void)
{
	// BIT 1, B
	Instruction_BIT_N_R(1, Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x49(void)
{
	// BIT 1, C
	Instruction_BIT_N_R(1, Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x4A(void)
{
	// BIT 1, D
	Instruction_BIT_N_R(1, Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x4B(void)
{
	// BIT 1, E
	Instruction_BIT_N_R(1, Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x4C(void)
{
	// BIT 1, H
	Instruction_BIT_N_R(1, Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x4D(void)
{
	// BIT 1, L
	Instruction_BIT_N_R(1, Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x4E(void)
{
	// BIT 1, (HL)
	Instruction_BIT_N_M(1, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x4F(void)
{
	// BIT 1, A
	Instruction_BIT_N_R(1, Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x50(void)
{
	// BIT 2, B
	Instruction_BIT_N_R(2, Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x51(void)
{
	// BIT 2, C
	Instruction_BIT_N_R(2, Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x52(void)
{
	// BIT 2, D
	Instruction_BIT_N_R(2, Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x53(void)
{
	// BIT 2, E
	Instruction_BIT_N_R(2, Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x54(void)
{
	// BIT 2, H
	Instruction_BIT_N_R(2, Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x55(void)
{
	// BIT 2, L
	Instruction_BIT_N_R(2, Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x56(void)
{
	// BIT 2, (HL)
	Instruction_BIT_N_M(2, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x57(void)
{
	// BIT 2, A
	Instruction_BIT_N_R(2, Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x58(void)
{
	// BIT 3, B
	Instruction_BIT_N_R(3, Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x59(void)
{
	// BIT 3, C
	Instruction_BIT_N_R(3, Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x5A(void)
{
	// BIT 3, D
	Instruction_BIT_N_R(3, Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x5B(void)
{
	// BIT 3, E
	Instruction_BIT_N_R(3, Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x5C(void)
{
	// BIT 3, H
	Instruction_BIT_N_R(3, Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x5D(void)
{
	// BIT 3, L
	Instruction_BIT_N_R(3, Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x5E(void)
{
	// BIT 3, (HL)
	Instruction_BIT_N_M(3, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x5F(void)
{
	// BIT 3, A
	Instruction_BIT_N_R(3, Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x60(void)
{
	// BIT 4, B
	Instruction_BIT_N_R(4, Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x61(void)
{
	// BIT 4, C
	Instruction_BIT_N_R(4, Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x62(void)
{
	// BIT 4, D
	Instruction_BIT_N_R(4, Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x63(void)
{
	// BIT 4, E
	Instruction_BIT_N_R(4, Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x64(void)
{
	// BIT 4, H
	Instruction_BIT_N_R(4, Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x65(void)
{
	// BIT 4, L
	Instruction_BIT_N_R(4, Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x66(void)
{
	// BIT 4, (HL)
	Instruction_BIT_N_M(4, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x67(void)
{
	// BIT 4, A
	Instruction_BIT_N_R(4, Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x68(void)
{
	// BIT 5, B
	Instruction_BIT_N_R(5, Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x69(void)
{
	// BIT 5, C
	Instruction_BIT_N_R(5, Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x6A(void)
{
	// BIT 5, D
	Instruction_BIT_N_R(5, Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x6B(void)
{
	// BIT 5, E
	Instruction_BIT_N_R(5, Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x6C(void)
{
	// BIT 5, H
	Instruction_BIT_N_R(5, Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x6D(void)
{
	// BIT 5, L
	Instruction_BIT_N_R(5, Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x6E(void)
{
	// BIT 5, (HL)
	Instruction_BIT_N_M(5, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x6F(void)
{
	// BIT 5, A
	Instruction_BIT_N_R(5, Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x70(void)
{
	// BIT 6, B
	Instruction_BIT_N_R(6, Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x71(void)
{
	// BIT 6, C
	Instruction_BIT_N_R(6, Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x72(void)
{
	// BIT 6, D
	Instruction_BIT_N_R(6, Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x73(void)
{
	// BIT 6, E
	Instruction_BIT_N_R(6, Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x74(void)
{
	// BIT 6, H
	Instruction_BIT_N_R(6, Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x75(void)
{
	// BIT 6, L
	Instruction_BIT_N_R(6, Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x76(void)
{
	// BIT 6, (HL)
	Instruction_BIT_N_M(6, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x77(void)
{
	// BIT 6, A
	Instruction_BIT_N_R(6, Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x78(void)
{
	// BIT 7, B
	Instruction_BIT_N_R(7, Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x79(void)
{
	// BIT 7, C
	Instruction_BIT_N_R(7, Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x7A(void)
{
	// BIT 7, D
	Instruction_BIT_N_R(7, Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x7B(void)
{
	// BIT 7, E
	Instruction_BIT_N_R(7, Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x7C(void)
{
	// BIT 7, H
	Instruction_BIT_N_R(7, Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x7D(void)
{
	// BIT 7, L
	Instruction_BIT_N_R(7, Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x7E(void)
{
	// BIT 7, (HL)
	Instruction_BIT_N_M(7, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x7F(void)
{
	// BIT 7, A
	Instruction_BIT_N_R(7, Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x80(void)
{
	// RES 0, B
	Instruction_RES_N_R(0, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x81(void)
{
	// RES 0, C
	Instruction_RES_N_R(0, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x82(void)
{
	// RES 0, D
	Instruction_RES_N_R(0, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x83(void)
{
	// RES 0, E
	Instruction_RES_N_R(0, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x84(void)
{
	// RES 0, H
	Instruction_RES_N_R(0, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x85(void)
{
	// RES 0, L
	Instruction_RES_N_R(0, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x86(void)
{
	// RES 0, (HL)
	Instruction_RES_N_M(0, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x87(void)
{
	// RES 0, A
	Instruction_RES_N_R(0, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x88(void)
{
	// RES 1, B
	Instruction_RES_N_R(1, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x89(void)
{
	// RES 1, C
	Instruction_RES_N_R(1, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x8A(void)
{
	// RES 1, D
	Instruction_RES_N_R(1, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x8B(void)
{
	// RES 1, E
	Instruction_RES_N_R(1, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x8C(void)
{
	// RES 1, H
	Instruction_RES_N_R(1, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x8D(void)
{
	// RES 1, L
	Instruction_RES_N_R(1, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x8E(void)
{
	// RES 1, (HL)
	Instruction_RES_N_M(1, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x8F(void)
{
	// RES 1, A
	Instruction_RES_N_R(1, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x90(void)
{
	// RES 2, B
	Instruction_RES_N_R(2, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x91(void)
{
	// RES 2, C
	Instruction_RES_N_R(2, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x92(void)
{
	// RES 2, D
	Instruction_RES_N_R(2, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x93(void)
{
	// RES 2, E
	Instruction_RES_N_R(2, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x94(void)
{
	// RES 2, H
	Instruction_RES_N_R(2, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x95(void)
{
	// RES 2, L
	Instruction_RES_N_R(2, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x96(void)
{
	// RES 2, (HL)
	Instruction_RES_N_M(2, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x97(void)
{
	// RES 2, A
	Instruction_RES_N_R(2, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0x98(void)
{
	// RES 3, B
	Instruction_RES_N_R(3, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0x99(void)
{
	// RES 3, C
	Instruction_RES_N_R(3, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0x9A(void)
{
	// RES 3, D
	Instruction_RES_N_R(3, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0x9B(void)
{
	// RES 3, E
	Instruction_RES_N_R(3, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0x9C(void)
{
	// RES 3, H
	Instruction_RES_N_R(3, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0x9D(void)
{
	// RES 3, L
	Instruction_RES_N_R(3, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0x9E(void)
{
	// RES 3, (HL)
	Instruction_RES_N_M(3, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0x9F(void)
{
	// RES 3, A
	Instruction_RES_N_R(3, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xA0(void)
{
	// RES 4, B
	Instruction_RES_N_R(4, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xA1(void)
{
	// RES 4, C
	Instruction_RES_N_R(4, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xA2(void)
{
	// RES 4, D
	Instruction_RES_N_R(4, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xA3(void)
{
	// RES 4, E
	Instruction_RES_N_R(4, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xA4(void)
{
	// RES 4, H
	Instruction_RES_N_R(4, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xA5(void)
{
	// RES 4, L
	Instruction_RES_N_R(4, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xA6(void)
{
	// RES 4, (HL)
	Instruction_RES_N_M(4, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xA7(void)
{
	// RES 4, A
	Instruction_RES_N_R(4, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xA8(void)
{
	// RES 5, B
	Instruction_RES_N_R(5, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xA9(void)
{
	// RES 5, C
	Instruction_RES_N_R(5, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xAA(void)
{
	// RES 5, D
	Instruction_RES_N_R(5, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xAB(void)
{
	// RES 5, E
	Instruction_RES_N_R(5, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xAC(void)
{
	// RES 5, H
	Instruction_RES_N_R(5, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xAD(void)
{
	// RES 5, L
	Instruction_RES_N_R(5, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xAE(void)
{
	// RES 5, (HL)
	Instruction_RES_N_M(5, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xAF(void)
{
	// RES 5, A
	Instruction_RES_N_R(5, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xB0(void)
{
	// RES 6, B
	Instruction_RES_N_R(6, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xB1(void)
{
	// RES 6, C
	Instruction_RES_N_R(6, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xB2(void)
{
	// RES 6, D
	Instruction_RES_N_R(6, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xB3(void)
{
	// RES 6, E
	Instruction_RES_N_R(6, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xB4(void)
{
	// RES 6, H
	Instruction_RES_N_R(6, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xB5(void)
{
	// RES 6, L
	Instruction_RES_N_R(6, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xB6(void)
{
	// RES 6, (HL)
	Instruction_RES_N_M(6, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xB7(void)
{
	// RES 6, A
	Instruction_RES_N_R(6, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xB8(void)
{
	// RES 7, B
	Instruction_RES_N_R(7, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xB9(void)
{
	// RES 7, C
	Instruction_RES_N_R(7, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xBA(void)
{
	// RES 7, D
	Instruction_RES_N_R(7, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xBB(void)
{
	// RES 7, E
	Instruction_RES_N_R(7, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xBC(void)
{
	// RES 7, H
	Instruction_RES_N_R(7, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xBD(void)
{
	// RES 7, L
	Instruction_RES_N_R(7, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xBE(void)
{
	// RES 7, (HL)
	Instruction_RES_N_M(7, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xBF(void)
{
	// RES 7, A
	Instruction_RES_N_R(7, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xC0(void)
{
	// SET 0, B
	Instruction_SET_N_R(0, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xC1(void)
{
	// SET 0, C
	Instruction_SET_N_R(0, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xC2(void)
{
	// SET 0, D
	Instruction_SET_N_R(0, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xC3(void)
{
	// SET 0, E
	Instruction_SET_N_R(0, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xC4(void)
{
	// SET 0, H
	Instruction_SET_N_R(0, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xC5(void)
{
	// SET 0, L
	Instruction_SET_N_R(0, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xC6(void)
{
	// SET 0, (HL)
	Instruction_SET_N_M(0, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xC7(void)
{
	// SET 0, A
	Instruction_SET_N_R(0, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xC8(void)
{
	// SET 1, B
	Instruction_SET_N_R(1, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xC9(void)
{
	// SET 1, C
	Instruction_SET_N_R(1, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xCA(void)
{
	// SET 1, D
	Instruction_SET_N_R(1, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xCB(void)
{
	// SET 1, E
	Instruction_SET_N_R(1, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xCC(void)
{
	// SET 1, H
	Instruction_SET_N_R(1, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xCD(void)
{
	// SET 1, L
	Instruction_SET_N_R(1, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xCE(void)
{
	// SET 1, (HL)
	Instruction_SET_N_M(1, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xCF(void)
{
	// SET 1, A
	Instruction_SET_N_R(1, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xD0(void)
{
	// SET 2, B
	Instruction_SET_N_R(2, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xD1(void)
{
	// SET 2, C
	Instruction_SET_N_R(2, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xD2(void)
{
	// SET 2, D
	Instruction_SET_N_R(2, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xD3(void)
{
	// SET 2, E
	Instruction_SET_N_R(2, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xD4(void)
{
	// SET 2, H
	Instruction_SET_N_R(2, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xD5(void)
{
	// SET 2, L
	Instruction_SET_N_R(2, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xD6(void)
{
	// SET 2, (HL)
	Instruction_SET_N_M(2, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xD7(void)
{
	// SET 2, A
	Instruction_SET_N_R(2, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xD8(void)
{
	// SET 3, B
	Instruction_SET_N_R(3, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xD9(void)
{
	// SET 3, C
	Instruction_SET_N_R(3, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xDA(void)
{
	// SET 3, D
	Instruction_SET_N_R(3, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xDB(void)
{
	// SET 3, E
	Instruction_SET_N_R(3, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xDC(void)
{
	// SET 3, H
	Instruction_SET_N_R(3, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xDD(void)
{
	// SET 3, L
	Instruction_SET_N_R(3, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xDE(void)
{
	// SET 3, (HL)
	Instruction_SET_N_M(3, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xDF(void)
{
	// SET 3, A
	Instruction_SET_N_R(3, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xE0(void)
{
	// SET 4, B
	Instruction_SET_N_R(4, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xE1(void)
{
	// SET 4, C
	Instruction_SET_N_R(4, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xE2(void)
{
	// SET 4, D
	Instruction_SET_N_R(4, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xE3(void)
{
	// SET 4, E
	Instruction_SET_N_R(4, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xE4(void)
{
	// SET 4, H
	Instruction_SET_N_R(4, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xE5(void)
{
	// SET 4, L
	Instruction_SET_N_R(4, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xE6(void)
{
	// SET 4, (HL)
	Instruction_SET_N_M(4, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xE7(void)
{
	// SET 4, A
	Instruction_SET_N_R(4, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xE8(void)
{
	// SET 5, B
	Instruction_SET_N_R(5, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xE9(void)
{
	// SET 5, C
	Instruction_SET_N_R(5, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xEA(void)
{
	// SET 5, D
	Instruction_SET_N_R(5, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xEB(void)
{
	// SET 5, E
	Instruction_SET_N_R(5, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xEC(void)
{
	// SET 5, H
	Instruction_SET_N_R(5, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xED(void)
{
	// SET 5, L
	Instruction_SET_N_R(5, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xEE(void)
{
	// SET 5, (HL)
	Instruction_SET_N_M(5, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xEF(void)
{
	// SET 5, A
	Instruction_SET_N_R(5, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xF0(void)
{
	// SET 6, B
	Instruction_SET_N_R(6, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xF1(void)
{
	// SET 6, C
	Instruction_SET_N_R(6, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xF2(void)
{
	// SET 6, D
	Instruction_SET_N_R(6, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xF3(void)
{
	// SET 6, E
	Instruction_SET_N_R(6, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xF4(void)
{
	// SET 6, H
	Instruction_SET_N_R(6, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xF5(void)
{
	// SET 6, L
	Instruction_SET_N_R(6, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xF6(void)
{
	// SET 6, (HL)
	Instruction_SET_N_M(6, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xF7(void)
{
	// SET 6, A
	Instruction_SET_N_R(6, &Registers.A);
	CPU_clock_update(8);
}

void CBOpcode_0xF8(void)
{
	// SET 7, B
	Instruction_SET_N_R(7, &Registers.B);
	CPU_clock_update(8);
}

void CBOpcode_0xF9(void)
{
	// SET 7, C
	Instruction_SET_N_R(7, &Registers.C);
	CPU_clock_update(8);
}

void CBOpcode_0xFA(void)
{
	// SET 7, D
	Instruction_SET_N_R(7, &Registers.D);
	CPU_clock_update(8);
}

void CBOpcode_0xFB(void)
{
	// SET 7, E
	Instruction_SET_N_R(7, &Registers.E);
	CPU_clock_update(8);
}

void CBOpcode_0xFC(void)
{
	// SET 7, H
	Instruction_SET_N_R(7, &Registers.H);
	CPU_clock_update(8);
}

void CBOpcode_0xFD(void)
{
	// SET 7, L
	Instruction_SET_N_R(7, &Registers.L);
	CPU_clock_update(8);
}

void CBOpcode_0xFE(void)
{
	// SET 7, (HL)
	Instruction_SET_N_M(7, Registers.HL);
	CPU_clock_update(16);
}

void CBOpcode_0xFF(void)
{
	// SET 7, A
	Instruction_SET_N_R(7, &Registers.A);
	CPU_clock_update(8);
}
