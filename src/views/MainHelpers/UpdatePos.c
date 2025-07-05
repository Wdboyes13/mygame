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

#include "../../game_setup.h"
#include "../../global.h"
#include <math.h>
#include <stdlib.h>

void UpdatePos(){
    static float speed = 2.0f;
    static Uint32 lastTime = 0;     // last recorded time in ms
    static Uint32 elapsed = 0;      // accumulator for elapsed time
    static Uint32 lastSpawn = 0;

    Uint32 currentTime = SDL_GetTicks();
    if (lastTime == 0) lastTime = currentTime;

    Uint32 delta = currentTime - lastTime;
    elapsed += delta;
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

    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_UP] || keystate[SDL_SCANCODE_W]) pos.y -= 5;
    if (keystate[SDL_SCANCODE_DOWN] || keystate[SDL_SCANCODE_S]) pos.y += 5;
    if (keystate[SDL_SCANCODE_LEFT] || keystate[SDL_SCANCODE_A]) pos.x -= 5;
    if (keystate[SDL_SCANCODE_RIGHT] || keystate[SDL_SCANCODE_D]) pos.x += 5;

    // Move all enemies toward player
    for (int i = 0; i < enemy_count; ++i) {
        float dx = (float)(pos.x - enemies[i].x);
        float dy = (float)(pos.y - enemies[i].y);
        float length = sqrtf(dx * dx + dy * dy);
        if (length != 0) {
            dx /= length;
            dy /= length;
            enemies[i].x += (int)(dx * speed);
            enemies[i].y += (int)(dy * speed);
        }
    }
}