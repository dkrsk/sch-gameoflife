#ifndef GOL_CORE_H
#define GOL_CORE_H

#include <stdlib.h>

#include "gol_struct.h"

struct cell **init_world();
void destroy_world(struct cell ***world);
void update(struct cell ***world, struct cell ***next);

#endif