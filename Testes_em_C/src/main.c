#include <stdio.h>
#include "soma.h"
#include "subtracao.h"
#include "divisao.h"

int main() {
    printf("Soma: %d\n", soma(5, 3));
    printf("Subtração: %d\n", subtracao(5, 3));
    printf("Divisão: %f\n", divisao(5, 2));
    return 0;
}

