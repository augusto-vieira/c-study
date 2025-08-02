#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "cliente.h"

char *getNome(void *cliente);
void setNome(void *cliente, char *nome);

char *getCpf(void *cliente);
void setCpf(void *cliente, char *cpf);

Cliente *newCliente(){
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
    if(cliente == NULL)
    {
        fprintf(stderr, "Erro ao instanciar Cliente...\n");  
        exit(EXIT_FAILURE);
    }

    cliente->getNome = getNome;
    cliente->setNome = setNome;

    cliente->getCpf = getCpf;
    cliente->setCpf = setCpf;

    return cliente;
}

char *getNome(void *cliente){
    Cliente *obj = (Cliente*)cliente;
    return obj->nome;
}

void setNome(void *cliente, char *nome){
   Cliente *obj = (Cliente*)cliente; 
   strncpy(obj->nome, nome, sizeof(obj->nome));
}

char *getCpf(void *cliente){
    Cliente *obj = (Cliente*)cliente;
    return obj->cpf;
}

void setCpf(void *cliente, char *cpf){
    Cliente *obj = (Cliente*)cliente;
    strncpy(obj->cpf, cpf, sizeof(obj->cpf));
}