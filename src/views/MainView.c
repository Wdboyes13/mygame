#include "../views.h"
#include "../game_setup.h"
#include "MainHelpers/Helpers.h"

void MainView(SDL_Event *e, int *running, char** CurrView){
    UpdatePos();
    while (SDL_PollEvent(e)) {
        if (e->type == SDL_QUIT) *running = 0;
    }

    if (SDL_HasIntersection(&pos, &enempos)){
        SDL_Log("Player Hit Enemy Detected\n");
        *CurrView = "Death";
    }

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // clear screen
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, sprite, NULL, &pos);   // draw sprite
    SDL_RenderCopy(ren, ensprite, NULL, &enempos);
    SDL_RenderPresent(ren);                    // update screen
    SDL_Delay(16); // ~60 FPS
}