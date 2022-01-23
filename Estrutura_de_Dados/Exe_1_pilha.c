#include<stdio.h>
#include<stdlib.h>


#define TAMANHO_PILHA 100


// inline: função pequena é muito utilizada 

//se a sua função retorna um ponteiro de tipo void, ela pode retornar um ponteiro para qualquer tipo de valor (inteiro,caracter,vetor,estrutura)
/*	Ponteiro generico: 
	void *nome_ponteiro;
	exemplo: void *v;
	
	
	  int main(){
		  // Ponteiro generico aponta para qualquer tipo de coisa;
		  void *pp;
		  int p2 = 10;
		  
		  p = &p2; // Endereço de int
		  printf("Endereco em pp: %p \n",pp);
		  
		  /*
		    Antes de acessar o conteúdo é preciso converter o ponteiro genérico para
			o tipo de ponteiro com o qual se deseja trabalhar 
		  */
		/*  printf("Conteudo %d \n", *pp); // ERRO
		  
		  printf("Conteudo %d \n", *(int*)pp); // CORRETO, (int*) = converte o endereço(pp) para int, * depois acessar o valor
		  
	return 0;  
}
	*/
	

/*
   ponteiro para função, na prática,todo nome de função é um ponteiro para função
   podemos passar um ponteiro para função como um argumento para outra função e assim permitir que aquela função execute a função que nós quisermos 

int test(int x);

int main(){
	int (*func)(int) = test;
	func(13);
	
	return 0;
}

int test(int x){
	printf("%d\n", x);
}
*/

/*
int func(void **a){
	printf("%d\n\n",*(int*)a);
	static char hello[] = "Hello word!!!";
	
	return(a = hello);
}

int main(){
	int x = 512;
	void *p = &x;
	
	/*
    int (*funcPointer)(int) = func;  // Ponteiro para função = int (*funcPointer)(int) 
	funcPointer(p);
	
	p = func(p);
	printf("%s\n",(char*)p);
	printf("%s\n",p); 

	return 0;
}
 */

typedef int (*Op)(int n1, int n2);

typedef struct __attribute__((__packed__)) //https://riptutorial.com/c/example/31059/packing-structures
{
    char op;
    Op operation;
} Operations;

int soma(int value1, int value2);
int subtrai(int value1, int value2);
int multiplica(int value1, int value2);
int divide(int value1, int value2);

typedef enum{
    Operation = 1,
    Value1,
    Value2
} Defines;

Operations operations[] = 
{
    {'+', soma},
    {'-', subtrai},
    {'*', multiplica},
    {'/', divide},
};

const int operations_amount = sizeof(operations) / sizeof(operations[0]);


int main(int argc, char *argv[])
{
    printf("operations %d --- operations[0] %d \n",sizeof(operations),sizeof(operations[0]));

    int value1;
    int value2;
    char operation;
    int result = 0;

    if(argc != 4){
        fprintf(stderr, "Error must be 4 elements.\ne.g.\n%s operation value1 value2\noperation : +, -, '*' ,/\n", argv[0]);
        return EXIT_FAILURE;
    }

    operation = argv[Operation][0];

    value1 = atoi(argv[Value1]);
    value2 = atoi(argv[Value2]);

    for(int i = 0; i < operations_amount; i++)
    {
        if(operations[i].op == operation)
        {
            result = operations[i].operation(value1, value2);
            printf("operation: %c\nvalue1: %d\nvalue2: %d\n", operation, value1, value2);
            printf("Result: %d.\n", result);
            return 0;
        }
    }

    fprintf(stderr, "Operation does not exist Aborting...\n");
        return EXIT_FAILURE;
}

int soma(int value1, int value2)
{
    return value1 + value2;
}

int subtrai(int value1, int value2)
{
    return value1 - value2;
}

int multiplica(int value1, int value2)
{
    return value1 * value2;
}

int divide(int value1, int value2)
{
    if(value2 == 0)
        abort();

    return value1 / value2;
}


// buildin - include<...>
// File descriptor -- implementado por um open file