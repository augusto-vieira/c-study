#ifndef SHAPE_RECTANGLE_H_
#define SHAPE_RECTANGLE_H_

#include "Shape.h"

typedef struct 
{
    Shape_t *draw;
} Rectangle_t;

Shape_t new_Rectangle();

#endif /* SHAPE_RECTANGLE_H_ */