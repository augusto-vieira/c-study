#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* Tamanho do buffer estático */ 
#define BUFFER_SIZE 1024 

#define LINHAS    0
#define PALAVRAS  1
#define BYTES     2
#define VARIAVEIS 3

void contar_palavras_na_linha(char *linha, size_t *total){
  char *token = strtok(linha, " \t\n");
  while (token != NULL){
      total[PALAVRAS]++;
      token = strtok(NULL, " \t\n");
    }
}

void processar_entrada(char *buffer,size_t *total, FILE *entrada){
    
    /* Realiza a leitura, linha por linha */
    while (fgets(buffer, BUFFER_SIZE, entrada) != NULL){
      total[BYTES] += strlen(buffer);
      contar_palavras_na_linha(buffer, total);
      total[LINHAS]++;
      }
}

int main(int argc, char *argv[]){
  
  char buffer[BUFFER_SIZE];         
  size_t total[VARIAVEIS] = {0};
  FILE *entrada = stdin;

  /* Verificar se a entrada é o padrão ou Redirecionamento/Pipe */
  if(isatty(STDIN_FILENO) || argc != 1){
    
    if(argc == 1){
      processar_entrada(buffer, total, entrada);
      printf("%4zu %5zu %5zu\n", total[LINHAS], total[PALAVRAS], total[BYTES]);
      return EXIT_SUCCESS;
    }

    for(int i = 1; i < argc; i++){

      size_t total_tmp[VARIAVEIS] = {0};
      entrada = fopen(argv[i], "r");
      
      if(entrada == NULL){
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
      }
     
      processar_entrada(buffer, total_tmp, entrada);
      total[LINHAS]   += total_tmp[LINHAS];
      total[PALAVRAS] += total_tmp[PALAVRAS];
      total[BYTES]    += total_tmp[BYTES];
  
      printf("%4zu %5zu %5zu %s\n", total_tmp[LINHAS], total_tmp[PALAVRAS], total_tmp[BYTES], argv[i]);
    }
    if(argc > 2)
      printf("%4zu %5zu %5zu total\n", total[LINHAS], total[PALAVRAS], total[BYTES]);
  }
  else{
  
    processar_entrada(buffer, total, entrada);
    printf("%4zu %5zu %5zu\n", total[LINHAS], total[PALAVRAS], total[BYTES]);
    
  }   

  return EXIT_SUCCESS;
}
 