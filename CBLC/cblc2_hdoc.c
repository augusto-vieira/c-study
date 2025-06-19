#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ARGS_MIN 2
#define ARGS_MAX 3

#define F_NEW       "w+"
#define F_OVERWRITE "w"
#define F_APPEND    "a"

char *parse_args(char *args[], int *size_args){
  int size = *size_args;
  int index = 1;
 
  if(size == ARGS_MIN)
  {
    /* Caso tenha dois argumentos, o segundo não pode começar com a opção '-' */
    if(args[index][0] == '-')
    {
      fprintf(stderr, "./hdoc [OPÇÕES|-o/-a] [ARQUIVO] \n");
      return NULL;
    }
    
    /* Atribui o posição que contém o nome para o arquivo de saída */
    *size_args -= index;
    return F_NEW;
  }
  else if(size > ARGS_MAX)
  {
    fprintf(stderr, "Invalid number of args\n");
    return NULL;
  }

  /* O program aceita '-o' ou '-a' no primeiro ou último parâmetro */
  for(int i = 1; i < size; i++)
  {
    if (strcmp(args[i], "-o") == 0)
    { 
      *size_args = ++index;
      return F_OVERWRITE;  
    }
    else if(strcmp(args[i], "-a") == 0)
    {
      *size_args = ++index;
      return F_APPEND;
    }
    --index;
  }

  fprintf(stderr, "Invalid arg\n");
  return NULL;
}

int write_file(char **argv, int size, char *mode){
  char line [BUFSIZ];
  char *file = argv[size];

  /* Verifica se o arquivo existe, mas caso tenha a opção '-o' ou '-a' ele pode acessar */
  if ((access(file, F_OK) == 0 && strcmp(mode, "w")) && strcmp(mode, "a")) {
          fprintf(stderr, "File exists!\n");
          return EXIT_FAILURE;
  }  

  FILE *fstr = fopen(file, mode);
  
  if (!fstr)
  {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while(fgets(line, BUFSIZ, stdin) != NULL) 
  {
    fprintf(fstr ,"%s", line);
  }

  fclose(fstr);
  return EXIT_SUCCESS;
}

int main(int argc, char *argv[]){
  
  char *mode = parse_args(argv, &argc);

  if(mode == NULL)
    exit(EXIT_FAILURE);
  
  return write_file(argv, argc, mode);
}
 