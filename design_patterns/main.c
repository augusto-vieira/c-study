#include <stdio.h>

#include "Shape.h"
#include "ShapeFactory.h"

int main(void)
{
  ShapeFactory shapeFactory = new_ShapeFactory();

  Shape_t shape = shapeFactory.getShape("CIRCULO");
  shape.draw();

  shape = shapeFactory.getShape("SQUARE");
  shape.draw();

  shape = shapeFactory.getShape("RECTANGLE");
  shape.draw();

return 0;
}
