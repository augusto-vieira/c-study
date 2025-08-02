#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void sigquit(){
    // Função que trata o sinal SIG_QUIT
    printf("Recebi sinalização para terminar!\n");
    sleep(1);
    printf("Adeus!\n");
    exit(0);
}

int main(){
    pid_t filho;
    int a = 0;

    filho = fork();
    if(filho == 0){
        // Esta parte do codigo executa no processo filho 
        signal(SIGQUIT, sigquit); // Associa sinal SIGQUIT a função sigquit

        while (1)
        {
            printf("Processo Filho\n");
            sleep(1);
        }
    } else{
        // Está parte executa no processo pai
        printf("Processo filho tem PID: %d\n", filho);
        do{
            printf("Processo pai: a = %d\n", a);
            sleep(1);
            a++;

            if( a == 3)
              kill(filho, SIGQUIT); // Termina o processo filho
        }while(a < 6);
        waitpid(filho, 0, 0); // Espera o processo filho encerrar
    } 
    return 0;
}
