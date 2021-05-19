#include <stdio.h>

void funcao_maliciosa(){
    char c;
    char *d;

    for(int i = 0; i < 100; i++){
        printf("%c",d[i]);
    }
}

int main(int argc, char const *argv[])
{
    char  senha[] = "SENHA";

    funcao_maliciosa();

    return 0;
}