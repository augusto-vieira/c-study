#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "conta.h"

float getSaldo(Conta *obj);
void setSaldo(Conta *obj, float valor);

int getAgencia(Conta *obj);
void setAgencia(Conta *obj, int agencia);

void setTitular(Conta **obj, Client_t *titular);

struct conta
{
   int saldo;
   int agencia;
};

Conta_t *newConta(){
    Conta_t *conta = (Conta_t*)malloc(sizeof(Conta_t));
    if(conta == NULL)
    {
        fprintf(stderr, "Erro ao instanciar Conta...\n");  
        exit(EXIT_FAILURE);
    }

    conta->obj = (Conta*)malloc(sizeof(Conta));
    if(&conta->obj == NULL)
    {
        fprintf(stderr, "Erro ao instanciar Cliente...\n");  
        exit(EXIT_FAILURE);
    } 

    conta->getSaldo = getSaldo;
    conta->setSaldo = setSaldo;
    conta->getAgencia = getAgencia;
    conta->setAgencia = setAgencia;

    conta->setTitular = setTitular;

    return conta;
}

float getSaldo(Conta *obj){
    return obj->saldo;   
}

void setSaldo(Conta *obj, float valor){
    obj->saldo = valor;
}

int getAgencia(Conta *obj){
    return obj->agencia;
}
void setAgencia(Conta *obj, int agencia){
    obj->agencia = agencia;
}

void setTitular(Conta **obj, Client_t *titular){
    Conta_t *t = (Conta_t*)obj;
    t->titular = titular;
}
