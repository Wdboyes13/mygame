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

void MainView(SDL_Event *e, int *running, char** CurrView);
void DeadView(SDL_Event *e, int *running, char** CurrView);
void MenuView(SDL_Event *e, int *running, char** CurrView);
void WinView(SDL_Event *e, int* running, char **CurrView);
void CredsView(SDL_Event *e, int *running, char** CurrView);