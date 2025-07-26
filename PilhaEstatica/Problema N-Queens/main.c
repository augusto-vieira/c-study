// programa principal
#include<stdio.h>
#include<stdbool.h>

#include "PilhaSequencial.h"

bool isSafe(struct Board* board, int linha, int col);
bool resolver_NRainha(struct Board* board, int col);
void print(struct Board* board);

Pilha *pi;
struct Board dado = {0};

int main(void)
{
    pi = criar_Pilha();
    
     resolver_NRainha(&dado,0);
     printf("Tamanho da pilha %d\n", tamanho_Pilha(pi));
     print(&dado);

    return 0;
}

bool isSafe(struct Board* board, int linha, int col) 
{
    int i, j;
    /* Verifica a linha do lado esquerdo */
    for (i = 0; i < col; i++)                   
        if (board->b[linha][i])                 
            return false;
  
    /* Verifica a diagonal superior do lado esquerdo */
    for (i = linha, j = col; i >= 0 && j >= 0; i--, j--)
        if (board->b[i][j])
            return false;
  
    /* verifica a diagonal inferior do lado esquerdo */
    for (i = linha, j = col; j >= 0 && i < N; i++, j--)
        if (board->b[i][j])
            return false;
  
    return true;
}

/* Uma função de utilidade recursiva para resolver o problema de N-Rainha */
bool resolver_NRainha(struct Board* board, int col)
{
    /*Se todas as rainhas forem colocadas então retorna verdadeiro*/
    if (col >= N)
        return true;
  
    /* Considere esta coluna e tente colocar a rainha em todas as linhas, uma por uma */
    for (int i = 0; i < N; i++) {
        
        /* Verifica se a rainha pode ser colocada board[i][col] */
        if (isSafe(board, i, col)) {
        
            /* Coloque a rainha em board[i][col] */
            board->b[i][col] = 1;
            insere_Pilha(pi, dado); //add na pilha
            
            /* Recursão para colocar o resto das rainhas */
            if (resolver_NRainha(board, col + 1))
                return true;
  
            /* Se colocar a rainha no board[i][col] não levar a uma solução, remova a rainha de board[i][col] */
            board->b[i][col] = 0; // BACKTRACK
            remove_Pilha(pi); // remove da pilha
        }
    }
  
    /* Se a rainha não poder ser colocada em nenhuma linha nesta coluna, retorne falso  */
    return false;
}

void print(struct Board* board)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board->b[i][j]);
        printf("\n");
    }
}

