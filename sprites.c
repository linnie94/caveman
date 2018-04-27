#include "sprites.h"
#include <stdlib.h>

/*
typedef struct
{
    SDL_Rect rect;
    int time;
    int frames;
    int stretch;
} Sprites;
*/

Sprites* sprite(int x, int y)
{
    Sprites a;
    a.rect.x = rand() % 800;
    a.rect.y = rand() % 400;
    a.rect.w = x;
    a.rect.h = y;
    a.time = 0;
    a.frames = 12;
    a.stretch = 3;
}

