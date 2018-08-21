#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int status, i;
    pid_t pid[4] = {-1, -1, -1, -1}; /* determine os 4 processos */
    pid[0] = fork(); /* inicie o primiero processo filho */
    printf("PAI: criando o primeiro processo \n");

    if(pid[0] < 0){
        printf(stderr, "Erro ao criar processo #0 \n");
		return 1; 
    } else {
        if(pid[0] > 0){
            pid[1] = fork();
            printf("PAI: criando o segundo processo \n");
            if(pid[1] < 0){
                printf(stderr, "Erro ao criar processo #1 \n");
		        return 1;
            }
        } else{
            if(pid[0] == 0){
                pid[2] = fork();
                printf("Filho 1: criando seu filho processo \n");
                if(pid[1] < 0){
                    printf(stderr, "Erro ao criar processo #2 \n");
                    return 1;
                }
            } else {
                if(pid[1] == 0){
                    pid[3] = fork();
                    printf("Filho 2: criando seu filho processo \n");
                    if(pid[3] < 0){
                        printf(stderr, "Erro ao criar processo #3 \n");
                        return 1;
                    }
                }
            }
        }
    }
    
    for(i=0; i<2; ++i){
        status = wait(NULL);
    }
    printf("Processo-Filho #%d finalizou\n", status);

}