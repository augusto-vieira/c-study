# Curso Básico da Linguagem C
- Exercícios da aula 2: Dados e instruções
- [Anotações da aula](https://bolha.dev/blau_araujo/cblc/src/commit/643c375aafc14bea7bfa829a7e42bad4dac13ad3/aulas/02-dados-e-instrucoes/README.org)
- [Vídeo](https://www.youtube.com/watch?v=2KsvRJjshQ0&ab_channel=debxp)

## Pesquise e responda
- Quais são as finalidades da função `printf`?
- Em que cabeçalho da `glibc` ela é declarada?
- Quantos argumentos ela recebe?
- Como fazer para que a saída imprima quebras de linha?
- Para que servem os especificadores de formato `%d`, `%s`, `%c` e `%f`?

`Resposta:`
1. Quais são as finalidades da função `printf`?
- Exibir dados na saída padrão(stdout), permite formatar a saída,  controla os dados com especificador de formato, permitindo imprimir variáveis de diferentes tipos.

2. Em que cabeçalho da `glibc` ela é declarada?
- Em `man 3 printf` mostra que está em `stdio.h`.

3. Quantos argumentos ela recebe?
- Ela tem argumentos variáveis, logo, pode receber uma quantidade indeterminada.

4. Como fazer para que a saída imprima quebras de linha?
- A linguagem C possui algumas constantes predefinidas, como a sequencia de escape, neste caso, podemos usa a opção de nova linha `\n`.

5. Para que servem os especificadores de formato `%d`, `%s`, `%c` e `%f`?
- Ela indica o tipo de dado que será impresso.

## Operações aritméticas
Escreva um programa que, dado um valor inteiro associado à variável `num`, calcule e imprima os resultados das seguintes operações:

- `num` multiplicado por 15;
- `num` somado a `42`;
- `123` menos `num`;
- Divisão de `num` por `5`;
- Resto da divisão de num por `5`.

Esquema geral da saída do programa:
```bash
NUM x 15 = VALOR
NUM + 42 = VALOR
123 - NUM = VALOR
NUM / 5 = VALOR
RESTO DE NUM / 5 = VALOR
```
`Resposta:`
```c
#include <stdio.h>
int main()
{
    int num = 0;

    printf("NUM x 15 = %d\n", num *= 15);
    printf("NUM + 42 = %d\n", num += 42);
    printf("123 - NUM = %d\n", 123 - num);
    printf("NUM / 5 = %d\n", num / 5);
    printf("RESTO de NUM / 5 = %d\n", num % 5);

return 0;
}
```


## Números mágicos
O uso de valores literais sem um significado óbvio (números mágicos) é uma prática indesejável, mas pode ser evitada de várias formas. Sendo assim, analise as situações abaixo e proponha uma solução.

**Caso 1:** Propriedades de círculos
Meu programa tem funções para calcular a área e o perímetro de um círculo cujo raio (um inteiro) é recebido como argumento:
```c
#include ...

float circ_perim(int raio) {
    /* Circunferência = 2πr */
    return 2 * 3.14 * raio;
}

double circ_area(int raio) {
    /* Área = πr² */
    return 3.14 * raio * raio;
}

int main(void) { ... }
```
`Resposta:`
```c
#include ...
#define PI 3.14
float circ_perim(int raio) {
    /* Circunferência = 2πr */
    return 2 * PI * raio;
}

double circ_area(int raio) {
    /* Área = πr² */
    return PI * raio * raio;
}

int main(void) { ... }
```


**Caso 2:** Multiplicador constante

No meu programa, todas as operações aritméticas envolvem a multiplicação de um valor por `10`.
```c
#include <stdio.h>

int main(void) {
    int num1 = 13;
    int num2 = 29;

    printf("%d x %d = %d\n", num1, 10, num1 * 10);
    printf("%d x %d = %d\n", num1 + num2, 10, (num1 + num2) * 10);
    printf("%d x %d = %d\n", num2, 10, num2 * 10);
}
```
`Resposta:`
```c
#include <stdio.h>
#define CONSTANTE 10
int main(void) {
    int num1 = 13;
    int num2 = 29;

    printf("%d x %d = %d\n", num1, CONSTANTE, num1 * CONSTANTE);
    printf("%d x %d = %d\n", num1 + num2, CONSTANTE, (num1 + num2) * CONSTANTE);
    printf("%d x %d = %d\n", num2, CONSTANTE, num2 * CONSTANTE);
}
```

## 4. Compile, corrija e responda
Dado o programa abaixo (por exemplo, `main.c`)…

```c
#include <stdio.h>

int main(void) {
    char *fmt = "Circunferência de um círculo de raio %d: %.2f\n";
    printf(fmt, r, circ_perim(r));
    return 0;
}

float circ_perim(int raio) {
    /* Circunferência = 2πr */
    return 2 * 3.14 * raio;
}
```
`Resposta:`
```c
#include <stdio.h>

float circ_perim(int raio); // Declarado o protótipo de função

int main(void) {
    int r = 42; // Declarado o raio
    char *fmt = "Circunferência de um círculo de raio %d: %.2f\n";
    printf(fmt, r, circ_perim(r));
    return 0;
}

float circ_perim(int raio) {
    return 2 * 3.14 * raio;
}
```

- Qual foi o erro encontrado na compilação?
- Por que esse erro aconteceu?
- Qual foi a solução adotada?
- A sua solução é a única possível?
- Se não for, cite outras possibilidades.

`Resposta:`
1. Qual foi o erro encontrado na compilação?
- error: `'r' undeclared (first use in this function)`
- warning: `implicit declaration of function ‘circ_perim’`
- error: `conflicting types for ‘circ_perim’; have ‘float(int)`

2. Por que esse erro aconteceu?
- `r` não estava declarado na função.
- `circ_perim(r)` não estava encontrando a função a declaração da função.

3. Qual foi a solução adotada?
- Declarar uma variável `int r`
- Declarar o protótipo da função `circ_perim(r)` antes do `main`.

4. A sua solução é a única possível? Se não for, cite outras possibilidades.
- Não, poderíamos mover a função `circ_perim(r)` para antes do `main`. 


## 5. Pesquise e responda
Pesquise, entre as funções da `glibc`, aquelas que podem solucionar os problemas abaixo e demonstre como elas podem ser utilizadas.

- Pausar a execução do programa por 10 segundos.
- Apenas imprimir uma quebra de linha.
- Ler um número inteiro interativamente e atribuí-lo a uma variável.
- Imprimir um número inteiro decimal em base 8 e base 16.
- Terminar a execução do programa com um valor de estado de término.

`Resposta:`
1. Pausar a execução do programa por 10 segundos.
```c
#include <unistd.h>  // Necessário para a função sleep

int main() {
    sleep(10);  // Pausa a execução por 10 segundos
    return 0;
}
```

2. Apenas imprimir uma quebra de linha.
```c
 putchar('\n');
 puts(""); 
```
3. Ler um número inteiro interativamente e atribuí-lo a uma variável.
```c
    int numero;
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);
    printf("Você digitou: %d\n", numero);
```

4. Imprimir um número inteiro decimal em base 8 e base 16.
```c
    int numero = 255;
    printf("Decimal: %d\n", numero);
    printf("Octal: %o\n", numero);
    printf("Hexadecimal: %x\n", numero);
```

5. Terminar a execução do programa com um valor de estado de término.
```c
#include <stdlib.h>  // cabeçalho para a função exit

int main() {
    //... 
    exit(0);  // Encerra o programa com status 0 (sucesso)
}
```