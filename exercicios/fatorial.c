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
