#include <stdio.h>
#include "tipos.h"
#include "mt.h"

Transicao transicoes[50];

void print_s(char string[], int size){
    for(int i = 0; i < size; i++){
        if(string[i] != ' '){
            printf("%c", string[i]);
        }else{
            break;
        }
    }
}

int alfabeto_contem(char alfabeto[], int size_alfabeto, char simbulo){
    if(!simbulo) return FALSE;

    for(int i = 0; i < size_alfabeto; i++){
        if(alfabeto[i] == simbulo) return TRUE;
    }
    return FALSE;
}

void entrada_dados(MT mt){
    printf("Alfabeto: ");
    scanf("%s", &mt.alfabeto);
    printf("Quantdade de Estados: ");
    scanf("%d", &mt.qtdEstadoes);
    printf("Quandtode de Transicoes: ");
    scanf("%d", &mt.qtdTransicoes);

    printf("Transicoes: \n");
    char char_entrada;
    int num_entrada;
    for(int i = 0; i < mt.qtdTransicoes; i++){
        printf("%d -> ", i+1);
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
    scanf("%d", &mt.nPalavras);

    // Coleta as palavras e armazena na fita
    char t_palavra[100];
    int cabecote = 0;
    for(int i = 0; i < mt.nPalavras; i++){
        scanf("%s", &t_palavra);
        for(int j = 0; j < sizeof(t_palavra); j++){
            if(!t_palavra[j]) break;

            mt.fita[cabecote] = t_palavra[j];
            cabecote += 1;
        }
        mt.fita[cabecote] = ' ';
        cabecote += 1;
    }
}

void processar_palavras(MT mt){
    for(int i = 0; i < sizeof(mt.temp_fita); i++){
        mt.temp_fita[i] = '-';
    }

    // Verifica as palavras
    // Pega uma palavra da fita
    int cabecote = 0;
    int curr_palavra = 1;

    printf("------------\n");
    for(;cabecote < sizeof(&mt.fita); cabecote++){
        int estado = 1;

        //Limpa a palavra
        for(int i = 0; i < sizeof(&mt.palavra); i++){
            if(mt.palavra[i] == '-') break;
            mt.palavra[i] = ' ';
        }

        //Limpa a fita temporaria
        for(int i = 0; i < sizeof(&mt.temp_fita); i++){
            if(mt.temp_fita[i] != '-') break;
            mt.temp_fita[i] = ' ';
        }

        //Encontra a nova palavra na fita, passa para a palavra e para a fita temporaria
        for(int i = 0; i < sizeof(&mt.palavra); i++){
            if(mt.fita[cabecote] == ' ') break;

            mt.palavra[i] = mt.fita[cabecote];
            mt.temp_fita[i] = mt.fita[cabecote];
            mt.temp_fita[i+1] = '-';
            cabecote += 1;
        }

        if(alfabeto_contem(mt.alfabeto, sizeof(&mt.alfabeto), mt.palavra[0]) == FALSE){
            printf("Fechado \n");
            break;
        }

        for(int i = 0; i < sizeof(&mt.palavra);){
            Transicao t = checar_transicao(transicoes, mt.qtdTransicoes, estado, mt.temp_fita[i]);
            estado = t.estadoAlvo;
            if(estado == mt.qtdEstadoes || estado == 0) break;

            mt.temp_fita[i] = t.simboloGravar;
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

        printf("%d - ", curr_palavra);
        curr_palavra++;
        if(estado == mt.qtdEstadoes){
            print_s(mt.palavra, sizeof(&mt.palavra));
            printf(" OK\n");
        }else{
            print_s(mt.palavra, sizeof(&mt.palavra));
            printf(" not OK\n");
        }
    }
}