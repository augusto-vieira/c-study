#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "cliente.h"

char *getNome(Cliente *obj);
void setNome(Cliente *obj, char *nome);
char *getCPF(Cliente *obj);
void setCPF(Cliente *obj, char *cpf);

struct cliente 
{
  char nome[50];
  char cpf[20];
};

Client_t *newCliente(){
    Client_t *cliente = (Client_t*)malloc(sizeof(Client_t));
    if(cliente == NULL)
    {
        fprintf(stderr, "Erro ao instanciar Cliente...\n");  
        exit(EXIT_FAILURE);
    }
    
    cliente->obj = (Cliente*)malloc(sizeof(Cliente));
    if(&cliente->obj == NULL)
    {
        fprintf(stderr, "Erro ao instanciar Cliente...\n");  
        exit(EXIT_FAILURE);
    }    

    cliente->getNome = getNome;
    cliente->setNome = setNome;
    cliente->getCPF = getCPF;
    cliente->setCPF = setCPF;

    return cliente;
}

char *getNome(Cliente *obj){
    return obj->nome;
}

void setNome(Cliente *obj, char *nome){   
   strncpy(obj->nome, nome, sizeof(obj->nome));
}

char *getCPF(Cliente *obj){
    return obj->nome;
}

void setCPF(Cliente *obj, char *cpf){   
   strncpy(obj->cpf, cpf, sizeof(obj->cpf));
}
