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


	return 0;
}

