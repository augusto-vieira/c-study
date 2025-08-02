/* 
	- o tipo de dado "lista"
	- implementar as suas funções 
*/

struct lista {
	int qtd;
	struct aluno dados[MAX];
};

void Lista* cria_lista(){
	Lista *li;
	li = (Lista*)malloc(sizeof(struct lista));
	if(li != NULL)
		li ->qtd = 0;
	return li;
}

void libera_lista(Lista* li){
	free(li);
}

int tamnho_lista(Lista* li){
	if(li == NULL)
		return -1;
	else
		return li->qtd;
}

int tamnho_cheia(Lista* li){
	if(li == NULL)
		return -1;
	return(li->qtd == MAX);
}