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
// ИСПРАВЛЕНО: убрано дублирование nodelay и timeout
void interactive() {  // опечатка: было interective, правильно interactive
    initscr();              // 1. Инициализация ncurses
    noecho();               // 2. Не отображать вводимые символы
    curs_set(0);            // 3. Скрыть курсор
    keypad(stdscr, TRUE);   // 4. Включить функциональные клавиши
    timeout(40);            // 5. Таймаут 40 мс (заменяет nodelay)
    // nodelay(stdscr, TRUE); - УБРАНО! timeout(40) делает то же самое
}