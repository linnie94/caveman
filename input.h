#include "sdl.h"

typedef struct
{
    int x;
    int y;
    const uint8_t* key;
    SDL_Event event;
    uint32_t button;
} Input;

Input* input();

