#include <stdio.h>

// ponteiro para função de emitir som
typedef void (*func_emitir_som)(void);

// ponteiro para função de peso e idade
typedef int (*func_caracteristicas)(void);

// tipo genérico
typedef struct {
  func_emitir_som soar;
  func_emitir_som comida;
  
  func_caracteristicas dados;
  
} Animal;

void eat(void) {
  puts("capim");
}

int Info(void) {
  return 100;
}


void latir(void) {
  puts("au! au!");
}

void miar(void) {
  puts("miau! miau!");
}

void mugir(void) {
  puts("muuu! muuu!");
}

int main(void) {
  Animal vaca     = { &mugir,&eat, &Info };
  Animal cachorro = { &latir };
  //Animal gato     = { &miar  };
  Animal gato;
  gato.soar = miar;

  vaca.soar();     // a vaca muge
  vaca.comida();
 // vaca.dados();
 printf("Valor e %d \n",vaca.dados());
  
  
  cachorro.soar(); // o cachorro late
  gato.soar();     // o gato mia

	

  return 0;
}