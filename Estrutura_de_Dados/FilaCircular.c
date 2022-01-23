#include<stdio.h>
#include<stdlib.h>

/*
    Com o conceito de fila circular, ao chegar ao final da fila, o ponteiro de controle da
    fila vai imediatamente para o início da fila novamente (se este estiver vago)

    1. Estado inicial
    2. enqueue(D)   - O item D é armazenado ao final da fila
    3. enqueue(E)   - O item D é armazenado ao final da fila
    4. dequeue()    - Retirado o item A da fila
    5. • enqueue(F) - O item F é armazenado ao final da fila
       • enqueue(G) - O item G é armazenado ao final da fila
    6. dequeue()    - Retirado o item B da fila
    7. enqueue(H)   - O item H é armazenado ao final da fila. Neste momento, o
                      ponteiro da fila chegou ao final do vetor que contém a implementação da fila.
    8. • dequeue()  - Retirado o item C da fila
       • enqueue(I) - O item I é armazenado ao final da fila (mas no início do vetor)
    9. enqueue(K)   - O item K é armazenado ao final da fila (mas na segunda posição do vetor)
*/

#define TAMANHO_MAXIMO 10

struct queue
{
    int itens[TAMANHO_MAXIMO];
    int front, rear, qtd;
};

struct queue q;
//q.front = q.rear = -1;

// vazio
int empty(struct queue *pq)
{
    if(pq->front == pq->rear)
    {
        return 1;
    }
    return 0;
}

// enfileirar
void enqueue(struct queue *pq, int x)
{
    /* Inversão das posições dos ponteiros. Se o final do vetor já foi
       alcançado, então retorna-se ao início do vetor */
    if(pq->rear == TAMANHO_MAXIMO - 1)
    {
        pq->rear = 0;
    }
    else
    {
        pq->rear++;
    }

    if( pq->rear == pq->front)
    {
        printf("\nEstouro da Fila");
        exit(1);
    }
    
    pq->itens[pq->rear] = x;
    pq->qtd++;
    return;
}

int size(struct queue *pq)
{
    /* se o final da fila ainda não alcançou o final do vetor... */
    // if(pq->front <= pq->rear)
    //{
        /* tamanho da fila =  final da fila - o início da fila... */
       // return pq->rear - pq->front;
    //}

    /* ... se não, quer dizer que o ponteiro de final da fila já alcançou o final do vetor
    e foi reposicionado para o início do vetor, então o tamanho da fila é a quantidade
    de itens que ainda restam até chegar ao final do vetor somando itens que estão
    no início do vetor */
   // return pq->rear + pq->front;  */
   return pq->qtd;
}

int front(struct queue *pq)
{
    return pq->itens[pq->front + 1]; 
}

// desenfileirar 
int dequeue(struct queue * pq)
{
    int x, i;
    if(empty(pq))
    {
        printf("\nFila vazia");
        exit(1);
    }

    /* Inversão das posições dos ponteiros. Se o final do vetor já foi alcançado,
       então retorna-se ao início do vetor */
    if( pq->front == TAMANHO_MAXIMO - 1)
    {
         pq->front = 0;
    }
    else
    {
         (pq->front)++;
    }

    pq->qtd--;
    return (pq->itens[pq->front]);
   
}

int main(void)
{
    struct queue q;
    q.front = -1;
    q.rear  = -1;
    q.qtd   = 0;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("\nTamanho da fila %d", size(&q));
    printf("\nProximo da fila %d", front(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nProximo da fila %d", front(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTamanho da fila %d\n", size(&q));
    
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);

    printf("\nTamanho da fila %d", size(&q));
    printf("\nProximo da fila %d", front(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nProximo da fila %d", front(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTamanho da fila %d\n", size(&q));

    enqueue(&q,10);
    enqueue(&q,11);
    enqueue(&q,12);
    enqueue(&q,13);
    enqueue(&q,14);
    enqueue(&q,15);
    enqueue(&q,16);
    enqueue(&q,17);
    enqueue(&q,18);

    printf("\nTamanho da fila %d", size(&q));
    printf("\nProximo da fila %d", front(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nProximo da fila %d", front(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTamanho da fila %d", size(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTamanho da fila %d\n", size(&q));

    printf("\nFila vazia %d", empty(&q));

    enqueue(&q, 20);
    enqueue(&q, 21);
    enqueue(&q, 22);
    enqueue(&q, 23);
    enqueue(&q, 24);
    enqueue(&q, 25);

    printf("\nTamanho da fila %d", size(&q));
    printf("\nProximo da fila %d", front(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nProximo da fila %d", front(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTamanho da fila %d", size(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTamanho da fila %d", size(&q));
    printf("\nTirando da fila %d", dequeue(&q));
    printf("\nTamanho da fila %d\n", size(&q));

    printf("\nFila vazia %d", empty(&q)); 
    printf("\n");
    return 0;

}