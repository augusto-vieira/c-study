# •	Pilha Estática 

Uma estrutura do tipo **"Pilha"** é uma sequência de elementos do mesmo tipo, como as “Lista” e “Filas”. Seus elementos possuem estrutura interna abstraída, ou seja, complexidade é arbitraria e não afeta o seu funcionamento.
 

Uma **Pilha** é um tipo especial de **Lista**.

Inserções e exclusões de elementos ocorrem apenas no início da Pilha.

![Pilha Estatica](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/PilhaEstatica/img/gif/Push_Pop.gif)

1. **Aplicações:**
    - Análise de uma expressão matemática 
    - Avaliação de expressão pós-fixa
    - Converter uma expressão in-fixa para pós-fixa
    - Converter um número decimal para binário
    - Gerenciamento de memória
    - Problemas de Backtracking
    - etc


2. **Em uma "Pilha" podemos realizar as seguintes operações básicas::**
    - Criação da pilha
    - Inserção de um elemento no "início"
    - Exclusão de um elemento do "inicio"
    - Acesso a um elemento do "inicio"
    - Destruição da Pilha
    - etc


3. **Essas operações dependem do tipo de alocação de memória usa**
    - **Estática**
    - Dinâmica

Alocação estática:  

>- O espaço de memória é alocada no momento da compilação
>-  Existe a definição do número máximo de elementos da “Pilha”
>- Acesso sequencial: elementos consecutivos da memória 


## **Pilha Estática**
Tipo de "Pilha" onde o sucessor de um elemento ocupa a posição física seguinte do mesmo(uso de "array").

![Pilha pi](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/PilhaEstatica/img/Pilha_pi.png)


Definimos a Pilha em dois arquivos.

**"PilhaSequencial.h" :** Definir
- Os protótipos das funções
- O tipo de dado armazenado na pilha
- O ponteiro "pilha"
- Tamanho do vetor usado na pilha

**"PilhaSequencial.h" :** Definir
- O tipo de dados  "pilha"
- Implementar as suas funções. 


**Algumas informações básicas sobre a pilha:**
 - Tamanho
 - Se está cheia



>Em uma "Pilha" a inserção é sempre no início/topo. Também existe o caso em que a inserção é feita em uma “Pilha” que está vazia.
>
>**Cuidado:** não se pode inserir em uma pilha cheia.

>Em uma "Pilha" a remoção é sempre no seu início/topo.
>
>**Cuidado:** não se pode remover de uma pilha vazia.

> Em uma "Pilha" a consulta se dá apenas ao elemento que está no seu início.


``` C
/* PilhaSequencial.h */

// tamanho máximo do vetor que representa a pilha
#define MAX 100

// elemento/dado que será armazena em cada posição do vetor pilha
struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct pilha Pilha;
```

``` c
/* PilhaSequencial.c */
#include<stdio.h>
#include <stdlib.h>

#include "PilhaSequencial.h"

struct pilha
{
   int qtd;
   struct aluno dados[MAX]; 
};
``` 

``` C
/* main.c */
#include "PilhaSequencial.h"

int main(int argc, char **argv)
{
    Pilha *pi;
    pi = criar_Pilha();
    
    return 0;
}

```
# ![Criar Pilha](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/PilhaEstatica/img/criar_Pilha.png)



### Referência:
- https://programacaodescomplicada.wordpress.com/
- https://www.youtube.com/user/progdescomplicada

