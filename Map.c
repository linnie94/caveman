#include "Map.h"

static SDL_Rect get_tile(char c)
{
    switch(c)
    {
        default:
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
        case '#':
            {
                SDL_Rect floor;
                floor.x = 16;
                floor.y = 144;
                floor.w = floor.h = 16;
                return floor;
            }
        case '*':
            {
                SDL_Rect torch;
                torch.x = 64;
                torch.y = 112;
                torch.w = torch.h = 16;
                return torch;
            }
    }
}

void Map_Draw(char* map[3][16], int xres, int yres, SDL_Renderer* renderer, SDL_Texture* texture)
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
