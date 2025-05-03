#include <stdio.h>
#include <unistd.h>

int main(void){

  if(isatty(STDIN_FILENO))
    printf("[Entrada padrao] do terminal\n");
  else
    printf("Nao eh a Entrada padrao\n");
  
  if(isatty(STDOUT_FILENO))
    printf("[Saida padrao] do terminal\n");
  else
    printf("Nao eh a Saida padrao\n");
  
  return 0;
}