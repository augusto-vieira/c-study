#include <stdio.h>

typedef struct Dog_
{
    int a;
    int b;
}Dog;

typedef struct Pug_
{                 
    Dog super;    //  Dog *super; Erro  no casting
    char c;
}Pug;


/*
  Subtipagem em C
  
  Se o início da Struct maior for igual ao da Struct menor, vc pode fazer casting de uma para outra.
  Isso funciona por causa do Layout de memória, a linguagem C garante que a primeira coisa que vc colocar na 
  struct vai estar no primeiro endereço de memória. Os campos da struct não são reordenados como em outras linguagens.

               _ _ _ _ _ _
 Struct Dog = |    a      |
              |-----------|
              |    b      |
              |_ _ _ _ _ _|

               _ _ _ _ _ _
 Struct Pug = |    Super  |
              |-----------|   
              |    c      |
              |_ _ _ _ _ _|  

               _ _ _ _ _ _
 Struct Pug = |    a      |
              |-----------|
              |    b      |
              |_ _ _ _ _ _|
              |    c      |
              |_ _ _ _ _ _|

mundo java instanceoff  / Pug é uma instância de Dog
é um subtivo, significa que eu posso tratar um ponteiro(de um tipo) com outro ponteiro(de outro tipo).
o que é composição?
*/


int main()
{
   
    Dog d;
    d.a = 10;
    d.b = 99;

    printf("Dog: a = %d | b = %d|\n", d.a, d.b);

    Pug pug;
    pug.super.a = 88; 
    pug.super.b = 77;
    pug.c = 'A';

    printf("Pug: a = %d | b = %d | c = %c|\n",  pug.super.a ,  pug.super.b, pug.c);

    Dog *x = (Dog*) &pug;
    printf("Dog: a = %d | b = %d |\n", x->a, x->b);

    x->a = 222;
    printf("pug.super.a = %d\n",  pug.super.a);

   return 0;
}