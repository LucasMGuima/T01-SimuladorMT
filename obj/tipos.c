#include <stdio.h>
#include "tipos.h"

void print(Transicao transicao){
    printf("-> %i %c %c %c %i\n", transicao.estado, transicao.simboloLeitura
                           , transicao.simboloGravar, transicao.mover
                           , transicao.estadoAlvo);
}

Transicao checar_transicao(Transicao transicoes[], unsigned short int qtd_transicoes, unsigned short int estado_atual, unsigned char simbulo_lido){
    for(int i = 0; i < qtd_transicoes; i++){
        Transicao t = transicoes[i];
        if(t.estado == estado_atual && t.simboloLeitura == simbulo_lido) return t;
    }
    Transicao t;
    return t;
}