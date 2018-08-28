#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* hello_world(void *tid){
	printf("Hello World. Esta é a Thread %d\n", (int) (size_t)tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){    
    int i = 0;
    while(i<atoi(argv[1])){
        pthread_t thread;
        int status;
        void *thread_return;

        printf("Processo principal criando thread\n");
        status = pthread_create(&thread, NULL, hello_world, i);

        if(status!=0){
            printf("Erro na criação da thread. Codigo de Erro:%d\n", status);
            return 1;
        }

        ++i;
        if(i==atoi(argv[1])){
            printf("Esperando Thread finalizar....\n");
            pthread_join(thread, &thread_return);
            printf("Thread finalizada\n");
            printf("processo pai vai finalizar\n");
        }
        
    }  

	return 0;
}