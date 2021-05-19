// this i_ii_ptr is a function
// that returns int*
// and takes two ints
// int* i_ii_ptr(int, int);

// it now becomes a function pointer
// that points to a function
// that return int
// and takes two ints
// int (*i_ii_ptr)(int, int);

// i_ii_ptr is now a typedef
// a function pointer type
// this type points to a function
// that returns int and
// takes two ints
typedef int (*i_ii_ptr)(int, int);

int call (i_ii_ptr func, int a, int b)
{
    return func(a,b);
}

int sum(int a, int b)
{
    return a + b;
}
int main(void)
{
  printf("A + b = %d", call(sum, 3, 2));
}

// =========================

 int main(void)
 {
     // age_t is an instance of pointer
     // that points to int
     // int *age_t;

     // this is not a pointer type
     // that points to an int 
     // typedef int* aget_t;

     // a function type
     // that returns double
     // takes two doubles
     // double(double, double);

     // func_t is an instance of a function
     // that returns double
     // and takes two doubles as parameter
     // double func_t(double, double);

     // func_t is an instance of a function  
     // that returns a pointer to double
     // and this func_t takes two doubles
     // double* func_t(double, double);

     // func_t is an instance of function pointer
     // that points to a function
     // that returns double
     // and takes two doubles
     // double (*func_t)(double, double);

     // now func_t is type - a type alias
     // for a function pointer that returns
     // double and takes two doubles
     // func_t is now a function pointer type
     typedef double (*func_t)(double, double);

     // int is a type
     // age_t is an instance

     // now age_t is a type -- type alias for int
     // age_t is now a type
     typedef int age_t;

 }
// =========================
	
	/*
	
	video : https://www.youtube.com/watch?v=KrjrCgttZuM&ab_channel=ThomasKim 

	Argument Passing and Naming Conventions
	Stack Frame and Function Call Conventions
	https://goo.gl/3iHWPw

	cdecl, stdcall

	Calling Conventions - https://goo.gl/B2Zyfk

	Download Source Code:
	http://www.TalkPlayFun.com/download/c...
	
	*/

//****************************************************************************************************

// este i_ii_ptr é uma função
// que retorna int*
// e leva dois ints
// int* i_ii_ptr(int, int);


// agora se torna um ponteiro de função
// que aponta para uma função
// esse retorno int
// e leva dois ints
// int (*i_ii_ptr)(int, int);


// i_ii_ptr agora é um typedef
// um tipo de ponteiro de função
// este tipo aponta para uma função
// que retorna int e
// leva dois ints
typedef int (*i_ii_ptr)(int, int);

int call (i_ii_ptr func, int a, int b)
{
    return func(a,b);
}

int sum(int a, int b)
{
    return a + b;
}
int main(void)
{
  printf("A + b = %d", call(sum, 3, 2));
}

 int main(void)
 {
	// age_t é uma instância de ponteiro
    // que aponta para int
    // int * age_t;
	
	// este não é um tipo de ponteiro
    // que aponta para um int
    // typedef int* aget_t;
	
	// um tipo de função
    // que retorna o double
    // leva dois doubles
    // double(double, double);
	
	// func_t é uma instância de uma função
    // que retorna double
    // e leva dois double como parâmetro
	// double func_t(double, double);
	
	// func_t é uma instância de uma função
    // que retorna um ponteiro para double
    // e este func_t leva dois double
    // double* func_t (double, double);
	
	// func_t é uma instância do ponteiro de função
    // que aponta para uma função
    // que retorna double
    // e leva dois double
    // double (*func_t) (double, double);
	
	// agora func_t é tipo - um alias de tipo
    // para um ponteiro de função que retorna
    // double e leva dois double
    // func_t agora é um tipo de ponteiro de função
	typedef double (*func_t)(double, double);
	
	// int é um tipo
    // age_t é uma instância

    // agora age_t é um alias de tipo - tipo para int
    // age_t agora é um tipo
	typedef int age_t;
 }
//****************************************************************************************************