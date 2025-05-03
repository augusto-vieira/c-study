#include <stdio.h>
#include <unistd.h>
#include <string.h>

void contar_palavras(char *buffer, int *palavras)
{
  char *token = strtok(buffer, " \t\n");
  while(token != NULL){
        (*palavras)++;
        token = strtok(NULL, " \t\n");
    }
}

int main(int argc, char *argv[]){
  
 char buffer[1024] = {0};
 int palavras = 0;


  // Lê enquanto houver dados na entrada
  while (fgets(buffer, 1024, stdin) != NULL){
    contar_palavras(buffer, &palavras);
    printf("A:[%d]\n", palavras);
  }
  
  return 0;
}
 