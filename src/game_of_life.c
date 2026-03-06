
#include "gol_io.h"
#include "gol_core.h"
#include "gol_struct.h"

#define SPEED_MAX 100
#define SPEED_MIN 2000
#define SPEED_STEP 100

int clamp_speed(int value);

int main()
{
    struct cell** world = init_world();
    struct cell** wolrd2 = init_world();
    int speed = 200;
    int load_res = load_pattern(world);
    interactive();
    if(load_res) {
        int input = handle_input();
        while (input != INPUT_QUIT)
        {   
            int input = handle_input();
            if (input == INPUT_FASTER){
                speed = clamp_speed(speed-SPEED_STEP);
            }
            if (input == INPUT_SLOWER){
                speed = clamp_speed(speed+SPEED_STEP);
            } 
            
            timeout(speed);
            render(world, speed);
            update(&world, &wolrd2);
        }
        destroy_world(&world);
    }
    else {
        render_message("incorrent input data");
    }
    endwin();
    return 0;
}

int clamp_speed(int value){
    int res = value;
    if(value > SPEED_MIN) {
        res = SPEED_MIN;
    }
    else if (value < SPEED_MAX) {
        res = SPEED_MAX;
    }
    return res;
}