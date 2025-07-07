#pragma once

#include "../game_setup.h"

static const char* IMG0 = "res/nums/0.png";
static const char* IMG1 = "res/nums/1.png";
static const char* IMG2 = "res/nums/2.png";
static const char* IMG3 = "res/nums/3.png";
static const char* IMG4 = "res/nums/4.png";
static const char* IMG5 = "res/nums/5.png";
static const char* IMG6 = "res/nums/6.png";
static const char* IMG7 = "res/nums/7.png";
static const char* IMG8 = "res/nums/8.png";
static const char* IMG9 = "res/nums/9.png";

extern SDL_Texture *sprite0;
extern SDL_Texture *sprite1;
extern SDL_Texture *sprite2;
extern SDL_Texture *sprite3;
extern SDL_Texture *sprite4;
extern SDL_Texture *sprite5;
extern SDL_Texture *sprite6;
extern SDL_Texture *sprite7;
extern SDL_Texture *sprite8;
extern SDL_Texture *sprite9;

void InitNumRend(void);
void Render2DNumber(int Number, SDL_Rect Pos1, SDL_Rect Pos2);