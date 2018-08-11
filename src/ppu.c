#include "ppu.h"

void PPU_init(void) {
    PPU.modeclk = 0;
    PPU.mode = MODE_OAM;
    PPU.line = 0;

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

    PPU_init_palette();
}

void PPU_init_palette(void) {
	palette[4] = SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF);
	palette[3] = SDL_MapRGB(surface->format, 0x00, 0x00, 0x00);
	palette[2] = SDL_MapRGB(surface->format, 0x55, 0x55, 0x55);
	palette[1] = SDL_MapRGB(surface->format, 0xAA, 0xAA, 0xAA);
    palette[0] = SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF);
}

void PPU_clock_update(int8_t delta) {
    PPU.modeclk += delta;

    switch (PPU.mode) {
        case MODE_OAM:
            if (PPU.modeclk >= 80) {
                PPU.modeclk -= 80;
                PPU.mode = MODE_VRAM;
            }
            break;
        case MODE_VRAM:
            if (PPU.modeclk >= 172) {
                PPU.modeclk -= 172;
                PPU.mode = MODE_HBLANK;

                // TODO: Write line to framebuffer
            }
            break;
        case MODE_HBLANK:
            if (PPU.modeclk >= 204) {
                PPU.modeclk -= 204;
                PPU.line++;

                if (PPU.line >= 143) {
                    PPU.mode = MODE_VBLANK;
                    // TODO: Copy framebuffer to window
                }
                else {
                    PPU.mode = MODE_OAM;
                }
            }
            break;
        case MODE_VBLANK:
            if (PPU.modeclk >= 4560) {
                PPU.modeclk -= 4560;
                PPU.mode = MODE_OAM;
                PPU.line = 0;
            }
            break;
        default:
            printf("Error: Detected an undefined GPU mode.\n");
            exit(EXIT_FAILURE);
            break;
    }
}

void PPU_draw(void) {
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

void PPU_randomize(void) {
    for (uint8_t i = 0; i < SCREEN_HEIGHT; i++) {
        for (uint8_t j = 0; j < SCREEN_WIDTH; j++) {
            framebuffer[i*SCREEN_WIDTH + j] = rand() % 4;
        }
    }
}

void PPU_exit(void) {
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    surface = NULL;
    window = NULL;
    SDL_Quit();
}
