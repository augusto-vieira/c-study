//Arquivo PilhaDin.h

// elemento/dado que será armazena em cada posição da pilha
struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Pilha;

Pilha* criar_Pilha();

void libera_Pilha(Pilha* pi);

int tamanho_Pilha(Pilha* pi);

int Pilha_cheia(Pilha* pi);

int Pilha_vazia(Pilha* pi);

int insere_Pilha(Pilha* pi, struct aluno al);

int remove_Pilha(Pilha* pi); 

int consulta_topo_Pilha(Pilha* pi, struct aluno *al);
