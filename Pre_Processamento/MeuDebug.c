#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdarg.h>


//#define DEBUG  //Deu certo
/*
#ifdef DEBUG
#define DEBUG_PRINT printf
#else
#define DEBUG_PRINT(...)
#endif

*/


// Debug com informações de arquivo
#if defined(DEBUG) && DEBUG == 2
 #define DEBUG_PRINT(fmt, args...) fprintf(stderr, "DEBUG: %s:%d:%s():\n-> " fmt, \
    __FILE__, __LINE__, __func__, ##args)

// Debug simples
#elif defined(DEBUG) && DEBUG ==1 
 #define DEBUG_PRINT printf

#else
 #define DEBUG_PRINT(fmt, args...) /* Não faça nada */
#endif


//Usando typedef na struct para encurtar o comando na declaração
typedef struct
{
  int matricula ;
  float nota;
}tAluno;

typedef struct
{
  char a;
  char b;
  
}teste;

// 'F5' Começar a debugar seu  código
// 'F10' Analisar  a linha sem entrar no código interno
// 'F11' Analisar a linha e entrar no código interno
// 'SHIFT + F11' sair do bloco de código atual e continuar a execução 


int max (int xn,...){
	//printf("%d\n",n);

	int x;
	va_list v1;
	va_start (v1,xn);
		
	for(int i = 0; i < 10; i++){
		x = va_arg(v1,int);
		printf("%d\n",x);
	}
	va_end(v1);

	
	DEBUG_PRINT("teste com debug \n");
	return 0;
}

int main (void)
{

printf("*************************************************\n");
printf("		struct 			\n");
printf("*************************************************\n");

 max(10,0,1,2,3,4,5,6,7,8,9);

 char a[] = "Augusto";
 
 DEBUG_PRINT("%s \n",a);

printf("sem debug\n");
/*
  //a1 é uma struct do tipo tAluno
  tAluno a1 ; 
  
  //*ptrAluno é um ponteiro do tipo tAluno que
  //recebe o endereço de a1;
  tAluno *ptrAluno = &a1;   
  
  //Atribuindo valores para os membros da struct a1
  a1.matricula =555;
  a1.nota = 8.0;
  
  //exibindo dados usando a struct diretamente usando .
  printf ("matricula: %d nota: %.2f \n",a1.matricula,a1.nota);
  
  //Podemos atribuir ou acessar um valor usando o ponteiro (*ptrAluno)
  (*ptrAluno).nota = 8.5;
  
  //exibindo dados usando um ponteiro para struct
  printf ("\nmatricula: %d nota: %.2f \n",(*ptrAluno).matricula,(*ptrAluno).nota);
  
  //ptrAluno-> substitui a notação (*ptrAluno). de forma mais intuitiva  
  
  //atribuindo um novo valor para a nota usando ptrAluno->
  ptrAluno->nota = 9.0;
  
  //portanto (*ptrAluno).nota é o mesmo que usar ptrAluno->nota
  
  printf ("\nmatricula: %d nota: %.2f \n",ptrAluno->matricula,ptrAluno->nota);

 char A2 = '*';
 printf("*\n");
 printf("A\n");
 printf("%c\n",A2);
 
 //for (int x = 0; x <) */
 /* printf("\n teste\n");
  char *p = "hello word !!!";
  char v[] = "hello worD !!!";
  puts(p);
  puts(v);
  
  int retorno = strcmp(p,v);
  printf("%i \n",retorno);
  printf("-----------------------\n");
  char **frases = {"Augusto", "Frases", "!!!"};
  //char *frases[] = {"Augusto", "Frases", "!!!"};   
  //printf("%s\n", frases[2]); 
  // char *test = "1234";
 // printf("test = %s\n", test+1);
 
  printf("%c\n", *frases+0);
 printf("%c\n", *frases+1);
 printf("%c\n", *frases+2);
 printf("%c\n", *(frases+2)); 
  
  printf("%p\n", &frases);
  printf("%p\n", &frases+1);
  printf("%p\n", &frases+2);
  printf("%p\n", &frases+3);
  printf("-----------------------\n");*/

  void Nome(char *n);
  size_t name;
  char nome[] = "Hello2";
  Nome(nome);
}


void Nome(char *n){
	
	printf("%s",n);
}