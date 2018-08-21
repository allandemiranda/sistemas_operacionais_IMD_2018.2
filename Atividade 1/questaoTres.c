/**
 * @file questaoTres.c
 * @brief Exercício 3
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int a = 0;
int b = 1;

/**
 * @brief Função pra criar filhos e somar dentro do filho
 * 
 * @param numero Número de filhos a efetuar a operação
 * @return int Retorna o valor final
 */
int filho(int numero){
    pid_t pid;    
    pid = fork(); 
    if (pid < 0){ //erro ao criar filho
		printf("Erro ao criar processo \n");
		return 1;
	}
    if(pid == 0){ //entrar no filho do filho
        if((numero-1)>=0){
            // executar somatorio dentro do filho            
            a = a + b;
            b = b + 1;                        
            filho(numero-1); //criar novo filho dentro do filho
            return a;
        }
    }
}

int main(int argc, char * argv[]){
    int valor = filho(atoi(argv[1]));    /*< crie filhos... */
    printf("%d \n", valor);
    return 0;
}