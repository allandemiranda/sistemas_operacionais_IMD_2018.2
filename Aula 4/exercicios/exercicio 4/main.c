#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t pid[] = {-1, -1}; /*< Os filhos */

	pid[0] = fork(); /*< Iniciar o primeiro filho (1) */

	if(pid[0] < 0){ /* Erro ao criar o filho (1) */
		printf("Erro ao criar processo \n");
        return 1;
	}
	if(pid[0] > 0){ /* Caso seja o pai entre aqui */ 
		pid[1] = fork(); /*< Crie o segundo filho (2) */

		if(pid[1] < 0){ /* Erro ao criar segundo filho */
			printf("Erro ao criar processo \n");
			return 1;
		}
	}

	if((pid[0] > 0) && (pid[1] > 0)){ /* Caso não seja nemo filho 1 nem o filho 2, você é o pai e entra aqui */
		for(int i=1; i<=50; ++i){ /* Inicie a contagem dos números pedidos de 1 a 50 */
			printf("PID=%d; PPID=%d; %d\n", getpid(), getppid(), i);
			sleep(2);
		}
		printf("Processo pai vai morrer");
		exit(0); /* Finalize o processo pai */
	}

	if(pid[0]==0){ /* Coso você seja filho 1 entre aqui */
		printf("Filho 1 foi criado");
		for(int i=100; i<=199; ++i){/* Inicie a contagem dos números pedidos de 100 a 199 */
			printf("PID=%d; PPID=%d; %d\n", getpid(), getppid(), i);
			sleep(1);
		}
		printf("Filho 1 vai morrer");
		exit(0); /* Finalize o processo filho 1 */
	}

	if(pid[1]==0){ /* Coso você seja filho 2 entre aqui */
		printf("Filho 2 foi criado");
		for(int i=200; i<=299; ++i){ /* Inicie a contagem dos números pedidos de 200 a 299 */
			printf("PID=%d; PPID=%d; %d\n", getpid(), getppid(), i);
			sleep(1);
		}
		printf("Filho 2 vai morrer");
		exit(0); /* Finalize o processo filho 2 */
	}
}