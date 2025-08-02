#include <stdio.h>
#include "Rectangle.h"

static void rectangle_draw()
{
    printf("Inside Rectangle::draw() method.\n");
}

Shape_t new_Rectangle()
{
    Shape_t retangulo =
    {
        .draw = rectangle_draw
    };

    return retangulo;
}

