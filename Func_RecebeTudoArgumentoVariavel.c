#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int id;
	char nome[40];
} Teste;

typedef struct 
{
	char op;
	float valor;
} Teste_1;

int inserir_dados(Teste *t)
{
	t->id = 99;
	strncpy(t->nome,"Joao",40);
	return 0;
}

int inserir_dadosTeste1(Teste_1 *t)
{
	t->op = 'A';
	t->valor = 2.33;
	return 0;
}

char char_fun(char *str)
{
	printf("\n\tchar_func: %s\n", str);
	return 0;
}

int int_func(int *valor)
{
   printf("\n\tint_func: %d\n",*valor);
   return 0;
}

float float_func(float *valor)
{
   printf("\n\tfloat_func: %.2f\n",*valor);
   return 0;
}

double double_func(int *i_valor, float *f_valor,  char *str)
{
	printf("\n\tdouble_func: %d - %.2f - %s\n", *i_valor, *f_valor, str);
	return 0;
}

void void_func(void)
{
	printf("\n\tvoid_func: %d\n", 10);
}

// Ponteiro para funçãp com Argumentos Variáveis
typedef void (*pf)(void*, ...);

typedef struct 
{
	pf func;
} Interface;

Interface opcao[] = 
{
	(void*)inserir_dados,
	(void*)inserir_dadosTeste1,
	(void*)char_fun,
	(void*)int_func,
	(void*)float_func,
	(void*)void_func,
	(void*)double_func,
};

const int size_opcao = sizeof(opcao) / sizeof(opcao[0]);

int main(void){
	
	Teste t;
	Teste_1 t2;

	char *str = "Hellor World !!!";
	int int_valor = 99;
	float float_valor = 23.79;

	for(int i = 0; i < size_opcao; i++)
	{
		if( i == 0)
		opcao[i].func(&t);
		
		else if ( i == 1)
		opcao[i].func(&t2);

		else if ( i == 2)
		opcao[i].func(str);	

		else if ( i == 3)
		opcao[i].func(&int_valor);	

		else if ( i == 4)
		opcao[i].func(&float_valor);	

		else if ( i == 5)
		opcao[i].func(NULL);

		else if ( i == 6)
		opcao[i].func(&int_valor, &float_valor, "Deu Certo !!!");			

	} 

	printf("\n Struct_1 id = %d",t.id);
	printf("\n Struct_1 nome = %s\n",t.nome);

	printf("\n Struct_2 p = %c",t2.op);
	printf("\n Struct_2 valor = %.2f\n",t2.valor); 

	return 0;
}