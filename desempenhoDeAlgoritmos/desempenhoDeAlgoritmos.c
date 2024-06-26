#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <string.h>
#include "desempenhoDeAlgoritmos.h"


//Define do TIMSORT
#define RUN 60

/** MENU PRINCIPAL **/
void escolhaMenuAlgoritmos(){
    printf(
        "\n\t======== SELECIONE UM ALGORITMO ========\n\n"
        "\t\t 1. BubbleSort\n"
        "\t\t 2. InsertionSort\n"
        "\t\t 3. SelectionSort\n"
        "\t\t 4. ShellSort\n"
        "\t\t 5. MergeSort\n"
        "\t\t 6. QuickSort\n"
        "\t\t 7. HeapSort\n"
        "\t\t 8. RadixSort\n"
        "\t\t 9. CountigSort\n"
        "\t\t 10. TimSort\n\n"
        "\t\t 11. Encerrar\n\n"
        "\t========================================\n\n"
        "\tNumero: "
    );
}

/** MENU SEGUND�RIO **/
void escolhaMenuElementos(int escolhaAlgoritmo){
    char* nomeDoAlgoritmo = nomeAlgoritmo(escolhaAlgoritmo);
    if(nomeDoAlgoritmo == NULL){
        printf("\n\tErro na escolha do nome do algoritmo. Tente novamente.\n\n");
        system("pause");
        return;
    }

    printf(
        "\n\t======== QUANTIDADE DE ELEMENTOS - %s ========\n\n"
        "\t\t 1. 1.000\n"
        "\t\t 2. 5.000\n"
        "\t\t 3. 10.000\n"
        "\t\t 4. 20.000\n"
        "\t\t 5. 50.000\n"
        "\t\t 6. 100.000\n\n"
        "\t\t 7. Voltar\n"
        , nomeDoAlgoritmo);
    extensorDivisoria(nomeDoAlgoritmo);
    printf("\n\tNumero: ");
}

/** AUMENTA O TAMANHO DO DIVISOR COM BASE NO NOME DO ALGORITMO **/
void extensorDivisoria(char* nomeDoAlgoritmo){
    //Verifica o tamanho da string que compoe o nome do algoritmo.
    int tamanho_nomeDoAlgoritmo = strlen(nomeDoAlgoritmo), tamanho_base = 44;
    char *extensao = (char *)calloc((tamanho_nomeDoAlgoritmo + tamanho_base + 1), sizeof(char));

    if(!extensao){
        printf("\n\tErro na alocacao de memoria. Tente novamente.\n\n");
        system("pause");
        return;
    }
    //Com base no tamanho do nome do algoritmo, a divisoria e alocada no vetor.
    for(int i = 0; i < (tamanho_base + tamanho_nomeDoAlgoritmo); i++){
        extensao[i] = '=';
    }
    printf("\n\t%s\n", extensao);
    free(extensao);
}

/** ALOCA��O DO VETOR DIN�MICO **/
int *alocacaoVetor(int extensaoVetor){
    int* vetor = (int*) calloc(extensaoVetor,sizeof(int));
    if(vetor == NULL){
        return 0;
    }
    /* Iniciando o gerador de n�meros aleatorios rand() e configurando a semente
    de srand para o tempo atual para sempre gerar n�meros diferentes */
    srand(time(NULL));
    for(int i = 0; i < extensaoVetor; i++){
        vetor[i] = rand() % extensaoVetor; // Preenchendo o vetor com n�meros de 0 - extensaoVetor
    }
    return vetor;
}

/** ESCOLHA DA QUANTIDADE A SER ORDENADO **/
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

/** PONTEIRO PARA A ESCOLHA DO ALGORITMO **/
void* escolheAlgoritmo(int escolhaAlgoritmo){
    switch(escolhaAlgoritmo){
        case 1: return bubbleSort;
        case 2: return insertionSort;
        case 3: return selectionSort;
        case 4: return shellsort;
        case 5: return mergeSort;
        case 6: return quickSort;
        case 7: return heapSort;
        case 8: return radixSort;
        case 9: return countingSort;
        case 10: return timSort;
        default: return 0;
    }
}

