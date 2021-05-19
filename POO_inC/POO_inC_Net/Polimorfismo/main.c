
// https://www.embarcados.com.br/ponteiro-em-c-polimorfismo/

#include <stdio.h>

#include "Forma.h"
#include "Derivada.c"

void Circle_Draw(Shape const * const me);
void Rectangle_Draw(Shape const * const me);
void Triangle_Draw(Shape const * const me);
 
int main()
{
    Circle circle;
    Triangle triangle;
    Rectangle rectangle;
 
    //tabelas de funções virtuais para cada tipo de estrutura
    Shape_VTable VTable_circle;
    Shape_VTable VTable_triangle;
    Shape_VTable VTable_rectangle;
 
    //inicialização das tabelas de acordo com sua função de desenho
    VTable_circle.Draw = Circle_Draw;
    VTable_rectangle.Draw = Rectangle_Draw;
    VTable_triangle.Draw = Triangle_Draw;
 
    //inicialização das estruturas com a tabela de funções virtuais
    circle.base.VTable = &VTable_circle;
    triangle.base.VTable = &VTable_rectangle;
    rectangle.base.VTable = &VTable_triangle;
 
    //Vetor com ponteiros para dados do tipo Shape, ou seja, o tipo base
    Shape * shapes[3] = {
        (Shape *)&circle,
        (Shape *)&triangle,
        (Shape *)&rectangle
    };
 
    int i;
 
    for(i = 0; i < 3; i++)
    {
        //chamada da função virtual
        //shapes[i]->               É um ponteiro para uma das estruturas
        //shapes[i]->VTable->       Indica o acesso ao membro VTable que também é um ponteiro
        //shapes[i]->VTable->Draw   Acessa o ponteiro de função Draw definido em VTable
        shapes[i]->VTable->Draw((Shape const * const)&shapes[i]);
    }
 
    return 0;
}
 
void Circle_Draw(Shape const * const me)
{
    printf("Circle!\r\n");
}
 
void Rectangle_Draw(Shape const * const me)
{
    printf("Rectangle!\r\n");
}
 
void Triangle_Draw(Shape const * const me)
{
    printf("Triangle!\r\n");
}