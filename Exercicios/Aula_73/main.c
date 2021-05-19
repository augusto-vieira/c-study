#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
	/*
		Para se escrever uma string em um arquivo usamos a função fputs
		Forma geral:
			int fputs(char *str, FILE *fp);
		Retorno:
			- Em caso de erro: a constante EOF 
			- Em caso de sucesso: um valor diferente de ZERO
		
	*/
	
	FILE *f;
	
	f= fopen("arquivo.txt","w");   
	if(f== NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}
	
	char texto[20] = "Meu programa em C"
	// Grava toda a string de uma vez
	int retorno = fputs(texto, f);
	if(retorno == EOF)
	{
		printf("Erro na Gravação\n");
	}
	fclose(f);
	
	/*
	FILE *f;
	
	f= fopen("arquivo.txt","w");   
	if(f== NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}
	fputs("Hello",f);  // OBS: fputs não coloca no final \n', ela escreve exatamente a sua string no arquivo
	fputs("World",f);
	
	// contorno
	fputs("Hello\n",f);  // Colocar '\n' na string
	fputs("World\n",f);
	// ou
	fputs("Hello",f);  
	fputc('\n',f);		 // Colocar '\n' com fputc 
	fputs("World",f);
	
	
	fclose(f);
	
	*/
	
	
	return 0;
}