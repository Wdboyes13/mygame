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

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>
#include "game_setup.h"
#include "views.h"

int main(int argc, char* argv[]) {
    (void)argv; (void)argc;
    init_game();

    int running = 1;
    SDL_Event e;
    char* CurrView = "Game";

    while (running){
        if (strcmp(CurrView, "Game") == 0){
            MainView(&e, &running, &CurrView);
        } else if (strcmp(CurrView, "Death") == 0) {
            DeadView(&e, &running, &CurrView);
        }
    }
    cleanup_game();
    return 0;
}