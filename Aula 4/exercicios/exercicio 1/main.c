#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid[4]={-1, -1, -1, -1}; /*< crie os 4 processos que serão usados */

    int status; /*< Usado para verificar os processos ao final do código */

    /* Criando os dois priemiros filhos do pai **/

    pid[0] = fork(); /*< Criar o primeiro processo filho (1) */
    if (pid[0] < 0){
        printf("Erro ao criar processo #0 \n");
        return 1;
    }
    if(pid[0] > 0){ /*< se este ainda for o pai ele terá um pid maior que 0, então... */
        printf("PAI: criando o segundo processo \n");
        pid[1] = fork(); /*< Criar o segundo processo filho (2) */
        if (pid[1] < 0){
            printf("Erro ao criar processo #1 \n");
            return 1;
        }
    }

    /** Criado os filhos 1 e 2 do pai, vamos criar os filhos dos filhos 1 e 2 **/

    if(pid[0] == 0){ /*< Entre no filho 1 */
        printf("FILHO#1: Criando o processo filho do filho cujo PID é %d\n", getpid());             
        pid[2] = fork(); /*< crie filho do filho 1 */
        for(int l; l<1000; ++l){
            //loop finito para teste
        }
        
    }

    if(pid[1] == 0){ /*< Entre no filho 2 */
        printf("FILHO#2: Criando o processo filho do filho cujo PID é %d\n", getpid());             
        pid[3] = fork(); /*< crie filho do filho 2 */
        for(int k; k<1000; ++k){
            //loop finito para teste
        }

    }
                    
    status = wait(NULL);        
    printf("Processo #%d finalizou\n", status);
    
    return 0;
}