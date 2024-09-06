#include <stdio.h>
#include "main.h"
#include "obj/tipos.h"

int main(){
    printf("Alfabeto: ");
    scanf("%s", &alfabeto);
    printf("Quantdade de Estados: ");
    scanf("%d", &qtdEstadoes);
    printf("Quandtode de Transicoes: ");
    scanf("%d", &qtdTransicoes);
    printf("Numero de Palavras: ");
    scanf("%d", &nPalavras);

    printf("Transicoes: \n");
    Transicao transicoes[10];
    char entrada;
    for(int i = 0; i < qtdTransicoes; i++){
        scanf("%s", &entrada);
        transicoes[i].estado = (int) entrada;
        scanf("%s", &entrada);
        transicoes[i].simboloLeitura = entrada;
        scanf("%s", &entrada);
        transicoes[i].simboloGravar = entrada;
        scanf("%s", &entrada);
        transicoes[i].mover = entrada;
        scanf("%s", &entrada);
        transicoes[i].estadoAlvo = (int) entrada;
    }

    printf("Transicoes: \n");
    for(int i = 0; i < qtdTransicoes; i++){
        print(transicoes[i]);
        printf("\n");
    }
}