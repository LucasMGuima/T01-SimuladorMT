#ifndef TIPOS_H_
#define TIPOs_H_

//Delcara os tipos
typedef struct transicao {
    unsigned short int estado;
    unsigned char simboloLeitura;
    unsigned char simboloGravar;
    unsigned char mover;
    unsigned short int estadoAlvo;
} Transicao;

//Funcoes
/*
*   Escreve na tela a transição entrada como parametro
*
*   @param transicao Transicao a ser escrita na tela
*/
void print(Transicao transicao);

#endif