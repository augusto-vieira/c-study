/*
.
two-fer
Crie um programa que receba nomes (João, Maria, José, etc...) como argumentos e, para cada nome, 
imprima: Um para NOME, um para mim.. Se nenhum argumento for fornecido, a saída impressa deverá ser: Um para você, um para mim..

1-Exemplo: teste.c joão
saída    : Um para João, um para mim.

2-Exemplo: teste.c Maria José
saída    : Um para Maria, um para mim.
           Um para José, um para mim.

3-Exemplo: teste.c
saída    : Um para você, um para mim.
.
*/

int main(int argc, char *argv[])
{
   printf("Um para %s, um para mim.\n", argc > 1 ? argv[1] : "você");
   for (int i = 2; i < argc; i++)
   {
      printf("Um para %s, um para mim.\n", argv[i]);
   }
   return 0;
}
