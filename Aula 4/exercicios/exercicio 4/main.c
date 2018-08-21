#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t pid[] = {-1, -1};

	pid[0] = fork();

	if(pid[0] < 0){
		printf("Erro ao criar processo \n");
        return 1;
	}
	if(pid[0] > 0){
		pid[1] = fork();

		if(pid[1] < 0){
			printf("Erro ao criar processo \n");
			return 1;
		}
	}

	if((pid[0] > 0) && (pid[1] > 0)){
		for(int i=1; i<=50; ++i){
			printf("PID=%d; PPID=%d; %d\n", getpid(), getppid(), i);
			sleep(2);
		}
		printf("Processo pai vai morrer");
		exit(-1);
	}

	if(pid[0]==0){
		printf("Filho 1 foi criado");
		for(int i=100; i<=199; ++i){
			printf("PID=%d; PPID=%d; %d\n", getpid(), getppid(), i);
			sleep(1);
		}
		printf("Filho 1 vai morrer");
		exit(-1);
	}

	if(pid[1]==0){
		printf("Filho 2 foi criado");
		for(int i=200; i<=299; ++i){
			printf("PID=%d; PPID=%d; %d\n", getpid(), getppid(), i);
			sleep(1);
		}
		printf("Filho 2 vai morrer");
		exit(-1);
	}
}