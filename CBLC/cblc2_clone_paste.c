#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINHAS 100     /* Tamanho Máximo da Linha */
#define MAX_TAM_LINHA 1024 /* Quantidade Máxima de Linhas */
#define MAX_ARQUIVOS 10    /* Quantidade Máxima de Arquivos */

/*
            coluna 0   coluna 1
          +---------+---------+
linha 0   |     A1  |    B1   |
linha 1   |     A2  |    B2   |
linha 2   |     A3  |    B3   |
          +------------+------+

Primeiro arquivo      Segundo arquivo
linhas[0][0] = "A1"   linhas[1][0] = "B1"
linhas[0][1] = "A2"   linhas[1][1] = "B2"
linhas[0][2] = "A3"   linhas[1][2] = "B3"

*/

void imprimir_resultado(char linhas[][MAX_LINHAS][MAX_TAM_LINHA],
                        int total_arquivos,
                        int linhas_max)
{
  /* loop para cada linha atual */
  for (int i = 0; i < linhas_max; i++)
  {
    /* loop para coluna (arquivo) */
    for (int j = 0; j < total_arquivos; j++)
    {
      printf("%s\t", linhas[j][i]);
    }
    printf("\n");
  }
}

int processar_entrada(FILE *entrada, char linhas[][MAX_TAM_LINHA])
{
  /* Contar o número de linhas lidas no arquivo */
  int contador = 0;

  char buffer[MAX_TAM_LINHA];

  /* Realiza a leitura, linha por linha */
  while (fgets(buffer, sizeof(buffer), entrada) != NULL)
  {
    /* Remover a nova linha */
    buffer[(strcspn(buffer, "\n"))] = '\0';

    strcpy(linhas[contador], buffer);
    contador++;
  }

  return contador;
}

int main(int argc, char *argv[])
{
  FILE *entrada = stdin;

  /* Matriz contendo todas as linhas de todos os arquivos */
  char linhas[MAX_ARQUIVOS][MAX_LINHAS][MAX_TAM_LINHA] = {0};

  int max_linhas = 0;
  int tmp_linhas_lidas = 0;

  size_t redirecionamento = isatty(STDIN_FILENO);

  /* Verificar se a entrada é um Redirecionamento ou Pipe */
  if ((redirecionamento && argc == 1) || argc == 1)
  {
    tmp_linhas_lidas = processar_entrada(entrada, linhas[0]);
    imprimir_resultado(linhas, 1, tmp_linhas_lidas);
  }

  /* Se houver arquivos como argumentos */
  else
  {
    for (int i = 1; i < argc; i++)
    {
      /* Faço a Leitura de cada arquivo*/
      entrada = fopen(argv[i], "r");

      if (entrada == NULL)
      {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
      }

      tmp_linhas_lidas = processar_entrada(entrada, linhas[i - 1]);

      /* Atualiza o maior número de linhas lidas entre os arquivos */
      if (tmp_linhas_lidas > max_linhas)
        max_linhas = tmp_linhas_lidas;
    }
    imprimir_resultado(linhas, argc - 1, max_linhas);
  }

  return EXIT_SUCCESS;
}