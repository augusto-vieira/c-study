A função `isatty()` é uma função da biblioteca padrão C, definida no cabeçalho `<unistd.h>`, que verifica se o descritor de arquivo fornecido se refere a um terminal (também conhecido como tty) interativo.

Propósito:
Ela retorna verdadeiro (1) se o descritor de arquivo especificado estiver associado a um terminal, e falso (0) caso contrário.

Em resumo, `isatty()` é uma ferramenta útil para verificar se a interação do usuário com o programa está ocorrendo em um ambiente de terminal ou se o fluxo está sendo redirecionado, ajudando no controle de saída ou comportamentos interativos.

Este é um pequeno programa que informa se a entrada padrão e a saída padrão estão associadas a um terminal.

```c
#include <stdio.h>
#include <unistd.h>

int main(void){

  if(isatty(STDIN_FILENO))
    printf("[Entrada padrao] do terminal\n");
  else
    printf("Nao eh a Entrada padrao\n");
  
  if(isatty(STDOUT_FILENO))
    printf("[Saida padrao] do terminal\n");
  else
    printf("Nao eh a Saida padrao\n");
  
  return 0;
}
```
Saída:
```bash
$ ./isatty
"Entrada padrao do terminal"
"Saida padrao do terminal"

$ ./isatty < /dev/null
"Nao eh a [Entrada] padrao"
"Saida padrao do terminal"

$ ./isatty | cat
"Entrada padrao do terminal"
"Nao eh a [Saida] padrao"
```