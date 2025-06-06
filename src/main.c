#include "main.h"
#include <time.h>
#include "init.h"
#include "walker.h"

bool setup(struct State **state);
void cleanup(struct State **state);

int main(void) {
    bool exit_status = EXIT_FAILURE;

    struct State *state = nullptr;
    if (setup(&state)) {
        run(state);
        exit_status = EXIT_SUCCESS;
    }

    cleanup(&state);
    state = nullptr;

    return exit_status;
}

bool setup(struct State **state) {
    *state = calloc(1, sizeof(struct State));
    if (*state == NULL) {
        fprintf(stderr, "Error allocating memory: %s\n", SDL_GetError());
        return false;
    }

    struct State *s = *state;
    s->steps = 0;

    if (!init_sdl(s)) {
        return false;
    }

    if (!init_walker(s)) {
        return false;
    }

    s->is_running = true;
    s->last_frame_time = 0;
    s->frame_count_init_time = SDL_GetTicks();
    s->frame_count = 0;
    s->enable_fps_count = false;
    srand(time(NULL));

    return true;
}

void cleanup(struct State **state) {
    if (*state) {
        struct State *s = *state;
        if (s->renderer) {
            SDL_DestroyRenderer(s->renderer);
            s->renderer = nullptr;
        }
        if (s->window) {
            SDL_DestroyWindow(s->window);
            s->window = nullptr;
        }
        free(s);
    }
    SDL_Quit();
}