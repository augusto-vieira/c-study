#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]){

	int a, b;
	printf("Digite dois valores: ");
	scanf("%d",&a);
	scanf(" %d",&b);
	
	FILE *file;
	file = fopen("Entrada.txt","w");
	if(file == NULL){
		printf("Arquivo nao pode ser aberto\n");
		exit(1);
	}
	fprintf(file,"%d %d", a, b);
	fclose(file);

	freopen("Entrada.txt", "r", stdin);	
	if(dup2(fileno(popen("tee Saida.txt", "w")), STDOUT_FILENO) < 0){
		fprintf(stderr, "Nao pode redirecionar a saida\n");
		return 1;
	}
	
	if(system("soma")){
		fprintf(stderr, "Erro na execucao de soma...\n");
	}
		
	file = fopen("Saida.txt","r");
	if(file == NULL){
		printf("Arquivo nao pode ser aberto\n");
		exit(1);
	}
	char c = fgetc(file);
	while( !feof(file))  				 // !0 = verdadeiro, continua o laço.
	{   								 // !1 = falso, termina o laço.
		printf("%c",c);
		c = fgetc(file);
	}
	
	fclose(file);


	/*
    printf("pre-tee\n");

    if(dup2(fileno(popen("tee out.txt", "w")), STDOUT_FILENO) < 0) {
        fprintf(stderr, "Nao pode redirecionar a saida\n");
        return 1;
    }
    printf("post-tee\n");  */
	
	/*
	Explicação:
	popen()retorna a FILE*, mas dup2()espera um descritor de arquivo (fd), então fileno()converte o FILE* em um fd. 
	Em seguida, dup2(..., STDOUT_FILENO)diz para substituir stdout pelo fd de popen().

	Ou seja, você gera um processo filho (popen) que copia todas as suas entradas para stdout e um arquivo e, 
	em seguida, transporta seu stdout para esse processo.
	*/

    return 0;

}