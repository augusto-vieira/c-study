// incluindo as bibliotecas
#include <stdio.h>


// Ponteiro para funçao de emitir som
typedef void (*pfn_emitir_som) (void);
typedef void (*pfn_veiculo) (int);

// Tipo genérico 
typedef struct{
	pfn_emitir_som soar;
}Animal;

typedef struct{
	pfn_veiculo veiculo;
}Descricao;


typedef struct{
	char fabricante[100];
	char modelo[20];
	char cor[20];
	int ano;
}Tipo; 

void V1(int a){
  printf("%i\n",a);
}
/*
void V2(tipo a){
	printf("V2\n");
	printf("%s",a.fabricante);
	printf("%s",a.modelo);
	printf("%i",a.ano);
} */ 


void latir(void){
	puts("au! au! au!");
}

void miar(void){
	puts("miau! miau! miau!");
}

void mugir(void){
	puts("muuu! muuu! muuu!");
}

int main() {
	printf("Hello word!!!\n");
	Animal vaca = {&mugir};
	Animal cachorro = {&latir};
	Animal gato = {&miar};
	
	vaca.soar();
	cachorro.soar();
	gato.soar();
	
	int x;
	Descricao v1 = {&V1};
	//Descricao v2 = {&V2};
	
	v1.veiculo(5);
	
return 0;
}