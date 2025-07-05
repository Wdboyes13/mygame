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

extern SDL_Rect pos;
extern SDL_Rect deadpos;

extern Mix_Music *music;

#define MAX_ENEMIES 100

extern SDL_Rect enemies[MAX_ENEMIES];
extern int enemy_count;


void init_game(void);
void cleanup_game(void);
void initmusic();