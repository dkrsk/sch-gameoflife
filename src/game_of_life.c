
#include "gol_core.h"
#include "gol_io.h"
#include "gol_struct.h"

#define DELAY_MIN 50
#define DELAY_MAX 2000
#define DELAY_STEP 50
#define TIMEOUT 20

int clamp_delay(int value);

int main() {
    struct cell** world = init_world();
    struct cell** world2 = init_world();
    int load_res = 0;
    if(world != NULL && world2 != NULL) {
        load_res = load_pattern(world);
    }

    interactive();
    timeout(TIMEOUT);

    if (load_res) {
        int input = 0;
        int delay = 500;
        int timer = 0;

        while (input != INPUT_QUIT) {
            render(world, delay);
            input = handle_input();
            if (input == INPUT_FASTER) {
                delay = clamp_delay(delay - DELAY_STEP);
            }
            if (input == INPUT_SLOWER) {
                delay = clamp_delay(delay + DELAY_STEP);
            }
            timer += TIMEOUT;
            if (timer >= delay) {
                update(&world, &world2);
                timer = 0;
            }
        }
        destroy_world(&world);
        destroy_world(&world2);
    } else {
        render_message("Incorrect input data");
    }
    destroy_world(&world);
    destroy_world(&world2);
    endwin();
    return 0;
}

int clamp_delay(int value) {
    int res = value;
    if (value > DELAY_MAX) {
        res = DELAY_MAX;
    } else if (value < DELAY_MIN) {
        res = DELAY_MIN;
    }
    return res;
}
