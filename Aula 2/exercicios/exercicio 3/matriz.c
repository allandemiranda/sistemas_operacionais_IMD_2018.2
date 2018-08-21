/**
 * @file matriz.c
 * @brief exercícios do slid
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <stdio.h>
#include <stdlib.h>

/** 
 * @brief Função para criação da matriz
 * 
 * @param tamanhoLinha Quantidad de elementos na linha da matriz
 * @param tamanhoColuna Quantidade de colunas da matriz
 * @retunr Vetor alocado
 **/
int ** alocarMatriz(int tamanhoLinha, int tamanhoColuna){
    if(tamanhoColuna < 1 || tamanhoLinha < 1){
        printf ("Erro: Parametro invalido \n");
        return NULL;
    } else {
        int **matriz;
        matriz = (int *) malloc(tamanhoLinha * sizeof(int *));
        if(matriz == NULL){
            printf("Erro: Memória insuficiente \n");
            return NULL;
        } else {
            for(int i=0; i<tamanhoLinha; ++i){
                matriz[i] = (int *) malloc(tamanhoColuna * sizeof(int));
                if(matriz[i] == NULL){
                    printf("Erro: Memória insuficiente \n");
                    return NULL;
                }
            }
            return matriz;
        }
    }
}

/**
 * @brief Função para preenchimeto da matriz com o elemento
 * 
 * @param matriz Aponta apra a matriz que será preenchida
 * @param tamanhoLinha Quantidade de linhas presente na matriz
 * @param tamanhoColuna  Quantidade de colunas presente na matriz
 * @param elemento Elemento a ser adicionado em toda a matriz
 */
void preencherMatriz(int **matriz, int tamanhoLinha, int tamanhoColuna, int elemento){
    for(int i=0; i<tamanhoLinha; ++i){
        for(int j=0; j<tamanhoColuna; ++j){
            int *linha = (*matriz + i);
            int *coluna = linha + j;
            *coluna = elemento;
        }
    }
}

/**
 * @brief Função para liberar matriz
 * 
 * @param matriz Aponta para a matriz a ser liberada
 * @param tamanhoLinha Quantidade de elementos que existe na linha
 * @param tamanhoColuna Quantidade de elementos que existe na coluna
 * @return int** Resultado da liberação da matriz
 */
int ** liberarMatriz(int **matriz, int tamanhoLinha, int tamanhoColuna){
    if(matriz == NULL){ /* Caso não haja nada na matriz */
        return NULL;
    } else {
        for(int i=0; i<tamanhoLinha; ++i){ 
            free(matriz[i]);/*< Liberar os elementos da linha (que geram as colunas) */
        }
        free(matriz); /*< Liberar o vetor linha inicial */
        return NULL;
    }
}

/**
 * @brief Função para multiplicar matrizes e imprimir na tela
 * 
 * @param matrizUm Ponteiro apontando para primeira matriz
 * @param matrizDois Ponteiro aponando par segunda matriz
 * @param tamanho Tamanho da matriz quadratica
 */
void multiplicarMatrizes(int **matrizUm, int **matrizDois, int tamanho){
    int **matrizFinal = alocarMatriz(tamanho, tamanho); /*< Criando uma nova matriz para poder multiplicar elementos */
    for(int i=0; i<tamanho; ++i){
        for(int j=0; j<tamanho; ++j){
            for(int k=0; k<tamanho; ++k){
                matrizFinal[i][j] += matrizUm[i][k] * matrizDois[k][i];
            }
        }
    }
    for(int i=0; i<tamanho; ++i){ /* Imprimir elementos da matriz final */
        for(int j=0; j<tamanho; ++j){
            printf("%d ", matrizFinal[i][j]);
        }
        printf("\n");
    }
    liberarMatriz(matrizFinal, tamanho, tamanho); /* Liberar matriz criada nesta função */
}

int main(int argc, char *argv[]){
    int *matriz_b, *matriz_c;
    matriz_b = alocarMatriz(atoi(argv[1]), atoi(argv[1]));
    matriz_c = alocarMatriz(atoi(argv[1]), atoi(argv[1]));
    preencherMatriz(matriz_b, atoi(argv[1]), atoi(argv[1]), atoi(argv[2]));
    preencherMatriz(matriz_c, atoi(argv[1]), atoi(argv[1]), atoi(argv[3]));
    multiplicarMatrizes(matriz_b, matriz_c, atoi(argv[1]));
    liberarMatriz(matriz_b, atoi(argv[1]), atoi(argv[1]));
    liberarMatriz(matriz_c, atoi(argv[1]), atoi(argv[1]));
    return 0;
}