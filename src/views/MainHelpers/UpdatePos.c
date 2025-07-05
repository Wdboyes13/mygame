#include "../../game_setup.h"
#include <math.h>

void UpdatePos(){
    static float speed = 2.0f;
    static Uint32 lastTime = 0;     // last recorded time in ms
    static Uint32 elapsed = 0;      // accumulator for elapsed time

    Uint32 currentTime = SDL_GetTicks();
    if (lastTime == 0) lastTime = currentTime; // init on first call

    elapsed += (currentTime - lastTime);
    lastTime = currentTime;

    // Increase speed by 0.5 every 10 seconds (10000 ms)
    if (elapsed >= 10000) {
        speed += 0.5f;
        elapsed = 0;
        SDL_Log("Enemy speed increased to: %.2f\n", speed);
    }

    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_UP] || keystate[SDL_SCANCODE_W]) pos.y -= 5;
    if (keystate[SDL_SCANCODE_DOWN] || keystate[SDL_SCANCODE_S]) pos.y += 5;
    if (keystate[SDL_SCANCODE_LEFT] || keystate[SDL_SCANCODE_A]) pos.x -= 5;
    if (keystate[SDL_SCANCODE_RIGHT] || keystate[SDL_SCANCODE_D]) pos.x += 5;

    float dx = (float)(pos.x - enempos.x);
    float dy = (float)(pos.y - enempos.y);
    float length = sqrtf(dx*dx + dy*dy);
    if (length != 0) {
        dx /= length;
        dy /= length;
        enempos.x += (int)(dx * speed);
        enempos.y += (int)(dy * speed);
    }
}