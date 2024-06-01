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
        if(!(escolhaAlgoritmo >= 1 && escolhaAlgoritmo <= 11)){
            printf("\n\tERRO - Valor invalido. Por favor, insira um valido.\n\n");
            system("pause");
            continue;
        }
        if(escolhaAlgoritmo != 11){
            while(!(escolhaElementos >= 1 && escolhaElementos <= 7)){
                system("cls");
                escolhaMenuElementos();
                scanf("%d", &escolhaElementos);
                if(escolhaElementos < 1 || escolhaElementos > 7){
                    printf("\n\tERRO - Valor invalido. Por favor, insira um valido.\n\n");
                    system("pause");
                    fflush(stdin);
                    continue;
                }
                if(escolhaElementos == 7){
                    continue;
                }
                medicaoDeTempo(escolhaAlgoritmo, escolhaElementos);
                fflush(stdin);
                system("pause");
            }
        }else{
            printf("\n\tEncerrando...\n");
        }
    }while(escolhaAlgoritmo != 11);
}
