#include<stdio.h>
#include<string.h>

void func1(char* arr[])
{
    //function body
	printf("z -> **(arr+2) = %c\n",**(arr+2));
	printf("z -> *arr[2] = %c\n",*arr[2]);
	printf("z -> **(arr+2) = %c\n",**arr+6);
	printf("z -> *arr[2] = %c\n",*arr[2]);
	printf("z -> *arr[2]+1 = %c\n",*arr[2]+1);
}
void func2(char** arr)
{
    printf("x = %c\n",*arr[0]);
	printf("y = %c\n\n",**(arr+1));
	
	
	printf("z -> **(arr+2) = %c\n",**(arr+2));
	printf("z -> *arr[2] = %c\n",*arr[2]);
	printf("z -> **(arr+2) = %c\n",**arr+6);
	printf("z -> *arr[2] = %c\n",*arr[2]);
	printf("z -> *arr[2]+1 = %c\n",*arr[2]+1);
}

void print(char* arr[]){
	printf(" %x\n",arr[0]);
	//citty[0]+0, *(citty[0]+0)
	printf("z -> **(arr+2) = %s\n",arr[0]+1);
}

int main()
{
    //x, y and z are pointer to char
    char x[3]={'1', '2', '3'};
    char y[3]={'4', '5', '6'};
    char z[3]={'7', '8', '9'};

    //arr is pointer to char pointer
    char* arr[3]={x, y, z};
   // func1(arr);
   // func2(arr);
	
	/*
		Um ponteiro para um array de caracteres é uma string literal.
		Por padrão, qualquer string literal sempre será const. Não há maneira de contornar isso. 
		Tentar modificar um literal de string geralmente resultará em um segfault.
		Um array de caracteres pode ser modificado, agora uma string literal não pode ter seus valores modificados.
		
		******************************************************************
		char strs[][] = {
		"Hello",
		"World"
		}; // transforma os literais de string em matrizes de caracteres
		strs[0][0] = 'X'; // valido
		
		******************************************************************
		
		char* strs[] = {
		"Hello",
		"World",
		};
		strs[0][0] = 'X'; // tentando modificar um ponteiro para um literal de string constante, ocorre o erro undefined (indefinido)
		
		******************************************************************
		
	*/
	
	char city[][12] = {
			"Chennai",
			"Kolkata",
			"Mumbai",
			"New Delhi"
	};
	printf(" city[][12] size =  %d\n",sizeof(city));
	printf(" city = %d\n",&city);
	printf("---- %x - %c -----\n\n",&city[0][0],city[0][0]);
	printf("---- %x - %c -----\n\n",&city[1][0],city[1][0]);
	printf("---- %x - %c -----\n\n",&city[2][0],city[2][0]);
	printf("---- %x - %c -----\n\n",&city[3][0],city[3][0]);
	
		char *citty[4] = {		
		    "Chennai",
			"Kolkata",
			"Mumbai",
			"New Delhi"
	};
	printf(" *city[4] size =  %d\n",sizeof(citty)); 
	printf("%x\n",&citty[0]);
	printf("%x\n",&citty[1]); 
	printf("%x\n",&citty[2]);
	printf("%x\n",&citty[3]);
	
	printf("          %x \n\n",citty);
	printf("--------- %x - %c --------- \n",citty[0]+0, *(citty[0]+0));
	printf("--------- %x - %c ---------- \n",citty[1]+0, *(citty[1]+0));
	printf("--------- %x - %c ---------- \n",citty[2]+0, *(citty[2]+0));
	printf("--------- %x - %c ---------- \n",citty[3]+0, *(citty[3]+0));
	
	printf("--------- --------- \n");
	
	
	printf("--------- %s  --------- \n",*(citty+2));
	printf("--------- %s  --------- \n",*(citty+1));
	printf("--------- %x  --------- \n",&*(citty+2));
	printf("--------- %x  --------- \n",&citty+3);
   
   print(citty);
   
  // char name[] = "hello";
   char *name = "hello";
   char *a = name;
  // strcmp(*a,name);
   printf("\n%c -- %d -- %d --- %d\n\n",*name, name, &name, &name[0]);
   printf("%c -- %d -- %d --- %d\n",*(name+1), name+1, &*name+1, &name[1]);
   
    printf("name+0 = %d\n",name+0);
	 printf("name+1 = %d -- %c\n",name+1,*(name+1));
	  printf("name+2 = %d\n",name+2);
	  
     printf("\n&name+0 = %d\n",&name);
	 printf("&name+1 = %d\n",&name+1);
	 printf("&name+2 = %d\n",&name+2);
	 printf("name = %d\n",sizeof(&name));
	 printf("%s\n",a);
	 printf("%c\n",*(a+1));
	 puts(a);s
	 
	 /*
		Para um computador de 32 bits, o tamanho do ponteiro pode ser de 4 bytes ; Os computadores de 64 bits podem ter 8 bytes .
		Ou um computador de 64 bits executando um sistema operacional de 32 bits terá 4 bytes . Ainda assim, sob uma arquitetura específica, 
		todos os tipos de ponteiros (void *, int *, char *, long * etc) terão o mesmo tamanho (exceto ponteiros de função).
	 */
   
   return 0;
}