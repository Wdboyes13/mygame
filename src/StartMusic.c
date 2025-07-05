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