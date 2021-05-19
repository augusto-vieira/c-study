#include<stdio.h>
#include<stdlib.h>

/*
Uma ila é um conjunto ordenado de itens a partir do qual se podem eliminar
itens numa extremidade - início da ila - e no qual se podem inserir itens na
outra extremidade - inal da ila.

Ela é uma prima próxima da pilha, pois os itens são inseridos e removidos
de acordo com o princípio de que o primeiro que entra é o primeiro que sai - irst in,
irst out (FIFO).

O conceito de ila existe no mundo real, vide exemplos como ilas de banco,
pedágios, restaurantes etc. As operações básicas de uma ila são:

insert ou enqueue - insere itens numa ila (ao inal).
remove ou dequeue - retira itens de uma ila (primeiro item).
empty 			  - veriica se a ila está vazia.
size 			  - retorna o tamanho da ila.
front 			  - retorna o próximo item da ila sem retirar o mesmo da ila.
*/

#define TAMANHO_MAXIMO 100

struct queue // queue = fila
{
	int itens[TAMANHO_MAXIMO];
	int front, rear;
};

int empty(struct queue *pq) // vazio
{
	/* se o início da fila for igual ao final da fila, a fila está vazia */
	if(pq->front == pq->rear)
	{
		return 1;
	}
	return 0;
}

void enqueue(struct queue *pq, int x) // enfileirar
{
	if(pq->rear + 1 >= TAMANHO_MAXIMO)
	{
		printf("\nEstouro da capacidade da Fila");
		exit(1);
	}
	pq->itens[pq->rear++] = x;
	return;
}

int size(struct queue *pq)
{
	return (pq->rear + 1);
}

int front(struct queue *pq)
{
	/* o primeiro elemento sempre está no início do vetor */
	return pq->itens[0];
}

int dequeue(struct queue *pq) // desenfileirar
{
	int x, i;
	if(empty(pq))
	{
		printf("\nFila vazia");
		exit(1);
	}
	
	/* Salva o primeiro elemento e refaz o arranjo dos itens, puxando o segundo elemento
	   para o primeiro, o terceiro para o segundo e assim sucessivamente. */
	x = pq->itens[0];
	for(i = 0; i < pq->rear; i++)
	{
		pq->itens[i] = pq->itens[i+1];
	}
	pq->rear--;
	return x;

}

int main(int argc, char **argv)
{
	struct queue q;
	q.front = 0; q.rear = 0;

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);

	printf("\nFila vazia %d", empty(&q));
	printf("\nTamanho da Fila %d", size(&q));
	printf("\nProximo da fila %d", front(&q));
	printf("\nTirando da fila %d", dequeue(&q));
	printf("\nTirando da fila %d", dequeue(&q));
	printf("\nTirando da fila %d", dequeue(&q));
	printf("\nProximo da fila %d", front(&q));
	printf("\nTirando da fila %d", dequeue(&q));

	printf("\nFila vazia %d", empty(&q));
	printf("\n");

return 0;
}