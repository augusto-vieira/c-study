#include<stdio.h>
#include<stdlib.h>
int main()
{
   char str[100];
   printf("Enter a string in lower case: ");
   scanf("%[a-z]",str);
   printf("String = %s\n",str);
   return 0;
}