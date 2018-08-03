#include "test.h"

void Test_implementation_opcodes(void) {
    for (uint8_t i = 0; i <= 0xFF; i++) {
        Opcode_decode(i);
    }
}