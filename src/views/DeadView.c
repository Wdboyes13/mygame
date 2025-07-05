#include "../views.h"
#include "../game_setup.h"

void DeadView(SDL_Event *e, int* running, char **CurrView){
    (void)CurrView;
    while (SDL_PollEvent(e)) {
        if (e->type == SDL_QUIT) *running = 0;
    }
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, deadsprite, NULL, &deadpos);
    SDL_RenderPresent(ren);
    SDL_Delay(16);
}