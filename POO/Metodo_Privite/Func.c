#include <stdio.h>

/* Comportamento indefinido: já definido no principal.
  * Binutils 2.24 dá um erro e se recusa a vincular.
  * https://stackoverflow.com/questions/27667277/why-does-borland-compile-with-multiple-definitions-of-same-object-in-different-c
  *
/* void f () {puts ("a f"); } *

/* OK: apenas declarado, não definido. Usará o principal. */
//void f(void);

/* OK: visível apenas para este arquivo. */
// static void sf(){puts ("a sf");}

/*
void a(){
     f();
     sf();
} */
							 
static void staticFunc(void) // Funciona -> void staticFunc(void)
{
   printf("Inside the static function staticFunc() ");
}
