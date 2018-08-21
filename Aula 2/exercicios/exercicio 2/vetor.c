/**
 * @file vetor.c
 * @brief exercícios do slid
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função para criação de vetores dinâmicos
 * @param tamanho Tamanho do vetor a ser alocado
 * @return Ponteiro para o inicio do vetor locado
 **/ 
int * alocarVetor(int tamanho){
    if(tamanho < 1){ /* Tamanho insuficiente para alocação de um vetor */
        printf ("Erro: Parametro invalido \n");
        return NULL; /*< Retornar erro */
    } else {
        int *vetor;
        vetor = (int *) malloc(tamanho * sizeof(int)); /*< Alocar espaço na memória do tamanho solicitado */
        if(vetor == NULL){ /* Caso não tenha memória disponível suficiente apra alocar vertor */
            printf("Erro: Memória insuficiente \n");
            return NULL; /*< Retornar erro */
        } else {
            return vetor; 
        }
    }
}

/**
 * @brief Função para liberar espaço alocado no vetor dinâmico
 * @param vetor Aponta para onde está alocado o vetor na memória
 * @retunr NULL
 **/
int * liberarVetor(int *vetor){
    if(vetor == NULL){ /* Se não tiver mais alocado */
        return NULL;
    } else { /* Caso exista um vetor alocado */
        free(vetor);
        return NULL;
    }
}

/**
 * @brief Função para mutiplicar os elemento dos vetores e imprimir
 * @param vetorUm Aponta para o priemiro vetor
 * @param VetorDois Aponta para o segundo vetor
 * @param tamanho tamanho do vetor
 **/
void multiplicacaoDeElementos(int *vetorUm, int *vetorDois, int tamanho){
    for(int i=0; i<tamanho; ++i){
        int resultado = (*(vetorUm + i)) * (*(vetorDois + i)); /*< Multiplicar elementos do vetor */
        printf("%d ", resultado);
    }
    printf("\n");
}

/**
 * @brief Função preencher vetor com argumentos
 * @param vetor Vetor a ser preenchido
 * @param elemento O que será preenchido
 * @param tamanho tamanho do vetor a ser preenchido
 **/
void preencherVetor(int *vetor, int elemento, int tamanho){
    for(int i=0; i<tamanho; ++i){
        int *modificar = vetor + i;
        *modificar = elemento;
    }
}

int main(int argc, char *argv[]){
    int *vetor_b, *vetor_c;
    vetor_b = alocarVetor(atoi(argv[1]));
    vetor_c = alocarVetor(atoi(argv[1]));
    preencherVetor(vetor_b, atoi(argv[2]), atoi(argv[1]));
    preencherVetor(vetor_c, atoi(argv[3]), atoi(argv[1]));
    multiplicacaoDeElementos(vetor_b, vetor_c, atoi(argv[1]));
    vetor_b = liberarVetor(vetor_b);
    vetor_c = liberarVetor(vetor_c);
    return 0;
}