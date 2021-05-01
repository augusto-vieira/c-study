#include <stdio.h>
#include <string.h>

#include "ShapeFactory.h"
#include "Shape.h"

#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"

Shape_t get_draw(const char *shapeType)
{
    Shape_t forma;

    if( !(strcmp(shapeType, "CIRCULO")))
    {
        forma =  new_Circulo();
    }
    
    if( !(strcmp(shapeType, "SQUARE")))
    {
        forma = new_Square();	
        
    }		
    
    if( !(strcmp(shapeType, "RECTANGLE")))
    {
        forma =  new_Rectangle(); 
    }
    
    return forma;	 		
}

ShapeFactory new_ShapeFactory()
{
    ShapeFactory shapeFactory;
    shapeFactory.getSahpe = get_draw;

    return shapeFactory;
}