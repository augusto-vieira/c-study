#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "aluno.h"
#include "menu.h"



int main(void)
{
	
	// Turma turma; 
//	float s[] = {1,2,3,4,5,6};
	/*float s2[] = {7,8,9,10,1.1,9.9};
	Registros *registro = criar();
	
	getAluno(registro); */
	
	
	//char e[100];
	//fscanf(stdin," %s", &e);
	    int iEntradas = 0;
		Registros *registro = criar();
		
		//registro = criar();
	
		writeTurma(registro,&iEntradas);
		getTurma(registro,iEntradas);

		editarTurma(registro,iEntradas);
		getTurma(registro,iEntradas);  


	/*	writeTurma(registro,&iEntradas);
		printf("Antes  %d   ---- \n",iEntradas);
		newTurma(&registro,&iEntradas);
		printf("depois  %d   ---- \n",iEntradas);
		writeTurma(registro,&iEntradas);

		
		getTurma(registro,iEntradas);  */


		

		//fgets(x, sizeof(x), stdin);
		//fscanf();

		//printf("%d -- %d ++++ %d\n",strlen(a),strlen(b), strlen(x));


		/*
		printf("---- Primeira turma ---\n");
	    setTurma(registro,a, 5, 2020,&iEntradas);

		printf("\tget turma \n");
		getTurma(registro,iEntradas);  */


		
		//menu();
		//cleanBuffer();
		//scanf(" %d", &c);

		//cleanBuffer();
	
	

	return 0;
}

// Encapsulamento
// É uma boa prática de programação não PERMITIR que os OBJETOS acessem os atributos de forma DIRETA

// Logo usamos MÉTODOS de acesso(funções da classe ou struct), atraves de métodos acessamos os atributos.
/*
struct Carro
{
	string marca;
	int ano
};



// atribui
void setMarca(string x){
	marca = x; 
}

// Retorna o valor 
void getMarca(string x){
	return marca; 
}

*/

// ============ Arquivos de cabeçalho ===========
// Carro.h  (Classe)
// Carro.c

// ============ Construtor e Destrutor ==========
// Ele constroi um objeto
// Atributos pré-definidos
// Carro c1; // --> vem com construtor padrão
// Carro c1("Fiat", 2017); // Construtor especial
// após declarar (Carro c1("Fiat", 2017)) para alterar os atributos
// tem que usar os métodos(set) 

// Construtor e Destrutor sempre tem o mesmo no nome da Classe

// Destrutor
// Ele destroi os objetos
// ~Carro(); // tem o '~'


// ============ Atributo Static ===============
//	static int pneus;
// static é um ATRIBUTO da CLASSE
// é um atributo igual para todo mundo,
// caso o seu valor seja alterado, muda para todos.

