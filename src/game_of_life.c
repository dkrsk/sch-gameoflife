
#include "gol_io.h"
#include "gol_core.h"
#include "gol_struct.h"

int main()
{
    struct cell** world = init_world();
    struct cell** wolrd2 = init_world();
    int speed = 40;
    load_pattern(world);
    int input = handle_input();
    while (input != 10)
    {
        int input = handle_input();
        render(world, speed);
        update(&world, &wolrd2);
    }
    destroy_world(&world);
    return 0;
}