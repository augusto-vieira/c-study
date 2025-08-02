#include<stdio.h>
#include<stdarg.h>



/*
  Macros:
         va_start
         va_arg
         va_end
    
*/


void print_ints(int num, ...){
	va_list args;
	
	va_start(args, num);
	
	for(int i = 0; i < num; i++){
		int value = va_arg(args,int);
		printf("%d:  %d\n",i,value);
	}
	
	va_end(args);
}

int main()
{
   print_ints(3,24,26,312);
   print_ints(2,256,512);
   
   return 0;
}


