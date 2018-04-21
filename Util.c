#include "Util.h"

void Util_QuickFill(SDL_Renderer* renderer, int r, int g, int b)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
}

void check(void* p)
{
    if(p == NULL)
    {
        printf(SDL_GetError()\n);
        exit(1);
    }
}

SDL_Surface* load(const char* path, uint32_t r, uint32_t g, uint32_t b)
{
    // Loads surface from bmp image.
    SDL_Surface* bmp = SDL_LoadBMP(path);
    check(bmp);
    // Removes alpha channel from surface so a color key can be applied to surface.
    SDL_PixelFormat* allocation = SDL_AllocFormat(SDL_PIXELFORMAT_RGB888);
    check(allocation);
    SDL_Surface* converted = SDL_ConvertSurface(bmp, allocation, 0);
    check(converted);
    // Frees old surface.
    SDL_FreeFormat(allocation);
    SDL_FreeSurface(bmp);
    // Applies color key to new surface.
    SDL_SetColorKey(converted, SDL_TRUE, SDL_MapRGB(converted->format, r, g, b));
    // Returns new surface.
    return converted;
}

