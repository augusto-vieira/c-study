#include <stdio.h>
#include <stdlib.h>

/*
	utiliza a função calloc para criar uma matriz em tempo de
	execução. De forma idêntica a malloc, a função calloc retorna um ponteiro nulo
	(NULL) no caso de erro de alocação de memória.
*/

int main(void){
	/* A declaração de uma matriz de 2 dimensões exige um ponteiro para ponteiro. */
	int **p;
	int i, j, k, x;
	printf("\nDigite as dimensoes da matriz ->");
	scanf("%d %d",&i, &j);
	
	/* 
	   Alocação da primeira dimensão. Internamente, a função calloc fará uma multiplicação da
	   quantidade de elementos pelo tamanho de cada elemento para saber quanto de memória
	   deve ser alocada. 
	*/
	p = (int**)calloc(i, sizeof(int*));
	if(p == NULL){
		printf("\nErro de alocacao de memoria");
		exit(1);
	}
	
	for(k = 0; k < i; k++){
		/* Alocação das linhas de cada coluna (segunda dimensão) */
		p[k] = calloc(j, sizeof(int));
		if(p[k] == NULL){
			printf("\nErro de alocacao de memoria");
		exit(1);
		}
		
	}
	
	for(k = 0; k < i; k++){
		for(x = 0; x < j; x++){
			printf("Digite o numero para o indice %d, %d ->",k,x);
			scanf("%d",&p[k][x]);
		}
	}
	
	for(k = 0; k < i; k++){
		for(x = 0; x < j; x++){
			printf("O numero do indice %d, %d eh %d\n",j, x, p[k][x]);
		}
	}
	
	printf("\nLiberando memoria alocada");
	for(k = 0; k < i; k++){
		free(p[k]);  /* Primeiro deve ser liberada a memória para linha da matriz... */
	}
	free(p); /* ... para depois liberar a memória do vetor que continha as linhas. */
	
	
	/*
	Internet - liberar array 
	int **array;
	int size1 = sizeof(array)/sizeof(array[0]);
	 for(int i=0; i<size1; i++) {
     free(array[i]);
	 }
	free(array);
	
	*/
	
	
	return 0;
}