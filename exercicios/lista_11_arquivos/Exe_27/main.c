#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "aluno.h"




int main(void)
{
	int size_turmas = 0;
    size_t size_alunos = 2;
    size_t size_notas  = 5;

    Turma *turmas = criar();
    
    setTurma(turmas,"Matematica", 4, 2020, &size_turmas);
    getTurma(turmas, size_turmas);
 

    alocaTurmas(&turmas, &size_turmas);
    
    setTurma(turmas,"PORTUGUES", 10, 2021, &size_turmas);
    getTurma(turmas, size_turmas);

    // Variavel -> Numero da turma -> Quantidades de alunos
    // turma[x]->aluno[n] 
    alocaAlunos(turmas,1,2);

    //Variavel -> Numero da turma -> Numero do aluno - > Quantidades de notas
    // turma[x]->aluno[x]->notas[n]
    alocaNotas(turmas,1,0, 5);
    alocaNotas(turmas,1,1, 5);
    
    //variavel -> Nome -> Nota -> Qual turma,Qual aluno, Posiçao da nota
                                  //turma[x] -> aluno[x]-> nota[x]
    setAluno(turmas,"Augusto", 10, 1, 1, 1);
    setAluno(turmas,"Cansei",5, 1, 0, 0);

    // Variavel -> Qual turma -> Quantos alunos
    // turma[x]
    getAluno(turmas,1,2);   

    getTurma(turmas, size_turmas);


    int *p;
    p = malloc(5 * sizeof(int));

    p[0] = 1;
     p[1] = 2;
      p[2] = 3;
       p[3] = 4;
    
    int *p1 = realloc(p,33 *sizeof(int));
    printf("\n*\tp[0] = %d\t &p[0] = %p - %d\n",p[0], &p[0], &p[0]);
    
    // Equivalente a malloc
   // p1 =(int*) realloc(NULL, 100 * sizeof(int));
    // free(p1);

   *p1 = 10;

    
    printf("\n*p[0] = %d\t &p[0] = %p - %d\n",p[0], &p[0], &p[0]);
    printf("*p[1] = %d\t &p[1] = %p - %d\n",p[1], &p[1],  &p[1]);
    printf("*p[2] = %d\t &p[2] = %p - %d\n",p[2], &p[2], &p[2]);

    
    printf("*p1[0] = %d\t &p1[0] = %p - %d\n",p1[0], &p1[0], &p1[0]);
    printf("*p1[1] = %d\t &p1[1] = %p - %d\n",p1[1], &p1[1], &p1[1]);
    printf("*p1[2] = %d\t &p1[2] = %p - %d\n",p1[2], &p1[2], &p1[2]);



	return 0;
}

