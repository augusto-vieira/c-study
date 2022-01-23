//Arquivo TipoAbstratoDeDados.c
#include <stdio.h>
#include <stdlib.h>

#include "Ponto.h"

int main(void){
	float d;
	Ponto *p,*q;
	//Ponto r; //ERRO
	
	p = pto_cria(10,21);
	q = pto_cria(7,25);
	// q->x = 2;  //ERRO
	
	d = pto_distancia(p,q);
	printf("Distancia entre pontos: %f \n",d);
	pto_libera(q);
	pto_libera(p);
	
	system("pause");
	return 0;
}

/*
  Para gerar executável no Windows :
  
   Na pasta consta os seguintes arquivos;
   - Ponto.c
   - Ponto.h
   - TipoAbstratoDeDado
  
   1º Abra o cmd na pasta dos arquivos:
       digite no terminal:
	    gcc -c -I -w  Ponto.c
	    gcc -c -I -w  TipoAbstratoDeDado.c
	      Criamos os arquivos objetos "Ponto.o" e "TipoAbstratoDeDado.o"
		
	2º Basta linkar os arquivos objetos e criar o executável, 	
	    digite no terminal:
		gcc -o bin TipoAbstratoDeDado.o Ponto.o
		  Isso ira criar um executável chamando "bin.exe"

*/