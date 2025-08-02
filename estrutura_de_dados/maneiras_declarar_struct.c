#include<stdio.h>
#include<stdlib.h>


 typedef struct HR{
	  int horas;
    }HR;


int main(void){
/*
  struct horario{
	  int horas;
	  int minutos;
	  int segundos;
    };
  
  // Inicializando uma variavel do tipo estrutura
   struct horario agora;
   agora.horas = 10;
   agora.minutos = 20;
   agora.segundos = 30;
   printf("%d:%d:%d \n",agora.horas, agora.minutos, agora.segundos);

   // Definindo uma estrutura e declarando uma variavel
   // igual a  " struct horario agora; "
     struct horario{
	  int horas;
	  int minutos;
	  int segundos;
    } agora;
		 
	 // declarando uma variavel e atribuindo valor 
	 struct horario{
	  int horas;
	  int minutos;
	  int segundos;
    } agora = {10, 20, 30};
	
     // O primeiro membro recebe o valor, os demais zeram;  
	 struct horario{
	  int horas;
	  int minutos;
	  int segundos;
    } agora = {10};
	
	
	 
	 struct horario{
	  int horas;
	  int minutos;
	  int segundos;
    };
	 // atribuindo valores nos membros em qualquer ordem;
	  struct horario agora = {.segundo = 10, .minutos = 20  
	  */
	  
	  HR a;
	  a.horas = 929;
	  printf("%d\n",a.horas);
	  return 0;   
}