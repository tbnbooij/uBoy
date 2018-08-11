#ifndef GRAPHICS_H
#define GRAPHICS_H
#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 144
#define SCALE 3
#include "SDL2/SDL.h"
#include <stdlib.h>
#include <stdint.h>

static uint8_t framebuffer[SCREEN_HEIGHT * SCREEN_WIDTH];
static SDL_Window *window = NULL;
static SDL_Surface *surface = NULL;
static uint32_t palette[5];

void Graphics_init(void);
void Graphics_init_palette(void);
void Graphics_draw(void);
void Graphics_randomize(void);
void Graphics_exit(void);


#endif // GRAPHICS_H