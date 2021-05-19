#include <stdio.h>
#include <stdlib.h>


	/*
		As funções de escrita de blocos de bytes permitem escrever dados mais complexos,
		como os tipos int, float, double, array ou mesmo um tipo definido pelo programador,
		como, por exemplo, a struct.

		Por questão de tamanho e velocidade, esses dados são preferencialmente gravados
		em arquivos binário.
	*/

	/*
		Para se escrever um bloco de bytes em um arquivo usamos a função fwrite()

		Forma geral:
			int fwrite(void *buffer, int bytes, int count, FILE *fp);
		
		Parâmetros:
			buffer: ponteiro genérico para os dados
			bytes : tamanho, em bytes, de cada unidade de dado a ser gravada
			count : total de unidades de dados  que devem ser gravadas
			fp	  : ponteiro para arquivo

		Retorno:
			- Total de unidades de dados gravados com sucesso, logo,
			  se o valor for igual a count, sucesso na gravação;
	*/

//int main(int argc, char *argv[])
//{
	/*
	FILE *arq;

	arq = fopen("vetor.txt","wb");  // wb - escrita binária   
	if(arq == NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}
	
	int total_gravado, v[5] = {1,2,3,4,5};

	// Grava todo array no arquivo (5 posições)
	total_gravado = fwrite(v, sizeof(int), 5, arq);


	if(total_gravado != 5)
	{
		printf("Erro na Escrita do arquivo!\n");
	}

	fclose(arq);
	return 0;
	*/
	/*
	FILE *arq;

	arq = fopen("dados.txt","wb");  // wb - escrita binária   
	if(arq == NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}
	
	char str[20] = "Hello World!";
	float x = 5;
	int v[5] = {1,2,3,4,5};

	fwrite(str, sizeof(char), 20, arq);
	fwrite(&x, sizeof(float), 1, arq);
	fwrite(v, sizeof(int), 5, arq);
	
	fclose(arq);
	return 0;
	*/

//}

struct cadastro
{
	char nome[30], endereco[30];
	int idade;
};

int main(void)
{
	FILE *arq;

	arq = fopen("dados.txt","wb");  // wb - escrita binária   
	if(arq == NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}	

	struct cadastro cad = 
	{
		"Andre",
		"Rua 1",
		31
	};

	fwrite(&cad, sizeof(struct cadastro), 1, arq);
	
	fclose(arq);
	return 0;
}