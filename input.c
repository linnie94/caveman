#include "input.h"


Input* input()
{
    SDL_PollEvent(&event);
    button = SDL_GetMouseState(&x, &y);
}

