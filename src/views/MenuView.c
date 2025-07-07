#include "../views.h"
#include "../game_setup.h"
#include "../ScoreRenderer/Numbers.h"

void MenuView(SDL_Event *e, int *running, char** CurrView) {
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_SPACE]) *CurrView = "Game";
    
    while (SDL_PollEvent(e)) {
        if (e->type == SDL_QUIT) *running = 0;
    }

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // clear screen
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, menusprite, NULL, &menupos);   // draw sprite
    Render2DNumber(10, ScorePos1, ScorePos2);
    SDL_RenderPresent(ren);                    // update screen
    SDL_Delay(16); // ~60 FPS
}