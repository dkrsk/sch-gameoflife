#ifndef GOL_STRUCT_H
#define GOL_STRUCT_H

#define WORLD_SIZE_X 80
#define WORLD_SIZE_Y 25

struct cell {
    int x;
    int y;
    int state;
};

#endif