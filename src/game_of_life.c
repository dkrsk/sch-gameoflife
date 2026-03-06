
#include "gol_io.h"
#include "gol_struct.h"

int main()
{
    struct cell** world = init_world();
    load_pattern(&world);
    int input = handle_input();
    while (input != 10)
    {
        int input = handle_input();
        render(world);
        update(&world);
    }
    destroy_world(&world);
    return 0;
}