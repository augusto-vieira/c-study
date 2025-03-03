#include <stdio.h>
#include <string.h>

#define LINHAS 1024
#define COLUNAS 1024

int ordenar(char str[][LINHAS], int n_linhas)
{
   for (int i = 0; i < n_linhas; i++)
   {
      printf("%s", str[i]);
   }
   return 0;
}
int main(int argc, char *argv[])
{
   char str[LINHAS][COLUNAS] = {0};
   char buffer[LINHAS] = {0};

   int qnt_linhas = 0;

   // Lê da entrada padrão (stdin) e imprime na tela
   while (fgets(buffer, sizeof(buffer), stdin) != NULL)
   {
      printf("%s", buffer);
      strncpy(str[qnt_linhas], buffer, LINHAS);
      qnt_linhas++;
   }
   printf("total %d\n", qnt_linhas);

   ordenar(str, qnt_linhas);

   return 0;
}
