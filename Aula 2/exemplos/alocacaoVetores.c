#include <stdio.h>
#include <stdlib.h>

int main (int argc,  char *argv[]){
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int c=atoi(argv[3]);
	
	int *vetor1, *vetor2, *vetorFinal;
	int i;

	vetor1 = malloc(a*sizeof(int));
	for(i=0;i<a;i++)
		vetor1[i] = b;
	vetor2 = malloc(a*sizeof(int));
	for(i=0;i<a;i++)
		vetor2[i] = c;

	vetorFinal = malloc(a*sizeof(int));
	for(i=0;i<a;i++){
		vetorFinal[i] = (int)vetor1[i]* (int)vetor2[i];
		printf("%d ", (int)vetorFinal[i]);
	}
	free(vetor1);
	free(vetor2);
	free(vetorFinal);
	printf("\n");
	return 0;
}
