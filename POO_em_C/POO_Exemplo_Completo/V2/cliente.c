#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "cliente.h"

struct cliente 
{
  char nome[50];
  char cpf[20];
};

Cliente *newCliente(){
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
    if(cliente == NULL)
    {
        fprintf(stderr, "Erro ao instanciar Cliente...\n");  
        exit(EXIT_FAILURE);
    }
    
    return cliente;
}

char *getNome(Cliente *cliente){
    return cliente->nome;
}

void setNome(Cliente *cliente, char *nome){
   strncpy(cliente->nome, nome, sizeof(cliente->nome));
}

char *getCpf(Cliente *cliente){
    return cliente->cpf;
}

void setCpf(Cliente *cliente, char *cpf){
    strncpy(cliente->cpf, cpf, sizeof(cliente->cpf));
}