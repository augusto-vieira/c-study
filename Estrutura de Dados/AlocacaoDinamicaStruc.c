#include<stdio.h>
#include<stdlib.h>


struct ST_DADOS{
	char nome[40];
	float salario;

/* Estrutura dentro de uma estrutura */
struct nascimento{
	int ano;
	int mes;
	int dia 
}dt_nascimento;

};

int main(void){
	/* ponteiro para estrutura */
	struct ST_DADOS *p;

	/* alocação de momória para o ponteiro da estrutura */
	p = (struct ST_DADOS*)malloc(sizeof(struct ST_DADOS));

	/* string (vetor de caracter) é um ponteiro, por isto a ausencia do & */
	printf("\n Entre com o nome -> ");
	scanf("%s",&p->nome);

	printf("Entre com o salario ->");
	scanf("%f", &p->salario);

	/*
	 O  ->  é chamando de pointer member (apontador de membro). Ele é usado para referenciar um
	 campo da estrututa no lugar do ponto (.)
	*/
	
	printf("Entre com o nascimento - >");
	scanf("%d%d%d",&p->dt_nascimento.dia,
				   &p->dt_nascimento.mes,
				   &p->dt_nascimento.ano);


	printf("\n===== Dados digitados =====");
	printf("\nNome = %s",p->nome);
	printf("\nSalario = %f",p->salario);
	printf("\nNascimento = %d/%d/%d\n",p->dt_nascimento.dia,
									   p->dt_nascimento.mes,
									   p->dt_nascimento.ano);

free(p);

return 0;
}