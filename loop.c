#include "loop.h"
#include "walker.h"

void run(struct State *s) {
    while (s->is_running) {
        process_input(s);
        delay(s);
        if (s->enable_fps_count) {
            count_fps(s);
        }
        if (s->steps < MAX_STEPS) {
            update(s);
            draw(s);
        }
        SDL_Delay(10);
    }
}

void process_input(struct State *s) {
    while (SDL_PollEvent(&s->event)) {
        switch (s->event.type) {
            case SDL_EVENT_QUIT:
                s->is_running = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                switch (s->event.key.scancode) {
                    case SDL_SCANCODE_ESCAPE:
                        s->is_running = false;
                        break;
                    case SDL_SCANCODE_F:
                        s->enable_fps_count = !s->enable_fps_count;
                        if (s->enable_fps_count) {
                            s->frame_count_init_time = SDL_GetTicks();
                            s->frame_count = 0;
                        }
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void update(struct State *s) {
    update_walker(s);
    s->steps++;
}

void draw(struct State *s) {
    SDL_RenderPresent(s->renderer);
    draw_walker(s);
}

void delay(struct State *s) {
    uint64_t delay = s->last_frame_time + FRAME_TARGET_TIME - SDL_GetTicks();
    if (delay > 0 && delay <= FRAME_TARGET_TIME) {
        SDL_Delay(delay);
    }
    s->last_frame_time = SDL_GetTicks();
}

void count_fps(struct State *s) {
    s->frame_count++;
    if (s->frame_count % 100 == 0) {
        s->avg_fps = (int) (s->frame_count / ((double) (s->last_frame_time - s->frame_count_init_time) / 1000));
        s->frame_count_init_time = s->last_frame_time;
        s->frame_count = 0;
        printf("FPS: %d\n", s->avg_fps);
    }
}
