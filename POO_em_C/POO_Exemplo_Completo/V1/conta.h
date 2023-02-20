#ifndef CONTA_H_
#define CONTA_H_

#include "cliente.h"

typedef struct 
{
   float saldo;
   int agencia;
   Cliente *titular;
} Conta;

float getSaldo(Conta *conta);
void setSaldo(Conta *conta, float valor);

int getAgencia(Conta *conta);
void setAgencia(Conta *conta, int agencia);

void setTitular(Conta *conta, Cliente *titular);

#endif /* CONTA_H_ */