# Curso Básico da Linguagem C
- Exercícios da aula 1: História
- [Anotações da aula](https://bolha.dev/blau_araujo/cblc/src/commit/643c375aafc14bea7bfa829a7e42bad4dac13ad3/aulas/01-historia/README.org)
- [Vídeo](https://youtu.be/wqJQL5W9FIw)

## 1. Pesquise e explique

As classificações abaixo são utilizadas para descrever as características da
linguagem C: pesquise e explique cada uma delas.

- Linguagem de alto nível;
- Linguagem compilada;
- Linguagem procedural;
- Linguagem imperativa;
- Linguagem estruturada.

`Resposta:`

1. **Linguagem de alto nível:**
Aquela cuja sintaxe está focada na compreensão humana, com forte abstração do HW.

2. **Linguagem compilada:**
Linguagem de programação que é traduzida para código de máquina antes da execução.

3. **Linguagem procedural:** 
É um paradigma de programação baseado em procedimentos, os quais são executados em uma sequência. Os procedimentos são uma forma de organizar o código em blocos que podem ser reutilizados. Eles também são conhecidos como rotinas, sub-rotinas, métodos ou funções.

4. **Linguagem imperativa:**
É um paradigma de programação que descreve a computação como ações, enunciados ou comandos que alteram o estado (variáveis) de um programa. Semelhante ao comportamento imperativo das linguagens naturais, que expressam ordens, programas imperativos são uma sequência de comandos que o computador deve executar.

5. **Linguagem estruturada:**
Um padrão ou paradigma de programação que organiza o código em blocos e usa estruturas de controle bem definidas.

## 2. Analise o programa

Dado o programa abaixo (**salve.c)**, explique cada uma perguntas nos comentários.

```c
#include <stdio.h> // O que é isso e para que serve? 

// Por que todo o programa é escrito na função 'main()'?
int main(void) {
    
    puts("Salve, simpatia!"); // O que faz e como se usa a função 'puts()'?

    return 0; // Para que serve esta instrução? 
}
```
`Resposta:`
1. `include <stdio.h>`:
O `include` é uma diretiva de pré-processamento que instrui o compilador a incluir o conteúdo de um arquivo externo no código fonte. Isso é feito antes da compilação do código propriamente. O `<stdio.h>` é o nome do arquivo de cabeçalho que está sendo incluído. Ele faz parte da biblioteca padrão da linguagem C e é usado para operações de entrada e saída.

2. `main()`:
A razão de todo o programa ser escrito na função main( ) é por causa da especificação da linguagem C. A função main( ) serve como o ponto central que inicia e organiza a execução do código, garantindo a consistência e a portabilidade do programa.

3. `puts("Salve, simpatia!")`: 
Conforma informado no `man 3 puts`, essa função escreve uma string no stdout e adiciona uma quebra de linha.

4. `return 0`: 
Isso está sinalizando ao sistema operacional que o programa foi executado com sucesso (qualquer valor diferente de 0 é interpretado como erro).

## 3. Compile, encontre, explique e corrija os bugs

O uso de *números mágicos* (valores literais que não dão pistas de seus significados) é desaconselhado porque dificultam a leitura semântica do código. Sendo assim, nós utilizaremos a constante simbólica `EXIT_SUCCESS`,
definida na biblioteca padrão com valor `0`, em vez do inteiro literal `0` como argumento da instrução `return`:

```c
#include <stdio.h>

int main(void) {
    puts("Salve, simpatia!");
    return EXIT_SUCCESS
}
```

Observe o resultado da compilação:

```c
:~$ gcc salve.c -o salve
```
- Quantos *erros* foram encontrados e quais são eles?
- Quais são as correções sugeridas pelo **gcc**?
- Como ficou o código corrigido?

`Resposta:`
1. Quantos *erros* foram encontrados e quais são eles?
- **2 erros**, não foi declarado o cabeçalho `stdio.h` que se encontra a constante simbólica `EXIT_SUCCESS`. Na instrução ` return EXIT_SUCCESS` está faltando o `;`.

2. Quais são as correções sugeridas pelo **gcc**?
- Incluir o header `<stdlib.h>` e adicionar o `;` na instrução `return EXIT_SUCCESS`;

3. Como ficou o código corrigido?
```c 
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    puts("Salve, simpatia!");
    return EXIT_SUCCESS;
}
```
## 4. Compile, pesquise e responda

Dado o código abaixo (por exemplo, **main.c**):

```c
#define EXIT_SUCCESS 0

int puts(const char *string);

int main(void) {
    puts("Salve, simpatia!");
    return EXIT_SUCCESS;
}
```

Compilação:

```c
:~$ gcc main.c
:~$
```

- Nenhum erro foi reportado, mas por quê?
- Como você executaria o binário resultante?

`Resposta:`
1. Nenhum erro foi reportado, mas por quê?
- `EXIT_SUCCESS` está sendo declara e redefinida (já que existe por padrão).
- `puts` foi declarado seu protótipo da função, essa declaração é suficiente para o compilador saber que a função puts existe.

2. Como você executaria o binário resultante?
- ./a.out

## 5. Pesquise e responda

Quando não explicitamos a especificação utilizada para compilar o nosso programa
(opção `-std=PADRÃO` do `gcc`), qual será o padrão utilizado e como podemos
confirmar isso pela linha de comandos?

`Resposta:`
```bash
// Podemos verificar com a opção -v na compilação
gcc -v salve.c
```

