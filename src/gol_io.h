#ifndef GOL_IO_H
#define GOL_IO_H

#include <ncurses.h>

#include "gol_struct.h"

#define INPUT_NONE 0
#define INPUT_FASTER 1
#define INPUT_SLOWER -1
#define INPUT_QUIT 10

void interactive(int tickrate);

void render(struct cell** world, int speed);

int load_pattern(struct cell** world);

int handle_input();

void render_message(char* message);

#endif
