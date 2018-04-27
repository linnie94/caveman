#include "sdl.h"

/*
typedef struct
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    int xres;
    int yres;
} Sdl;
*/

Sdl* sdl(int xres, int yres)
{
    Sdl s;
    s.xres = xres;
    s.yres = yres;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(xres, yres, 0, s.window, s.renderer);
    if(s.window == NULL || s.renderer == NULL)
    {
        printf("%s\n", SDL_GetError());
    }
}
