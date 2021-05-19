#include <stdio.h>
#include <uchar.h>

int main(void){
	char16_t c16 = 219; 
	char32_t c32 = 192;
    
    char a = 'A';	
	
	printf("char = %d\n",sizeof(a));
	
	printf("char16_t '%c' = %d\n",c16, sizeof(c16));
	printf("char16_t  = %d\n",sizeof(char16_t));
	
	printf("char32_t '%c' = %d\n",c32, sizeof(c32));
	printf("char32_t  = %d\n",sizeof(char32_t));
	
	return 0;
}