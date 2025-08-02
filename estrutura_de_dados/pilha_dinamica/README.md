# •	Pilha Dinâmica 

Uma estrutura do tipo **"Pilha"** é uma sequência de elementos do mesmo tipo, como as “Lista” e “Filas”. Seus elementos possuem estrutura interna abstraída, ou seja, complexidade é arbitraria e não afeta o seu funcionamento.
 

Uma **Pilha** é um tipo especial de **Lista**.

Inserções e exclusões de elementos ocorrem apenas no início da Pilha.

![Pilha Din](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/PilhaEstatica/img/gif/Push_Pop.gif)

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
    - Estática
    - **Dinâmica**

Alocação Dinâmica:  

>- O espaço de memória é alocada em tempo de execução
>- A "Pilha" cresce à medida que novos elementos são armazenados, e diminui à medida que elementos são removidos
>- Acesso encadeado: cada elemento pode estar em uma área distinta da memória. Para acessar um elemento, é preciso percorrer todos os seu antecessores na "Pilha".


## **Pilha Dinâmica**
Tipo de "Pilha" onde o sucessor de um elemento aponta para o seu sucessor na "Pilha". Usa um ponteiro especia(Ponteiro para Ponteiro) para o primeiro elemento da "Pilha" e uma indicaçao de final de pilha

![Pilha pi](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/Pilha%20Dinamica/img/Pilha_pi.png)


Definimos a Pilha em dois arquivos.

**"PilhaSequencial.h" :** Definir
- Os protótipos das funções
- O tipo de dado armazenado na pilha
- O ponteiro "pilha"

**"PilhaSequencial.h" :** Definir
- O tipo de dados  "pilha"
- Implementar as suas funções. 


**Algumas informações básicas sobre a pilha:**
 - Tamanho
 - Se está cheia
 - Se está vazia



>Em uma "Pilha" a inserção é sempre no início/topo. Também existe o caso em que a inserção é feita em uma “Pilha” que está vazia.
>
>**Cuidado:** não se pode inserir em uma pilha cheia.

>Em uma "Pilha" a remoção é sempre no seu início/topo.
>
>**Cuidado:** não se pode remover de uma pilha vazia.

> Em uma "Pilha" a consulta se dá apenas ao elemento que está no seu início.


``` C
/* PilhaDin.h */


// elemento/dado que será armazena em cada posição da pilha
struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Pilha;
```

``` c
/* PilhaSequencial.c */
#include<stdio.h>
#include <stdlib.h>

#include "PilhaDin.h"

struct elemento
{
   struct aluno dados; 
   struct elemento *prox;
};

typedef struct elemento Elem;
``` 

``` C
/* PilhaDin.h */

Pilha* criar_Pilha();
```
``` C
/* PilhaDin.c */

Pilha* criar_Pilha()
{
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    
    if(pi != NULL)
        *pi = NULL;

    return pi;    
}
```
``` C
/* main.c */
#include "PilhaDin.h"

int main(int argc, char **argv)
{
    Pilha *pi;
    pi = criar_Pilha();
    
    return 0;
}
```
# ![Criar_Pilha](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/Pilha%20Dinamica/img/criar_Pilha.png)

``` C
/* PilhaDin.h */

void libera_Pilha(Pilha* pi);
```
``` C
/* PilhaDin.c */

void libera_Pilha(Pilha* pi)
{
    if(pi != NULL)
    {
        Elem* no;
        while ((*pi) != NULL ))
        {
            no = *pi;
            pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    } 
}
```
``` C
/* main.c */
#include "PilhaDin.h"

int main(int argc, char **argv)
{
    ...

    libera_Pilha(pi);
    
    return 0;
}
```
# ![Libera_Pilha](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/Pilha%20Dinamica/img/gif/Libera_Pilha.gif)

``` C
/* PilhaDin.h */

int tamanho_Pilha(Pilha* pi);
```
``` C
/* PilhaDin.c */

int tamanho_Pilha(Pilha* pi)
{
    if(pi == NULL)
        return 0;
    
    int cont = 0;
    Elem* no = *pi;

    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }

    return cont;
}
```
``` C
/* main.c */
#include "PilhaDin.h"

int main(int argc, char **argv)
{
    ...

    tamanho_Pilha(pi)
    
    return 0;
}
```
# ![Tamanho_Pilha](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/Pilha%20Dinamica/img/gif/Tamanho_Pilha.gif)

``` C
/* PilhaDin.h */

int Pilha_vazia(Pilha* pi);
```
``` C
/* PilhaDin.c */

int Pilha_vazia(Pilha* pi)
{
    // vazia == 1, != 0
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;

    return 0;
}
```
``` C
/* main.c */
#include "PilhaDin.h"

int main(int argc, char **argv)
{
    ...

    Pilha_vazia(pi)
    
    return 0;
}
```
# ![Pilha_Vazia](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/Pilha%20Dinamica/img/Pilha_vazia.png)

``` C
/* PilhaDin.h */

int insere_Pilha(Pilha* pi, struct aluno al);
```
``` C
/* PilhaDin.c */

int insere_Pilha(Pilha* pi, struct aluno al)
{
    if(pi == NULL)
        return 0;

    Elem* no = (Elem*)malloc(sizeof(Elem));

    if(no == NULL)
        return 0;

    no->dados = al;    
    no->prox  = (*pi);  
    *pi = no;           

    return 1;
}
```
``` C
/* main.c */
#include "PilhaDin.h"

int main(int argc, char **argv)
{
    struct aluno Joao;
   
    insere_Pilha(pi, Joao);
    
    return 0;
}
```
# ![Insere_Pilha](https://github.com/augusto-vieira/LinguagemC_Pilha/blob/master/Pilha%20Dinamica/img/gif/Insere_Pilha.gif)


### Referência:
- https://programacaodescomplicada.wordpress.com/
- https://www.youtube.com/user/progdescomplicada

