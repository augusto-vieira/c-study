#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
	/*
		Para se ler uma string de um arquivo usamos a função fgets
		Forma geral:
			int fgets(char *str, int tamanho, FILE *fp);
		Retorno:
			- Em caso de erro: NULL 
			- Em caso de sucesso: um ponteiro para o primeiro caracter de str		
	*/
	
	char str[20];  // Subtrair o caracter '\0' terminador, tamanho da frase = 19 caracteres
	FILE *arq;
	
	arq = fopen("arquivo.txt","r");   
	if(arq == NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}

	char *result = fgets(str, 12, arq);  // 12 - '\0' =  Lê 11 caracteres
	if(result == NULL)
	{
		printf("Erro na Leitura\n");
	}
	else
	{
		printf("%s", str);
	}

	printf("\n");
	fclose(arq);

	/*
		A função fgets() lê uma string até encontrar um caracter de nova linha  '\n'
		ou "tamanho - 1" caracteres
	*/

	return 0;
}