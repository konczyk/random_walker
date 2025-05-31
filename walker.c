#include "walker.h"

bool init_walker(struct State *s) {
    SDL_FRect walker;
    walker.x = WINDOW_WIDTH / 2;
    walker.y = WINDOW_HEIGHT / 2;
    walker.w = WALKER_SIZE;
    walker.h = WALKER_SIZE;
    s->walker = walker;

    return true;
}

void draw_walker(struct State *s) {
    SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(s->renderer, &s->walker);
}
