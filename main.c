//#include <stdio.h>
//#include <SDL2/SDL.h>
#include "Util.h"

int main()
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    int xres = 800;
    int yres = 400;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(xres, yres, 0, &window, &renderer);
    Util_QuickFill(renderer, 255, 255, 0);
    Util_QuickFill(renderer, 255, 0, 0);
    Util_QuickFill(renderer, 0, 255, 0);
    Util_QuickFill(renderer, 0, 0, 255);

}
