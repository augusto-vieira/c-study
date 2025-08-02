#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"


struct _aluno
{
	char nome[40] ;
	float *nota;
};

struct _turma
{
	char id[40];
	int semestre;
	int ano;
    Aluno *aluno;
};


void setTurma(Turma *turma, const char *id, int semestre, int ano, int *count)
{
   
    strncpy(turma[*count].id, id,strlen(id) + 1);
    turma[*count].semestre = semestre;
    turma[*count].ano = ano;
    
    (*count)++;   
}

void getTurma(Turma *turma, int count)
{
    for(int i = 0; i < count; i++ )
    {
        //puts(turma[i].id);
        printf("\nTurma: %s ",turma[i].id);
        printf("semestre %d ",turma[i].semestre);
        printf("ano de %d",turma[i].ano);
    }
}

void setAluno(Turma *turma , const char *nome, float nota, int n_turma, int n_aluno, int n_nota)
{
    
     // Aloca para t[2].aluno[1].nota[2] ou .nome
    strncpy(turma[n_turma].aluno[n_aluno].nome, nome, strlen(nome) + 1);
    turma[n_turma].aluno[n_aluno].nota[n_nota] = nota;            

}

void getAluno(Turma *turma, size_t n_turma, size_t n_alunos)
{
  
   for (int i = 0; i < n_alunos; i++)
    {
      printf("\n%s",turma[n_turma].aluno[i].nome);
      printf("\n%3.f",turma[n_turma].aluno[i].nota[i]);

    }

}

Turma *criar(void)
{
    Turma *criar;
    criar = (Turma*) malloc(sizeof(Turma));
   
   return criar;
}

void alocaTurmas(Turma **aloca_turmas, const int *size_turma)
{   
    // Aloca para t[2].aluno[x].nota[x]
	Turma *verifica;
     verifica = (Turma*) realloc(*aloca_turmas,(*size_turma + 1) * sizeof(Turma));
    
    if(verifica == NULL)
    {
		fprintf(stderr,"\nErro de re-alocacao de memoria");
		exit(1);  
    }
    else
    {
      (*aloca_turmas) = verifica;
    }
     
}

void alocaAlunos(Turma *aloca_alunos, const int n_turma, size_t n_alunos)
{
    // Aloca para t[x].aluno[2].nota[x]
    aloca_alunos[n_turma].aluno = (Aluno*)malloc(n_alunos * sizeof(Aluno));

    if(aloca_alunos[n_turma].aluno == NULL)
    {
		fprintf(stderr,"\nErro na locacao de memoria de Alunos");
		exit(1);  
    }
}

void alocaNotas(Turma *aloca_notas, const int n_turma, const int n_aluno,  size_t n_notas)
{
    /* Aloca para t[2].aluno[1].nota[2]
    t[2].aluno[1].nota = (float*) malloc(2 * sizeof(float)); */
   
    aloca_notas[n_turma].aluno[n_aluno].nota = (float*)malloc(n_notas * sizeof(float));

    if(aloca_notas[n_turma].aluno[n_aluno].nota == NULL)
    {
		fprintf(stderr,"\nErro na locacao de memoria de Notas");
		exit(1);  
    }
}

void digiteNotas(void)
{
    /*
    char buffer[40];
    int x;
    float *notas;

    printf("\nNome do Aluno:");
    gets();

     printf("\nQuantidade de Notas:");
     scanf("%d",&x);

     if(x > 0)
     {
         notas = (float*)malloc( x * sizeof(float));
     }

     setAluno(buffer); */

} 



void writeTurma(Turma *write, int *count)
{ 


}  


void editarTurma(Turma *dado, int count)
{   /*
    char nome[40] = {0};
    int i = 0;
   
    
	printf("\n\t-%d-Digite o Nome: ",count);
    fgets(nome, sizeof(nome), stdin);
    
    for(i = 0; i < count && strncmp(dado[i].turma.id, nome,strlen(nome)) != 0; i++ );
    
    if(i >= count){
		printf("\n\tRegistro nao encontrado...");
	}
    else
    {   
        printf("----- %d --------",dado[i].turma.ano);
       // CHECK_createTurma(dado[i].turma);
       //  writeTurma(&dado[i].turma, count);
    }    */
}

