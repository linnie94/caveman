#pragma once

#include <SDL2/SDL.h>

typedef struct Sdl
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    int xres;
    int yres;
}sdl;
