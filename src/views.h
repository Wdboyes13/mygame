#pragma once

#include <SDL2/SDL.h>

void MainView(SDL_Event *e, int *running, char** CurrView);
void DeadView(SDL_Event *e, int *running, char** CurrView);