#include <stdio.h>
int main (){

int i = 0;
int j = 0;

int a = i++; // a = 0, i = 1
int b = ++j; // b = 1, j = 1

printf("*************************************************\n");
printf("i++ (pos incremento)  ++i (pre incremento)\n");
printf("*************************************************\n");

printf("int a,i = 0\n");
printf("int b,j =0 \n\n");
printf("int a = i++ \n");
printf("int b = ++j \n\n");
printf("Resultado : a = %d  e  b = %d\n",a,b);
}