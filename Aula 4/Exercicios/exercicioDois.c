#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pidUm;
    pidUm = fork();
    if(pidUm==0){
        printf("Filho 1 foi criado \n");
        printf("Esta é a execução do filho(PID=%d), cujo pai tem PID=%d\n    ", getpid(), getppid());
        for(int i=100; i<=199; ++i){
            printf("%d ",i);
            sleep(1);
        }
        printf("Filho 1 vai morrer \n");
        return 0;
    } else {
        pid_t pidDois;
        pidDois = fork();
        if(pidDois==0){
            printf("Filho 2 foi criado \n");
            printf("Esta é a execução do filho(PID=%d), cujo pai tem PID=%d\n    ", getpid(), getppid());
            for(int i=200; i<=299; ++i){
                printf("%d ",i);
                sleep(1);
            }
            printf("Filho 2 vai morrer \n");
            return 0;
        } else {
            for(;;){
                if(wait(NULL)==pidUm){
                    break;
                }
            }
            for(;;){
                if(wait(NULL)==pidDois){
                    break;
                }
            }
            printf("Processo pai vai morrer \n ");
            return 0;
        }
    }
}