void escolhaMenuAlgoritmos();

void escolhaMenuElementos();

int *alocacaoVetor(int extensaoVetor);

int escolheValor(int escolhaElementos);

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

int particiona(int *V, int inicio, int final );

void quickSort(int *V, int inicio, int fim);

void heapify(int *vetor, int tamanho, int i);

void heapSort(int *vetor, int tamanho);

void countSort(int *arr, int n, int exp);

int getMax(int *arr, int n);

void radixSort(int *arr, int n);

int* countingSort(int array[], int tamanho);

void timSort(int *v, int n);

int minRunLength(int n);

void insertionSortTim(int *v, int left, int right);

void mergeTim(int *v, int l, int m, int r);
