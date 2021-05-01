#ifndef SHAPE_SHAPEFACTORY_H_
#define SHAPE_SHAPEFACTORY_H_

#include "Shape.h"

typedef struct 
{
    Shape_t (*getSahpe)(const char *shapeType);
} ShapeFactory;

ShapeFactory new_ShapeFactory();

#endif /* SHAPE_SHAPEFACTORY_H_ */