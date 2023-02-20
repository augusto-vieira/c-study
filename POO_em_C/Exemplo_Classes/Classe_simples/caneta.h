#ifndef CANETA_H_
#define CANETA_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct 
{
  char modelo[50];
  float ponta;
  char cor[20];
  bool tampada;
}Caneta;

void caneta_new(Caneta *caneta, const char *m, const char *c, float p);

char *caneta_get_modelo(Caneta caneta);
void  caneta_set_modelo(Caneta *caneta, const char *str);

float caneta_get_ponta(Caneta caneta);
void  caneta_set_Ponta(Caneta *caneta, float p);

void caneta_tampar(Caneta *caneta);
void caneta_destampar(Caneta *caneta);

void caneta_status(Caneta caneta);

#endif
