#ifndef GOL_CORE_H
#define GOL_CORE_H

#include <stdlib.h>

#include "gol_struct.h"

struct cell *init_world();
void destroy_world(struct cell **world);
int count_neighbors(struct cell point);
void update(struct cell **world);

#endif