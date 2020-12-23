#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct 
{
	char nome[40];
	float *nota;//nota[10];
}Aluno;

typedef struct 
{
	char id;
	int semestre;
	int ano;
    Aluno *aluno;///aluno[100];
}Turma;


int main(void){

    Turma *t;

     // Aloca para t ou t[0]
    t = (Turma*)malloc(sizeof(Turma));

  

    // Aloca para t->aluno[1]
    t->aluno = (Aluno*)malloc(2 * sizeof(Aluno));
    
    // Aloca para t.aluno[0].nota[2]
    t->aluno->nota = (float*) malloc(2 * sizeof(float));

    // Aloca para t.aluno[1].nota[2]
    t->aluno[1].nota = (float*) malloc(2 * sizeof(float));

    t->aluno->nota[0] = 777.666;  // Equivalente
    t->aluno[0].nota[0] = 12.1;   // Equivalente
    printf("\n\t %f",  t->aluno->nota[0]);
    printf("\n\t %f",  t->aluno[0].nota[0]);
 
    t->aluno[1].nota[0] = 55.55;  // [0]
    t->aluno[1].nota[1] = 44.44;   // [1] 
    printf("\n\t %f", t->aluno[1].nota[0]);
    printf("\n\t %f", t->aluno[1].nota[1]); 


    // ---------  // -----------
    /*
    //Realloc faz uma copia dos meus dados, logo, copia t para t1
    //https://www.youtube.com/watch?v=vEMTGkANXM4&ab_channel=LinguagemCPrograma%C3%A7%C3%A3oDescomplicada
    // tempo = 4:52
    Turma *t1 = (Turma*)realloc(t,sizeof(Turma));

    printf("\n\t %f", t1->aluno[1].nota[0]);
    printf("\n\t %f", t1->aluno[1].nota[1]); */
    /*
    printf("\n\t -------------");
    t1->aluno[1].nota[0] = 55.55;  // [0]
    t1->aluno[1].nota[1] = 44.44;   // [1] 

    printf("\n\t %f",  t1->aluno[1].nota[0]);
    printf("\n\t %f",  t1->aluno[1].nota[1]);
    /*

    */


    t = (Turma*)realloc(t,3 * sizeof(Turma));
    // Aloca para t[2].aluno[1]
    t[2].aluno = (Aluno*)malloc(2 * sizeof(Aluno));
    
    // Aloca para t[2].aluno[0].nota[2]
    t[2].aluno->nota = (float*) malloc(2 * sizeof(float));

    // Aloca para t[2].aluno[1].nota[2]
    t[2].aluno[1].nota = (float*) malloc(2 * sizeof(float)); 
    
    printf("\n\t ---- %f", t[2].aluno[1].nota[0]);
    printf("\n\t ---- %f", t[2].aluno[1].nota[1]); 


    free(t->aluno[0].nota);
    free(t->aluno[1].nota);
    
    free( t->aluno);
    free(t);

    return 0;
}