#ifndef GOL_IO_H
#define GOL_IO_H

#include <ncurses.h>
#include "gol_struct.h"

// Коды возврата для handle_input
#define INPUT_NONE      0   // ничего не нажато
#define INPUT_FASTER    1   // увеличить скорость (A)
#define INPUT_SLOWER   -1   // уменьшить скорость (Z)
#define INPUT_QUIT     10   // выход из игры (пробел)

// Инициализация ncurses для интерактивного режима
void interactive(void);

// Отрисовка текущего состояния мира
void render(struct cell **world, int speed);

// Загрузка начального состояния из stdin
void load_pattern(struct cell **world);

// Обработка пользовательского ввода
// Возвращает: 0 - ничего, 1 - быстрее, -1 - медленнее, 10 - выход
int handle_input(void);

#endif
