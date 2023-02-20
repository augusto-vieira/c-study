#ifndef CANETA_H_
#define CANETA_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct caneta Caneta;

Caneta *caneta_new(const char *m, const char *c, float p);
void caneta_destroy(Caneta *obj);


char *caneta_get_modelo(Caneta *caneta);
void  caneta_set_modelo(Caneta *caneta, const char *str);

float caneta_get_ponta(Caneta *caneta);
void  caneta_set_Ponta(Caneta *caneta, float p);

void caneta_tampar(Caneta *caneta);
void caneta_destampar(Caneta *caneta);

void caneta_status(Caneta *caneta);

#endif
