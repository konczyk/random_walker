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
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

#define WALKER_SIZE 3
#define MAX_STEPS (((WINDOW_HEIGHT * WINDOW_WIDTH) / 2) / WALKER_SIZE)

struct State {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    bool is_running;
    struct SDL_FRect walker;
    uint32_t steps;

    uint64_t last_frame_time;
    uint64_t frame_count_init_time;
    int frame_count;
    int avg_fps;
    bool enable_fps_count;
};

#endif