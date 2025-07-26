#include<stdio.h>
#include<stdlib.h>

#define TAMANHO_PILHA 100

/*
	Uma pilha em C pode ser declarada como uma estrutura contendo dois objetos:
	um vetor para armazenar os elementos da pilha e um inteiro para indicar a
	posição atual do topo da pilha
*/

/* Estrutura que irá conter a pilha de informações */
struct pilha{
	int topo;
	int itens[TAMANHO_PILHA];
};

/*
A estrutura de dados do tipo pilha, LIFO - last in irst out (último a entrar primeiro a sair)

push 	 - coloca uma informação na pilha (empilha).
pop      - retira uma informação da pilha (desempilha).
size     - retorna o tamanho da pilha.
stackpop - retorna o elemento superior da pilha sem removê-lo (equivalente às operações de pop e um push).
empty    - verifica se a pilha está vazia.
*/

int empty(struct pilha *p);
int pop(struct pilha *p);
void push(struct pilha *p, int e);
int size(struct pilha *p);
int stackpop(struct pilha *p);

int main(void){
	struct pilha x;
	x.topo = -1;
	
	push(&x,1);
	push(&x,2);
	push(&x,3);
	
	printf("\nTamanho da pilha %d",size(&x));
	printf("\nElemento do topo da pilha %d",stackpop(&x));
	
	printf("\n%d", pop(&x));
	printf("\n%d", pop(&x));
	printf("\n%d", pop(&x));
	printf("\n%d", pop(&x));
 
 return 0;
}


int empty(struct pilha *p){
	if(p->topo == -1){
		return 1;
	}
	return 0;
}

int pop(struct pilha *p){
	if(empty(p)){
		printf("\nPilha vazia");
		exit(1);
	}
	/* retorna o item da pilha atual e diminui a posição da pilha */
	return(p->itens[p->topo--]);
}

void push(struct pilha *p, int e){
	if(p->topo == (TAMANHO_PILHA - 1)){
		printf("\nEstouro da pilha");
		exit(1);
	}
	
	/* 
		após verificar se não haveria estouro na capacidade da pilha, é criado uma
		nova posição na pilha e o elemento é armazenado
	*/
	p->itens[++(p->topo)] = e;
	return;
}

int size(struct pilha *p){
	/* sempre lembrando que na linguagem C o índice de um vetor começa no posição 0 */
	return p->topo + 1;
}

int stackpop(struct pilha *p){
	return p->itens[p->topo];
}