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

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdlib.h>

// Expose these so main can access them
extern SDL_Window *win;
extern SDL_Renderer *ren;
extern SDL_Texture *sprite;
extern SDL_Texture *ensprite;
extern SDL_Texture *deadsprite;
extern SDL_Texture *restsprite;

extern SDL_Rect restpos;
extern SDL_Rect pos;
extern SDL_Rect deadpos;

extern Mix_Music *music;

#define MAX_ENEMIES 100

extern SDL_Rect enemies[MAX_ENEMIES];
extern int enemy_count;


void init_game(void);
void cleanup_game(void);
void initmusic();
void repos();