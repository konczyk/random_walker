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

void update_walker(struct State *s) {
    int step = rand() % 4;
    switch (step) {
        case 0:
            if (s->walker.x + WALKER_SIZE < WINDOW_WIDTH) {
                s->walker.x += WALKER_SIZE;
            }
            break;
        case 1:
            if (s->walker.x - WALKER_SIZE > 0) {
                s->walker.x -= WALKER_SIZE;
            }
            break;
        case 2:
            if (s->walker.y + WALKER_SIZE < WINDOW_HEIGHT) {
                s->walker.y += WALKER_SIZE;
            }
            break;
        case 3:
            if (s->walker.y - WALKER_SIZE > 0) {
                s->walker.y -= WALKER_SIZE;
            }
            break;
        default:
            break;
    }
}

void draw_walker(struct State *s) {
    SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(s->renderer, &s->walker);
}
