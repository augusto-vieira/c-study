# Implementar um algoritmo para calcular o fatorial de 30!
## Resultado esperado:
```bash
0! :    1
1! :    1
2! :    2
3! :    6
4! :    24
5! :    120
...
28! :   304888344611713860501504000000
29! :   8841761993739701954543616000000
30! :   265252859812191058636308480000000
```
## O Problema
O maior número inteiro sem sinal que pode ser armazenado em C, em uma arquitetura de 64 bits, utilizando o tipo `unsigned long long`, é igual a \(2^{64} - 1\), que corresponde a **18.446.744.073.709.551.615**. Esse tipo de dado permite representar apenas números inteiros de até 64 bits, o que impõe limitações em certos cálculos. Por exemplo, no caso do fatorial, só é possível calcular **até o fatorial de 20!**, pois \(20! = 2.432.902.008.176.640.000\), que ainda está dentro do limite. No entanto, \(21!\) já ultrapassa a capacidade de armazenamento do tipo `unsigned long long`.

## Solução Proposta
Para superar essa limitação, podemos utilizar o tipo `__uint128_t`, um tipo de dado inteiro de 128 bits disponível em alguns compiladores, como o GCC. No entanto, esse tipo não faz parte do padrão oficial da linguagem C, o que significa que seu uso não é portável entre diferentes compiladores ou plataformas.

Outra limitação importante é que a biblioteca padrão de C não oferece suporte nativo para manipulação de tipos de 128 bits. Por exemplo, não é possível imprimir diretamente um valor do tipo `__uint128_t` usando a função `printf`. Para contornar essa restrição, a solução foi converter o resultado das operações em um vetor de caracteres e, em seguida, exibir o valor como uma string.

```c
#include <stdio.h>
int main()
{
    __uint128_t fatorial = 1;
    char str[128];
    int contador = 0;

    for (int i = 1; i <= 30; i++) {
        fatorial *= i;

        // Convertendo o valor para um vetor de caracteres
        contador = 0;  
        if (fatorial == 0) {
            str[contador++] = '0';
        } else {
            for (__uint128_t temp = fatorial; temp > 0; temp /= 10) {
                str[contador++] = (temp % 10) + '0';
            }
        }
        str[contador] = '\0';

        // Invertendo a string
        for (int i = 0; i < contador / 2; i++) {
            char temp = str[i];
            str[i] = str[contador - 1 - i];
            str[contador - 1 - i] = temp;
        }
        printf("%d! : \t%s\n", i, str); 
    }
   return 0;
}
```
