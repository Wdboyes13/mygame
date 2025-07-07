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
#include "../global.h"
#include "MainHelpers/Helpers.h"

Uint32 lastTime = 0;     // last recorded time in ms
Uint32 lastSpawn = 0;

void ResetTimers() {
    Uint32 now = SDL_GetTicks();
    lastTime = now;
    lastSpawn = now - 10001; // forces immediate spawn next frame
}

void MainView(SDL_Event *e, int *running, char** CurrView){
    Uint32 currentTime = SDL_GetTicks();
    if (lastTime == 0) lastTime = currentTime;
    lastTime = currentTime;

    // Multiply enemies every 10 seconds
    if (currentTime - lastSpawn > 10000 && enemy_count < MAX_ENEMIES) {
        enemies[enemy_count++] = (SDL_Rect){
            rand() % (WinWidth - 64),
            rand() % (WinHeight - 64),
            64, 64
        };
        lastSpawn = currentTime;
        SDL_Log("Spawned enemy #%d\n", enemy_count);
    }

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