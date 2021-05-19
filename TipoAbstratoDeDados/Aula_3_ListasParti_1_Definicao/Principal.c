#include<stdio.h>


int main(void){
	
	//programa principal
Lista *li;   // igual a FILE *arquivos

li = cria_lista();  // igual a F = fopen()...

libera_lista(li);  // igual a fclose()...

int x = tamanho_lista(li);

int y = lista_cheia(li);

	
	return 0;
}
