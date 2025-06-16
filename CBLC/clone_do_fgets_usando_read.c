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