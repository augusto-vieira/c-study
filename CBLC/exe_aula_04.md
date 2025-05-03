# Curso Básico da Linguagem C
- Exercícios da aula 4: Variáveis e ponteiros
- [Anotações da aula](https://bolha.dev/blau_araujo/cblc/src/branch/main/aulas/04-variaveis/README.org)
- [Vídeo](https://www.youtube.com/watch?v=i7RKtMgSSrM&ab_channel=debxp)

## 1. Pesquise e responda
- Existe uma forma para alterar uma variável em uma função a partir de
  outra função: como fazer isso?
- Por que as variáveis de uma função, em princípio, são locais à própria função?
- Se o valor associado a um ponteiro é um endereço, o que termos com a
  avaliação de `NOME_DO_PONTEIRO`?

`Resposta:`
1. Existe uma forma para alterar uma variável em uma função a partir de
  outra função: como fazer isso?
- Sim, podemos modificar essa variável passando ela por `referência` para outra função.
- Em C, temos dois tipos de passagem de parâmetros para uma função:
    - Passagem por valor: Passa uma cópia do valor.
    - Passagem por referência: Simulada com ponteiros, permitindo que a função modifique diretamente a variável original.

2. Por que as variáveis de uma função, em princípio, são locais à própria função?
- A variáveis locais são locais porque só podem ser acessadas dentro do escopo da função em que são declaradas, elas só existem enquanto a função está sendo executada.

3. Se o valor associado a um ponteiro é um endereço, o que termos com a avaliação de `&NOME_DO_PONTEIRO`?
- Temos o endereço da variável do tipo ponteiro.
    - variável = dado na memória.
    - ponteiro = endereço de um dado.
    - **Ambos são variáveis, o que muda é o referencial.**

## 2. Analise o código, pesquise e responda

Este é mais um "Olá, mundo":

```c
#include <stdio.h>

char *msg = "Salve, simpatia!";

int main(void) {
    puts(msg);
    return 0;
}
```

Se ponteiros recebem endereços como valores, por que eu fiz a atribuição de uma string e o meu programa funcionou?

`Resposta:`
- Expressões constantes de strings são avaliadas para um endereço de memória no tempo de compilação (assim como arrays), neste caso, a string e armazenadas na seção `.rodata` e retornando para o ponteiro o endereço do primeiro carácter da String.
- Em `char msg[] = "Salve"`, a string `"Salve;"` é usada para inicializar o `vetor msg[]`. Em vez de armazenar a string na seção `.rodata` (onde são armazenados dados constantes), os caracteres são copiados diretamente para a memória alocada para o array na pilha, dentro dos dados locais da função.


## 3. Compile, analise e demonstre

```c
#include <stdio.h>

int main(void) {

    int a = 0;
    int b = 875569217;
    int c = 1280655661;
    int d = 1129071171;

    char *p = (char *)&d;
    
    int i = 0;
    while (*(p + i) != '\0') {
        putchar(*(p + i));
        i++;
    }
    putchar('\n');

    // printf("%p\n%p\n%p\n%p\n", &d, &c, &b, &a);
    
    return 0;
}
```

- Como o código funciona?
- O que estou tentando imprimir?
- Com o `printf` comentado, eu consigo imprimir o que eu quero?
- Se eu tirar o comentário, eu tenho a impressão que eu quero?
- Por que acontece essa diferença de comportamento?
- Como imprimir corretamente apenas o que eu quero?

`Resposta:`
1. Como o código funciona?
- Ele faz um casting do tipo `int` para o `char`, posteriormente faz print de cada byte da variável **d** até **a**. 

2. O que estou tentando imprimir?
- A frase "CBLC-AULA 04"

3. Com o `printf` comentado, eu consigo imprimir o que eu quero?
- Não, o print mostrado são os bytes da variável d ('CBLC').
```bash
# Sem printf
$ CBLC
```

4. Se eu tirar o comentário, eu tenho a impressão que eu quero?
- Sim, toda frase é mostrada.
```bash
# Com printf
$ CBLC-AULA 04
$ 0x7ffdd5f1deac
$ 0x7ffdd5f1deb0
$ 0x7ffdd5f1deb4
$ 0x7ffdd5f1deb8
```

5. Por que acontece essa diferença de comportamento?
- O problema é com as variáveis não utilizadas. O compilador otimiza e não escreve esses dados na pilha da função main, então só tem lixo. Ao utilizar elas para alguma coisa (um printf, por exemplo) ou declarar como volatile (isso avisa ao gcc que a variável pode  ser usada por algo externo), elas estarão disponíveis para serem lidas.
  
6. Como imprimir corretamente apenas o que eu quero?
- Mudar a variável para o tipo 'volatile int'.
```bash
# Com volatile
$ CBLC-AULA 04
```

```c
#include <stdio.h>

int main(void) {

  /* No Windows, os bytes estão invertidos */
  /* No MAC, os bytes estão corretos, mas sempre mostra a frase e qualquer cenário */

  /* Mudei a ordem do exercício, no Windows, os bytes estão */
  volatile int d = 1129071171; 
  volatile int c = 1280655661; 
  volatile int b = 875569217;  
  volatile int a = 0;
  
  char *p = (char *)&d;
   int i = 0;
   while (*(p + i) != '\0') {
       putchar(*(p + i));
       i++;
  }

  putchar('\n');

  //printf("%p\n%p\n%p\n%p\n", &d, &c, &b, &a);

  return 0;
}
```

## 4. Pesquise e responda

- Para que serve e como usar a função `putchar`?
- Quando e por que utilizar `putchar('\n')` em vez de `puts("")`?
- Como funciona a estrutura de repetição `while`?
- Para que servem os especificadores de formato `%zu` e `%p`?

1. Para que serve e como usar a função `putchar`?
- É utilizada para imprimir um único caractere no console. Ela pertence à biblioteca `<stdio.h>`.

2. Quando e por que utilizar `putchar('\n')` em vez de `puts("")`?
- `putchar('\n')` é deal para quando você deseja imprimir exatamente um único caractere, neste caso,imprime apenas o caractere de nova linha `('\n')`.
- `puts("")` imprime uma `string` seguida de uma nova linha automática `(\n)` ela é ideal para quando você quer imprimir uma string e, automaticamente, adicionar uma nova linha no final.

3. Como funciona a estrutura de repetição `while`?
- O while é uma estrutura de repetição que executa um bloco de código enquanto uma condição for verdadeira. A condição é avaliada antes de cada iteração.
```c
while (condição) {
    // bloco de código a ser executado enquanto a condição for verdadeira
}
```

4. Para que servem os especificadores de formato `%zu` e `%p`?
-  `%zu`: é utilizado para imprimir valores do tipo `size_t`, que é um tipo de dado que representa o tamanho de objetos em bytes.
- `%p`: é utilizado para imprimir o endereço de memória de uma variável.

## 5. Desafio: quadrado de um número

Crie um programa que peça a digitação de um número inteiro ao usuário
e imprima o quadrado desse número.

*Requisitos:*

- O programa deve testar se o número digitado é um inteiro válido.
- Se não for, o programa deve terminar com uma mensagem enviada para
  a saída padrão de erros (`stderr`) e estado de término `1`.

*Dicas:*

- Utilize a função `scanf` para ler o número digitado.
- Existe uma variante do `printf` que possibilita imprimir na saída de erros em vez da saída padrão.
- Existe um cabeçalho que define constante com os limites dos tipos inteiros.

`Resposta:`
```c
#include <stdio.h>
#include <limits.h>

#define SUCESSO 0
#define ERRO 1

int fmt_input(long long *entrada, int status)
{
    char verificador;
    status = ERRO;
 
    /*   Verificar se o scanf leu uma ocorrência com sucesso.       */
    /*   %d -> input(1) | input(1.1) | input (1.A) | return (1)     */
    
    /*   Se começar com qualquer coisa diferente de um número, é 0. */
    /*   %d -> input(A) | input(A.1) | input(.)    |  return (0)    */
    
    if(scanf("%lld", entrada) == 1)
    {
        /* Verifica se a sequência não contém (1.)(1.1)(1.A) */
        verificador = getchar();

        if(verificador == '\n' || verificador == ' ')
            status = SUCESSO;                
    }

    return status;
}
int main(){
    
    /* O 'int' está implícito */
    long long entrada = 0;

    int status = 0;

    puts("informe um numero inteiro valido.");
    
    status = fmt_input(&entrada, status);

    if(status)
    {
        /* Achei em 'man 3 printf' */
        fprintf(stderr, "Entrada invalida.\n");
    }
    
    else if(!(entrada >= INT_MIN && entrada <= INT_MAX))
    {
        /* Outra forma de escrever no stderr*/
        dprintf(2,"Valor fora do intervalo de um int '2147483647' a '-2147483648'\n");
        status = ERRO;
    }

    else
    {
        printf("%lld\n", entrada * entrada);
    }

    return status;
}
```