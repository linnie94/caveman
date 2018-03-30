#include "Util.h"

int main()
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    int xres = 800;
    int yres = 400;
    const uint8_t* key;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(xres, yres, 0, &window, &renderer);
    int done = 0;
    while(!done)
    {
        int t1;
        t1 = SDL_GetTicks();
        SDL_PollEvent(&event);
        key = SDL_GetKeyboardState(NULL);
        if(event.type == SDL_QUIT || key[SDL_SCANCODE_ESCAPE] || key[SDL_SCANCODE_END])
        {
            done = 1;
        }

        Util_QuickFill(renderer, 255, 255, 0);
        SDL_Delay(60);
        Util_QuickFill(renderer, 255, 0, 0);
        SDL_Delay(60);
        Util_QuickFill(renderer, 0, 255, 0);
        SDL_Delay(60);
        Util_QuickFill(renderer, 0, 0, 255);
        SDL_Delay(60);
        int t2;
        t2 = SDL_GetTicks();
        printf("%d\n", t2 - t1);
    }

}
