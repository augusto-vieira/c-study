#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "conta.h"

float getSaldo(void *conta);
void setSaldo(void *conta, float valor);


int getAgencia(void *conta);
void setAgencia(void *conta, int agencia);

void setTitular(void *data, Cliente *titular);

Conta *newConta(){
    Conta *conta = (Conta*)malloc(sizeof(Conta));
    if(conta == NULL)
    {
        fprintf(stderr, "Erro ao instanciar Conta...\n");  
        exit(EXIT_FAILURE);
    }

    conta->getSaldo = getSaldo;
    conta->setSaldo = setSaldo;
    conta->getAgencia = getAgencia;
    conta->setAgencia = setAgencia;

    conta->setTitular = setTitular;

    return conta;
}

float getSaldo(void *conta){
    Conta *obj = (Conta*)conta;
    return obj->saldo;   
}

void setSaldo(void *conta, float valor){
    Conta *obj = (Conta*)conta;
    obj->saldo = valor;
}

int getAgencia(void *conta){
    Conta *obj = (Conta*)conta;
    return obj->agencia;
}

void setAgencia(void *conta, int agencia){
    Conta *obj = (Conta*)conta;
    obj->agencia = agencia;    
}


void setTitular(void *conta, Cliente *titular){
    Conta *obj = (Conta*)conta;
    obj->titular = titular;
}