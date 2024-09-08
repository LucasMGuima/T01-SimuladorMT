#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "obj/tipos.h"

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
    scanf("%d", &nPalavras);

    // Coleta as palavras e armazena na fita
    char t_palavra[100];
    int cabecote = 0;
    for(int i = 0; i < nPalavras; i++){
        scanf("%s", &t_palavra);
        for(int j = 0; j < sizeof(t_palavra); j++){
            if(!t_palavra[j]) break;

            fita[cabecote] = t_palavra[j];
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
    int curr_palavra = 1;

    printf("------------\n");
    for(;cabecote < sizeof(fita); cabecote++){
        int estado = 1;

        //Limpa a palavra
        for(int i = 0; i < sizeof(palavra); i++){
            if(palavra[i] == '-') break;
            palavra[i] = ' ';
        }

        //Limpa a fita temporaria
        for(int i = 0; i < sizeof(temp_fita); i++){
            if(temp_fita[i] != '-') break;
            temp_fita[i] = ' ';
        }

        //Encontra a nova palavra na fita, passa para a palavra e para a fita temporaria
        for(int i = 0; i < sizeof(palavra); i++){
            if(fita[cabecote] == ' ') break;

            palavra[i] = fita[cabecote];
            temp_fita[i] = fita[cabecote];
            temp_fita[i+1] = '-';
            cabecote += 1;
        }

        if(alfabeto_contem(alfabeto, sizeof(alfabeto), palavra[0]) == FALSE){
            break;
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

        printf("%d - ", curr_palavra);
        curr_palavra++;
        if(estado == qtdEstadoes){
            print_s(palavra, sizeof(palavra));
            printf(" OK\n");
        }else{
            print_s(palavra, sizeof(palavra));
            printf(" not OK\n");
        }
    }
}