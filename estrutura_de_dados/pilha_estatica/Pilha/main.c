// programa principal
#include<stdio.h>

#include "PilhaSequencial.h"

int main(void)
{
    
    Pilha *pi;

    // Primeira coisa que eu faço com a pilha é criar ela.
    pi = criar_Pilha();

    // Criando uma estrutura do tipo "aluno" para colocar na pilha
    struct aluno Date_1, Date_2,Date_3, print;
    Date_1.matricula = 100;
    Date_2.matricula = 200;
    Date_3.matricula = 300;

    printf("Tamanho da Pilha = %d\n", tamanho_Pilha(pi));

    // Verifico se a pilha está cheia
    if( !(Pilha_cheia(pi)) )
    {
        printf("push, push, push\n");
        insere_Pilha(pi, Date_1);
        insere_Pilha(pi, Date_2);
        insere_Pilha(pi, Date_3);
    } 
    else
    {
        printf("Pilha cheia!\n");
        return -1;
    }

    printf("Tamanho da Pilha = %d\n", tamanho_Pilha(pi));

    //copio o último elemeto da pilha para "print".
    consulta_topo_Pilha(pi, &print);
    printf("Consulta ao topo da Pilha = matricula [%d]\n", print.matricula);
    
    remove_Pilha(pi);
    printf("Removendo um elemento da Pilha, tamanho = %d\n", tamanho_Pilha(pi));

    libera_Pilha(pi);

    return 0;
}

