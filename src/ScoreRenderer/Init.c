#include "Numbers.h"


SDL_Texture *sprite0 = NULL;
SDL_Texture *sprite1 = NULL;
SDL_Texture *sprite2 = NULL;
SDL_Texture *sprite3 = NULL;
SDL_Texture *sprite4 = NULL;
SDL_Texture *sprite5 = NULL;
SDL_Texture *sprite6 = NULL;
SDL_Texture *sprite7 = NULL;
SDL_Texture *sprite8 = NULL;
SDL_Texture *sprite9 = NULL;\


#define InitNum(num)  \
    SDL_Surface* surf##num = IMG_Load(IMG##num); \
    if (!surf##num) exit(1); \
    sprite##num = SDL_CreateTextureFromSurface(ren, surf##num); \
    SDL_FreeSurface(surf##num)

void InitNumRend(void){
    InitNum(0); InitNum(1); InitNum(2);
    InitNum(3); InitNum(4); InitNum(5);
    InitNum(6); InitNum(7); InitNum(8);
    InitNum(9);
}