#include <stdio.h>
#include <stdlib.h>

#define SAIR -1

typedef struct
{
    int Num_Projeto;
    float valor;
    char  DespesaReceita;
    float Projetos[10];
} Info;

void cleanBuffer(void);
void CodigoDoProjeto(Info *boleto);
void Valor(Info *boleto);
void Receita(Info *boleto);

//Ponteiro para função que recebe uma estrutura()
typedef void (*pf)(void (*ptr) (Info));

typedef struct 
{
    pf pfunc;
} Inicializa;

 // pf pfunc[];

Inicializa ini[] = 
{
    CodigoDoProjeto,
    Valor,
    Receita
};  
 
const int size_ini = sizeof(ini) / sizeof(ini[0]);


int main(int argc, char *argv[]) 
{
    Info projeto;  
    do
    {
        for(int i = 0; i < size_ini; i++)
        {
            ini[i].pfunc(&projeto);
            if(projeto.Num_Projeto == SAIR)
            break;
        }

    }while (projeto.Num_Projeto != SAIR);
    
    printf("\n");
    for(int i = 0; i < 10; i++)
    {
        printf("Saldo do projeto %d = %.2f \n", i,projeto.Projetos[i]);
    }
    
    return 0;
}


inline void cleanBuffer(void)
{
    char c;
    while ((c = getchar()) != '\n'  && c != EOF);
}

void CodigoDoProjeto(Info *boleto)
{
    printf("\nNumero do Projeto: ");
    scanf("%d",&boleto->Num_Projeto);
    cleanBuffer();
}

void Valor(Info *boleto)
{
    printf("\nDigite o Valor: ");
    scanf("%f",&boleto->valor);
    cleanBuffer(); 
}

void Receita(Info *boleto)
{
    printf("\nDigite o tipo de transacao (R ou D): ");
    scanf("%c",&boleto->DespesaReceita);
    cleanBuffer();

    if(boleto->DespesaReceita == 'R' || boleto->DespesaReceita == 'r')
    {
        boleto->Projetos[boleto->Num_Projeto] += boleto->valor;
    }
    else if (boleto->DespesaReceita == 'D' || boleto->DespesaReceita == 'd')
    {
        boleto->Projetos[boleto->Num_Projeto] -= boleto->valor;
    }
    else
    {
       fprintf(stderr, "\nTipo de transacao ' %c ' invalida...\n",boleto->DespesaReceita);
       return EXIT_FAILURE;
    }
    
}


/*
  Função que retorna ponteiro
  tipo_retornado *nome_da_função(lista_de_parametrôs)

  Ponteiro para função
  tipo_retornado (*nome_do_ponteiro)(lista_de_tipos)

  int (*ptr)(int, int);
  int soma(int x, int y);
  ptr = soma;
  resultado = p(x, y);


  Passando um ponteiro para função como parâmetro
  considere : int (*ptr)(int, int);
  int executa (int (*ptr)(int, int), int x, inty);
  
  int soma(int x, int y);
  int executa (int (*ptr)(int, int), int x, inty){
      return ptr(x, y);
  }
  resultando = executa(soma, x, y);


   tipos de nomemclatura, estilo
   snake case 
   came case
   phascal case (CamelCase)

   LowerCamelCase 
   Upper...


 versionamento semantico 

*/