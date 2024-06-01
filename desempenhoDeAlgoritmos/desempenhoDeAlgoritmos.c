#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <string.h>
#include "desempenhoDeAlgoritmos.h"

#define MIN_RUN 32
#define TAMANHO 300

/** EXPLICA��O: Ol� pessoal! Espero que esteja tudo bem com voc�s (obs: Gabi, n�o me mata). Venho aqui falar um pouco sobre o
c�digo e como ocorre a sua l�gica. Para come�ar, no "main" ocorre a escolha b�sica do menu, onde o usu�rio escolhe qual dos algoritmos
ele deseja, digitando o n�mero associado a cada fun��o. Caso ele escolha um n�mero ou uma letra incompat�vel, o programa exibi um alerta e impede que o usu�rio
prossiga no c�digo. O mesmo se aplica � sele��o da quantidade de elementos escolhidos para ordena��o. Pois bem, se todos os inputs estiverem
corretos, o programa chama a seguinte fun��o:

"medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);"

passando como argumentos o algoritmo escolhido e a escolha dos elementos. Feito isso, entramos na fun��o que gere todo o programa. Voc�s devem
estar se perguntando o que s�o as fun��es de switch case que retornam n�meros, algoritmos e nomes de fun��es, e agora vou explicar o motivo dessa l�gica.
Era uma vez o Pedro Lauton pensando em como fazer para selecionar os diversos algoritmos que temos nesse projeto. Ele pensou em fazer um switch case para
cada um, e foi o que ele fez. Nesse switch case, Pedro reparou que o c�digo em cada case era o mesmo para quase todas as fun��es, a �nica coisa que mudava
era o nome da fun��o que estava sendo chamada. Assim, t�nhamos 10 cases iguais em que a �nica diferen�a era s� as chamadas das fun��es. Pensando nisso, o nosso
pequeno Pedro Lauton se perguntou se n�o havia algum m�todo de fazer apenas um �nico bloco gen�rico que mudasse apenas a chamada da fun��o de acordo com o valor
escolhido pelo usu�rio. Ap�s um per�odo de pesquisa, Pedro encontrou algo que lhe servia perfeitamente, um ponteiro para fun��o! Esse ponteiro era perfeito, porque
o mesmo bloco de c�digo podia ativar diferentes fun��es e, assim, economizar um grande switch case (economizou cerca de 300 linhas de c�digo, o Pedro ficou bem feliz com essa otimiza��o!).
Para exemplificar, abaixo ser� mostrado o ponteiro:

"void (*algoritmo)(int*, int);"

Ele � do tipo void, pois as fun��es que ele referencia tamb�m s�o. No "(*algoritmo)" passamos o ponteiro da fun��o e logo ap�s explanamos os argumentos que
essa fun��o vai ter. Assim, para escolher a fun��o que ser� referenciada pelo "(*algoritmo)" usamos outra fun��o:

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
        default: return NULL;
    }
}

De acordo com a entrada do usu�rio, o endere�o de uma fun��o � devolvido, tornando o sonho do pequeno Pedro Lauton realizado, o sonho de ter um bloco gen�rico
que lhe permitisse ter menos linhas de c�digo. Outras fun��es tamb�m foram feitas para referenciar algo, como a convers�o do n�mero digitado pelo usu�rio em
quantidades plaus�veis para ordena��o, como mostra a fun��o abaixo:

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

E por fim, temos a seguinte fun��o:

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

Ela se torna necess�ria uma vez que o bloco gen�rico � est�tico e somente troca a fun��o com base no ponteiro. Ent�o, para trocar o nome da fun��o de
acordo com a fun��o escolhida, foi feito um c�digo que retorna a string com o devido nome da fun��o. N�o � demais? Vale ressaltar que duas fun��es exigem mais
do que dois argumentos (Merge e Quick), por isso foi feita uma exce��o para as duas, onde o ponteiro comporta tr�s argumentos:

"void (*algoritmo)(int*, int, int);"

O restante do c�digo � aloca��o de vetores e os algoritmos de ordena��o, acredito que n�o precisam ser explicados. Dessa forma, creio que as principais d�vidas tenham
sido sanadas. Qualquer coisa, estou � disposi��o para mais um Contos de Pedro Lauton!

At� mais!
**/


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
        "\t==========================================\n\n"
        "\tNumero: "
    );
}

