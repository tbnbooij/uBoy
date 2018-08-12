#ifndef PPU_H
#define PPU_H

#include "SDL2/SDL.h"
#include <stdlib.h>
#include <stdint.h>

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 144
#define SCALE 3

#define MODE_HBLANK 0
#define MODE_VBLANK 1
#define MODE_OAM 2
#define MODE_VRAM 3

static struct
{
    uint8_t mode;
    uint16_t modeclk;
    uint8_t line;
} PPU;

static uint8_t framebuffer[SCREEN_HEIGHT * SCREEN_WIDTH];
static SDL_Window *window = NULL;
static SDL_Surface *surface = NULL;
static uint32_t palette[5];

extern void PPU_init(void);
static void PPU_init_palette(void);
extern void PPU_clock_update(int8_t delta);
extern void PPU_draw(void);
extern void PPU_randomize(void);
extern void PPU_exit(void);

#endif // PPU_H