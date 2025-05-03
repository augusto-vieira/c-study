
# Desafio Final de Conclusão do CBLC

## Descrição

O teste final consiste em criar um **clone do `wc`** (word count), seguindo os mesmos métodos de leitura: argumentos, pipe e redirecionamento.  
O objetivo é reproduzir as mesmas saídas do comando original. A implementação de opções (`-l`, `-w`, etc.) **não é obrigatória**.

## Aprendizados Esperados

- Exploração de funções da `libc`.
- Melhorias de performance no código.

## Restrições

- **Não utilizar alocação dinâmica de memória** (`malloc`, `realloc`, `free`).
- Utilizar apenas **buffers na pilha** (vetores estáticos).

## Dicas

- Use `man isatty`: essa função permite verificar se o descritor de arquivo está associado a um terminal.  
  Ela será útil para identificar se a entrada está vindo do teclado ou de um redirecionamento/pipe.
  
  Observação: Quando há **argumentos**, o redirecionamento é **ignorado**.
    ```bash
    $ echo banana | wc /etc/shells /etc/passwd
    11   15   154 /etc/shells
    41   68  2318 /etc/passwd
    52   83  2472 total
    ```
## Resultado Esperado

**Sem argumentos:**

```bash
$ wc
banana
laranja
    2   2   15
```

**Com arquivos passados como argumento:**

```bash
$ wc /etc/shells
  11   15   154 /etc/shells
```

```bash
$ wc /etc/shells /etc/passwd
  11   15   154 /etc/shells
  41   68  2318 /etc/passwd
  52   83  2472 total
```

**Com redirecionamento ou pipe (sem nomes de arquivo):**

```bash
$ wc < /etc/shells
  11   15   154
```

```bash
$ cat /etc/shells | wc
  11   15   154
```

```bash
$ echo maçã | wc
      1       1       7
```
## Como Compartilhar Seu Código

- **GitHub Gist**: Ideal para quem já usa GitHub e quer algo simples e integrado.
- **GitLab Snippets**: Ótimo para usuários do GitLab, sem necessidade de criar um repositório.
- **Pastebin**: Solução rápida para compartilhar sem preocupações com organização.
- **GistBox**: Ferramenta para gerenciar e organizar seus GitHub Gists de maneira amigável.
--- 

### 🚀 Meus passos para chegar na resolução do problema

#### 🛠️ Etapa 1: Configurar a Leitura de Entrada
- **📥 Passo 1.1**: Detectar se a entrada está vindo do terminal, de um arquivo ou de um pipe/redirecionamento(estudei isatty.) 
- **📄 Passo 1.2**: Ler os dados da entrada correta usando um buffer estático.

#### 🔢 Etapa 2: Contar Linhas, Palavras e Bytes
- **📏 Passo 2.1**: Percorrer o buffer contando o número de quebras de linha (estudei strtok).
- **📝 Passo 2.2**: Contar as palavras separadas por espaços e quebras de linha.
- **📦 Passo 2.3**: Contar a quantidade total de bytes lidos.

#### 📂 Etapa 3: Gerenciar Argumentos de Arquivos
- **🗂️ Passo 3.1**: Verificar se foram passados nomes de arquivos como argumentos.
- **📚 Passo 3.2**: Abrir e processar cada arquivo separadamente, somando os totais.

#### 🖥️ Etapa 4: Exibir o Resultado
- **👀 Passo 4.1**: Mostrar a contagem de linhas, palavras e bytes para cada entrada lida.
- **➕ Passo 4.2**: Se múltiplos arquivos forem processados, imprimir também o total geral.

#### ✅ Etapa 5: Validar todos os tipos de entradas
- **🎯 Passo 5.1**: Criei um Makefile de teste com as entradas.

#### 🏆 FIM:
- O código abaixo teve três versões:
  - A primeira foi funcional (feio mas funciona 😅)
  - A segunda versão foi uma melhoria de estrutura e sintaxe.
  - A última(abaixo), melhoria na lógica do código.
---
### Implementação do código
```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* Tamanho do buffer estático */ 
#define BUFFER_SIZE 1024 

#define LINHAS    0
#define PALAVRAS  1
#define BYTES     2
#define VARIAVEIS 3

void contar_palavras_na_linha(char *linha, size_t *total){
  char *token = strtok(linha, " \t\n");
  while (token != NULL)
    {
      total[PALAVRAS]++;
      token = strtok(NULL, " \t\n");
    }
}

void processar_entrada(char *buffer,size_t *total, FILE *entrada){
    
    /* Realiza a leitura, linha por linha */
    while (fgets(buffer, BUFFER_SIZE, entrada) != NULL)
    {
      total[BYTES] += strlen(buffer);
      contar_palavras_na_linha(buffer, total);
      total[LINHAS]++;
    }
}

int main(int argc, char *argv[]){
  
  char buffer[BUFFER_SIZE];         
  size_t total[VARIAVEIS] = {0};
  FILE *entrada = stdin;

  size_t redirecionamento = isatty(STDIN_FILENO);
 
  /* Verifica se a entrada é um Redirecionamento ou Pipe */
  if( (redirecionamento && argc == 1) || argc == 1)
  {  
    processar_entrada(buffer, total, entrada);
    printf("%4zu %5zu %5zu\n", total[LINHAS], total[PALAVRAS], total[BYTES]); 
  }
  
  else{
      for(int i = 1; i < argc; i++)
      {
        size_t total_tmp[VARIAVEIS] = {0};
        entrada = fopen(argv[i], "r");
        
        if(entrada == NULL)
        {
          perror("Erro ao abrir o arquivo");
          return EXIT_FAILURE;
        }
       
        processar_entrada(buffer, total_tmp, entrada);
        total[LINHAS]   += total_tmp[LINHAS];
        total[PALAVRAS] += total_tmp[PALAVRAS];
        total[BYTES]    += total_tmp[BYTES];
    
        printf("%4zu %5zu %5zu %s\n", total_tmp[LINHAS], total_tmp[PALAVRAS], total_tmp[BYTES], argv[i]);
      }
      
      if(argc > 2)
        printf("%4zu %5zu %5zu total\n", total[LINHAS], total[PALAVRAS], total[BYTES]);   
  }   

  return EXIT_SUCCESS;
}
```