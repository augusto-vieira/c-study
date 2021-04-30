#ifndef SHAPE_SHAPEFACTORY_H_
#define SHAPE_SHAPEFACTORY_H_


#include "Shape.h"

typedef struct 
{
    Shape_t* (*getSahpe)(void *objeto);
} ShapeFactory;

ShapeFactory* new_ShapeFactory();

Shape_t* get_draw(void *shapeType);


#endif /* SHAPE_SHAPEFACTORY_H_ */