/** NOME DO ALGORIMO SELECIONADO **/
char* nomeAlgoritmo(int escolhaAlgoritmo){
    switch(escolhaAlgoritmo){
        case 1: return "BubbleSort";
        case 2: return "InsertionSort";
        case 3: return "SelectionSort";
        case 4: return "Shellsort";
        case 5: return "MergeSort";
        case 6: return "QuickSort";
        case 7: return "HeapSort";
        case 8: return "RadixSort";
        case 9: return "CountingSort";
        case 10: return "TimSort";
        default: return NULL;
    }
}

/** ALOCA��O DO MELHOR VETOR **/
int* melhorVetor(int extensaoVetor){
    int* vetorMelhorCaso = (int*) calloc(extensaoVetor,sizeof(int));
    if(vetorMelhorCaso == NULL){
        printf("\n\tErro na alocacao de memoria. Tente novamente.\n\n");
        system("pause");
        return 0;
    }
    for(int i = 0; i < extensaoVetor; i++){
        vetorMelhorCaso[i] = i;
    }
    return vetorMelhorCaso;
}

/** ALOCA��O DO PIOR VETOR **/
int* piorVetor(int extensaoVetor){
    int* vetorPiorCaso = (int*) calloc(extensaoVetor,sizeof(int));
    if(vetorPiorCaso == NULL){
        printf("\n\tErro na alocacao de memoria. Tente novamente.\n\n");
        system("pause");
        return 0;
    }
    for(int i = extensaoVetor, k = 0; i > 0 ; i--, k++){
        vetorPiorCaso[k] = i;
    }
    return vetorPiorCaso;
}

double calcularTempo(struct timeval start, struct timeval end) {
    long seconds, useconds;
    double total_time;

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    total_time = (seconds * 1000000 + useconds);

    return total_time;
}

/** COLETA O MELHOR E PIOR CEN�RIO DE ORDENA��O **/
void medicaoDeTempoMelhorPiorCaso(int escolhaAlgoritmo, int escolhaElementos){
    struct timeval start, end; //biblioteca <sys/time.h>
    double total_time;

    int extensaoVetor = escolheValor(escolhaElementos);
    if(!extensaoVetor){
        printf("\n\tErro na escolha dos dados. Tente novamente.\n\n");
        system("pause");
        return;
    }

    char* nomeDoAlgoritmo = nomeAlgoritmo(escolhaAlgoritmo);
    if(nomeDoAlgoritmo == NULL){
        printf("\n\tErro na escolha do nome do algoritmo. Tente novamente.\n\n");
        system("pause");
        return;
    }

    int* vetorMelhorCaso = melhorVetor(extensaoVetor);
    if(!vetorMelhorCaso){
        return;
    }

    int* vetorPiorCaso = piorVetor(extensaoVetor);
    if(!vetorPiorCaso){
        return;
    }

    // Algoritmos Merge e Quick precisam de mais argumentos que os outros
    if(escolhaAlgoritmo == 5 || escolhaAlgoritmo == 6){
        // Cria-se um ponteiro para a fun��o
        void (*algoritmo)(int*, int, int);
        algoritmo = escolheAlgoritmo(escolhaAlgoritmo);
        if(!algoritmo){
            printf("\n\tErro na escolha do algoritmo. Tente novamente.\n\n");
            system("pause");
            return;
        }
        // pega o tempo inicial
        gettimeofday(&start, NULL);
        //executa o algoritmo selecionado
        algoritmo(vetorMelhorCaso, 0, extensaoVetor);
        gettimeofday(&end, NULL);
        //realiza o calculo
        total_time = calcularTempo(start, end);
        printf("\tMelhor tempo de ordenacao do %s: %.3f microssegundos; \n\tIsso equivale a %.3f segundos.\n\n\n", nomeDoAlgoritmo, total_time, total_time/1000000);
        free(vetorMelhorCaso);

        gettimeofday(&start, NULL);
        algoritmo(vetorPiorCaso, 0, extensaoVetor);
        gettimeofday(&end, NULL);
        total_time = calcularTempo(start, end);
        printf("\tPior tempo de ordenacao do %s: %.3f microssegundos; \n\tIsso equivale a %.3f segundos.\n", nomeDoAlgoritmo, total_time, total_time/1000000);
        free(vetorPiorCaso);
    }else{
        void (*algoritmo)(int*, int);
        algoritmo = escolheAlgoritmo(escolhaAlgoritmo);
        if(!algoritmo){
            printf("\n\tErro na escolha do algoritmo. Tente novamente.\n\n");
            system("pause");
            return;
        }

        gettimeofday(&start, NULL);
        algoritmo(vetorMelhorCaso, extensaoVetor);
        gettimeofday(&end, NULL);
        total_time = calcularTempo(start, end);
        printf("\tMelhor tempo de ordenacao do %s: %.3f microssegundos; \n\tIsso equivale a %.3f segundos.\n\n\n", nomeDoAlgoritmo, total_time, total_time/1000000);
        free(vetorMelhorCaso);

        gettimeofday(&start, NULL);
        algoritmo(vetorPiorCaso, extensaoVetor);
        gettimeofday(&end, NULL);
        total_time = calcularTempo(start, end);
        printf("\tPior tempo de ordenacao do %s: %.3f microssegundos; \n\tIsso equivale a %.3f segundos.\n", nomeDoAlgoritmo, total_time, total_time/1000000);
        free(vetorPiorCaso);
    }
}

