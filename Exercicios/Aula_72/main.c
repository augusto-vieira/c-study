#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
	/*
	 Ao utilizar EOF, quando manipulando dados binários, um valor inteiro igual 
	 ao valor de constante EOF pode ser lido.
	 
	 Para evitar este tipo de situação, a linguagem C inclui a função feof().
	 Forma geral:
		int feof(FILE *p);
	 Retorno:
		- Essa função retorna um valor inteiro igual a ZERO se ainda não 
		  estiver atingido o final do arquivo.
	*/
	
	/*
	 int feof(FILE *p);
	 feof();
	 Essa função serve para qualquer tipo de arquivo, qualquer tipo de dados.
	 Muito melhor que trabalhar com a constante EOF. 
	 A constante EOF é melhor usada em programas que tem somente fgetc,fputc
	*/
	
	FILE *f;
	
	f= fopen("arquivo.txt","r");   
	if(f== NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}
	
	char c = fgetc(f);
	while( !feof(f))  // Única mudança,  !0 = verdadeiro, continua o laço.
	{   							 //  !1 = falso, termina o laço.
		printf("%c",c);
		c = fgetc(f);
	}
	printf("\nFim\n");
	fclose(f);
	
	return 0;
}