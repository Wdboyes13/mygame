#include "game_setup.h"
#include "global.h"  // Your definitions for WinWidth, PlayerIMG, etc.

SDL_Window *win = NULL;
SDL_Renderer *ren = NULL;
SDL_Texture *sprite = NULL;
SDL_Texture *ensprite = NULL;
SDL_Texture *deadsprite = NULL;
Mix_Music *music = NULL;

SDL_Rect pos;
SDL_Rect deadpos;
SDL_Rect enemies[MAX_ENEMIES] = {0};
int enemy_count = 1;

void init_game(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) exit(1);
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) exit(1);

    initmusic();

    win = SDL_CreateWindow("Le Gamé", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WinWidth, WinHeight, 0);
    if (!win) exit(1);

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!ren) exit(1);

    SDL_Surface* surf = IMG_Load(PlayerIMG);
    if (!surf) exit(1);
    sprite = SDL_CreateTextureFromSurface(ren, surf);
    SDL_FreeSurface(surf);

    SDL_Surface* ensurf = IMG_Load(EnemyIMG);
    if (!ensurf) exit(1);
    ensprite = SDL_CreateTextureFromSurface(ren, ensurf);
    SDL_FreeSurface(ensurf);

    SDL_Surface* deadsurf = IMG_Load(DeathScreenIMG);
    if (!deadsurf) exit(1);
    deadsprite = SDL_CreateTextureFromSurface(ren, deadsurf);
    SDL_FreeSurface(deadsurf);

    pos = (SDL_Rect){100, 100, 64, 64};
    enemies[0] = (SDL_Rect){(WinWidth - 64) / 2, (WinHeight - 64) / 2, 64, 64};
    deadpos = (SDL_Rect){(WinWidth - 400) / 2, (WinHeight - 200) / 2, 400, 200};
}

void cleanup_game(void) {
    if(sprite) SDL_DestroyTexture(sprite);
    if(ensprite) SDL_DestroyTexture(ensprite);
    if(deadsprite) SDL_DestroyTexture(deadsprite);
    if(ren) SDL_DestroyRenderer(ren);
    if(win) SDL_DestroyWindow(win);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();
}