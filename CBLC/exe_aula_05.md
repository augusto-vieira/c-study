# Curso Básico da Linguagem C
- Exercícios da aula 5: Variáveis e ponteiros
- [Anotações da aula](https://bolha.dev/blau_araujo/cblc/src/commit/643c375aafc14bea7bfa829a7e42bad4dac13ad3/aulas/05-controle/README.org)
- [Vídeo](https://www.youtube.com/watch?v=9dvDL7FbYKY&ab_channel=debxp)

## 1. Desafio: caracteres alfanuméricos ASCII
Crie um programa que produza a seguinte saída:
```bash
======================================================
DEC OCT HEXA CHR | DEC OCT HEXA CHR | DEC OCT HEXA CHR
-----------------+------------------+-----------------
 48  60 0x30  0  |  65 101 0x41  A  |  97 141 0x61  a
 49  61 0x31  1  |  66 102 0x42  B  |  98 142 0x62  b
 50  62 0x32  2  |  67 103 0x43  C  |  99 143 0x63  c
 51  63 0x33  3  |  68 104 0x44  D  | 100 144 0x64  d
 52  64 0x34  4  |  69 105 0x45  E  | 101 145 0x65  e
 53  65 0x35  5  |  70 106 0x46  F  | 102 146 0x66  f
 54  66 0x36  6  |  71 107 0x47  G  | 103 147 0x67  g
 55  67 0x37  7  |  72 110 0x48  H  | 104 150 0x68  h
 56  70 0x38  8  |  73 111 0x49  I  | 105 151 0x69  i
 57  71 0x39  9  |  74 112 0x4a  J  | 106 152 0x6a  j
                 |  75 113 0x4b  K  | 107 153 0x6b  k
                 |  76 114 0x4c  L  | 108 154 0x6c  l
                 |  77 115 0x4d  M  | 109 155 0x6d  m
                 |  78 116 0x4e  N  | 110 156 0x6e  n
                 |  79 117 0x4f  O  | 111 157 0x6f  o
                 |  80 120 0x50  P  | 112 160 0x70  p
                 |  81 121 0x51  Q  | 113 161 0x71  q
                 |  82 122 0x52  R  | 114 162 0x72  r
                 |  83 123 0x53  S  | 115 163 0x73  s
                 |  84 124 0x54  T  | 116 164 0x74  t
                 |  85 125 0x55  U  | 117 165 0x75  u
                 |  86 126 0x56  V  | 118 166 0x76  v
                 |  87 127 0x57  W  | 119 167 0x77  w
                 |  88 130 0x58  X  | 120 170 0x78  x
                 |  89 131 0x59  Y  | 121 171 0x79  y
                 |  90 132 0x5a  Z  | 122 172 0x7a  z
======================================================
```
`Resposta:`
```c
#include <stdio.h>

int main(void) {
 char *linha_externa = "======================================================";
 char *linha_interna = "-----------------+------------------+-----------------";
 
 char *colunas = "DEC OCT HEXA CHR | DEC OCT HEXA CHR | DEC OCT HEXA CHR";
 
 int num = '0';
 int maiuscula = 'A';
 int minuscula = 'a';

 puts(linha_externa);
 puts(colunas);
 puts(linha_interna);

 for (size_t i = 0; i < 26; i++)
 {
    for (size_t i = 0; i < 1; i++)
    {
       for (size_t i = 0; i < 1; i++)
       {
        if (num <= '9')
        {
            printf(" %d  %o 0x%x  %c  |  %d %o 0x%x  %c  | %3d  %o 0x%x  %c", 
                                num, num, num, num, 
                                maiuscula, maiuscula, maiuscula, maiuscula, 
                                minuscula, minuscula, minuscula, minuscula);
        }else{
            printf("                 |  %d %o 0x%x  %c  | %3d  %o 0x%x  %c", 
                                maiuscula, maiuscula, maiuscula, maiuscula, 
                                minuscula, minuscula, minuscula, minuscula);
        }

        minuscula++;
       }
       maiuscula++;
    }
    num++;
    putchar('\n');
 }

puts(linha_externa);
    return 0;
}
```

## Desafio: dias da semana
Pesquise e crie um programa que receba um número inteiro entre 1 e 7 como argumento e imprima o nome do dia correspondente da semana.

**Requisitos:**
- Utilize uma estrutura switch para resolver o problema.
- Se o número não estiver no intervalo de 1 a 7, o programa deve imprimir Número inválido.
- Se não houver argumentos, a mensagem deve ser `Número incorreto de argumentos`.
- Em ambos os casos anteriores, o programa deve terminar com erro.
- Se o argumento recebido for -h, o programa deve exibir uma mensagem de uso e terminar com sucesso.

**Dicas:**
Para receber argumentos, os parâmetros da função `main` devem ser (nesta ordem):

- `int argc` - Número de argumentos recebidos.
- `char **argv` - Vetor de palavras (strings) recebidas como argumentos.

Cada palavra no vetor `argv` pode ser acessada com `argv[N]`, onde `N` é o índice do argumento acessado.

O primeiro argumento (`argv[0]`) sempre será a invocação do programa.

Todo argumento é recebido como uma string, inclusive os numéricos.

`Resposta:`
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum 
{
    SEGUNDA = 1,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO,
    DOMINGO
}semana;


int main(int argc, char **argv) {

    if(argc == 1)
    {
        puts("Numero incorreto de argumentos!");
        return 0;
    }
    if (!strcmp(argv[1], "-h"))
    {
        puts("Informe um numero entre 1 e 7.");
        return 0;
    }
    
    /* converte a string para inteiro */
    int op = atoi(argv[1]);
    
    switch (op)
    {
    case SEGUNDA:
        puts("Segunda!");
        break;

    case TERCA:
        puts("Terca!");
        break; 

    case QUARTA:
        puts("Quarta!");
        break;    
        
    case QUINTA:
        puts("Quinta!");
        break;    

    case SEXTA:
        puts("Sexta!");
        break;       

    case SABADO:
        puts("Sabado!");
        break;

    case DOMINGO:
        puts("Domingo!");
        break;               
    default:
        puts("Numero invalido!");
        break;
    }

    return 0;
}
```

## 3. Desafio: conversão de base 10 para 16 e vice-versa
Crie um programa que receba um inteiro como argumento e imprima…

- Se o número começar com `0x`, o número convertido da base `16` para a base `10`.
- Se começar com um inteiro diferente de 0, o número convertido da base `10` para `16`.
- Se começar com `0` ou tiver letras inválidas para um número em hexa, uma mensagem de erro.

`Resposta:`
```c
#include <stdio.h>
#include <stdlib.h> // atoi e strtol
#include <ctype.h>  // toupper 

int main(int argc, char **argv) {

    char *validador = argv[1];

    if(*(validador) == '0' && toupper(*(validador + 1)) == 'X')
    {
        int count = 2;
        char c;

        while (*(validador + count) != '\0')
        {
            c = *(validador + count);
            
           /* Verifico cada caractere da string se é valido (A - F) */
           if( toupper(c) > 'F')
            {
                puts("Valor invalido...");
                return 0;
            }
            count++;
        }   
        
        /* Converto string (hex) para inteiro */
        printf("dec: %ld\n", strtol(validador, 0, 16));
    }
    else if(*(validador) >= '1' &&  *(validador) <= '9')
    {
        int count = 1;
    
       
        while (*(validador + count) != '\0')
        {
            /* Verifico cada caractere da string se é valido (1 - 9) */
            if(*(validador + count) >= '9')
            {
                puts("Valor invalido!!!");
                return 0;
            }
            count++;
        } 
        
        /* Converto string (decimal) para inteiro */
        printf("hex: %x\n", atoi((validador)));
    }else{
        puts("Valor invalido.");
    }
}
```