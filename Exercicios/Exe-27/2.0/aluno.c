#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"


struct _aluno
{
	int matricula;
    char nome[40] ;
	float n0, n2, n3, n4;
};

struct _turma
{
	char id[40];
	int semestre;
	int ano;
    Aluno *aluno;
};

struct _registro
{
   // Turma dados;
   Aluno;
    Registro *next;
};


Registro *criar(void)
{
    Registro *criar;
    criar = ( Registro*) malloc(sizeof( Registro));

    if(criar != NULL)
        *criar = NULL; //Incio do Nó igual a NULL |inicio|---> NULL

        
   
   return criar;
}
/*
void libera_registro( Registro *registro)
{
    if(registro != NULL)
    {
        Registro *no;
        while ((*registro) != NULL)
        {
            no = *registro;
            *registro = (*registro)->next;
            free(no);
        }
        free(registro);
    }
}  */

