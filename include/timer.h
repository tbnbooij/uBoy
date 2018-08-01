#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>

struct {
    uint64_t time;
} Timer;

void Timer_init(void);
void Timer_update(uint8_t machine_cycles);

#endif // TIMER_H
