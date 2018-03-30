#include "Util.h"

int main()
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    const int xres = 800;
    const int yres = 400;
    const uint8_t* key;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(xres, yres, 0, &window, &renderer);
    int done = 0;
    while(!done)
    {
        const int t1 = SDL_GetTicks();
        SDL_PollEvent(&event);
        key = SDL_GetKeyboardState(NULL);
        if(event.type == SDL_QUIT || key[SDL_SCANCODE_ESCAPE] || key[SDL_SCANCODE_END])
        {
            done = 1;
        }
        Util_QuickFill(renderer, rand() % 256, rand() % 256, rand() % 256);
        SDL_RenderPresent(renderer);
        const int t2 = SDL_GetTicks();
        const int ms = 1000.0 / (60 - (t2 - t1));
        SDL_Delay(ms < 0 ? 0 : ms);
    }

}
