#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
10  20 100 arquivo.txt
10 linhas
20 palavras
100 bytes (caracteres)

*/

#define BUFFER_SIZE 1024  // Tamanho do buffer estático

void contar_palavras_na_linha(char *linha, size_t *total_palavras){
  char *token = strtok(linha, " \t\n");
  while (token != NULL){
      (*total_palavras)++;
      token = strtok(NULL, " \t\n");
    }
}

// void processar_entrada(size_t *buffer,size_t *total_linhas, size_t *total_palavras, size_t *total_bytes){
//       // Leitura da entrada linha por linha
//       while (fgets(buffer, BUFFER_SIZE, stdin) != NULL){
//         total_bytes += strlen(buffer);
//         contar_palavras_na_linha(buffer, &total_palavras);
//         total_linhas++;
//       }
// }

int main(int argc, char *argv[]){
  
  char buffer[BUFFER_SIZE];         // Buffer para armazenar cada linha da entrada
  size_t total_bytes = 0;           // Contador de bytes (caracteres lidos)
  size_t total_palavras = 0;        // Contador de palavras
  size_t total_linhas = 0;          // Contador de linhas


  if(isatty(STDIN_FILENO)){
    printf("Entrada Padrao\n");
    FILE *input_file = stdin;
    //if()
    for(int i = 1; i < argc; i++){

      size_t tmp_bytes    = 0;
      size_t tmp_palavras = 0;
      size_t tmp_linhas   = 0;

      input_file = fopen(argv[i], "r");
      if(input_file == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
      }
      // Leitura da entrada linha por linha
      while (fgets(buffer, BUFFER_SIZE, input_file) != NULL){
        tmp_bytes += strlen(buffer);
        contar_palavras_na_linha(buffer, &tmp_palavras);
        tmp_linhas++;
        }    
      printf("%4zu %5zu %5zu %s\n", tmp_linhas, tmp_palavras, tmp_bytes, argv[i]);
      total_bytes    += tmp_bytes;
      total_palavras += tmp_palavras;
      total_linhas   += tmp_linhas;
    }
    if(argc > 2)
      printf("%4zu %5zu %5zu total\n", total_linhas, total_palavras, total_bytes);
  }
  else{
    //printf("Redirecionamento ou Pipe\n");
    // Leitura da entrada linha por linha
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL){
      total_bytes += strlen(buffer);
      contar_palavras_na_linha(buffer, &total_palavras);
      total_linhas++;
      }

    // Exibe os resultados: linhas, palavras e bytes
    printf("%4zu %5zu %5zu\n", total_linhas, total_palavras, total_bytes);
    
  }
    
  return 0;
}
 