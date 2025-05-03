# Curso Básico da Linguagem C
- Exercícios da aula 6: Vetores
- [Anotações da aula](https://bolha.dev/blau_araujo/cblc/src/commit/643c375aafc14bea7bfa829a7e42bad4dac13ad3/aulas/06-vetores/README.org)
- [Vídeo](https://www.youtube.com/watch?v=W5TGNQYFs4E&ab_channel=debxp)

## Desafio: Função `print_array_shift`
Dado o programa abaixo:
```c
#include <stdio.h>

int main(void) {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int desloca = ???; // <--- inicializar com o valor do deslocamento!

    print_array_shift(/* ??? */);

    return 0;
}
```
Escreva a função print_array_shift de acordo com essa descrição:
```bash
PROTÓTIPO:
    void print_array_shift(int *arr, int size, int shift);

DESCRIÇÃO:
    Desloca para a esquerda os elementos do vetor 'arr', de tamanho 'size', em 'shift' posições e imprime os valores na sequência resultante.
```
No teste, programa deverá imprimir no terminal:
```bash
:~$ ./a.out
6 7 8 9 10 1 2 3 4 5
```
`Resposta:`
```c
void print_array_shift(int *arr, int size, int shift)
{
    int aux = 0;
    
    for(size_t i = 0; i < shift; i++)
    {
        /* guarda o conteúdo da posição atual [1] */
        aux = *arr; 
        
        /* copia o valor da posição anterior na posição atual */
        for(size_t j = 0; j < size; j++)
        {
            *(arr + j) = *(arr + j + 1);
        }
        
        /* copia o conteúdo da posição atual para o último elemento do vetor */
        *(arr + size - 1) = aux;
        
    }

    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int main(void) {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int desloca = 5;

    int size = sizeof(vetor) / sizeof(vetor[0]);
   
    print_array_shift(vetor, size, desloca);
    return 0;
}
```

## 2. Desafio: Função `array_shift`
Dado o programa abaixo:
```c
#include <stdio.h>

int main(void) {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int desloca = ???; // <--- inicializar com o valor do deslocamento!

    array_shift(/* ??? */);

    /* Rotina de impressão do resultado do deslocamento */

    return 0;
}
```
Crie a função array_shift de acordo com a descrição abaixo:
```bash
PROTÓTIPO:
    void array_shift(int *arr, int size, int shift);

DESCRIÇÃO:
    Desloca para a esquerda os elementos do vetor 'arr', de tamanho 'size', em 'shift' posições.
```
A saída do teste deve ser a mesma do desafio anterior.

`Resposta:`
```c
#include <stdio.h>

void array_shift(int *arr, int size, int shift)
{
    int aux = 0;
    
    for(size_t i = 0; i < shift; i++)
    {
        /* guarda o conteúdo da posição atual [1] */
        aux = *arr; 
        
        /* copia o valor da posição anterior na posição atual */
        for(size_t j = 0; j < size; j++)
        {
            *(arr + j) = *(arr + j + 1);
        }
        
        /* copia o conteúdo da posição atual para o último elemento do vetor */
        *(arr + size - 1) = aux;      
    }
}

int main(void) {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int desloca = 5;

    int size = sizeof(vetor) / sizeof(vetor[0]);
   
    array_shift(vetor, size, desloca);

    /* Rotina de impressão do resultado do deslocamento */
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", vetor[i]);
    }
    putchar('\n');

    return 0;
}
```

## 3. Desafio: Função array_reverse
Dado o programa abaixo:
```c
#include <stdio.h>

int main(void) {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /* Rotina da impressão do vetor original */
    
    array_reverse(/* ??? */);

    /* Rotina de impressão do vetor invertido */

    return 0;
}
```
Escreva a função array_reverse de acordo com a descrição abaixo:
```bash
PROTÓTIPO:
    void array_reverse(int *arr, int size);

DESCRIÇÃO:
    Inverte a ordem dos elementos do vetor 'arr'.
```
O teste deverá imprimir…
```bash
:~$ ./a.out
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1
```
`Resposta:`
```c
#include <stdio.h>

void array_reverse(int *arr, int size)
{    
    int aux = 0;
    
    for (size_t i = 0; i < (size / 2 ); i++)
    {
        /* guarda o conteúdo da posição atual */
        aux = *(arr + i);
        
        /* posição atual recebe o valor da ultima posição */
        *(arr + i) = *(arr + size - i - 1);

        /* ultima posição  recebe o valor da posição atual */
        *(arr + size - i - 1) = aux;
    }
}

void print_vetor(int *vetor, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", vetor[i]);
    }
    putchar('\n');
}

int main(void) {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int size = sizeof(vetor) / sizeof(vetor[0]);

   /* Rotina da impressão do vetor */
    print_vetor(vetor, size);
     
    array_reverse(vetor, size);

    print_vetor(vetor, size);

    return 0;
}
```