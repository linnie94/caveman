#pragma once

#include <stdio.h>
#include <SDL2/SDL.h>

void Util_Check(void* p);

void Util_QuickFill(SDL_Renderer* renderer, int r, int g, int b);

SDL_Surface* Util_load(const char* path, uint32_t r, uint32_t g, uint32_t b);


