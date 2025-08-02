//Arquivo PilhaSequencial.h

// Tamanho máximo do vetor que representa a pilha
#define MAX 100

// Tamanho do tabuleiro
#define N 4

struct Board
{
    int b[N][N];
};

typedef struct pilha Pilha;

Pilha* criar_Pilha();

void libera_Pilha(Pilha* pi);

int tamanho_Pilha(Pilha* pi);

int Pilha_cheia(Pilha* pi);

int Pilha_vazia(Pilha* pi);

int insere_Pilha(Pilha* pi, struct Board al);

int remove_Pilha(Pilha* pi); 

int consulta_topo_Pilha(Pilha* pi, struct Board *al);
