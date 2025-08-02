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
		Para se ler um bloco de bytes em um arquivo usamos a função fread()

		Forma geral:
			int fread(void *buffer, int bytes, int count, FILE *fp);
		
		Parâmetros:
			buffer: ponteiro genérico para os dados
			bytes : tamanho, em bytes, de cada unidade de dado a ser gravada
			count : total de unidades de dados  que devem ser gravadas
			fp	  : ponteiro para arquivo

		Retorno:
			- Total de unidades de dados lidos com sucesso, logo,
			  se o valor for igual a count, sucesso na leitura;
	*/

//int main(int argc, char *argv[])
//{	
	/*
	FILE *arq;

	arq = fopen("vetor.txt","rb");  // rb - leitura binária   
	if(arq == NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}
	
	int total_lido, v[5]; // = {1,2,3,4,5};

	total_lido = fread(v, sizeof(int), 5, arq);

	if(total_lido != 5)
	{
		printf("Erro na Leitura do arquivo!\n");
		exit(1);
	}
	
	fclose(arq);
	printf("%d, %d, %d, %d, %d\n", v[0], v[1], v[2], v[3], v[4]);

	return 0;  
    */

	/*
	FILE *arq;

	arq = fopen("dados.txt","rb");  // rb - Leitura binária   
	if(arq == NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}
	
	char str[20]; // = "Hello World!"
	float x;	  // = 5;
	int v[5];     // = {1,2,3,4,5};

	fread(str, sizeof(char), 20, arq);
	fread(&x, sizeof(float), 1, arq);
	fread(v, sizeof(int), 5, arq);

	printf("%s\n%f\n",str, x);
	printf("%d, %d, %d, %d, %d\n", v[0], v[1], v[2], v[3], v[4]);
	
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

	arq = fopen("dados.txt","rb");  // Leitura binária     
	if(arq == NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}	

	struct cadastro cad; // = {"Andre",	"Rua 1", 31};
	fread(&cad, sizeof(struct cadastro), 1, arq);

	printf("%s\n%s\n%d", cad.nome, cad.endereco, cad.idade);
	
	fclose(arq);
	return 0;
}
