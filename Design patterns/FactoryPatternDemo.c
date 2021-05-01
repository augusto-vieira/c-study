#include <stdio.h>

#include "Shape.h"
#include "ShapeFactory.h"

int main(void)
{
  ShapeFactory shapeFactory = new_ShapeFactory();

  Shape_t shape = shapeFactory.getSahpe("CIRCULO");
  shape.draw();

  shape = shapeFactory.getSahpe("SQUARE");
  shape.draw();

  shape = shapeFactory.getSahpe("RECTANGLE");
  shape.draw();

return 0;
}
