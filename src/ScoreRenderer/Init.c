/*
A Little Game made with SDL2
Copyright (C) 2025  Wdboyes13

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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