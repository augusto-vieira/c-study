#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "conta.h"

struct conta
{
   float saldo;
   int agencia;
};

Conta *newConta(){
    Conta *conta = (Conta*)malloc(sizeof(Conta));
    if(conta == NULL)
    {
        fprintf(stderr, "Erro ao instanciar Conta...\n");  
        exit(EXIT_FAILURE);
    }
    return conta;
}

float getSaldo(Conta *conta){
    return conta->saldo;   
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
