#include <stdio.h>
#include <string.h>
#include "conta.h"

float getSaldo(Conta *conta){
    return conta->saldo ;
}

void setSaldo(Conta *conta, float valor){
    conta->saldo += valor;
}

int getAgencia(Conta *conta){
    return conta->agencia;
}

void setAgencia(Conta *conta, int agencia){
    conta->agencia = agencia;
}

void setTitular(Conta *conta, Cliente *titular){
    conta->titular = titular;
}