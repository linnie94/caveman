#pragma once

#include <SDL2/SDL.h>

struct Sdl
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    int xres;
    int yres;
    Sdl(int xres, int yres);
}
