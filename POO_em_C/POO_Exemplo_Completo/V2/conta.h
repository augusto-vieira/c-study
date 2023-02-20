#ifndef CONTA_H_
#define CONTA_H_

#include "cliente.h"

// Encapsular os dados de conta
typedef struct conta Conta;

// Constructor
Conta *newConta();

//Representa os Métodos
float getSaldo(Conta *conta);
void setSaldo(Conta *conta, float valor);

int getAgencia(Conta *conta);
void setAgencia(Conta *conta, int agencia);

#endif /* CONTA_H_ */