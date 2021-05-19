#include "menu.h"

void cleanBuffer(void)
{
    char c;
    while ((c = getchar()) != '\n'  && c != EOF);
} 

void menu(void)
{
    char opcao = 'G';
    do{
        
    	printf("\na - Definir informacoes da turma");
		printf("\nb - Inserir aluno e notas");
		printf("\nc - Exibir alunos e medias");
		printf("\nd - Exibir alunos aprovados");
		printf("\ne - Exibir alunos reprovados");
        printf("\nf - Salvar dados em Disco");
		printf("\ng - Sair do programa(fim)");
		printf("\nEntre com uma opcao -> ");
        fscanf(stdin,"%c",&opcao);
       // getchar();
        cleanBuffer();

        if(toupper(opcao) == 'A')
        {
            printf("\n[c] para criar turma.");
            printf("\n[e] para editar turma.\n");
            fscanf(stdin,"%c",&opcao);
            //cleanBuffer();
            
            if (toupper(opcao) == 'C')
            {
                // CHECK_createTurma();
            }
            else
            {

            }
        } 
    
    } while(toupper(opcao) != 'G' );   
}

void  CHECK_createTurma(Turma *p)
{/*
    char identifacao[40];
	int semestre;
	int ano;
    cleanBuffer();
    printf("\nNome para identificar a turma: ");
    fgets(identifacao, sizeof(identifacao), stdin);

    

    printf("\nSemetre: ");
    fscanf(stdin, "%d",&semestre);
    cleanBuffer();

    printf("\nAno: ");
    fscanf(stdin, "%d",&ano);
    cleanBuffer();
    
    printf("\nAqui: %d %d %s ",  semestre, ano, identifacao); */
}



