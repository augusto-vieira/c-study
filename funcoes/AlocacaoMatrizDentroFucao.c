#include <stdio.h>
#include <stdlib.h>

void aloca(int ***p, int x, int y);

	/* a função recebe um ponteiro para uma matriz */
void aloca(int ***p, int x, int y){
	int i;
	*p = (int**)malloc(x * sizeof(int));
	if(*p == NULL){
		printf("\nErro de alocacao de memoria!");
		exit(1);
	}
	
	for(i = 0; i < y; i++){
        (*p)[i] = (int *) malloc(sizeof(int) * y);
		if((*p)[i] == NULL ){
		  printf("\nErro de alocacao de memoria!");
		  exit(1);
		}
    }
	return;
}
	

int main(void){

	int **p; /* declaração de uma matriz com duas dimensões */
	int i,k;	
	
	aloca(&p, 4, 5 ); /* passando para a função o endereço de memória do ponteiro */
	
	for( i = 0; i<4 ;i++){
		for(k = 0; k < 5; k++){
		 p[i][k] = i + k;
		}
	}	

	for(i = 0; i < 4; i++){
		for( k = 0; k < 5; k++){
			printf("%d ", p[i][k]); /* referência aos elementos através de linha e coluna */
		}
		printf("\n");
	}

return 0;
}