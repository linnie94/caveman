#include <stdio.h>
#include <SDL2/SDL.h>

typedef struct
{
    SDL_Rect rect;
    int time;
    int frames;
    int stretch;
} Sprites;


Sprites* sprite(int x, int y);
