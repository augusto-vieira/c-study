#include<stdio.h>
#include<stdarg.h>
#include<string.h>

int printf_(const char *format, ...){

	va_list args;
	int done;
	
	// Inútil, mas legal
	char *substring = strstr(format, "chave");
	if(substring != format) return 0;  
	
	va_start(args, format);
	done = vfprintf(stdout, format, args);
	va_end(args);
	
	return done;
}

int main()
{
   int x =10;
   char a = 'b';
   char strName[] = "string";
  
   printf_("Esta frase nao vai aparecer.\n");
   printf_("chave, %d - %c - %s - \"Hello world\"\n", x,a,strName);
   
   return 0;
}