//
//  main.c
//  caveman
//
//  Created by Lynn Hyerin Sohn on 2018-03-28.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Util.h"

void draw_grass(int xres, int yres, SDL_Renderer* renderer, SDL_Texture* texture)
{
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
}

void draw_ghost(uint8_t* key, float vx, float vy, SDL_Renderer* renderer, SDL_Texture* texture_c, SDL_Rect* to_g)
{
    SDL_Rect from_g;
    from_g.x = 96;
    from_g.y = 96;
    from_g.w = 16;
    from_g.h = 16;
    if(vx > 0)
    {
        to_g->x += vx;
    }
    else
    {
        to_g->x -= vx;
    }
    if(vy > 0)
    {
        to_g->y += vy;
    }
    else
    {
        to_g->y -= vy;
    }
    if(key[SDL_SCANCODE_D])
    {
        vx += 1;
        from_g.y = 96;
    }
    if(key[SDL_SCANCODE_A])
    {
        vx -= 1;
        from_g.y = 80;
    }
    if(key[SDL_SCANCODE_W])
    {
        vy -= 1;
        from_g.y = 112;
    }
    if(key[SDL_SCANCODE_S])
    {
        vy += 1;
        from_g.y = 64;
    }
    SDL_RenderCopy(renderer, texture_c, &from_g, &to_g);
}

int main()
{
    SDL_Window* window;
    SDL_Renderer* renderer = NULL;
    const int xres = 800;
    const int yres = 400;
    float vx = 0.0;
    float vy = 0.0;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(xres, yres, 0, &window, &renderer);
    SDL_Surface* surface = Util_load("art/basic.bmp", 255, 255, 255);
    SDL_Surface* surface_c = Util_load("art/chars.bmp", 255, 255, 255);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Texture* texture_c = SDL_CreateTextureFromSurface(renderer, surface_c);
    if(surface == NULL || texture == NULL)
    {
        printf("%s\n", SDL_GetError());
        exit(1);
    }
    // Input
    const uint8_t* key = SDL_GetKeyboardState(NULL);
    SDL_Event event;

    SDL_Rect to_g;
    to_g->x = 16;
    to_g->y = 16;
    to_g->w = 32;
    to_g->h = 32;

    // Main Loop
    int done = 0;
    while(!done)
    {
        const int t1 = SDL_GetTicks();
        // Exit
        SDL_PollEvent(&event);
        key = SDL_GetKeyboardState(NULL);
        if(event.type == SDL_QUIT || key[SDL_SCANCODE_ESCAPE] || key[SDL_SCANCODE_END] || key[SDL_SCANCODE_X])
        {
            done = 1;
        }
        // Screen
        Util_QuickFill(renderer, 0, 0, 0);
        draw_grass(xres, yres, renderer, texture);
        // Ghost
        draw_ghost(key, vx, vy, renderer, texture_c, &to_g);
        SDL_RenderPresent(renderer);
        const int t2 = SDL_GetTicks();
        const int ms = 1000.0 / (60 - (t2 - t1));
        SDL_Delay(ms < 0 ? 0 : ms);
    }
}
