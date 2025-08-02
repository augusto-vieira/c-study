#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"
#include <ctype.h>

#define SAIR -1

typedef struct 
{
    Projeto projeto[10];
    int quantidade;
} Projetos;

void cleanBuffer(void);
void CodigoDoProjeto(Projeto *projeto);
void Valor(Projeto *projeto);
void Receita(Projeto *projeto);
void Relatorio(Projetos *projetos);

double Calcula_Total(Projetos *projetos);

typedef void (*Interface)(Projeto *);

Interface ini[] = 
{
    CodigoDoProjeto,
    Valor,
    Receita
};
 
const int size_ini = sizeof(ini) / sizeof(ini[0]);

int main(int argc, char *argv[]) 
{
    Projetos projetos = {0};
    char continua;  
  
    for(;;)
    {
        Projeto *projeto = &projetos.projeto[projetos.quantidade];

        for(int i = 0; i < size_ini; i++)
        {
            ini[i](projeto);            
        }

        printf("Deseja cadastrar um novo produto? ");
        scanf("%c", &continua);        
        projetos.quantidade++;
        if(toupper(continua) != 'S')
            break;
            
    }
    
    printf("Saldo total dos projetos = %.2lf \n", Calcula_Total(&projetos));    
    Relatorio(&projetos);
    
    return 0;
}


inline void cleanBuffer(void)
{
    char c;
    while ((c = getchar()) != '\n'  && c != EOF);
}

void CodigoDoProjeto(Projeto *projeto)
{
    printf("\nNumero do Projeto: ");
    scanf("%d",&projeto->codigo);
    cleanBuffer();
}

void Valor(Projeto *projeto)
{
    printf("\nDigite o Valor: ");
    scanf("%f",&projeto->valor);
    cleanBuffer(); 
}

void Receita(Projeto *projeto)
{
    char tipo;
    while(1)
    {
        printf("\nDigite o tipo de transacao (R ou D): ");
        scanf("%c",&tipo);
        if(toupper(tipo) == 'R' || toupper(tipo) == 'D')
        {
            projeto->despesa_receita = toupper(tipo);
            break;
        }
        else{
            fprintf(stderr, "\nTipo de transacao ' %c ' invalida...\n",tipo);
        }
        cleanBuffer();
    }

    cleanBuffer();
}

double Calcula_Total(Projetos *projetos)
{
    double total = 0.0;
    for(int i = 0; i < projetos->quantidade; i++)
    {
        if(projetos->projeto[i].despesa_receita == 'R')
            total += projetos->projeto[i].valor;
        else
            total -= projetos->projeto[i].valor;
    }

    return total;
}

void Relatorio(Projetos *projetos)
{
    for(int i = 0; i < projetos->quantidade; i++)
    {
        Projeto *projeto = &projetos->projeto[i];
        printf("Projeto codigo: %d.\n", projeto->codigo);
        printf("Projeto valor: %.2f.\n", projeto->valor);
        printf("Projeto codigo: %s.\n\n", (projeto->despesa_receita == 'R' ? "receita" : "dispesa"));
    }
}