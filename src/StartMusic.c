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

#include "game_setup.h"
#include "global.h"

void initmusic(){
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    // Initialize SDL_mixer with MP3 support
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! Mix_Error: %s\n", Mix_GetError());
        SDL_Quit();
        exit(1);
    }

    music = Mix_LoadMUS(BGMusic);
    if (!music) {
        printf("Failed to load MP3: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        exit(1);
    }

    // Play the music (-1 means loop indefinitely)
    if (Mix_PlayMusic(music, -1) == -1) {
        printf("Mix_PlayMusic error: %s\n", Mix_GetError());
    }
}