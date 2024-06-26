#include <sys/time.h>

void escolhaMenuAlgoritmos();

void escolhaMenuElementos(int escolhaAlgoritmo);

void extensorDivisoria(char* nomeDoAlgoritmo);

int *alocacaoVetor(int extensaoVetor);

int escolheValor(int escolhaElementos);

void* escolheAlgoritmo(int escolhaAlgoritmo);

char* nomeAlgoritmo(int escolhaAlgoritmo);

int* melhorVetor(int extensaoVetor);

int* piorVetor(int extensaoVetor);

double calcularTempo(struct timeval start, struct timeval end);

void medicaoDeTempoMelhorPiorCaso(int escolhaAlgoritmo, int escolhaElementos);

void medicaoDeTempo(int escolhaAlgoritmo, int escolhaElementos);

void bubbleSort(int *vetor, int tamanho);

void insertionSort(int *v, int n);

void selectionSort(int *vetor, int tamanho);

void shellsort(int *vetor, int tamanho);

void mergeSort(int *v, int inicio, int fim);

void merge(int *v, int inicio, int meio, int fim);

void quickSort(int *V, int esquerda, int direita);

void heapSort(int *arr, int n);

void heapify(int *arr, int n, int i);

void trocar(int *a, int *b);

void radixSort(int *vetor, int tamanho);

int* countingSort(int array[], int tamanho);

void timSort(int *arr, unsigned int size);

int minsort(int arg1, int arg2);

void insertionTim(int *arr, int l, int r);

void mergeTim(int arr[], int temp[], int l, int m, int r);
