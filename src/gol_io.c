#include "gol_io.h"

#include <ncurses.h>

int handle_input(void) {
    int ch = getch();  // неблокирующий ввод из ncurses
    int res;

    if (ch == ' ') {
        res = INPUT_QUIT;
    } else if (ch == 'a' || ch == 'A') {
        res = INPUT_FASTER;
    } else if (ch == 'z' || ch == 'Z') {
        res = INPUT_SLOWER;
    } else {
        res = INPUT_NONE;
    }
    return res;
}
void render(struct cell** world, int speed) {
    erase();  // ncurses очистка

    box(stdscr, 0, 0);  // Рисуем рамку

    for (int x = 0; x < WORLD_SIZE_X; x++)  // Рисуем клетки
    {
        for (int y = 0; y < WORLD_SIZE_Y; y++) {
            if (world[x][y].state) {
                if (has_colors()) attron(COLOR_PAIR(1));
                mvaddch(x + 1, y + 1, 'o');
            } else {
                if (has_colors()) attron(COLOR_PAIR(2));
                mvaddch(x + 1, y + 1, ' ');
            }
        }
    }

    if (has_colors())  // Информационная панель
        attron(COLOR_PAIR(2));
    mvprintw(WORLD_SIZE_X + 2, 2, "Delay: %d ms | A - faster, Z - slower, Space - exit", speed);

    refresh();
}

void render_message(char* message) { printf("%s", message); }

int load_pattern(struct cell** world) {
    int code = 1;
    int tmp = 0;
    for (int x = 0; x < WORLD_SIZE_X; x++) {
        for (int y = 0; y < WORLD_SIZE_Y; y++) {
            if (scanf("%1d", &tmp) && (tmp == 1 || tmp == 0)) {
                world[x][y].state = tmp;
            } else {
                code = 0;
            }
        }
    }
    if (freopen("/dev/tty", "r", stdin) == NULL) {  // переход на ввод с клавиатуры
        code = 0;
    }
    return code;
}
void interactive(int tickrate) {  // вызов функций ncurses
    initscr();                    // инициализация графики
    noecho();                     // не отображать вводимые символы
    curs_set(0);                  // скрыть курсор(мигание)
    timeout(tickrate);   // таймаут ожидания ВВОДА (в handle_input). тикрейт
    if (has_colors()) {  // если экран поддерживает цвета
        start_color();   // инициализация цветов
        use_default_colors();  // использовать стандартные цвета темы терминала
        init_pair(1, COLOR_CYAN, -1);  // пара цветов №1 - голубой. текст и стандартный фон
        init_pair(2, -1, -1);  // пара цветов №2 - стандартный текст и стандартный фон
    }
}