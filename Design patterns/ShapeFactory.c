#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ShapeFactory.h"
#include "Shape.h"

#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"

ShapeFactory* new_ShapeFactory()
{
   ShapeFactory *shapeFactory = malloc(sizeof(ShapeFactory));
   
    if(shapeFactory == NULL)
        return NULL;
    
    shapeFactory->getSahpe = &get_draw;
    
    return shapeFactory;
}

Shape_t* get_draw(void *shapeType)
{
    
    if(shapeType == NULL)
    {
        return NULL;
    }
    if( !(strcmp((char*)shapeType, "CIRCULO")))
    {
        Shape_t *forma = malloc(sizeof(Shape_t));
        forma->draw = &circulo_draw;
        return forma;	
    }
    
    if( !(strcmp((char*)shapeType, "SQUARE")))
    {
        Shape_t *forma = malloc(sizeof(Shape_t));
        forma->draw = &square_draw;
        return forma;	
    }		
    
        if( !(strcmp((char*)shapeType, "RECTANGLE")))
    {
        Shape_t *forma = malloc(sizeof(Shape_t));
        forma->draw = &rectangle_draw;
        return forma;	
    }		

return NULL;	
}