/** FUN��O CHAMADA NO ARQUIVO PRINCIPAL / COLETA O TEMPO M�DIO DE ORDENA��O DE 10 VETORES ALEAT�RIOS **/
void medicaoDeTempo(int escolhaAlgoritmo, int escolhaElementos){
    struct timeval start, end; //sys/time.h
    double total_time, mediaTempoDeExecucao = 0;

    char* nomeDoAlgoritmo = nomeAlgoritmo(escolhaAlgoritmo);
    if(nomeDoAlgoritmo == NULL){
        printf("\n\tErro na escolha do nome do algoritmo. Tente novamente.\n\n");
        system("pause");
        return;
    }

    int extensaoVetor = escolheValor(escolhaElementos);
    if(!extensaoVetor){
        printf("\n\tErro na escolha dos dados. Tente novamente.\n\n");
        system("pause");
        return;
    }

    if(escolhaAlgoritmo == 5 || escolhaAlgoritmo == 6){
        void (*algoritmo)(int*, int, int);
        algoritmo = escolheAlgoritmo(escolhaAlgoritmo);
        if(!algoritmo){
            printf("\n\tErro na escolha do algoritmo. Tente novamente.\n\n");
            system("pause");
            return;
        }

        for(int i = 0; i < 10; i++){
            int *vetor = alocacaoVetor(extensaoVetor);
            if(!vetor){
                printf("\n\tErro na alocacao de memoria. Tente novamente.\n\n");
                return;
            }

            gettimeofday(&start, NULL);
            algoritmo(vetor, 0, extensaoVetor);
            gettimeofday(&end, NULL);
            total_time = calcularTempo(start, end);
            mediaTempoDeExecucao += total_time;
            free(vetor);
        }
        extensorDivisoria(nomeDoAlgoritmo);
        printf("\n\tTempo medio de ordenacao do %s: %.3f microssegundos; \n\tIsso equivale a %.3f segundos.\n\n\n", nomeDoAlgoritmo, (mediaTempoDeExecucao / 10), (mediaTempoDeExecucao / 10)/1000000);
        medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
        extensorDivisoria(nomeDoAlgoritmo);
        printf("\n");
    }else{
        void (*algoritmo)(int*, int);
        algoritmo = escolheAlgoritmo(escolhaAlgoritmo);
        if(!algoritmo){
            printf("\n\tErro na escolha do algoritmo. Tente novamente.\n\n");
            system("pause");
            return;
        }

        for(int i = 0; i < 10; i++){
            int *vetor = alocacaoVetor(extensaoVetor);
            if(!vetor){
                printf("\n\tErro na alocacao de memoria. Tente novamente.\n\n");
                return;
            }
            gettimeofday(&start, NULL);
            algoritmo(vetor, extensaoVetor);
            gettimeofday(&end, NULL);
            total_time = calcularTempo(start, end);
            mediaTempoDeExecucao += total_time;
            free(vetor);
        }
        extensorDivisoria(nomeDoAlgoritmo);
        printf("\n\tTempo medio de ordenacao do %s: %.3f microssegundos; \n\tIsso equivale a %.3f segundos.\n\n\n", nomeDoAlgoritmo, (mediaTempoDeExecucao / 10), (mediaTempoDeExecucao / 10)/1000000);
        medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
        extensorDivisoria(nomeDoAlgoritmo);
        printf("\n");
    }
}

