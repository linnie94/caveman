#include "Portal.h"

int Portal_Location(char* portals[], SDL_Rect* to_g)
{
    if(portals[(to_g->y + 16) / 32][(to_g->x + 16) / 32] != ' ')
    {
        return portals[(to_g->y + 16) / 32][(to_g->x + 16) / 32] - '0';
    }
    return -1;
}
