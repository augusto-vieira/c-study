#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
	/*
	 Ler o conteudo de um arquivo em minusculo e criar outro 
	 arquivo com o texto em maiúsculo
	*/
	
	FILE *f1, *f2;
	
	f1 = fopen("minuscula.txt","r");   
	f2 = fopen("maiuscula.txt","w");  
	
	if(f1 == NULL || f2 == NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}
	
	
	// Ler todo conteúdo de um arquivo
	char c = fgetc(f1);
	while(c != EOF)
	{   
		fputc(toupper(c),f2);  // grava dados no f2, toupper é uma função que converte a -> A
		c = fgetc(f1);
	}
	
	fclose(f1);
	fclose(f2);
	
	return 0;
}