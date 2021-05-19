#include <stdio.h>
int main (){

printf("*************************************************\n");
printf("Comando Break  e  Continue \n");
printf("*************************************************\n");

printf(" int a =0\n");
printf("for(int i = 0; i <= 5; i++ )\n\n");
int a =0;
  for(int i = 0; i <= 5; i++){
 	
	if(i == 4){
	printf ("Executou o Break,finaliza o for\n");
	printf(" i = %d \n",i);
	printf(" a = %d \n",a);
	break; // Encera o ciclo for
	} 
	
	if(i == 3){
	printf ("Executou o Continue,pula para proxima contagem (i) \n");
	printf(" i = %d \n",i);
	printf(" a = %d \n",--a);
	continue;   // Para o for aqui, pula para próxima contagem i++ 
	}
	
	printf("Execuntado o for: \n");
	printf(" i = %d \n",i);
	printf(" a = %d \n",a++);
      }
}