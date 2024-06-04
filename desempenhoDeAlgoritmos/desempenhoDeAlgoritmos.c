#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <string.h>
#include "desempenhoDeAlgoritmos.h"


//Define do TIMSORT
#define MIN_RUN 60

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

/** MENU SEGUNDÁRIO **/
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

/** ALOCAÇÃO DO VETOR DINÂMICO **/
int *alocacaoVetor(int extensaoVetor){
    int* vetor = (int*) calloc(extensaoVetor,sizeof(int));
    if(vetor == NULL){
        return 0;
    }
    /* Iniciando o gerador de números aleatorios rand() e configurando a semente
    de srand para o tempo atual para sempre gerar números diferentes */
    srand(time(NULL));
    for(int i = 0; i < extensaoVetor; i++){
        vetor[i] = rand() % 100; // Preenchendo o vetor com números de 0 - 100
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

/** ALOCAÇÃO DO MELHOR VETOR **/
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

/** ALOCAÇÃO DO PIOR VETOR **/
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

/** COLETA O MELHOR E PIOR CENÁRIO DE ORDENAÇÃO **/
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
        // Cria-se um ponteiro para a função
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
        printf("\tMelhor tempo de ordenacao do %s: %.3f microssegundos\n", nomeDoAlgoritmo, total_time);
        free(vetorMelhorCaso);

        gettimeofday(&start, NULL);
        algoritmo(vetorPiorCaso, 0, extensaoVetor);
        gettimeofday(&end, NULL);
        total_time = calcularTempo(start, end);
        printf("\tPior tempo de ordenacao do %s: %.3f microssegundos\n", nomeDoAlgoritmo, total_time);
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
        printf("\tMelhor tempo de ordenacao do %s: %.3f microssegundos\n", nomeDoAlgoritmo, total_time);
        free(vetorMelhorCaso);

        gettimeofday(&start, NULL);
        algoritmo(vetorPiorCaso, extensaoVetor);
        gettimeofday(&end, NULL);
        total_time = calcularTempo(start, end);
        printf("\tPior tempo de ordenacao do %s: %.3f microssegundos\n", nomeDoAlgoritmo, total_time);
        free(vetorPiorCaso);
    }
}

/** FUNÇÃO CHAMADA NO ARQUIVO PRINCIPAL / COLETA O TEMPO MÉDIO DE ORDENAÇÃO DE 10 VETORES ALEATÓRIOS **/
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
        printf("\n\tTempo medio de ordenacao do %s: %.3f microssegundos\n\n", nomeDoAlgoritmo, (mediaTempoDeExecucao / 10));
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
        printf("\n\tTempo medio de ordenacao do %s: %.3f microssegundos\n\n", nomeDoAlgoritmo, (mediaTempoDeExecucao / 10));
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

/** ALGORITMO QUICKSORT **/
// Versão mais eficiente do quick - 2 elementos são movimentados por vez
int particiona(int *V, int inicio, int final){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    //pivo é a mediana - elemento usado para comparações
    pivo = (V[inicio] + V[final] + V[(inicio + final) / 2]) / 3;
    while(esq < dir){
        while(esq < final && V[esq] <= pivo)
            esq++;
        while(esq < dir && V[dir] > pivo)
            dir--;

        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
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

/** ALGORITMO HEAPSORT **/
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

/** ALGORITMO REDIXSORT **/
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
int getMax(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void radixSort(int *arr, int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
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
            mergeTim(vetor, left, mid, right);
        }
        size = 2 * size;
    }
}
/** ALGORITMO MERGE do TimSort **/
void mergeTim(int *v, int l, int m, int r) {
    int len1 = m - l + 1;
    int len2 = r - m;
    int *left = (int *)malloc(len1 * sizeof(int));
    int *right = (int *)malloc(len2 * sizeof(int));
    for (int i = 0; i < len1; i++)
        left[i] = v[l + i];
    for (int j = 0; j < len2; j++)
        right[j] = v[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j])
            v[k++] = left[i++];
        else
            v[k++] = right[j++];
    }
    while (i < len1)
        v[k++] = left[i++];
    while (j < len2)
        v[k++] = right[j++];
    free(left);
    free(right);
}
