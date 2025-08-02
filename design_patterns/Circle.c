#include <stdio.h>
#include "Circle.h"

static void circulo_draw()
{
    printf("Inside Circle::draw() method.\n");
}

Shape_t new_Circle()
{
    Shape_t circulo =
    {
        .draw = circulo_draw
    };

    return circulo;
}