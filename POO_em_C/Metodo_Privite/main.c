#include <stdio.h>
/*
void a(void);        

void f() { puts("main f"); }

static void sf() { puts("main sf");}

void m() {
    f();
    sf();
}

int main() {
    m();
    a();
    return 0;
}  */


// se o código abaixo for compilado, um erro será obtido, ou seja, “referência indefinida a staticFunc ()”. 
// Isso ocorre porque a função staticFunc () é uma função estática e só é visível em seu arquivo objeto.
void staticFunc(void);
int main()
{
   staticFunc();
   return 0;
}