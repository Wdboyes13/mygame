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

#include "../views.h"
#include "../game_setup.h"
#include "MainHelpers/Helpers.h"
#include "SDL2/SDL_mixer.h"


void MenuView(SDL_Event *e, int *running, char** CurrView) {
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_SPACE]) {
        memset(enemies, 0, sizeof(enemies));
         enemy_count = 0;
        points = -10;
        repos();
        ResetTimers();
        *CurrView = "Game"; 
    }
    if (keystate[SDL_SCANCODE_C]) *CurrView = "Creds";
    if (keystate[SDL_SCANCODE_M]) {
    if (Mix_PlayingMusic()) {
        if (Mix_PausedMusic()) {
                Mix_ResumeMusic();  // ← unpause
            } else {
                Mix_PauseMusic();   // ← pause
            }
        } else {
            if (Mix_PlayMusic(music, -1) == -1) {
                printf("Mix_PlayMusic error: %s\n", Mix_GetError());
            }
        }
        SDL_Delay(200);
    }
    
    while (SDL_PollEvent(e)) {
        if (e->type == SDL_QUIT) *running = 0;
    }

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // clear screen
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, menusprite, NULL, &menupos);   // draw sprite
    SDL_RenderPresent(ren);                    // update screen
    SDL_Delay(16); // ~60 FPS
}