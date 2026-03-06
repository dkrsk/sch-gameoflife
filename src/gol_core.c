#include "gol_core.h"

#include "gol_struct.h"

struct cell **init_world() {
    struct cell **world = // выделение памяти в кучу. (в случае поля более 1000*1000)
        malloc(WORLD_SIZE_X * WORLD_SIZE_Y * sizeof(struct cell) + WORLD_SIZE_X * sizeof(struct cell *));
    struct cell *ptr = (struct cell *)(world + WORLD_SIZE_X); // матрицу выделяю одним блоком

    for (int i = 0; i < WORLD_SIZE_X; i++) {
        world[i] = ptr + (i * WORLD_SIZE_Y);
        for (int j = 0; j < WORLD_SIZE_Y; j++) {
            world[i][j] = (struct cell){i, j, 0};
        }
    }
    return world;
}

void destroy_world(struct cell ***world) {
    free(*world); // очистка
    *world = NULL;
}

void clear_world(struct cell **world) {
    for (int i = 0; i < WORLD_SIZE_X; i++) {
        for (int j = 0; j < WORLD_SIZE_Y; j++) {
            world[i][j].state = 0; // заполняю мир нулями
        }
    }
}

int count_neighbors(int x, int y, struct cell **world) {
    int count = 0;
    for (int offx = -1; offx < 2; offx++) {
        for (int offy = -1; offy < 2; offy++) {
            if (offx != 0 || offy != 0) {
                int row = (x + offx + WORLD_SIZE_X) % WORLD_SIZE_X; // получение координат вокруг клетки на замкнутом поле
                int col = (y + offy + WORLD_SIZE_Y) % WORLD_SIZE_Y;

                if (world[row][col].state == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

void update(struct cell ***world, struct cell ***next) {
    struct cell **current = *world;
    struct cell **nextm = *next; // следующая генерация мира
    for (int i = 0; i < WORLD_SIZE_X; i++) {
        for (int j = 0; j < WORLD_SIZE_Y; j++) {
            int count = count_neighbors(i, j, current); // проверка правил игры
            if (count == 3) {
                nextm[i][j].state = 1;
            }
            if (count == 2 && current[i][j].state == 1) {
                nextm[i][j].state = 1;
            }
        }
    }
    *world = nextm; // меняем миры местами и очищаем "следующий"
    clear_world(current);
    *next = current;
}