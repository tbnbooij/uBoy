#include "timer.h"

void Timer_init(void) {
    Timer.time = 0;
}

void Timer_update(uint8_t cycles) {
    Timer.time += cycles;
}