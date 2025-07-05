#include "../views.h"
#include "../game_setup.h"
#include "MainHelpers/Helpers.h"

void MainView(SDL_Event *e, int *running, char** CurrView){
    UpdatePos();
    while (SDL_PollEvent(e)) {
        if (e->type == SDL_QUIT) *running = 0;
    }

    for (int i = 0; i < enemy_count; i++){
        if (SDL_HasIntersection(&pos, &enemies[i])){
            SDL_Log("Player hit enemy #%d\n", i);
            *CurrView = "Death";
            break;
        }
    }

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // clear screen
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, sprite, NULL, &pos);   // draw sprite
    for (int i = 0; i < enemy_count; ++i) {
        SDL_RenderCopy(ren, ensprite, NULL, &enemies[i]);
    }
    SDL_RenderPresent(ren);                    // update screen
    SDL_Delay(16); // ~60 FPS
}