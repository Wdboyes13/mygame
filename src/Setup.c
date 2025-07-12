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

#include "game_setup.h"
#include "global.h"
#include "ScoreRenderer/Numbers.h"

SDL_Window *win = NULL;
SDL_Renderer *ren = NULL;

SDL_Texture *sprite = NULL; SDL_Texture *ensprite = NULL;
SDL_Texture *deadsprite = NULL; SDL_Texture *restsprite = NULL;
SDL_Texture *menusprite = NULL; SDL_Texture *winsprite = NULL;
SDL_Texture *credsprite = NULL;
Mix_Music *music = NULL;

SDL_Rect pos; SDL_Rect restpos;
SDL_Rect deadpos; SDL_Rect origpos;
SDL_Rect menupos; SDL_Rect credpos;
SDL_Rect enemies[MAX_ENEMIES] = {0};
int enemy_count = 1;
int points = 0;

SDL_Rect ScorePos1; SDL_Rect ScorePos2;

void repos(){
    pos = (SDL_Rect){100, 100, 64, 64};
    enemies[0] = (SDL_Rect){(WinWidth - 64) / 2, (WinHeight - 64) / 2, 64, 64};
    deadpos = (SDL_Rect){(WinWidth - 400) / 2, (WinHeight - 200) / 2, 400, 200};
    restpos = (SDL_Rect){(WinWidth - 200) / 2, ((WinHeight - 100) / 2) + 125, 200, 100};
    menupos = (SDL_Rect){(WinWidth - 340) / 2, (WinHeight - 150) / 2, 340, 150};
}

#define InitSprite(SpriteName, SpriteIMG) \
    SDL_Surface* SpriteName##surf = IMG_Load(SpriteIMG); \
    if (!SpriteName##surf) exit(1); \
    SpriteName = SDL_CreateTextureFromSurface(ren, SpriteName##surf); \
    SDL_FreeSurface(SpriteName##surf); 

#define KillSprite(SpriteName) if (SpriteName) SDL_DestroyTexture(SpriteName)

void init_game(void) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) exit(1);
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) exit(1);

    initmusic();

    win = SDL_CreateWindow("Le Gamé", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WinWidth, WinHeight, 0);
    if (!win) exit(1);

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!ren) exit(1);
    
    InitSprite(sprite, PlayerIMG);
    InitSprite(ensprite, EnemyIMG);
    InitSprite(deadsprite, DeathScreenIMG);
    InitSprite(restsprite, RestButtonIMG);
    InitSprite(menusprite, MenuIMG);
    InitSprite(winsprite, WinIMG);
    InitSprite(credsprite, CredsIMG);

    InitNumRend();

    repos();

    ScorePos1 = (SDL_Rect){WinWidth -50, WinHeight - 50, 25, 50}; // First digit
    ScorePos2 = (SDL_Rect){WinWidth - 25, WinHeight - 50, 25, 50};  // Second digit
    credpos = (SDL_Rect){(WinWidth - 800) / 2, (WinHeight - 650) / 2, 800, 650};
}

void cleanup_game(void) {
    KillSprite(sprite); KillSprite(ensprite);
    KillSprite(deadsprite); KillSprite(restsprite);
    KillSprite(menusprite); KillSprite(winsprite);
    KillSprite(credsprite);

    if(ren) SDL_DestroyRenderer(ren);
    if(win) SDL_DestroyWindow(win);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();
}