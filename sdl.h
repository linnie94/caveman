#pragma once

#include <SDL2/SDL.h>
#include "Util.h"

typedef struct
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    int xres;
    int yres;
} Sdl;

Sdl* sdl(int xres, int yres);
