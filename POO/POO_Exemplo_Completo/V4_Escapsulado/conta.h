#ifndef CONTA_H_
#define CONTA_H_

#include "cliente.h"
#include "conta.h"

// Atributos Encapsulados
typedef struct conta Conta;

typedef struct 
{  
   // Referência para acessar os atributos encapsulados
   Conta *obj;
   Client_t *titular;

   // Métodos
   float (*getSaldo)(Conta *obj);
   void (*setSaldo)(Conta *obj, float valor);
   int (*getAgencia)(Conta *obj);
   void (*setAgencia)(Conta *obj, int agencia);

   void (*setTitular)(Conta **obj, Client_t *titular);

}Conta_t;

// Constructor
Conta_t *newConta();

#endif /* CONTA_H_ */