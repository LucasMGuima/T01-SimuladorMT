#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "obj/tipos.h"

Transicao transicoes[50];

void entrada_dados(){
    printf("Alfabeto: ");
    scanf("%s", &alfabeto);
    printf("Quantdade de Estados: ");
    scanf("%d", &qtdEstadoes);
    printf("Quandtode de Transicoes: ");
    scanf("%d", &qtdTransicoes);

    printf("Transicoes: \n");
    char char_entrada;
    int num_entrada;
    for(int i = 0; i < qtdTransicoes; i++){
        // Le o numero do estado
        scanf("%d", &num_entrada);
        transicoes[i].estado = num_entrada;
        // Le o simbulo de leitura do estado
        scanf("%s", &char_entrada);
        transicoes[i].simboloLeitura = char_entrada;
        // Le o simbulo a ser gravado
        scanf("%s", &char_entrada);
        transicoes[i].simboloGravar = char_entrada;
        // Le para qual direcao mover
        scanf("%s", &char_entrada);
        transicoes[i].mover = char_entrada;
        // Le para qual estado ir
        scanf("%d", &num_entrada);
        transicoes[i].estadoAlvo = num_entrada;
    }

    printf("Numero de Palavras: ");
    scanf("%d", &nPalavras);

    // Coleta as palavras e armazena na fita
    char palavra[100];
    int cabecote = 0;
    for(int i = 0; i < nPalavras; i++){
        scanf("%s", &palavra);
        for(int j = 0; j < sizeof(palavra); j++){
            if(!palavra[j]) break;

            fita[cabecote] = palavra[j];
            cabecote += 1;
        }
        fita[cabecote] = ' ';
        cabecote += 1;
    }
}

int main(){
    entrada_dados();  

    // Verifica as palavras
    // Pega uma palavra da fita
    int cabecote = 0;
    int estado = 1;


    for(int i = 0; i < sizeof(palavra); i++){
        if(fita[cabecote] == ' ') break;

        palavra[i] = fita[cabecote];
        cabecote += 1;
    }

    Transicao t = checar_transicao(transicoes, qtdTransicoes, estado, palavra[0]);
    print(t);
}