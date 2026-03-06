#include "gol_io.h"
#include <stdio.h>

int handle_input(void) {
    int ch = getch();  // неблокирующий ввод из ncurses
    
    switch(ch) {
        case ' ':      // Пробел - выход
            return INPUT_QUIT;
            
        case 'a':
        case 'A':      // A - увеличить скорость
            return INPUT_FASTER;
            
        case 'z':
        case 'Z':      // Z - уменьшить скорость
            return INPUT_SLOWER;
            
        default:
            return INPUT_NONE;
    }
}
void render(struct cell** world, int speed) {
    clear();  // ncurses очистка
    
    // Рисуем рамку
    box(stdscr, 0, 0);
    
    // Рисуем клетки
    for (int x = 0; x < WORLD_SIZE_X; x++) {
        for (int y = 0; y < WORLD_SIZE_Y; y++) {
            if (world[x][y].state) {
                mvaddch(x + 1, y + 1, '#');
            } else {
                mvaddch(x + 1, y + 1, '.');
            }
        }
    }
    
    // Информационная панель
    mvprintw(WORLD_SIZE_X + 2, 0, 
             "Скорость: %d мс | A - быстрее, Z - медленнее, Пробел - выход", 
             speed);
    
    refresh();
}