#include<stdio.h>
#include<stdlib.h>

int main(void){
	
	// Um vetor nada mais é que um ponteiro com alocação ESTÁTICA de memória 
	
	int aVetor[10];
	
	/* Declaração de vetor como ponteiro */
	
	int *pVetor;
	pVetor = (int*)malloc(10 * sizeof(int));   
	
	
	
	// Lista de Ponteiros
	// pVetor = (int*)malloc(10 * sizeof(int*)); 
	
	// Array dinâmico
	// pVetor = (int*)malloc(10 * sizeof(int));
	
	
	
	*pVetor = 1;
	*(pVetor+1) = 2;
	*(pVetor+14) = 3;
	
	printf("%d\n",*pVetor); 
	printf("%d\n",*(pVetor+1));
	printf("%d\n",pVetor[14]);
	
	
	// Print the sizeof integer 
    printf("Size of (aVetor) = %lu"
           " bytes\n", 
           sizeof(aVetor)); 
  
    // Print the size of (int*) 
    printf("Size of (*pVetor;) = %lu"
           " bytes\n", 
           sizeof(pVetor)); 
		   
		   
		   
		   /*
		   Portanto, sizeof(*p)significa "me dê o tamanho do conteúdo para o qual p aponta",
		   mas sizeof(int*)significa "me dê o tamanho do próprio tipo de ponteiro". 
		   Em sua máquina, intaparentemente tem 4 bytes, mas os ponteiros têm 8 bytes (máquina típica de 64 bits).
		   */
  
  
          // Declaração de matriz como ponteiro
  /*
    int **aMatriz;
	aMatriz = (int **) malloc( 2 * sizeof(int *)); //* linhas 
	for( int i=0; i < 2; i++)
	{
	aMatriz[i] = (int *) malloc(3 * sizeof(int)); //* colunas 
	}

   */	
   
   // disas imprimi
   // objdump -dM intel intel a.out | less
    return 0;  	
}