#ifndef FORMA_H_
#define FORMA_H_

typedef struct tShape Shape; //Define a estrutura Shape
typedef struct tShape_VTable Shape_VTable; //Define a tabela de funções virtuais
 
struct tShape_VTable
{
    void (*Draw)(Shape * const me); //Função virtual Draw que dever ser substituída
};
 
struct tShape
{
    //atributos
    int X;
    int Y;
    int Height;
    int Width;
 
    //tabela de funções virtuais – Ponteiro para o tipo Shape_VTable
    Shape_VTable * VTable;
};
#endif