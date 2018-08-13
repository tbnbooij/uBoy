/**
 * @brief The Picture Processing Unit of the emulator, responsible for
 * generating the video output.
 * 
 * @file ppu.h
 * @author tbnbooij
 * @date 2018-08-13
 */
#ifndef PPU_H
#define PPU_H

#include "SDL2/SDL.h"
#include <stdlib.h>
#include <stdint.h>

#define SCREEN_WIDTH 160 /**< The number of pixels along the width of the original Game Boy LCD */
#define SCREEN_HEIGHT 144 /**< The number of pixels along the height of the original Game Boy LCD */
#define SCALE 3 /**< An integer multiplier to scale the original screen dimensions with */

#define MODE_HBLANK 0 /**< The mode in which the PPU is done with drawing a line of the image and waiting to draw a new one */
#define MODE_VBLANK 1 /**< The mode in which the PPU is done with drawing all lines of a single frame and waiting to start with the next line */
#define MODE_OAM 2 /**< The mode in which the PPU is obtaining data from the OAM */
#define MODE_VRAM 3 /**< The mode in which the PPU is obtaining data from VRAM */

/**
 * @brief Struct that represents the state of the PPU
 * 
 */
static struct
{
    uint8_t mode; /**< The mode in which the PPU is currently operating */
    uint16_t modeclk; /**< An internal clock used to make mode transitions after certain periods of time expire */
    uint8_t line; /**< The current line the PPU is drawing */
} PPU;

static uint8_t framebuffer[SCREEN_HEIGHT * SCREEN_WIDTH]; /**< The buffer that holds for each pixel on the screen which palette value has to be drawn */
static SDL_Window *window = NULL; /**< The pointer to the window SDL2 creates **/
static SDL_Surface *surface = NULL; /**< The pointer to the surface SDL2 extracts from the window */
static uint32_t palette[5]; /**< The set of colors that are used by the PPU, indexed through an array **/

/**
 * @brief Initialize SDL2, the window, surface and call PPU_init_palette(). 
 * 
 */
extern void PPU_init(void);

/**
 * @brief Initialize the palette by setting each array cell to a 32-bit ARGB representation of a color.
 * 
 */
static void PPU_init_palette(void);

/**
 * @brief Function called by CPU_clock_update() that keeps the PPU and CPU in sync, maintains the state machine and calls 
 * functions for frame buffer manipulation at the right time.
 * 
 * @param delta The number of 'ticks' that have expired during the latest CPU instruction
 */
extern void PPU_clock_update(int8_t delta);

/**
 * @brief Draw the current frame buffer to the window.
 * 
 */
extern void PPU_draw(void);

/**
 * @brief Fill the framebuffer with random values ([0,4]).
 * 
 */
extern void PPU_randomize(void);

/**
 * @brief Free all memory allocated in PPU_init() and quit SDL2.
 * 
 */
extern void PPU_exit(void);

#endif // PPU_H