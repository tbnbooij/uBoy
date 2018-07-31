#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"
#include "instructions.h"
#include "debug.h"

FILE *rom;
void cleanup(void);

int main(int argc, char *argv[]) {
	atexit(&cleanup);

	// Kill program if no ROM-path has been entered
	if (argc < 2) {
		printf("ERROR: Received no ROM-path.\n");
	    	exit(EXIT_FAILURE);	
	}

	// Open the file in the command-line argument
	rom = fopen(argv[1], "rb");

	// Kill program if ROM does not exist
	if (!rom) {
		printf("ERROR: Received ROM-path does not exist.\n");
		exit(EXIT_FAILURE);
	}

	// Initialize emulator
	Memory_init();
	
	//Debug_print_registers();

	// Main loop of the emulator
	// 1. Instruction Fetch
	// 2. Instruction Decode
	// 3. Execution
	// 4. Interrupt Catching
	
	exit(EXIT_SUCCESS);
}

void cleanup(void) {
	fclose(rom);
	Memory_free();
}
