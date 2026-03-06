#ifndef GOL_STRUCT_H
#define GOL_STRUCT_H

#define WORLD_SIZE_X 25
#define WORLD_SIZE_Y 80

struct cell {
    int x;
    int y;
    int state;
};

#endif