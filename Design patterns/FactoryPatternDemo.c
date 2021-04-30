#include <stdio.h>

#include "Shape.h"
#include "ShapeFactory.h"

int main(void)
{
  ShapeFactory *shapeFactory = new_ShapeFactory();

  Shape_t *shape1 = shapeFactory->getSahpe("CIRCULO");

  shape1->draw();

  Shape_t *shape2 = shapeFactory->getSahpe("SQUARE");
  shape2->draw();

  Shape_t *shape3 = shapeFactory->getSahpe("RECTANGLE");
  shape3->draw();

return 0;
}
