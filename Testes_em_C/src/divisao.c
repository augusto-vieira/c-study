#include "divisao.h"

float divisao(int a, int b) {
    return (float)a / b;
}

// Divide três números inteiros: a / b / c
// Se b ou c for zero, retorna 0.0
float divisao3(int a, int b, int c) {
    if (b == 0 || c == 0) {
        return 0.0f;
    }
    return (float)a / b / c;
}