/** MENU SEGUND�RIO **/
void escolhaMenuElementos(){
    printf(
        "\n\t======== QUANTIDADE DE ELEMENTOS ========\n\n"
        "\t\t 1. 1.000\n"
        "\t\t 2. 5.000\n"
        "\t\t 3. 10.000\n"
        "\t\t 4. 20.000\n"
        "\t\t 5. 50.000\n"
        "\t\t 6. 100.000\n\n"
        "\t\t 7. Voltar\n\n"
        "\t===========================================\n\n"
        "\tNumero: "
    );
}

/** ALOCA��O DO VETOR **/
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

/** ESCOLHA DO VALOR A SER ORDENADO **/
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

/** ESCOLHA DO ALGORITMO **/
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
        default: return NULL;
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
        return NULL;
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
        return NULL;
    }
    for(int i = extensaoVetor, k = 0; i > 0 ; i--, k++){
        vetorPiorCaso[k] = i;
    }
    return vetorPiorCaso;
}

/** COLETA O MELHOR E PIOR CEN�RIO DE ORDENA��O **/
void medicaoDeTempoMelhorPiorCaso(int escolhaAlgoritmo, int escolhaElementos){
    struct timeval start, end; //biblioteca <sys/time.h>
    long seconds, useconds;
    double total_time;

    int extensaoVetor = escolheValor(escolhaElementos);
    if(extensaoVetor == 0){
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
    if(vetorMelhorCaso == NULL){
        return;
    }

    int* vetorPiorCaso = piorVetor(extensaoVetor);
    if(vetorPiorCaso == NULL){
        return;
    }

    if(escolhaAlgoritmo == 5 || escolhaAlgoritmo == 6){
        void (*algoritmo)(int*, int, int);
        algoritmo = escolheAlgoritmo(escolhaAlgoritmo);
        if(algoritmo == NULL){
            printf("\n\tErro na escolha do algoritmo. Tente novamente.\n\n");
            system("pause");
            return;
        }

        gettimeofday(&start, NULL);
        algoritmo(vetorMelhorCaso, 0, extensaoVetor);
        gettimeofday(&end, NULL);
        seconds  = end.tv_sec  - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        total_time = (seconds * 1000000 + useconds);
        printf("\tMelhor tempo de ordenacao do %s: %.3f microssegundos\n", nomeDoAlgoritmo, total_time);
        free(vetorMelhorCaso);

        gettimeofday(&start, NULL);
        algoritmo(vetorPiorCaso, 0, extensaoVetor);
        gettimeofday(&end, NULL);
        seconds  = end.tv_sec  - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        total_time = (seconds * 1000000 + useconds);
        printf("\tPior tempo de ordenacao do %s: %.3f microssegundos\n\n", nomeDoAlgoritmo, total_time);
        free(vetorPiorCaso);
    }else{
        void (*algoritmo)(int*, int);
        algoritmo = escolheAlgoritmo(escolhaAlgoritmo);
        if(algoritmo == NULL){
            printf("\n\tErro na escolha do algoritmo. Tente novamente.\n\n");
            system("pause");
            return;
        }

        gettimeofday(&start, NULL);
        algoritmo(vetorMelhorCaso, extensaoVetor);
        gettimeofday(&end, NULL);
        seconds  = end.tv_sec  - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        total_time = (seconds * 1000000 + useconds);
        printf("\tMelhor tempo de ordenacao do %s: %.3f microssegundos\n", nomeDoAlgoritmo, total_time);
        free(vetorMelhorCaso);

        gettimeofday(&start, NULL);
        algoritmo(vetorPiorCaso, extensaoVetor);
        gettimeofday(&end, NULL);
        seconds  = end.tv_sec  - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        total_time = (seconds * 1000000 + useconds);
        printf("\tPior tempo de ordenacao do %s: %.3f microssegundos\n\n", nomeDoAlgoritmo, total_time);
        free(vetorPiorCaso);
    }
}

/** FUN��O CHAMADA NO ARQUIVO PRINCIPAL / COLETA O TEMPO M�DIO DE ORDENA��O DE 10 VETORES ALEAT�RIOS **/
void medicaoDeTempo(int escolhaAlgoritmo, int escolhaElementos){
    struct timeval start, end; //sys/time.h
    long seconds, useconds;
    double total_time, mediaTempoDeExecucao = 0;

    char* nomeDoAlgoritmo = nomeAlgoritmo(escolhaAlgoritmo);
    if(nomeDoAlgoritmo == NULL){
        printf("\n\tErro na escolha do nome do algoritmo. Tente novamente.\n\n");
        system("pause");
        return;
    }

    int extensaoVetor = escolheValor(escolhaElementos);
    if(extensaoVetor == 0){
        printf("\n\tErro na escolha dos dados. Tente novamente.\n\n");
        system("pause");
        return;
    }

    if(escolhaAlgoritmo == 5 || escolhaAlgoritmo == 6){
        void (*algoritmo)(int*, int, int);
        algoritmo = escolheAlgoritmo(escolhaAlgoritmo);
        if(algoritmo == NULL){
            printf("\n\tErro na escolha do algoritmo. Tente novamente.\n\n");
            system("pause");
            return;
        }

        for(int i = 0; i < 10; i++){
            int *vetor = alocacaoVetor(extensaoVetor);
            if(vetor == NULL){
                printf("\n\tErro na alocacao de memoria. Tente novamente.\n\n");
                return;
            }

            gettimeofday(&start, NULL);
            algoritmo(vetor, 0, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            mediaTempoDeExecucao += total_time;
            free(vetor);
        }
        printf("\n\t===========================================\n");
        printf("\n\tTempo medio de ordenacao do %s: %.3f microssegundos\n\n", nomeDoAlgoritmo, (mediaTempoDeExecucao / 10));
        medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
        printf("\t===========================================\n\n");
    }else{
        void (*algoritmo)(int*, int);
        algoritmo = escolheAlgoritmo(escolhaAlgoritmo);
        if(algoritmo == NULL){
            printf("\n\tErro na escolha do algoritmo. Tente novamente.\n\n");
            system("pause");
            return;
        }

        for(int i = 0; i < 10; i++){
            int *vetor = alocacaoVetor(extensaoVetor);
            if(vetor == NULL){
                printf("\n\tErro na alocacao de memoria. Tente novamente.\n\n");
                return;
            }
            gettimeofday(&start, NULL);
            algoritmo(vetor, extensaoVetor);
            gettimeofday(&end, NULL);
            seconds  = end.tv_sec  - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            total_time = (seconds * 1000000 + useconds);
            mediaTempoDeExecucao += total_time;
            free(vetor);
        }
        printf("\n\t===========================================\n");
        printf("\n\tTempo medio de ordenacao do %s: %.3f microssegundos\n\n", nomeDoAlgoritmo, (mediaTempoDeExecucao / 10));
        medicaoDeTempoMelhorPiorCaso(escolhaAlgoritmo, escolhaElementos);
        printf("\t===========================================\n\n");
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

/** ALGORITMO QUICKSORT **/
void quickSort(int *V, int inicio, int fim) {
    int pivo;
    if(fim > inicio){
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
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

int minRunLength(int n) {
    int r = 0;
    while (n >= MIN_RUN) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

/** ALGORITMO INSERTIONSORT **/
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

int getMax(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/** ALGORITMO COUNTSORT **/
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

/** ALGORITMO REDIXSORT **/
void radixSort(int *arr, int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
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
