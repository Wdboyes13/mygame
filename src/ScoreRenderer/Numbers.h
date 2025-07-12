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

#include "../game_setup.h"


#ifdef _WIN32
static const char* IMG0 = "res\\nums\\0.png";
static const char* IMG1 = "res\\nums\\1.png";
static const char* IMG2 = "res\\nums\\2.png";
static const char* IMG3 = "res\\nums\\3.png";
static const char* IMG4 = "res\\nums\\4.png";
static const char* IMG5 = "res\\nums\\5.png";
static const char* IMG6 = "res\\nums\\6.png";
static const char* IMG7 = "res\\nums\\7.png";
static const char* IMG8 = "res\\nums\\8.png";
static const char* IMG9 = "res\\nums\\9.png";
#elif defined(__APPLE__RELEASE__)
static const char* IMG0 = "../Resources/GameImage/nums/0.png";
static const char* IMG1 = "../Resources/GameImage/nums/1.png";
static const char* IMG2 = "../Resources/GameImage/nums/2.png";
static const char* IMG3 = "../Resources/GameImage/nums/3.png";
static const char* IMG4 = "../Resources/GameImage/nums/4.png";
static const char* IMG5 = "../Resources/GameImage/nums/5.png";
static const char* IMG6 = "../Resources/GameImage/nums/6.png";
static const char* IMG7 = "../Resources/GameImage/nums/7.png";
static const char* IMG8 = "../Resources/GameImage/nums/8.png";
static const char* IMG9 = "../Resources/GameImage/nums/9.png";
#else
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
#endif


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