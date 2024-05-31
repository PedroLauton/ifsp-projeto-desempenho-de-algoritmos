#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include "desempenhoDeAlgoritmos.h"

#define MIN_RUN 32
#define TAMANHO 300

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
        "-----------------------------------\n\n"
        "Escolha: "
    );
}

int *alocacaoVetor(int extensaoVetor){
    int* vetor = (int*) calloc(extensaoVetor,sizeof(int));
    if(vetor == NULL){
        return NULL;
    }
    srand(time(NULL));
    for(int i = 0; i < extensaoVetor; i++){
        vetor[i] = rand() % 10;
    }
    return vetor;
}

int escolheValor(int escolhaElementos){
    switch(escolhaElementos){
        case 1: return 1000;
        case 2: return 5000;
        case 3: return 10000;
        case 4: return 20000;
        case 5: return 50000;
        case 6: return 100000;
        default: return 0;
    }
}
void medicaoDeTempoMelhorPiorCaso(int escolhaAlgoritmo, int escolhaElementos){
    struct timeval start, end;
    long seconds, useconds;
    double total_time;
    int extensaoVetor = escolheValor(escolhaElementos);

    int* vetorMelhorCaso = (int*) calloc(extensaoVetor,sizeof(int));
    if(vetorMelhorCaso == NULL){
        printf("\nErro na alocacao de memoria. Tente novamente.");
        return;
    }

    for(int i = 0; i < extensaoVetor; i++){
        vetorMelhorCaso[i] = i;
    }

    int* vetorPiorCaso = (int*) calloc(extensaoVetor,sizeof(int));
    if(vetorPiorCaso == NULL){
        printf("\nErro na alocacao de memoria. Tente novamente.");
        return;
    }

    for(int i = extensaoVetor, k = 0; i > 0 ; i--, k++){
        vetorPiorCaso[k] = i;
    }

    switch(escolhaAlgoritmo){
        case 1:
            gettimeofday(&start, NULL);
            bubbleSort(vetorMelhorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("\nMelhor tempo de ordenacao do BubbleSort: %.3f microssegundos\n", total_time);
            free(vetorMelhorCaso);

            gettimeofday(&start, NULL);
            bubbleSort(vetorPiorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("Pior tempo de ordenacao do BubbleSort: %.3f microssegundos\n", total_time);
            free(vetorPiorCaso);
            break;

        case 2:
            gettimeofday(&start, NULL);
            insertionSort(vetorMelhorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("\nMelhor tempo de ordenacao do InsertionSort: %.3f microssegundos\n", total_time);
            free(vetorMelhorCaso);

            gettimeofday(&start, NULL);
            insertionSort(vetorPiorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("Pior tempo de ordenacao do InsertionSort: %.3f microssegundos\n", total_time);
            free(vetorPiorCaso);
            break;

        case 3:
            gettimeofday(&start, NULL);
            selectionSort(vetorMelhorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("\nMelhor tempo de ordenacao do SelectionSort: %.3f microssegundos\n", total_time);
            free(vetorMelhorCaso);

            gettimeofday(&start, NULL);
            selectionSort(vetorPiorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("Pior tempo de ordenacao do SelectionSort: %.3f microssegundos\n", total_time);
            free(vetorPiorCaso);
            break;

        case 4:
            gettimeofday(&start, NULL);
            shellsort(vetorMelhorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("\nMelhor tempo de ordenacao do ShellSort: %.3f microssegundos\n", total_time);
            free(vetorMelhorCaso);

            gettimeofday(&start, NULL);
            shellsort(vetorPiorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("Pior tempo de ordenacao do ShellSort: %.3f microssegundos\n", total_time);
            free(vetorPiorCaso);
            break;

        case 5:
            gettimeofday(&start, NULL);
            mergeSort(vetorMelhorCaso, 0, extensaoVetor - 1);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("\nMelhor tempo de ordenacao do MergeSort: %.3f microssegundos\n", total_time);
            free(vetorMelhorCaso);

            gettimeofday(&start, NULL);
            mergeSort(vetorPiorCaso, 0, extensaoVetor - 1);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("Pior tempo de ordenacao do MergeSort: %.3f microssegundos\n", total_time);
            free(vetorPiorCaso);
            break;

        case 6:
            gettimeofday(&start, NULL);
            quickSort(vetorMelhorCaso, 0, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("\nMelhor tempo de ordenacao do QuickSort: %.3f microssegundos\n", total_time);
            free(vetorMelhorCaso);

            gettimeofday(&start, NULL);
            quickSort(vetorPiorCaso, 0, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("Pior tempo de ordenacao do QuickSort: %.3f microssegundos\n", total_time);
            free(vetorPiorCaso);
            break;

        case 7:
            gettimeofday(&start, NULL);
            heapSort(vetorMelhorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("\nMelhor tempo de ordenacao do TimSort: %.3f microssegundos\n", total_time);
            free(vetorMelhorCaso);

            gettimeofday(&start, NULL);
            heapSort(vetorPiorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("Pior tempo de ordenacao do TimSort: %.3f microssegundos\n", total_time);
            free(vetorPiorCaso);
            break;

        case 8:
            gettimeofday(&start, NULL);
            radixSort(vetorMelhorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("\nMelhor tempo de ordenacao do RadixSort: %.3f microssegundos\n", total_time);
            free(vetorMelhorCaso);

            gettimeofday(&start, NULL);
            radixSort(vetorPiorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("Pior tempo de ordenacao do RadixSort: %.3f microssegundos\n", total_time);
            free(vetorPiorCaso);
            break;

        case 9:
            gettimeofday(&start, NULL);
            countingSort(vetorMelhorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("\nMelhor tempo de ordenacao do CountingSort: %.3f microssegundos\n", total_time);
            free(vetorMelhorCaso);

            gettimeofday(&start, NULL);
            countingSort(vetorPiorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("Pior tempo de ordenacao do CountingSort: %.3f microssegundos\n", total_time);
            free(vetorPiorCaso);
            break;

        case 10:
            gettimeofday(&start, NULL);
            timSort(vetorMelhorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("\nMelhor tempo de ordenacao do TimSort: %.3f microssegundos\n", total_time);
            free(vetorMelhorCaso);

            gettimeofday(&start, NULL);
            timSort(vetorPiorCaso, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            printf("Pior tempo de ordenacao do TimSort: %.3f microssegundos\n", total_time);
            free(vetorPiorCaso);
            break;
    }
}
double medicaoDeTempo(int escolhaAlgoritmo, int escolhaElementos){
    struct timeval start, end;
    long seconds, useconds;
    double total_time, mediaTempoDeExecucao = 0;
    int extensaoVetor = escolheValor(escolhaElementos);

    switch(escolhaAlgoritmo){
        case 1:
            for(int i = 0; i < 10; i++){
                int *vetor = alocacaoVetor(extensaoVetor);
                if(vetor == NULL){
                    printf("\nErro na alocacao de memoria. Tente novamente.");
                    break;
                }
                gettimeofday(&start, NULL);
                bubbleSort(vetor, extensaoVetor);
                gettimeofday(&end, NULL);
                seconds  = end.tv_sec  - start.tv_sec;
                useconds = end.tv_usec - start.tv_usec;
                total_time = (seconds * 1000000 + useconds);
                mediaTempoDeExecucao += total_time;
                free(vetor);
            }
            medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
            return (mediaTempoDeExecucao/10);
            break;

        case 2:
            for(int i = 0; i < 10; i++){
                int *vetor = alocacaoVetor(extensaoVetor);
                if(vetor == NULL){
                    printf("\nErro na alocacao de memoria. Tente novamente.");
                    break;
                }
                gettimeofday(&start, NULL);
                insertionSort(vetor, extensaoVetor);
                gettimeofday(&end, NULL);
                seconds  = end.tv_sec  - start.tv_sec;
                useconds = end.tv_usec - start.tv_usec;
                total_time = (seconds * 1000000 + useconds);
                mediaTempoDeExecucao += total_time;
                free(vetor);
            }
            medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
            return (mediaTempoDeExecucao/10);
            break;

        case 3:
            for(int i = 0; i < 10; i++){
                int *vetor = alocacaoVetor(extensaoVetor);
                if(vetor == NULL){
                    printf("\nErro na alocacao de memoria. Tente novamente.");
                    break;
                }
                gettimeofday(&start, NULL);
                selectionSort(vetor, extensaoVetor);
                gettimeofday(&end, NULL);
                seconds  = end.tv_sec  - start.tv_sec;
                useconds = end.tv_usec - start.tv_usec;
                total_time = (seconds * 1000000 + useconds);
                mediaTempoDeExecucao += total_time;
                free(vetor);
            }
            medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
            return (mediaTempoDeExecucao/10);
            break;

        case 4:
            for(int i = 0; i < 10; i++){
                int *vetor = alocacaoVetor(extensaoVetor);
                if(vetor == NULL){
                    printf("\nErro na alocacao de memoria. Tente novamente.");
                    break;
                }
                gettimeofday(&start, NULL);
                shellsort(vetor, extensaoVetor);
                gettimeofday(&end, NULL);
                seconds  = end.tv_sec  - start.tv_sec;
                useconds = end.tv_usec - start.tv_usec;
                total_time = (seconds * 1000000 + useconds);
                mediaTempoDeExecucao += total_time;
                free(vetor);
            }
            medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
            return (mediaTempoDeExecucao/10);
            break;

        case 5:
            for(int i = 0; i < 10; i++){
                int *vetor = alocacaoVetor(extensaoVetor);
                if(vetor == NULL){
                    printf("\nErro na alocacao de memoria. Tente novamente.");
                    break;
                }
                gettimeofday(&start, NULL);
                mergeSort(vetor, 0, extensaoVetor - 1);
                gettimeofday(&end, NULL);
                seconds  = end.tv_sec  - start.tv_sec;
                useconds = end.tv_usec - start.tv_usec;
                total_time = (seconds * 1000000 + useconds);
                mediaTempoDeExecucao += total_time;
                free(vetor);
            }
            medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
            return (mediaTempoDeExecucao/10);
            break;

        case 6:
            for(int i = 0; i < 10; i++){
                int *vetor = alocacaoVetor(extensaoVetor);
                if(vetor == NULL){
                    printf("\nErro na alocacao de memoria. Tente novamente.");
                    break;
                }
                gettimeofday(&start, NULL);
                quickSort(vetor, 0, extensaoVetor);
                gettimeofday(&end, NULL);
                seconds  = end.tv_sec  - start.tv_sec;
                useconds = end.tv_usec - start.tv_usec;
                total_time = (seconds * 1000000 + useconds);
                mediaTempoDeExecucao += total_time;
                free(vetor);
            }
            medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
            return (mediaTempoDeExecucao/10);
            break;

        case 7:
            for(int i = 0; i < 10; i++){
                int *vetor = alocacaoVetor(extensaoVetor);
                if(vetor == NULL){
                    printf("\nErro na alocacao de memoria. Tente novamente.");
                    break;
                }
                gettimeofday(&start, NULL);
                heapSort(vetor, extensaoVetor);
                gettimeofday(&end, NULL);
                seconds  = end.tv_sec  - start.tv_sec;
                useconds = end.tv_usec - start.tv_usec;
                total_time = (seconds * 1000000 + useconds);
                mediaTempoDeExecucao += total_time;
                free(vetor);
            }
            medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
            return (mediaTempoDeExecucao/10);
            break;

        case 8:
            for(int i = 0; i < 10; i++){
                int *vetor = alocacaoVetor(extensaoVetor);
                if(vetor == NULL){
                    printf("\nErro na alocacao de memoria. Tente novamente.");
                    break;
                }
                gettimeofday(&start, NULL);
                radixSort(vetor, extensaoVetor);
                gettimeofday(&end, NULL);
                seconds  = end.tv_sec  - start.tv_sec;
                useconds = end.tv_usec - start.tv_usec;
                total_time = (seconds * 1000000 + useconds);
                mediaTempoDeExecucao += total_time;
                free(vetor);
            }
            medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
            return (mediaTempoDeExecucao/10);
            break;

        case 9:
            for(int i = 0; i < 10; i++){
                int *vetor = alocacaoVetor(extensaoVetor);
                if(vetor == NULL){
                    printf("\nErro na alocacao de memoria. Tente novamente.");
                    break;
                }
                gettimeofday(&start, NULL);
                countingSort(vetor, extensaoVetor);
                gettimeofday(&end, NULL);
                seconds  = end.tv_sec  - start.tv_sec;
                useconds = end.tv_usec - start.tv_usec;
                total_time = (seconds * 1000000 + useconds);
                mediaTempoDeExecucao += total_time;
                free(vetor);
            }
            medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
            return (mediaTempoDeExecucao/10);
            break;

        case 10:
            for(int i = 0; i < 10; i++){
                int *vetor = alocacaoVetor(extensaoVetor);
                if(vetor == NULL){
                    printf("\nErro na alocacao de memoria. Tente novamente.");
                    break;
                }
                gettimeofday(&start, NULL);
                timSort(vetor, extensaoVetor);
                gettimeofday(&end, NULL);
                seconds  = end.tv_sec  - start.tv_sec;
                useconds = end.tv_usec - start.tv_usec;
                total_time = (seconds * 1000000 + useconds);
                mediaTempoDeExecucao += total_time;
                free(vetor);
            }
            medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
            return (mediaTempoDeExecucao/10);
            break;

        default:
            return 0;
            break;
    }
}

void mergeSort(int *v, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(v, inicio, meio);
        mergeSort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }
}

void merge(int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (int*) malloc(tamanho * sizeof(int));
    if(temp == NULL){
        printf("Erro na alocacao de memoria. Tente novamente\n");
        return;
    }

    for(i = 0; i < tamanho; i++){
        if(!fim1 && !fim2){
            if(v[p1] < v[p2]){
                temp[i] = v[p1++];
            } else {
                temp[i] = v[p2++];
            }
            if(p1 > meio){
                fim1 = 1;
            }
            if(p2 > fim){
                fim2 = 1;
            }
        } else {
            if(!fim1){
                temp[i] = v[p1++];
            } else {
                temp[i] = v[p2++];
            }
        }
    }
    for(j = 0, k = inicio; j < tamanho; j++, k++){
        v[k] = temp[j];
    }
    free(temp);
}

int particiona(int *V, int inicio, int final ){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while(esq < dir){
        while(esq <= final && V[esq] <= pivo)
            esq++;

        while(dir >= 0 && V[dir] > pivo)
            dir--;

        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}

void quickSort(int *V, int inicio, int fim) {
    int pivo;
    if(fim > inicio){
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
    }
}

int* countingSort(int array[], int tamanho) {
    int maior_valor = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior_valor) {
            maior_valor = array[i];
        }
    }
    int *aux = (int *)calloc(maior_valor + 1, sizeof(int));
    int *saida = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        aux[array[i]]++;
    }
    for (int i = 1; i <= maior_valor; i++) {
        aux[i] += aux[i - 1];
    }
    for (int i = tamanho - 1; i >= 0; i--) {
        saida[aux[array[i]] - 1] = array[i];
        aux[array[i]]--;
    }
    free(aux);
    return saida;
}

void timSort(int *vetor, int n) {
    int minRun = minRunLength(n);
    for (int start = 0; start < n; start += minRun) {
        int end = (start + minRun - 1 < n - 1) ? (start + minRun - 1) : (n - 1);
        insertionSortTim(vetor, start, end);
    }
    int size = minRun;
    while (size < n) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? (left + 2 * size - 1) : (n - 1);
            merge(vetor, left, mid, right);
        }
        size = 2 * size;
    }
}

int minRunLength(int n) {
    int r = 0;
    while (n >= MIN_RUN) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

void insertionSortTim(int *v, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int aux = v[i];
        int j = i;
        while (j > left && aux < v[j - 1]) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
    }
}

void shellsort(int *vetor, int tamanho) {
    int intervalo, i, j, temp;
    for (intervalo = tamanho / 2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < tamanho; i++) {
            temp = vetor[i];
            for (j = i; j >= intervalo && vetor[j - intervalo] > temp; j -= intervalo) {
                vetor[j] = vetor[j - intervalo];
            }
            vetor[j] = temp;
        }
    }
}

void bubbleSort(int *v, int n){
    int i, continua, aux, fim = n;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
}

void selectionSort(int *v, int n){
    int i, j, menor, troca;
    for(i = 0; i < n; i++){
        menor = i;
        for(j = i; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
   }
}

void heapify(int *vetor, int tamanho, int i) {
    int maior = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < tamanho && vetor[left] > vetor[maior])
        maior = left;
    if (right < tamanho && vetor[right] > vetor[maior])
        maior = right;
    if (maior != i) {
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;
        heapify(vetor, tamanho, maior);
    }
}

void heapSort(int *vetor, int tamanho) {
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(vetor, tamanho, i);
    for (int i = tamanho - 1; i > 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        heapify(vetor, i, 0);
    }
}

void insertionSort(int *v, int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j - 1]); j--){
            v[j] = v[j - 1];
        }
        v[j] = aux;
    }
}

int getMax(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int *arr, int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

void radixSort(int *arr, int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}
