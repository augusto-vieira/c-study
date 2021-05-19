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
    Aluno aluno;
};

struct _registros
{
   Turma turma;
}; 


void setTurma(Turma *turma, const char *id, int semestre, int ano, int *count)
{
    printf("\n\t helooo %d\n",turma[*count].ano);
    strncpy(turma[*count].id, id,strlen(id) + 1);
    turma[*count].semestre = semestre;
    turma[*count].ano = ano;
    

    (*count)++;
}

void getTurma(Turma *turma, int count)
{
    for(int i = 0; i < count; i++ )
    {
        puts(turma[i].id);
        printf("\n%d",turma[i].semestre);
        printf("\n%d",turma[i].ano);
    }
    printf("\nFOI");
}

void setAluno(Registros *dados , const char *nome, float *nota, int size_nota)
{
    
    strncpy(dados->turma.aluno.nome, nome, sizeof(nome));  
    aloca(dados, size_nota);

    for(int i = 0; i < size_nota; i++)
    {
        dados->turma.aluno.nota[i] = nota[i];
    }
        strncpy(dados[0].turma.aluno.nome,"ola",4);
          
    /*
    strncpy(aluno->nome, nome, sizeof(nome));
    aluno->nota = nota; 
    aluno->aluno.nota = 99;
    */
}

void getAluno(Registros *dados)
{
  /*  printf("Nome: %s\n", aluno->turma.aluno.nome);
    printf("Nota: %2.f\n",aluno->turma.aluno.nota); */
   /*  for (size_t i = 0; i < 12; i++)
    {
       printf("[%d] = %2.f\n", i+1, dados->turma.aluno.nota[i]);
    }
     */
    printf("%s\n",dados[0].turma.aluno.nome);
    printf("%s\n",dados[1].turma.aluno.nome);
}

Registros *criar(void)
{
    Registros *registro;
    registro = (Registros*) malloc(sizeof(Registros));
    registro->turma.aluno.nota = (float*)malloc(sizeof(float));

   return registro;
}

void aloca(Registros *aloca_nota, size_t aloca_tamanho)
{
	//Vetor (*nota) dinamico ?
    aloca_nota->turma.aluno.nota =(float*) realloc(aloca_nota->turma.aluno.nota, aloca_tamanho);
	if(aloca_nota->turma.aluno.nota == NULL){
		fprintf(stderr,"\nErro de re-alocacao de memoria");
        printf("Erro");
		exit(1);
	}
}



void *newTurma(Registros **new_turma, int *count)
{
	(*new_turma) = (Registros*) realloc(*new_turma, (*count +1) *sizeof(Registros));
   // (*new_turma) = (Registros*) realloc(*new_turma, (*count) *sizeof(Registros));

    if(*new_turma == NULL)
    {
    	fprintf(stderr,"\nErro de re-alocacao de memoria");
        printf("Erro");
		exit(1);
	}
}


void writeTurma(Turma *write, int *count)
{ 
    char identifacao[40];
	int semestre;
	int ano; 

    cleanBuffer();
    printf("\nNome para identificar a turma: ");
    fgets(identifacao, sizeof(identifacao), stdin);
   // fgets(write->id, sizeof(write->id), stdin);
    
    printf("\nSemestre: ");
    fscanf(stdin, "%d",&semestre);
    cleanBuffer();

    printf("\nAno: ");
    fscanf(stdin, "%d",&ano);
    cleanBuffer();

    //setTurma(write, identifacao, semestre, ano, count); 

}  


void editarTurma(Registros *dado, int count)
{
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
    }
}

