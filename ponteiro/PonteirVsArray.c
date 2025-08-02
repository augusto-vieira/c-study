#include<stdio.h>
/*
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

*/
int main()
{
   /* //x, y and z are pointer to char
    char x[3]={'1', '2', '3'};
    char y[3]={'4', '5', '6'};
    char z[3]={'7', '8', '9'};

    //arr is pointer to char pointer
    char* arr[3]={x, y, z}; */

	char city[][12] = {
			"Chennai",
			"Kolkata",
			"Mumbai",
			"New Delhi"
	};
	printf(" city[][12] size =  %d\n",sizeof(city));

		char *citty[4] = {
		    "Chennai",
			"Kolkata",
			"Mumbai",
			"New Delhi",
	};

	printf(" *city[4] size =  %d\n",sizeof(citty));

	printf("%s\n",citty[0]);
	printf("%s\n",citty[1]);
	printf("%s\n",citty[2]);
	printf("%s\n",citty[3]);

   // func1(arr);
   // func2(arr);
   return 0;
}
