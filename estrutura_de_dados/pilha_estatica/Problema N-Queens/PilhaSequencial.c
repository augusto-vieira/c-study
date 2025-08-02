//Arquivo PilhaSequencial.c
#include<stdio.h>
#include <stdlib.h>

#include "PilhaSequencial.h"

struct pilha
{
   int qtd;
   struct Board dados[MAX]; 
};

Pilha* criar_Pilha()
{
    Pilha *pi;
    
    pi = (Pilha*)malloc(sizeof(struct pilha));
    
    if(pi != NULL)
        pi->qtd = 0;

    return pi;    
}

void libera_Pilha(Pilha* pi)
{
    free(pi);
}

int tamanho_Pilha(Pilha* pi)
{
    if(pi == NULL)
        return -1;
    else
        return pi->qtd;
}

int Pilha_cheia(Pilha* pi)
{
    if(pi == NULL)
        return -1;
    // cheia == 1,  != 0;
    return (pi->qtd == MAX);
}

int Pilha_vazia(Pilha* pi)
{
    if(pi == NULL)
        return -1;
    // vazia == 1, != 0
    return(pi->qtd == 0);
}

int insere_Pilha(Pilha* pi, struct Board al)
{
    if(pi == NULL)
        return 0;

    if(Pilha_cheia(pi))
        return 0;

    pi->dados[pi->qtd] = al; //Copio os dados
    pi->qtd++;  // incremento os valor

    return 1;
}

int remove_Pilha(Pilha* pi)
{
    if(pi == NULL || pi->qtd == 0)
        return 0;
    
    pi->qtd--;
    return 1;

    // o Dado continua na Pilha, mas pode ser sobrescrito.(não é mais possível acessalo)
}

int consulta_topo_Pilha(Pilha* pi, struct Board *al)
{
    if(pi == NULL || pi->qtd == 0)
        return 0;
    
    *al = pi->dados[pi->qtd - 1];

    return 1;
}