#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>

struct {
    uint64_t t;
} Timer;

void Timer_init(void);

#endif // TIMER_H
