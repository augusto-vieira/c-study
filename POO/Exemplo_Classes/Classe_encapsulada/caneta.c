#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "caneta.h"

struct caneta
{
  char modelo[50];
  float ponta;
  char cor[20];
  bool tampada;
};

Caneta *caneta_new(const char *m, const char *c, float p)
{
  Caneta *caneta = (Caneta*)malloc(sizeof(Caneta));
  if(caneta == NULL)
  {
    fprintf(stderr, "Erro ao instanciar Caneta...\n");  
    exit(EXIT_FAILURE);
  }

  strncpy(caneta->modelo, m, sizeof(caneta->modelo));
  strncpy(caneta->cor, c, sizeof(caneta->cor));
  caneta->ponta = p;
  caneta->tampada = true;
}

void caneta_destroy(Caneta *obj)
{
  free(obj);
}

char *caneta_get_modelo(Caneta *caneta)
{
  return caneta->modelo;
}
void caneta_set_modelo(Caneta *caneta, const char *str)
{
  strncpy(caneta->modelo, str, sizeof(caneta->modelo));
}

float caneta_get_ponta(Caneta *caneta)
{
  return caneta->ponta;
}

void caneta_set_ponta(Caneta *caneta, float p)
{
  caneta->ponta = p;
}

void caneta_tampar(Caneta *caneta)
{
  caneta->tampada = true;
}

void caneta_destampar(Caneta *caneta)
{
  caneta->tampada = false;
}

void caneta_status(Caneta *caneta)
{
  printf("SOBRE A CANETA:\n");
  printf("Modelo: %s\n", caneta_get_modelo(caneta));
  printf("Ponta: %.2f\n", caneta_get_ponta(caneta));
  printf("Cor: %s\n", caneta->cor);
  printf("Tampada: %i\n", caneta->tampada);
}
