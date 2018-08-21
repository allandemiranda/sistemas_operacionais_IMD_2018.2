/**
 * @file questaoUm.c
 * @brief Exercício 1
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Função para criar filhos dentro e filhos
 * 
 * @param numero número de filhos a ser criado dentro de filhos
 */
void filho(int numero){
    pid_t pid;    
    pid = fork(); 
    if (pid < 0){ //erro ao criar filho
		printf("Erro ao criar processo \n");
		return 1;
	}
    if(pid == 0){ //entrar no filho do filho
        printf("PID=%d; PPID=%d;\n", getpid(), getppid());
        if((numero-1)>0){
            filho(numero-1); //criar novo filho dentro do filho
        }
    }
}

int main(int argc, char * argv[]){
    filho(atoi(argv[1])); /*< crie filhos... */
    return 0;
}
