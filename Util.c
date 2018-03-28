#include "Util.h"

void Util_QuickFill(SDL_Renderer* renderer, int r, int g, int b)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

