# Descrição do Problema

Criar um programa que receba uma lista de linhas de texto pela entrada padrão e organize-as em ordem alfanumérica crescente. As linhas podem ser fornecidas através de um pipe ou lidas a partir de um arquivo por meio de redirecionamento de leitura. A solução deve ser da forma mais eficiente que conseguir.

Tipos de entrada:
```bash
 ./a.out < ordenar.txt
 cat ordenar.txt | ./a.out
```

Exemplo de uma lista:
```bash
banana
Maçã
abacaxi
laranja
Uva
manga
````
Saída esperada:
```bash
abacaxi
banana
laranja
Maçã
Uva
manga
```
---
### Meus passos para chegar na resolução do problema:
#### Etapa 1: Leitura da Entrada e Impressão (sem ordenação)
   - **Passo 1.1**: Ler a entrada do usuário.
   - **Passo 1.2**: Imprimir o que foi lido.
   - **Passo 1.3**: Guardar as linhas em uma lista.

#### Etapa 2: Processamento e Compreensão da Ordenação
   - **Passo 2.1**: Implementar um algoritmo simples de ordenação.
   - **Passo 2.2**: Entender o método de ordenação utilizado.

#### Etapa 3: Ordenação da Lista
   - **Passo 3.1**: Testar diferentes formas de comparação das linhas.
   - **Passo 3.2**: Após ordenar, imprimir a lista ordenada.
---
### Implementação do código
```c
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

        /* Comparação entre o caractere da lista[i] e lista[j] */
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
```

