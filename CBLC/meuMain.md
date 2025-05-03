**Como criar um program sem usar o nome `main`**
Conforme dito no vídeo do 'void main', é dito que a especificação tem uma forte recomendação em 'int main', mas não obrigatório.
Nesta caso, isso tem serve para o nome da função principal `main`. Para comprovar isso, vamos realizar um experimento.

# Como Criar um Programa sem Usar o Nome `main`

Conforme visto no vídeo [void main](), a especificação da linguagem C faz uma forte recomendação de usar a assinatura `int main()`, mas isso não é estritamente obrigatório.

Isso também se aplica nome da principal `main`, neste experimento, vamos explorar como podemos criar um programa em C sem usar o nome `main` para a função principal.

## Contexto

Embora seja altamente recomendado que a função principal do programa seja nomeada como `main`, a especificação da linguagem C permite outras abordagens.

## O Experimento `meuMain`

Para comprovar que podemos criar um programa sem usar o nome `main`, vamos realizar o seguinte:

1. Escrever um programa em C utilizando um nome alternativo para a função principal.
2. Compilar o código e observar o comportamento do compilador e do sistema operacional.
3. Verificar se o código é executado corretamente sem a função `main` convencional.

### Exemplo de Código

```c
#include <stdio.h>
#include <stdlib.h>

/*  Definindo a função principal com um nome alternativo */
int meuMain()
{
    puts("Salve, simpatia!");
    exit(EXIT_SUCCESS);
}
```

Nesta caso, como não estamos usando `main`, precisamos informar o ponto de entrada da função principal para o gcc.

`-nostartfiles`: Esse parâmetro instrui o compilador gcc a não incluir os arquivos de inicialização padrão.

`-e`: Esse parâmetro define o ponto de entrada do programa, ou seja, a função que será chamada primeiro quando o programa for executado.

**Compilando o programa**

```bash
gcc -nostartfiles -e meuMain meuMain.c -Wall
```
`saída:`
```bash
$ ./a.out
Salve, simpatia!
$  echo $?
0
```
