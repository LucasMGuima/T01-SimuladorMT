#include <stdio.h>
#include "tipos.h"

void print(Transicao transicao){
    printf("->");
    printf("%i %c %c %c %i", transicao.estado, transicao.simboloLeitura
                           , transicao.simboloGravar, transicao.mover
                           , transicao.estadoAlvo);
}