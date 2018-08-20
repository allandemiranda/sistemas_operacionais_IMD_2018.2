#include <stdio.h>
#include <stdlib.h>

int main (int argc,  char *argv[]){
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int c=atoi(argv[3]);
	
	int **matriz1, **matriz2, **matrizFinal;
	int i, j, k;

	matriz1 = (int **)malloc(a*sizeof(int*));
	for(i=0;i<a;i++){
		matriz1[i] = (int *)malloc(a*sizeof(int));
		for(j=0;j<a;j++)
			matriz1[i][j] = b;	
	}
	matriz2 = (int **)malloc(a*sizeof(int*));
	for(i=0;i<a;i++){
		matriz2[i] = (int *)malloc(a*sizeof(int));
		for(j=0;j<a;j++)
			matriz2[i][j] = c;	
	}
	matrizFinal = (int **)malloc(a*sizeof(int*));
	for(i=0;i<a;i++){
		matrizFinal[i] = (int *)malloc(a*sizeof(int));
		for(j=0;j<a;j++)
			matrizFinal[i][j] = 0;	
		
	}
	for(i=0;i<a;i++)
		for(j=0;j<a;j++)
			for(k=0;k<a;k++)
				matrizFinal[i][j] += matriz1[i][k] * matriz2[k][j];
	
	
	for(i=0;i<a;i++){
		for(j=0;j<a;j++)
			printf("%d ", (int)matriz1[i][j]);
		printf("\n");
	}
	for(i=0;i<a;i++){
		for(j=0;j<a;j++)
			printf("%d ", (int)matriz2[i][j]);
		printf("\n");
	}
	for(i=0;i<a;i++){
		for(j=0;j<a;j++)
			printf("%d ", (int)matrizFinal[i][j]);
		printf("\n");
	}
	return 0;
}
