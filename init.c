#include "init.h"

bool init_sdl(struct State *s) {
    if (!SDL_Init(SDL_FLAGS)) {
        fprintf(stderr, "Error initializing SDL3: %s\n", SDL_GetError());
        return false;
    }

    s->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!s->window) {
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
        return false;
    }

    s->renderer = SDL_CreateRenderer(s->window, nullptr);
    if (!s->renderer) {
        fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 255);
    SDL_RenderClear(s->renderer);

    return true;
}
