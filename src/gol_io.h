#ifndef GOL_IO_H
#define GOL_IO_H

#include <ncurses.h>

#include "gol_struct.h"

#define INPUT_NONE 0     // ничего не нажато
#define INPUT_FASTER 1   // увеличить скорость (A)
#define INPUT_SLOWER -1  // уменьшить скорость (Z)
#define INPUT_QUIT 10    // выход из игры (пробел)

// Инициализация ncurses для интерактивного режима
void interactive(void);

void render(struct cell** world, int speed);

int load_pattern(struct cell** world);

int handle_input();  // 0 - ничего. 1 - увеличить скорость. -1 уменьшить скорость. 10 - выход из игры

void render_message(char* message);

#endif
