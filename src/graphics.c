#include "graphics.h"

void Graphics_init(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        printf("ERROR: SDL failed initialization.\n%s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow(
        "uBoy",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH * SCALE,
        SCREEN_HEIGHT * SCALE,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        printf("ERROR: SDL Window could not be initialized.\n%s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    surface = SDL_GetWindowSurface(window);

    Graphics_init_palette();
}

void Graphics_init_palette(void) {
	palette[4] = SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF);
	palette[3] = SDL_MapRGB(surface->format, 0x00, 0x00, 0x00);
	palette[2] = SDL_MapRGB(surface->format, 0x55, 0x55, 0x55);
	palette[1] = SDL_MapRGB(surface->format, 0xAA, 0xAA, 0xAA);
    palette[0] = SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF);
}

void Graphics_draw(void) {
    SDL_Rect pixel = {0, 0, SCALE, SCALE};

    for (uint8_t i = 0; i < SCREEN_HEIGHT; i++) {
        pixel.y = i*SCALE;
        for (uint8_t j = 0; j < SCREEN_WIDTH; j++) {
            pixel.x = j*SCALE;
            if (framebuffer[i*SCREEN_WIDTH + j] >= 4) {
                continue;
            }
            SDL_FillRect(surface, &pixel, palette[framebuffer[i*SCREEN_WIDTH + j]]);
        }
    }

    SDL_UpdateWindowSurface(window);
}

void Graphics_randomize(void) {
    for (uint8_t i = 0; i < SCREEN_HEIGHT; i++) {
        for (uint8_t j = 0; j < SCREEN_WIDTH; j++) {
            framebuffer[i*SCREEN_WIDTH + j] = rand() % 4;
        }
    }
}

void Graphics_exit(void) {
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    surface = NULL;
    window = NULL;
    SDL_Quit();
}
