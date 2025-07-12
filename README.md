# A little game
__This is a little game made with SDL2__  


## Required  
You'll need 3 SDL Libraries  
SDL2, SDL2_mixer, and SDL2_image (With PNG Support)  
Linked are the releases I used  
[SDL2](https://github.com/libsdl-org/SDL/releases/tag/release-2.32.8)  
[SDL2_mixer](https://github.com/libsdl-org/SDL_mixer/releases/tag/release-2.8.1)  
[SDL2_image](https://github.com/libsdl-org/SDL_image/releases/tag/release-2.6.0)  

## Licensing  
__Main App License__  
__[Full License](/LICENSE)__  
__[License Info](/Licenses/main.txt)__  
- Copyright (c) 2025 Wdboyes13  
- License: GPLv3
  
__Background Music License__   
__[Full License](/Licenses/bgmfull.txt)__  
__[License Info](/Licenses/bgm.txt)__  
- Airport Lounge Kevin MacLeod (incompetech.com)   
- License:  Creative Commons: By Attribution 3.0 License   
  
__SDL2, SDL2_image, SDL2_mixer__    
__[License Info](/Licenses/sdl.txt)__  
- Copyright (C) 1997-2025 Sam Lantinga <slouken@libsdl.org>  
- License: ZLib  

__LLVM Libunwind__  
__[Full License](/Licenses/ApacheLLVM.txt)__  
- Copyright (c) LLVM Project  
- License: Apache 2.0 with LLVM Exception  

## To Build  
Quick build: `make` - This is a wrapper around CMake  
Normal Build:  
- `cmake -G Ninja`  
- `ninja`   
Using [CarMake](https://github.com/Wdboyes13/CarMake)  
- `cm -C cm --run`  