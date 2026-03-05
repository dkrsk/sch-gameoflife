#ifndef GOL_IO_H
#define GOL_IO_H

#include <ncurses.h>

#include "gol_struct.h"

void render(struct cell *world);

struct cell *load_pattern(char *input);

int handle_input();  // 0 - ничего. 1 - увеличить скорость. -1 уменьшить скорость. 10 - выход из игры

#endif