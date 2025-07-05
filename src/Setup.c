#include "game_setup.h"
#include "global.h"  // Your definitions for WinWidth, PlayerIMG, etc.

SDL_Window *win = NULL;
SDL_Renderer *ren = NULL;
SDL_Texture *sprite = NULL;
SDL_Texture *ensprite = NULL;
SDL_Texture *deadsprite = NULL;

SDL_Rect pos;
SDL_Rect enempos;
SDL_Rect deadpos;

int init_game(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return -1;
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) return -1;

    win = SDL_CreateWindow("Gamé", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WinWidth, WinHeight, 0);
    if (!win) return -1;

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!ren) return -1;

    SDL_Surface* surf = IMG_Load(PlayerIMG);
    if (!surf) return -1;
    sprite = SDL_CreateTextureFromSurface(ren, surf);
    SDL_FreeSurface(surf);

    SDL_Surface* ensurf = IMG_Load(EnemyIMG);
    if (!ensurf) return -1;
    ensprite = SDL_CreateTextureFromSurface(ren, ensurf);
    SDL_FreeSurface(ensurf);

    SDL_Surface* deadsurf = IMG_Load(DeathScreenIMG);
    if (!deadsurf) return -1;
    deadsprite = SDL_CreateTextureFromSurface(ren, deadsurf);
    SDL_FreeSurface(deadsurf);

    pos = (SDL_Rect){100, 100, 64, 64};
    enempos = (SDL_Rect){(WinWidth - 64) / 2, (WinHeight - 64) / 2, 64, 64};
    deadpos = (SDL_Rect){(WinWidth - 400) / 2, (WinHeight - 200) / 2, 400, 200};

    return 0;
}

void cleanup_game(void) {
    if(sprite) SDL_DestroyTexture(sprite);
    if(ensprite) SDL_DestroyTexture(ensprite);
    if(deadsprite) SDL_DestroyTexture(deadsprite);
    if(ren) SDL_DestroyRenderer(ren);
    if(win) SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
}