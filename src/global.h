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
#include "game_setup.h"


#ifdef _WIN32
static const char* PlayerIMG = "res\\player.png";
static const char* EnemyIMG = "res\\enemy.png";
static const char* DeathScreenIMG = "res\\dead.png";
static const char* BGMusic = "res\\bgm.wav";
static const char* RestButtonIMG = "res\\restart-button.png";
static const char* MenuIMG = "res\\menutxt.png";
static const char* WinIMG = "res\\Win.png";
static const char* CredsIMG = "res\\credits.png";
#else
static const char* PlayerIMG = "res/player.png";
static const char* EnemyIMG = "res/enemy.png";
static const char* DeathScreenIMG = "res/dead.png";
static const char* BGMusic = "res/bgm.wav";
static const char* RestButtonIMG = "res/restart-button.png";
static const char* MenuIMG = "res/menutxt.png";
static const char* WinIMG = "res/Win.png";
static const char* CredsIMG = "res/credits.png";
#endif
static const int WinWidth = 800;
static const int WinHeight = 650;

