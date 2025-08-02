#include<stdio.h>
#include<stdlib.h>

/*
	A passagem de um ponteiro por REFERÊNCIA a uma função gera um ponteiro
	para ponteiro.
*/

int funcao(int **piParametro){
	
	printf(" &piParametro: %d\n",&piParametro);     // Endereço de piParametro
	printf("  piParametro: %d\n",piParametro); 		// Conteúdo de piParametro
	printf(" *piParametro: %d\n",*piParametro);     // Conteúdo do endereço apontado por piParametro(piVariavel)
	printf("**piParametro: %d\n",**piParametro);    // Valor do endereço apontado por piParametro (*piVariavel)
	
	/*
	O ponteiro precisa apontar para um endereço concreto(int, daouble, bool, char) algo estático...
	int func ( int *p){};
	
    int main (void){
				int x = 10;
				int *p = &x;
				func(&p); // Errado
	} 
	*/
	return 0;
}

int main(void){
	int *piVariavel;
	piVariavel = (int*)malloc(sizeof(int));
	*piVariavel = 20;
	
	printf("Ponteiro por Referencia...\n");
	
	printf("&piVariavel: %d\n",&piVariavel);
	printf(" piVariavel: %d\n",piVariavel);
	printf("*piVariavel: %d\n",*piVariavel);
	printf("\n");
	funcao(&piVariavel);
	
	return 0;
}
   // ------------------------------  
  /*		
	float volume(float, float, float);
	printf("%f\n",volume(2,2,2));

     float volume(float comprimento, float largura, float altura)
   {
       return comprimento * largura * altura;
   }  */
  // ------------------------------
  
  
  // passagem por valor       int fun(int x){};
  
  // passagem por referencia  int func( int *x){};
  
  
  // ------------------------------
  /*
  int teste = 1;
  int *pTeste = &teste
  TestPointer(pTeste); // tenho que passaro endereço, logo, sem asterisco '*'
  
  printf("%d\n", teste);
  
  void TestPointer(int *pX){++*pX}
  
  */