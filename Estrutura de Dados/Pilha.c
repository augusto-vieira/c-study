#include<stdio.h>
#include<stdlib.h>

/*
A estrutura de dados do tipo pilha, LIFO - last in irst out (último a entrar primeiro a sair)

push 	 - coloca uma informação na pilha (empilha).
pop      - retira uma informação da pilha (desempilha).
size     - retorna o tamanho da pilha.
stackpop - retorna o elemento superior da pilha sem removê-lo (equivalente às operações de pop e um push).
empty    - veriica se a pilha está vazia.

*/

void push(int valor);
int pop(void);
int size(void);
int stacktop(void);

int pilha[20];
int pos = 0;

int main(int argc, char **argv){
	printf("\nColocados dados na pilha");
	push(1);
	push(2);
	push(9);
	
	printf("\nTamanho da pilha %d", size());
	
	printf("\nPegando dado da pilha: %d",pop());
	printf("\nPegando dado da pilha: %d",pop());
	printf("\nPegando dado da pilha: %d",pop());

	printf("\nTamanho da pilha %d",size());
	
return 0;
}

void push(int valor){
	pilha[pos] = valor;
	/* Empilha um novo elemento. Não é verificada a capacidade máxima da pilha*/
	pos++;
	return;
}

int pop(){
	/* Retorna o elemento do topo da pilha, Não é verificado o final da pilha */
	return(pilha[--pos]);
}

int size(){
	return pos; /* retorna o topo da pilha */
}

int stacktop(){
	/* retorna o topo da pilha sem desempilhar */
	return pilha[pos];
}