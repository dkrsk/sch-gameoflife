
#include "gol_core.h"
#include "gol_io.h"
#include "gol_struct.h"

#define DELAY_MAX 50
#define DELAY_MIN 1000
#define DELAY_STEP 50
#define TIMEOUT 20

int clamp_delay(int value);

int main() {
    struct cell** world = init_world();
    struct cell** wolrd2 = init_world();
    int load_res = load_pattern(world);

    interactive();
    timeout(TIMEOUT);

    if (load_res) {
        int input = 0;
        int delay = 200;
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
                update(&world, &wolrd2);
                timer = 0;
            }
        }
        destroy_world(&world);
    } else {
        render_message("Incorrent input data");
    }
    endwin();
    return 0;
}

int clamp_delay(int value) {
    int res = value;
    if (value > DELAY_MIN) {
        res = DELAY_MIN;
    } else if (value < DELAY_MAX) {
        res = DELAY_MAX;
    }
    return res;
}
