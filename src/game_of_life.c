
#include "gol_io.h"
#include "gol_core.h"
#include "gol_struct.h"

#define SPEED_MAX 100
#define SPEED_MIN 2000

int main()
{
    struct cell** world = init_world();
    struct cell** wolrd2 = init_world();
    interactive();
    int speed = 200;
    load_pattern(world);
    int input = handle_input();
    while (input != INPUT_QUIT)
    {   
        timeout(speed);
        int input = handle_input();
        if (input == INPUT_FASTER){
            speed -= 20;
        }
        if (input == INPUT_SLOWER){
            speed += 20;
        } 
        render(world, speed);
        update(&world, &wolrd2);
    }
    destroy_world(&world);
    return 0;
}

int clamp_speed(int value){
    int res = value;
    if(value > SPEED_MAX) {
        res = SPEED_MAX;
    }
    else if (value < SPEED_MIN) {
        res = SPEED_MIN;
    }
    return res;
}