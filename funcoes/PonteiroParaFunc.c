#include<stdio.h>
#include<stdlib.h>

// Função que retorna ponteiro
int *func_retornPonteiro(int x)
{
	return (int*)malloc(x * sizeof(int));
}

// Ponteiro para função como Argumento
int executa (int (*ponteiro_paraFunc)(int,int), int a , int b)
{
	return ponteiro_paraFunc(a, b);
}  

int soma(int a, int b)
{
	return a + b;
}

typedef struct 
{
	char str[20];
	int id;

} Teste;

int preencher(Teste *Struct , int valor)
{
	Struct->id = 100;
	snprintf(Struct->str,20,"Deu Certo!!!");
	printf("\n\nfunc preencher valor = %d", valor);
	return 0;
}

// Ponteiro para Função
typedef void (*pfun)(void*, int);

void abstracao(pfun func, void *estrutura, int valor)
{
	func(estrutura, valor);
}

int main(void){
	
	// Ponteiro para função
	int (*ptr)(int, int);

	//Ponteiro recebe o endereço da função
	ptr = soma;
	
	printf("\nSoma eh %d\n", ptr(2,5));
	printf("func executa: %d\n", executa(soma,5,5));

	int *p;
	p = func_retornPonteiro(4);


	for(int i = 0; i < 4; i++)
	p[i] = 5+i; 
	
	for(int x = 0; x < 4; x++)
	printf("\np[%d] = %d", x, p[x]);

	Teste dados;
	abstracao((void*)preencher, &dados, 55);
	printf("\n Struct id = %d",dados.id);
	printf("\n Struct str = %s\n",dados.str);

	return 0;
}