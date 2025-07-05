#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Expose these so main can access them
extern SDL_Window *win;
extern SDL_Renderer *ren;
extern SDL_Texture *sprite;
extern SDL_Texture *ensprite;
extern SDL_Texture *deadsprite;

extern SDL_Rect pos;
extern SDL_Rect enempos;
extern SDL_Rect deadpos;

int init_game(void);
void cleanup_game(void);