/** ALGORITMO BUBBLESORT **/
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

/** ALGORITMO INSERTIONSORT **/
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

/** ALGORITMO SELECTIONSORT **/
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

/** ALGORITMO SHELLSORT **/
void shellsort(int *vetor, int tamanho) {
    int intervalo, i, j, temp;
    for (intervalo = 1; intervalo < tamanho / 9; intervalo = 3 * intervalo + 1) {
        for (i = intervalo; i < tamanho; i++) {
            temp = vetor[i];
            for (j = i; j >= intervalo && vetor[j - intervalo] > temp; j -= intervalo) {
                vetor[j] = vetor[j - intervalo];
            }
            vetor[j] = temp;
        }
    }
}

/** ALGORITMO MERGE **/
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

/** ALGORITMO QUICK **/
void quickSort(int *vetor, int esquerda, int direita) {
    int i, j, pivo, aux;
    i = esquerda;
    j = direita;
    pivo = vetor[(esquerda + direita) / 2];

    while (i <= j) {
        while (vetor[i] < pivo && i < direita) {
            i++;
        }
        while (vetor[j] > pivo && j > esquerda) {
            j--;
        }
        if (i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if (j > esquerda) {
        quickSort(vetor, esquerda, j);
    }
    if (i < direita) {
        quickSort(vetor, i, direita);
    }
}

/** ALGORITMO HEAPSORT **/
void heapSort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        trocar(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(int *arr, int n, int i) {
    int iMaior = i;
    int iEsq = 2 * i + 1;
    int iDir = 2 * i + 2;

    if (iEsq < n && arr[iEsq] > arr[iMaior])
        iMaior = iEsq;

    if (iDir < n && arr[iDir] > arr[iMaior])
        iMaior = iDir;

    if (iMaior != i) {
        trocar(&arr[i], &arr[iMaior]);
        heapify(arr, n, iMaior);
    }
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/** ALGORITMO RADIXSORT **/
void radixSort(int *vetor, int tamanho){
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }
    free(b);
}

/** ALGORITMO COUNTINGSORT **/
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

/** ALGORITMO TIMSORT **/
void timSort(int *arr, unsigned int size) {
    if (arr == NULL || size <= 1) return;
    for (int i=0; i < size; i+=RUN) {
        insertionTim(arr, i, minsort(i+RUN-1, size-1));
    }

    int* temp = (int*)malloc(sizeof(int)*size);


    int l, m, r, n;
    for (n=RUN; n < size; n*=2) {
        for (l=0; l < size; l+=2*n) {
            m = l+n-1;
            r = minsort(l+2*n-1, size-1);
            if (m<r) {
                mergeTim(arr, temp, l, m, r);
            }
        }
    }
    free(temp);
}

int minsort(int arg1, int arg2) {
    if (arg1 <= arg2) {
        return arg1;
    } else {
        return arg2;
    }
}

void insertionTim(int *arr, int l, int r) {
    if (arr == NULL || l>=r) return;

    int key;
    int i, j;
    for (i=l+1; i<=r; i++) {
        key = arr[i];
        j = i-1;
        while (j>=l && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}

void mergeTim(int arr[], int temp[], int l, int m, int r) {
    if (arr == NULL || temp == NULL) return;
    if (l > m || m+1 > r) return;

    int i = l;
    int j = m + 1;
    int start = l;

    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            temp[start++] = arr[i++];
        } else if (arr[i] == arr[j]) {

            temp[start++] = arr[i++];
            temp[start++] = arr[j++];
        } else {
            temp[start++] = arr[j++];
        }

    }

    while (i <= m) {
        temp[start++] = arr[i++];
    }


    while (j <= r) {
        temp[start++] = arr[j++];
    }

    for (i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}
