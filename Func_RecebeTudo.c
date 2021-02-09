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

void void_func(void)
{
	printf("\n\tvoid_func: %d\n", 10);
}

// Ponteiro para função
typedef void (*pf)(void*);

// Função que recebe como parametro outra função de qualquer tipo
int abstracao(pf func, void *dado)
{	
	func(dado);
	return 0;
}

// Declarando o Ponteiro da Função, direto no argumento
/*
int abstracao(void (*pf)(void*), void *dado)
{	
	pf(dado);
	return 0;
} 
*/

int main(void){
	
	Teste t;

	abstracao((void*)inserir_dados, &t);
	printf("\n Struct_1 id = %d",t.id);
	printf("\n Struct_1 nome = %s\n",t.nome);
  
	Teste_1 t2;

	abstracao((void*)inserir_dadosTeste1, &t2);
	printf("\n Struct_2 p = %c",t2.op);
	printf("\n Struct_2 valor = %.2f\n",t2.valor); 

	char *str = "Hellor World !!!";
	int int_valor = 99;
	float float_valor = 23.79;
	
	abstracao((void*)char_fun, str);
	abstracao((void*)int_func, &int_valor);
	abstracao((void*)float_func, &float_valor);
	abstracao((void*)void_func, NULL);


	return 0;
}