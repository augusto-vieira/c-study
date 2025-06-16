# Criar um clone do fgets usando a função read
Aula: [Curso Básico da Linguagem C - Aula #11: Lendo a entrada padrão - 3/3](https://www.youtube.com/watch?v=bW3Xox6LP_U&list=PLXoSGejyuQGrDX08GVrQHAhh4j3KJ4iYN&index=13&ab_channel=debxp)
```c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

char *clone_fgets(char *buf, int size, int fd ){
  
  fflush(stdout);
  ssize_t ret = read(fd, buf, size - 1);
  
  if(ret > - 1){
    buf[ret] = '\0';
    return buf; 
  }

  return NULL;
}
int main(int argc, char *argv[]){
  
 char teste[10];

 printf("Digite algo -> ");
 
 if(clone_fgets(teste, 10, 0) == NULL)
    return 1;  
  
 printf("%s\n", teste);
  
 ioctl(0,TCFLSH, 0);   // limpar o buffer de entrada do terminal 

 return 0;
}
```
Saída:
```bash
$ ./a.out 
Digite algo -> 123
123
   # contém a quebra de linha do printf
$
```
```bash
$ ./a.out 
Digite algo -> 123456789
123456789
$
```
Sem  limpar o buffer (linha 28):
```bash
$ ./a.out 
Digite algo -> 123456789ls
123456789
$ ls     # executa o ls
Estudos-em-C  Makefile  a.out  exe_aula_01.c  read.c
$
```
Limpando o buffer (linha 28):
```bash
$ ./a.out 
Digite algo -> 123456789ls
123456789
$
```