/* 
	- os protótipos das funções 
	- o tipo de dado armazenado na lista
	- o ponteiro da "lista"
	- tamanho do vetor usado na lista
*/

#define MAX 100

struct aluno{
	int matricula;
	char nome [30];
	float n1,n2,n3;
};

typedef struct lista Lista;

Lista* cria_lista();

void libera_lista(Lista* li);

int tamnho_lista(Lista* li);

int tamnho_cheia(Lista* li);