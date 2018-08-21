/**
 * @file questaoDois.c
 * @brief Exercício 2
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 * OBS: Incompleta!!!
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>

int a = 0;

int main(int argc, char * argv[]){
    a = atoi(argv[1]);

    pid_t pid;

    int *mem;
    int seg_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);

    pid = fork();

    if(pid>0){ //Este é o pai
        int b = implementacao(a);	
		mem = shmat(seg_id, NULL, 0);
		sprintf(mem, b);
		shmdt(mem);
    }
    sleep(2);
    if(pid==0){ //Este é o filho
        int b = implementacao(&a);	
		mem = shmat(seg_id, NULL, 0);
		sprintf(mem, b);
		shmdt(mem);
        exit(0);
    }
    sleep(2);
    if(pid>0){	//Vota para o pai
		mem = shmat(seg_id, NULL, 0);
		printf("%d ", mem);
        exit(0);
    }
    
}