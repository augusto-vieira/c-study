#ifndef CONTA_H_
#define CONTA_H_

#include "cliente.h"

typedef struct 
{
   int saldo;
   int agencia;
   Cliente *titular;

   // Ponteiro para função 
   // Métodos
   float (*getSaldo)(void *conta);
   void (*setSaldo)(void *conta, float valor);
   
   int (*getAgencia)(void *conta);
   void (*setAgencia)(void *conta, int agencia);

   void (*setTitular)(void *data, Cliente *titular);  
} Conta;

Conta *newConta();

#endif /* CONTA_H_ */