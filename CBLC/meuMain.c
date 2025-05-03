
#include <stdio.h>
#include <stdlib.h>

/* Como criar um program sem usar o nome "main" */
// gcc -nostartfiles -e meuMain meuMain.c -Wall
int meuMain()
{
    puts("Salve, simpatia!");
    exit(EXIT_SUCCESS);
}