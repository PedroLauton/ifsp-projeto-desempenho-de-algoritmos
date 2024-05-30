#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "desempenhoDeAlgoritmos.h"


void escolhaMenuAlgoritmos(){
    printf(
        "------ESCOLHA DE ALGORITMO------\n\n"
        "1. BubbleSort\n"
        "2. InsertionSort\n"
        "3. SelectionSort\n"
        "4. ShellSort\n"
        "5. MergeSort\n"
        "6. QuickSort\n"
        "7. HeapSort\n"
        "8. RadixSort\n"
        "9. CountigSort\n"
        "10. TimSort\n\n"
        "11. Encerrar\n\n"
        "--------------------------------\n\n"
        "Escolha: "
    );
}

void escolhaMenuElementos(){
    printf(
        "------QUANTIDADE DE ELEMENTOS------\n\n"
        "1. 1.000\n"
        "2. 5.000\n"
        "3. 10.000\n"
        "4. 20.000\n"
        "5. 50.000\n"
        "6. 100.000\n\n"
        "7. Voltar\n\n"
        "--------------------------------\n\n"
        "Escolha: "
    );
}

int *alocacaoVetor(int extensaoVetor){
    int* vetor = (int*) calloc(5,sizeof(int));
    if(vetor == NULL){
        return 0;
    }
    srand(time(NULL));
    for(int i = 0; i < 5; i++){
        vetor[i] = rand() % 10;
        printf("%d, ", vetor[i]);
    }
    return vetor;
}
