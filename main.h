#ifndef SDL_MAIN_H
#define SDL_MAIN_H

#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include <stdio.h>
#include <stdlib.h>

#define SDL_FLAGS SDL_INIT_VIDEO
#define WINDOW_TITLE "Random Walker"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

struct State {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    bool is_running;
    struct SDL_FRect walker;
};

#endif