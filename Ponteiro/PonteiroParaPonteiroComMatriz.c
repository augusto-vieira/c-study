#include<stdio.h>
#include<stdlib.h>

int  **aloca(int i, int j);
void libera (int **p, int i, int j);
void leitura(int **p, int i, int j);
void imprime(int **p, int i, int j);


int main(void){
	int **p;
	int **p1;
	
	p = aloca(3, 2);
	leitura(p, 3, 2);
	
	p1 = aloca(2, 3);
	leitura(p1, 2, 3);
	
	imprime(p, 3, 2);
	imprime(p1, 2, 3);
	
	libera(p, 3, 2);
	libera(p1, 2, 3);
	
	return 0;
}

	/* 2 asteriscos (*) indicam que será retornada uma matriz */
int ** aloca(int i, int j){
	
	/* ponteiro de ponteiro. Indica que será alocada uma matriz de 2 dimensões */
	int **p;
	int x;
	p = calloc(i,sizeof(int)); /* alocação de linhas... */
	if( p == NULL ){
	   printf("\nErro de alocacao");
	   exit(-1);
	}

	for(x=0;x<i;x++){
		p[x]=calloc(j,sizeof(int)); /* ... e alocação de colunas */
		if( p[x] == NULL ){
			printf("\nErro de alocacao");
			exit(-1);
		}	
    }
return p;
}		


	/* 2 asteriscos (*) indicam que a função recebe uma matriz */
void leitura(int **p, int i, int j){
	 int x,y;
	 for(x=0;x<i;x++){
		for(y=0;y<j;y++){
		printf("Entre com o elemento %d,%d ->", x, y);
		scanf("%d", &p[x][y]); /* uso da matriz no formato tradicional */
		}
	 }
}



	/* 2 asteriscos (*) indicam que a função recebe uma matriz */
void imprime(int **p, int i, int j){
	 int x,y;
	 for(x=0;x<i;x++){
	     for(y=0;y<j;y++){
		 printf("\nElemento %d,%d = %d", x, y, p[x][y]);
        }
    }
}


	/* 2 asteriscos (*) indicam que a função recebe uma matriz */
void libera(int **p, int i, int j){
	 int x;
	 for(x=0;x<i;x++){
	 free(p[x]); /* libera coluna a coluna */
	}
	free(p); /* libera as linhas */
}