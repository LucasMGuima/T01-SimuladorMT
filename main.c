#include <stdio.h>
#include <stdlib.h>
#include "main.h"
// Codigos criados para facilitar implementação
#include "obj/tipos.h"
#include "obj/mt.h"

int main(){
    int opcao = -1;

    do{
        printf("===SIMULADOR DE MT===\n");
        printf(" 1 - Nova simulacao\n");
        printf(" 0 - Sair\n");
        printf("---------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("---------------------\n");
        
        if(opcao == 1){
            MT mt;
            mt = entrada_dados(mt);  
            processar_palavras(mt);
            printf("\n");
        }

    }while (opcao != FALSE);
    printf("Fechado\n");
}