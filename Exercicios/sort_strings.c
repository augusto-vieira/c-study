#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 100      // Número máximo de linhas que podem ser armazenadas
#define TAMANHO_BUFFER 1024 // Tamanho máximo do buffer para leitura de cada linha

void ordenar(char *lista[MAX_LINHAS], int total_linhas)
{
  /* Caracteres que serão comparados */
  char c1, c2;

  /* Índice do caractere atual dentro da string */
  int indice = 0;

  // Percorre cada elemento da lista
  for (int i = 0; i < total_linhas - 1; i++)
  {

    /* compara o elemento atual (lista[i]) com os elementos seguintes (lista[j]) */
    for (int j = i + 1; j < total_linhas; j++)
    {

      while (1)
      {
        c1 = toupper(lista[i][indice]);
        c2 = toupper(lista[j][indice]);

        /* debug das linhas */
        // printf("lista[%d][0](%c) - lista[%d][0](%c)\n", i, c1, j, c2);

        /* Compara o entre lista[i] e lista[j] */
        if (c1 > c2)
        {
          /* Troca as posições caso lista[i] seja maior que lista[j] */

          char *auxliar = lista[i]; //   [2](a)  --> [aux](a)
          lista[i] = lista[j];      //   [3](b)  -->  [2](b)
          lista[j] = auxliar;       //  [aux](a) -->  [3](a)
          indice = 0;
          break;
        }

        /*  Caso lista[i] já esteja corretamente ordenada, interrompe o loop */
        else if (c1 < c2)
        {
          break;
        }

        /* Se o caractere for igual, compara com o próximo caractere da string */
        indice++;
      }
    }
  }

  for (int i = 0; i < total_linhas; i++)
  {
    printf("Ordenado: %s", lista[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  /* Vetor de ponteiro para char, cada linhas vai ser uma String */
  char *lista[MAX_LINHAS] = {0};

  /* Vetor de caractere, buffer temporário para leitura das linhas */
  char buffer[TAMANHO_BUFFER] = {0};

  int total_linhas = 0;

  /* Lê da entrada padrão (stdin) */
  while (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    printf("Entrada:  %s", buffer);

    /* Aloca memória para a linha atual */
    lista[total_linhas] = (char *)malloc(strlen(buffer) + 1);
    if (lista[total_linhas] == NULL)
    {
      perror("Erro ao alocar memória");
      exit(EXIT_FAILURE);
    }

    /* Copia o conteúdo do buffer para a linha alocada */
    strcpy(lista[total_linhas], buffer);
    total_linhas++;

    /* Verifica se atingiu o número máximo de linhas */
    if (total_linhas >= MAX_LINHAS)
    {
      printf("Número máximo de linhas atingido.\n");
      break;
    }
  }

  printf("\n-------\n");
  ordenar(lista, total_linhas);

  return 0;
}
