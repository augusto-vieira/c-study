#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "caneta.h"

void caneta_new(Caneta *caneta, const char *m, const char *c, float p)
{
  strncpy(caneta->modelo, m, sizeof(caneta->modelo));
  strncpy(caneta->cor, c, sizeof(caneta->cor));
  caneta->ponta = p;
  caneta->tampada = true;
}

char *caneta_get_modelo(Caneta caneta)
{
  char *modelo = caneta.modelo;
  return modelo;
}
void caneta_set_modelo(Caneta *caneta, const char *str)
{
  strncpy(caneta->modelo, str, sizeof(caneta->modelo));
}

float caneta_get_ponta(Caneta caneta)
{
  return caneta.ponta;
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

void caneta_status(Caneta caneta)
{
  printf("SOBRE A CANETA:\n");
  printf("Modelo: %s\n", caneta_get_modelo(caneta));
  printf("Ponta: %.2f\n", caneta_get_ponta(caneta));
  printf("Cor: %s\n", caneta.cor);
  printf("Tampada: %i\n", caneta.tampada);
}
