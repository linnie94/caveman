//
//  main.c
//  caveman
//
//  Created by Lynn Hyerin Sohn on 2018-03-28.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Util.h"

#define WTO 32
#define WFROM 16

void draw_grass(int xres, int yres, SDL_Renderer* renderer, SDL_Texture* texture)
{
    // Grass
    SDL_Rect from = {0, 128, WFROM, WFROM};
    SDL_Rect to = {0, 0, WTO, WTO};
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

void draw_ghost(int s1, uint8_t* key, SDL_Rect* from_g, SDL_Rect* to_g)
{
    if(key[SDL_SCANCODE_D])
    {
        if(s1 % 3 == 1)
        {
            from_g->x = 96;
            from_g->y = 96;
        }
        else if(s1 % 3 == 2)
        {
            from_g->x = 112;
            from_g->y = 96;
        }
        else if(s1 % 3 == 3)
        {
            from_g->x = 128;
            from_g->y = 96;
        }
        to_g->x += 1;
        from_g->y = 96;
    }
    else if(from_g->y == 96)
    {
        if(s1 % 3 == 1)
        {
            from_g->x = 96;
            from_g->y = 96;
        }
        else if(s1 % 3 == 2)
        {
            from_g->x = 112;
            from_g->y = 96;
        }
        else if(s1 % 3 == 3)
        {
            from_g->x = 128;
            from_g->y = 96;
        }
    }
    if(key[SDL_SCANCODE_A])
    {
        if(s1 % 3 == 1)
        {
            from_g->x = 96;
            from_g->y = 80;
        }
        else if(s1 % 3 == 2)
        {
            from_g->x = 112;
            from_g->y = 80;
        }
        else if(s1 % 3 == 3)
        {
            from_g->x = 128;
            from_g->y = 80;
        }
        to_g->x -= 1;
        from_g->y = 80;
    }
    else if(from_g->y == 80)
    {
        if(s1 % 3 == 1)
        {
            from_g->x = 96;
            from_g->y = 80;
        }
        else if(s1 % 3 == 2)
        {
            from_g->x = 112;
            from_g->y = 80;
        }
        else if(s1 % 3 == 3)
        {
            from_g->x = 128;
            from_g->y = 80;
        }
    }
    if(key[SDL_SCANCODE_W])
    {
        if(s1 % 3 == 1)
        {
            from_g->x = 96;
            from_g->y = 112;
        }
        else if(s1 % 3 == 2)
        {
            from_g->x = 112;
            from_g->y = 112;
        }
        else if(s1 % 3 == 3)
        {
            from_g->x = 128;
            from_g->y = 112;
        }
        to_g->y -= 1;
        from_g->y = 112;
    }
    else if(from_g->y == 112)
    {
        if(s1 % 3 == 1)
        {
            from_g->x = 96;
            from_g->y = 112;
        }
        else if(s1 % 3 == 2)
        {
            from_g->x = 112;
            from_g->y = 112;
        }
        else if(s1 % 3 == 3)
        {
            from_g->x = 128;
            from_g->y = 112;
        }
    }
    if(key[SDL_SCANCODE_S])
    {
        if(s1 % 3 == 1)
        {
            from_g->x = 96;
            from_g->y = 64;
        }
        else if(s1 % 3 == 2)
        {
            from_g->x = 112;
            from_g->y = 64;
        }
        else if(s1 % 3 == 3)
        {
            from_g->x = 128;
            from_g->y = 64;
        }
        to_g->y += 1;
        from_g->y = 64;
    }
    else if(from_g->y == 64)
    {
        if(s1 % 3 == 1)
        {
            from_g->x = 96;
            from_g->y = 64;
        }
        else if(s1 % 3 == 2)
        {
            from_g->x = 112;
            from_g->y = 64;
        }
        else if(s1 % 3 == 3)
        {
            from_g->x = 128;
            from_g->y = 64;
        }
    }
}

SDL_Rect get_tile(char c)
{
    switch(c)
    {
        case ',':
            {
                SDL_Rect grass;
                grass.x = 0;
                grass.y = 128;
                grass.w = grass.h = 16;
                return grass;
            }
        case '%':
            {
                SDL_Rect river;
                river.x = 80;
                river.y = 32;
                river.w = river.h = 16;
                return river;
            }
        case '$':
            {
                SDL_Rect rock;
                rock.x = 32;
                rock.y = 112;
                rock.w = rock.h = 16;
                return rock;
            }
        case '!':
            {
                SDL_Rect tree;
                tree.x = 64;
                tree.y = 144;
                tree.w = tree.h = 16;
                return tree;
            }
    }
}

SDL_Rect* draw_map(char* map[], int xres, int yres, SDL_Renderer* renderer, SDL_Texture* texture)
{
    SDL_Rect to = {0, 0, 32, 32};
    for(int x = 0; x <= xres; x += 32)
    {
        for(int y = 0; y <= yres; y += 32)
        {
            char c = map[y/32][x/32];
            if(c != ' ')
            {
                SDL_Rect from = get_tile(c);
                to.x = x;
                to.y = y;
                SDL_RenderCopy(renderer, texture, &from, &to);
            }
        }
    }
}

void get_pos()
{
}

void print_number(char* portals[], SDL_Renderer* renderer, SDL_Texture* texture)
{
}

int main()
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    const int xres = 800;
    const int yres = 480;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(xres, yres, 0, &window, &renderer);
    SDL_Surface* surface = Util_load("art/basic.bmp", 255, 255, 255);
    SDL_Surface* surface_c = Util_load("art/chars.bmp", 255, 255, 255);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Texture* texture_c = SDL_CreateTextureFromSurface(renderer, surface_c);
    Util_Check(surface);
    Util_Check(texture);
    // Map
    char* map[] = {
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,",
        ",,,,,,,,,,,,,,,,,,,,,,,,,,"
    };

    char* map_obj[] = {
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "   $$$$$$$$$$$$$$         ",
        "  !%%%%%%%%%%%%%%!        ",
        "   $$$$$$$$$$$$$$         ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          "
    };

    char* portals[] = {
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "1                         ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          ",
        "                          "
    };

    // Input
    const uint8_t* key = SDL_GetKeyboardState(NULL);
    SDL_Event event;

    // Ghost
    SDL_Rect from_g = {96, 96, 16, 16};
    SDL_Rect to_g = {360, 200, 32, 32};

    // Main Loop
    int done = 0;
    while(!done)
    {
        const int t1 = SDL_GetTicks();
        int s1 = (t1/250) % 16;
        // Exit
        SDL_PollEvent(&event);
        key = SDL_GetKeyboardState(NULL);
        if(event.type == SDL_QUIT || key[SDL_SCANCODE_ESCAPE] || key[SDL_SCANCODE_END] || key[SDL_SCANCODE_X])
        {
            done = 1;
        }
        // Screen
        Util_QuickFill(renderer, 0, 0, 0);
        // Map
        draw_map(map, xres, yres, renderer, texture);
        draw_map(map_obj, xres, yres, renderer, texture);
        // Portals
        // Ghost
        draw_ghost(s1, key, &from_g, &to_g);
        SDL_RenderCopy(renderer, texture_c, &from_g, &to_g);
        SDL_RenderPresent(renderer);
        const int t2 = SDL_GetTicks();
        const int ms = 1000.0 / (60 - (t2 - t1));
        SDL_Delay(ms < 0 ? 0 : ms);
    }
}
