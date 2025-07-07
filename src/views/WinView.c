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

void WinView(SDL_Event *e, int* running, char **CurrView){
    (void)CurrView;
    while (SDL_PollEvent(e)) {
        if (e->type == SDL_QUIT) *running = 0;
        else if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT) {
            int mx = e->button.x;
            int my = e->button.y;

            // Check if the click is inside restpos
            if (mx >= restpos.x && mx <= restpos.x + restpos.w &&
                my >= restpos.y && my <= restpos.y + restpos.h) {
                    
                memset(enemies, 0, sizeof(enemies));
                enemy_count = 0;
                points = 0;
                repos();
                ResetTimers();
                *CurrView = "Game";  // or whatever view string you use
                return;
            }
        } 
    }

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, winsprite, NULL, &deadpos);
    SDL_RenderCopy(ren, restsprite, NULL, &restpos);
    SDL_RenderPresent(ren);
    SDL_Delay(16);
}