#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	int n;
	int **p;
	printf("\nEntre com um numero inteiro: ");
	scanf("%d",&n);
	
	p = (int **)malloc(n * sizeof(int *));
	  if(p == NULL){
		printf("memoria insuficiente.\n");
		exit(1);
	  }
	  for(int i = 0; i < n; i++){
		p[i] = (int *)malloc(n * sizeof(int));
		if(p[i] == NULL){
		  printf("memoria insuficiente.\n");
		  exit(1);
		}
	  }
	 p[0][0] = 1;
	 p[1][0] = 1;	p[1][1] = 1;
	 p[2][0] = 1;	p[2][1] = 2; p[2][2] = 1;
	 p[3][0] = 1;	p[3][1] = 3; p[3][2] = 3;	p[3][3] = 1;
	 
	 i
	 
	 
	 printf("%d\n",p[0][0]);
	 printf("%d %d\n",p[0][3], p[0][0]);
	 printf("%d %d %d\n",p[0][3], p[0][0],p[0][0]);
	 printf("%d %d %d %d\n",p[0][3], p[0][0],p[0][0],p[0][0]);
	 
	 
	 
	  printf("\n");
	  printf(" %d",p[0][0]);
	  printf("\n");
	  printf(" %d",p[0][0]);
	  printf(" %d",p[0][0]);
	  
	 
	 for(int i = 0; i < n; i++) {
		 free(p[i]);
	 }
	free(p);
	return 0;
} 