#include <stdio.h>
#include "Square.h"

static void square_draw()
{
    printf("Inside Square::draw() method.\n");
}

Shape_t new_Square()
{
    Shape_t quadrado =
    {
        .draw = square_draw
    };

    return quadrado;
}