//
//  main.c
//  caveman
//
//  Created by Lynn Hyerin Sohn on 2018-03-28.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Util.h"
#include "Map.h"
#include "Ghost.h"
#include "Portal.h"
#include "config.h"

int main()
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    int portal = 0;
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
    char* map[3][16] = {
        {
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,"
        },{
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,",
            ",,,,,,,,,,,,,,,,,,,,,,,,,"
        },{
            "                         ",
            " ####################### ",
            " ####################### ",
            " ####################### ",
            " ####################### ",
            " ####################### ",
            " ####################### ",
            " ####################### ",
            " ####################### ",
            " ####################### ",
            " ####################### ",
            " ####################### ",
            " ####################### ",
            " ####################### ",
            "                         ",
            "                         "
        }
    };

    char* map_obj[3][16] = {
        {
            "!!!!!!!!!!!! !!!!!!!!!!!!",
            "!                       !",
            "!                       !",
            "!                       !",
            "!                       !",
            "!                       !",
            "!                       !",
            "!  $$$$$$$$$$$$$$        ",
            "!  %%%%%%%%%%%%%%       !",
            "!  $$$$$$$$$$$$$$       !",
            "!                       !",
            "!                       !",
            "!                       !",
            "!                       !",
            "!!!!!!!!!!!!!!!!!!!!!!!!!",
            "!!!!!!!!!!!!!!!!!!!!!!!!!"
        },{
            "!!!!!!!!!!!!!!!!!!!!!!!!!",
            "!                       !",
            "!                       !",
            "!                       !",
            "!                       !",
            "!                       !",
            "!                       !",
            "!  $$$$$$$$$$$$$$       !",
            "! !%%%%%%%%%%%%%%!      !",
            "!  $$$$$$$$$$$$$$       !",
            "!                       !",
            "!                       !",
            "!                       !",
            "!                       !",
            "!!!!!!!!!!!! !!!!!!!!!!!!",
            "!!!!!!!!!!!!!!!!!!!!!!!!!"
        },{
            "*************************",
            "*                       *",
            "*                       *",
            "*                       *",
            "*                       *",
            "*                       *",
            "*                       *",
            "   $$$$$$$$$$$$$$       *",
            "*  %%%%%%%%%%%%%%       *",
            "*  $$$$$$$$$$$$$$       *",
            "*                       *",
            "*                       *",
            "*                       *",
            "*                       *",
            "*************************",
            "*************************"
        }
    };

    char* portals[3][16] = {
        {
            "            1            ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                        2",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         "
        },{
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "            0            "
        },{
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "0                        ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         ",
            "                         "
        }
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
        if(event.type == SDL_QUIT || key[SDL_SCANCODE_ESCAPE] || key[SDL_SCANCODE_END] || key[SDL_SCANCODE_X])
        {
            done = 1;
        }
        // Screen
        Util_QuickFill(renderer, 0, 0, 0);
        // Map
        Map_Draw(map[portal], xres, yres, renderer, texture);
        Map_Draw(map_obj[portal], xres, yres, renderer, texture);
        // Portals
        if(Portal_Location(portals[portal], &to_g) != -1)
        {
            portal = Portal_Location(portals[portal], &to_g);
        }
        // Ghost
        Ghost_Draw(s1, key, &from_g, &to_g);
        SDL_RenderCopy(renderer, texture_c, &from_g, &to_g);
        SDL_RenderPresent(renderer);
        const int t2 = SDL_GetTicks();
        const int ms = 1000.0 / (60 - (t2 - t1));
        SDL_Delay(ms < 0 ? 0 : ms);
    }
}
