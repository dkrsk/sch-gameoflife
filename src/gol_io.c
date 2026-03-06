#include "gol_io.h"
#include <stdio.h>

void interactive() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(40);
}

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
    
     box(stdscr, 0, 0);// Рисуем рамку
    
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

void load_pattern(struct cell **world) {
    // Очищаем мир
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            world[y][x].state = 0;
        }
    }
    
    // Читаем координаты из stdin
    int x, y;
    char line[256];
    
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '#') continue;  // пропускаем комментарии
        
        if (sscanf(line, "%d %d", &x, &y) == 2) {
            if (x >= 0 && x < WORLD_SIZE_X && y >= 0 && y < WORLD_SIZE_Y) {
                world[y][x].state = 1;  // world[строка][столбец]
            }
        }
    }
}
void interactive() {        // вызов функций ncurses
    initscr();              // 1. Инициализация графики
    noecho();               // 2. Не отображать вводимые символы
    curs_set(0);            // 3. Скрыть курсор
}