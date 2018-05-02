//
//  main.c
//  caveman
//
//  Created by Lynn Hyerin Sohn on 2018-03-28.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Util.h"

int main()
{
    SDL_Window* window;
    SDL_Renderer* renderer = NULL;
    const int xres = 800;
    const int yres = 400;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(xres, yres, 0, &window, &renderer);
    SDL_Surface* surface = Util_load("art/basic.bmp", 255, 255, 255);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Surface* surface_c = Util_load("art/chars.bmp", 255, 255, 255);
    SDL_Texture* texture_c = SDL_CreateTextureFromSurface(renderer, surface_c);
    if(surface == NULL || texture == NULL)
    {
        printf("%s\n", SDL_GetError());
        exit(1);
    }
    // Input
    const uint8_t* key;
    SDL_Event event;

    // Main Loop
    int done = 0;
    while(!done)
    {
        const int t1 = SDL_GetTicks();
        // Exit
        SDL_PollEvent(&event);
        key = SDL_GetKeyboardState(NULL);
        if(event.type == SDL_QUIT || key[SDL_SCANCODE_ESCAPE] || key[SDL_SCANCODE_END])
        {
            done = 1;
        }
        // Screen
        Util_QuickFill(renderer, 0, 0, 0);
        // Grass
        SDL_Rect from;
        from.x = 0;
        from.y = 128;
        from.w = 16;
        from.h = 16;
        SDL_Rect to;
        to.x = 0;
        to.y = 0;
        to.w = 32;
        to.h = 32;
        for(int x = 0; x < xres; x += 32)
        {
            for(int y = 0; y < yres; y += 32)
            {
                to.x = x;
                to.y = y;
                SDL_RenderCopy(renderer, texture, &from, &to);
            }
        }
        // Ghost R
        SDL_Rect from_gr;
        from_gr.x = 96;
        from_gr.y = 96;
        from_gr.w = 16;
        from_gr.h = 16;
        SDL_Rect to_gr;
        to_gr.x = 16;
        to_gr.y = 16;
        to_gr.w = 32;
        to_gr.h = 32;
        SDL_RenderCopy(renderer, texture_c, &from_gr, &to_gr);
        // Ghost L
        SDL_Rect from_gl;
        from_gl.x = 96;
        from_gl.y = 80;
        from_gl.w = 16;
        from_gl.h = 16;
        SDL_Rect to_gl;
        to_gl.x = 0;
        to_gl.y = 16;
        to_gl.w = 32;
        to_gl.h = 32;
        SDL_RenderCopy(renderer, texture_c, &from_gl, &to_gl);
        // Ghost U
        SDL_Rect from_gu;
        from_gu.x = 96;
        from_gu.y = 112;
        from_gu.w = 16;
        from_gu.h = 16;
        SDL_Rect to_gu;
        to_gu.x = 96;
        to_gu.y = 16;
        to_gu.w = 32;
        to_gu.h = 32;
        SDL_RenderCopy(renderer, texture_c, &from_gu, &to_gu);
        // Ghost D
        SDL_Rect from_gd;
        from_gd.x = 96;
        from_gd.y = 64;
        from_gd.w = 16;
        from_gd.h = 16;
        SDL_Rect to_gd;
        to_gd.x = 48;
        to_gd.y = 16;
        to_gd.w = 32;
        to_gd.h = 32;
        SDL_RenderCopy(renderer, texture_c, &from_gd, &to_gd);
        
        SDL_RenderPresent(renderer);
        const int t2 = SDL_GetTicks();
        const int ms = 1000.0 / (60 - (t2 - t1));
        SDL_Delay(ms < 0 ? 0 : ms);
    }
}
