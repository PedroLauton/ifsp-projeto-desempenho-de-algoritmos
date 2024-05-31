#include <stdio.h>
#include <stdlib.h>
#include "desempenhoDeAlgoritmos.h"

int main()
{
    int escolhaAlgoritmo = 0;
    do{
        system("cls");
        int escolhaElementos = 0;
        escolhaAlgoritmo = 0;
        escolhaMenuAlgoritmos();
        scanf("%d", &escolhaAlgoritmo);
        fflush(stdin);

        switch(escolhaAlgoritmo){
            case 1:
                while(!(escolhaElementos >= 1 && escolhaElementos <= 7)){
                    system("cls");
                    escolhaMenuElementos();
                    scanf("%d", &escolhaElementos);
                    if(escolhaElementos < 1 || escolhaElementos > 7){
                        printf("\nValor incoerente. Por favor, escolha novamente.\n\n");
                        system("pause");
                        fflush(stdin);
                    }
                    if(escolhaElementos == 7){
                        continue;
                    }
                    double tempoDeExecucao = medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);
                    printf("\nTempo medio de ordenacao do BubbleSort: %.3f microssegundos\n\n", tempoDeExecucao);
                    fflush(stdin);
                    system("pause");
                }
                break;

            case 2:
                while(!(escolhaElementos >= 1 && escolhaElementos <= 7)){
                    system("cls");
                    escolhaMenuElementos();
                    scanf("%d", &escolhaElementos);
                    if(escolhaElementos < 1 || escolhaElementos > 7){
                        printf("\nValor incoerente. Por favor, escolha novamente.\n\n");
                        system("pause");
                        fflush(stdin);
                    }
                    if(escolhaElementos == 7){
                        continue;
                    }
                    double tempoDeExecucao = medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);
                    printf("\nTempo medio de ordenacao do InsertionSort: %.3f microssegundos\n\n", tempoDeExecucao);
                    fflush(stdin);
                    system("pause");
                }
                break;

            case 3:
                while(!(escolhaElementos >= 1 && escolhaElementos <= 7)){
                    system("cls");
                    escolhaMenuElementos();
                    scanf("%d", &escolhaElementos);
                    if(escolhaElementos < 1 || escolhaElementos > 7){
                        printf("\nValor incoerente. Por favor, escolha novamente.\n\n");
                        system("pause");
                        fflush(stdin);
                    }
                    if(escolhaElementos == 7){
                        continue;
                    }
                    double tempoDeExecucao = medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);
                    printf("\nTempo medio de ordenacao do SelectionSort: %.3f microssegundos\n\n", tempoDeExecucao);
                    fflush(stdin);
                    system("pause");
                }
                break;

            case 4:
                while(!(escolhaElementos >= 1 && escolhaElementos <= 7)){
                    system("cls");
                    escolhaMenuElementos();
                    scanf("%d", &escolhaElementos);
                    if(escolhaElementos < 1 || escolhaElementos > 7){
                        printf("\nValor incoerente. Por favor, escolha novamente.\n\n");
                        system("pause");
                        fflush(stdin);
                    }
                    if(escolhaElementos == 7){
                        continue;
                    }
                    double tempoDeExecucao = medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);
                    printf("\nTempo medio de ordenacao do ShellSort: %.3f microssegundos\n\n", tempoDeExecucao);
                    fflush(stdin);
                    system("pause");
                }
                break;

            case 5:
                while(!(escolhaElementos >= 1 && escolhaElementos <= 7)){
                    system("cls");
                    escolhaMenuElementos();
                    scanf("%d", &escolhaElementos);
                    if(escolhaElementos < 1 || escolhaElementos > 7){
                        printf("\nValor incoerente. Por favor, escolha novamente.\n\n");
                        system("pause");
                        fflush(stdin);
                        break;
                    }
                    if(escolhaElementos == 7){
                        continue;
                    }
                    double tempoDeExecucao = medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);
                    printf("\nTempo medio de ordenacao do MergeSort: %.3f microssegundos\n\n", tempoDeExecucao);
                    fflush(stdin);
                    system("pause");
                }
                break;

            case 6:
                while(!(escolhaElementos >= 1 && escolhaElementos <= 7)){
                    system("cls");
                    escolhaMenuElementos();
                    scanf("%d", &escolhaElementos);
                    if(escolhaElementos < 1 || escolhaElementos > 7){
                        printf("\nValor incoerente. Por favor, escolha novamente.\n\n");
                        system("pause");
                        fflush(stdin);
                    }
                    if(escolhaElementos == 7){
                        continue;
                    }
                    double tempoDeExecucao = medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);
                    printf("\nTempo medio de ordenacao do QuickSort: %.3f microssegundos\n\n", tempoDeExecucao);
                    fflush(stdin);
                    system("pause");
                }
                break;

            case 7:
                while(!(escolhaElementos >= 1 && escolhaElementos <= 7)){
                    system("cls");
                    escolhaMenuElementos();
                    scanf("%d", &escolhaElementos);
                    if(escolhaElementos < 1 || escolhaElementos > 7){
                        printf("\nValor incoerente. Por favor, escolha novamente.\n\n");
                        system("pause");
                        fflush(stdin);
                    }
                    if(escolhaElementos == 7){
                        continue;
                    }
                    double tempoDeExecucao = medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);
                    printf("\nTempo medio de ordenacao do HeapSort: %.3f microssegundos\n\n", tempoDeExecucao);
                    fflush(stdin);
                    system("pause");
                }
                break;

            case 8:
                while(!(escolhaElementos >= 1 && escolhaElementos <= 7)){
                    system("cls");
                    escolhaMenuElementos();
                    scanf("%d", &escolhaElementos);
                    if(escolhaElementos < 1 || escolhaElementos > 7){
                        printf("\nValor incoerente. Por favor, escolha novamente.\n\n");
                        system("pause");
                        fflush(stdin);
                    }
                    if(escolhaElementos == 7){
                        continue;
                    }
                    double tempoDeExecucao = medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);
                    printf("\nTempo medio de ordenacao do RadixSort: %.3f microssegundos\n\n", tempoDeExecucao);
                    fflush(stdin);
                    system("pause");
                }
                break;

            case 9:
                while(!(escolhaElementos >= 1 && escolhaElementos <= 7)){
                    system("cls");
                    escolhaMenuElementos();
                    scanf("%d", &escolhaElementos);
                    if(escolhaElementos < 1 || escolhaElementos > 7){
                        printf("\nValor incoerente. Por favor, escolha novamente.\n\n");
                        system("pause");
                        fflush(stdin);
                    }
                    if(escolhaElementos == 7){
                        continue;
                    }
                    double tempoDeExecucao = medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);
                    printf("\nTempo medio de ordenacao do CountingSort: %.3f microssegundos\n\n", tempoDeExecucao);
                    fflush(stdin);
                    system("pause");
                }
                break;

            case 10:
                while(!(escolhaElementos >= 1 && escolhaElementos <= 7)){
                    system("cls");
                    escolhaMenuElementos();
                    scanf("%d", &escolhaElementos);
                    if(escolhaElementos < 1 || escolhaElementos > 7){
                        printf("\nValor incoerente. Por favor, escolha novamente.\n\n");
                        system("pause");
                        fflush(stdin);
                    }
                    if(escolhaElementos == 7){
                        continue;
                    }
                    double tempoDeExecucao = medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);
                    printf("\nTempo medio de ordenacao do TimSort: %.3f microssegundos\n\n", tempoDeExecucao);
                    fflush(stdin);
                    system("pause");
                }
                break;

            case 11:
                printf("\nEncerrando programa....\n");
                break;

            default:
                printf("\nValor incoerente. Por favor, escolha novamente.\n\n");
                system("pause");
                break;
        }

    }while(escolhaAlgoritmo != 11);
}
