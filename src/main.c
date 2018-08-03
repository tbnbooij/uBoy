#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "timer.h"
#include "memory.h"
#include "opcodes.h"
#include "instructions.h"
#include "debug.h"
//#include "test.h"

FILE *rom;
void cleanup(void);

int main(int argc, char *argv[]) {
	printf("[uBoy] A small (attempt at) a Game Boy emulator\n-----------------------------------------------\n");
	atexit(&cleanup);

	// Kill program if no ROM-path has been entered
	if (argc < 2) {
		printf("ERROR: Received no ROM-path.\n");
	    exit(EXIT_FAILURE);	
	}
	
	// Open the file in the command-line argument
	rom = fopen(argv[1], "rb");
	printf("[uBoy] Fetching ROM\n");

	// Kill program if ROM does not exist
	if (!rom) {
		printf("ERROR: Received ROM-path does not exist.\n");
		exit(EXIT_FAILURE);
	}

	printf("[uBoy] Initializing emulator\n");
	// Initialize emulator
	Memory_init();
	Registers_init();
	Timer_init();
	Opcodes_init();

	//Test_implementation_opcodes(); 

	// TODO: Copy ROM to memory

	// TODO: Main loop of the emulator
	// 1. Instruction Fetch
	// 2. Instruction Decode
	// 3. Execution
	// 4. Interrupt Catching

	exit(EXIT_SUCCESS);
}

void cleanup(void) {
	printf("[uBoy] Quitting the program\n");
	if (rom)
		fclose(rom);
	
	Memory_free();
}
