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

/*
*   Verifica dentro da lista de transicoes se existe um transição possivel dado o estado atual e simbulo lido.
*
*   @param transicoes Array contendo as transicoes
*   @param qtd_transicoes Quantidade de transicoes
*   @param estado_atual Estado em que se encontra a MT
*   @param simbulo_lido Simbolo lido na fita
* 
*   @return A transicao correspondenete encontrada ou uma transicao vazia com o estado alvo sendo 0
*/
Transicao checar_transicao(Transicao transicoes[], unsigned short int qtd_transicoes,unsigned short int estado_atual, unsigned char simbulo_lido);

#endif