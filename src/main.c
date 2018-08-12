#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "cpu.h"

int main(int argc, char *argv[])
{
	CPU_init();

	
	if (argc < 2)
	{
		printf("ERROR: Received no ROM-path.\n");
		exit(EXIT_FAILURE);
	}

	CPU_input(argv[1]);

	// TODO: Copy ROM to memory

	// TODO: Main loop of the emulator
	// 1. Instruction Fetch
	// 2. Instruction Decode
	// 3. Execution
	// 4. Interrupt Catching

	CPU_start();

	exit(EXIT_SUCCESS);
}
