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

    for(int i = 0; i < sizeof(temp_fita); i++){
        temp_fita[i] = '-';
    }

    // Verifica as palavras
    // Pega uma palavra da fita
    int cabecote = 0;
    
    printf("------------\n");
    for(;cabecote < sizeof(fita); cabecote++){
        int estado = 1;

        for(int i = 0; i < sizeof(palavra); i++){
            if(palavra[i] == '-') break;
            palavra[i] == '-';
        }

        for(int i = 0; i < sizeof(temp_fita); i++){
            if(temp_fita[i] != '-') break;
            temp_fita[i] = '-';
        }

        for(int i = 0; i < sizeof(palavra); i++){
            if(fita[cabecote] == ' ') break;

            palavra[i] = fita[cabecote];
            temp_fita[i] = fita[cabecote];
            cabecote += 1;
        }

        for(int i = 0; i < sizeof(palavra);){
            Transicao t = checar_transicao(transicoes, qtdTransicoes, estado, temp_fita[i]);
            estado = t.estadoAlvo;
            if(estado == qtdEstadoes || estado == 0) break;

            temp_fita[i] = t.simboloGravar;
            if(t.mover == 'D'){
                //Move o cabecote para a direita
                i++;
            }else{
                //Move o cabecote para a esquerda, se o cabecote estiver no limite inicial mantem em 0
                i--;
                if(i < 1){
                    i = 0;
                }
            }
        }

        if(estado == qtdEstadoes){
            printf("%s OK\n", palavra);
        }else{
            printf("%s not OK\n", palavra);
        }
        if(fita[cabecote+1] = ' ') break;
    }
}