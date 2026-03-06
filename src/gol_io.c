#include "gol_io.h"
#include <stdio.h>


int handle_input(void) {
    int ch = getch();  // неблокирующий ввод из ncurses
    int res;
    
    switch(ch) {
        case ' ':      // Пробел - выход
            res = INPUT_QUIT;
            break;
            
        case 'a':
        case 'A':      // A - увеличить скорость
            res = INPUT_FASTER;
            break;
            
        case 'z':
        case 'Z':      // Z - уменьшить скорость
            res = INPUT_SLOWER;
            break;
            
        default:
            res = INPUT_NONE;
            break;
    }
    return res;
}
void render(struct cell** world, int speed) {
    erase();  // ncurses очистка
    
    box(stdscr, 0, 0);// Рисуем рамку
    
    // Рисуем клетки
    for (int x = 0; x < WORLD_SIZE_X; x++) {
        for (int y = 0; y < WORLD_SIZE_Y; y++) {
            if (world[x][y].state) {
                mvaddch(x + 1, y + 1, '*');
            } else {
                mvaddch(x + 1, y + 1, '_');
            }
        }
    }
    
    // Информационная панель
    mvprintw(WORLD_SIZE_X + 2, 0, 
             "Delay: %d ms | A - faster, Z - slower, Space - exit", 
             speed);
    
    refresh();
}
void render_message(char* message){
    clear();
    printw(message);
    printw("\nPress any key to exit");
    refresh();
    getch();
}
int load_pattern(struct cell **world) {
    int code = 1;
    int tmp = 0;
    for (int x = 0; x < WORLD_SIZE_X; x++){
        for (int y = 0; y <WORLD_SIZE_Y; y++){
            if (scanf("%d",&tmp) && (tmp == 1 || tmp == 0)){
                world[x][y].state = tmp;
            }
            else {
                code = 0;
            }
        }
    }
    if(freopen("/dev/tty", "r", stdin) == NULL) {
        code = 0;
    }
    return code;
}
void interactive() {        // вызов функций ncurses
    initscr();              // 1. Инициализация графики
    noecho();               // 2. Не отображать вводимые символы
    curs_set(0);            // 3. Скрыть курсор
}