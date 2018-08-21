#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t pid[] = {-1, -1};

	pid[0] = fork();

	if(pid[0] < 0){
		
	}
}