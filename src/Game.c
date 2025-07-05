#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game_setup.h"
#include "views.h"

int main(void){
    init_game();

    int running = 1;
    SDL_Event e;
    char* CurrView = "Game";

    while (running){
        if (strcmp(CurrView, "Game") == 0){
            MainView(&e, &running, &CurrView);
        } else if (strcmp(CurrView, "Death") == 0) {
            DeadView(&e, &running, &CurrView);
        }
    }
    cleanup_game();
    return 0;
}