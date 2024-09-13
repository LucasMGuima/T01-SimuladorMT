#ifndef MT_H_
#define MT_H_

#define TRUE 1
#define FALSE 0

//Declaracao de variavel
typedef struct mt{
    unsigned char alfabeto[30];
    unsigned short int qtdEstadoes;
    unsigned short int qtdTransicoes;
    unsigned short int nPalavras;
    unsigned char fita[100];
    unsigned char palavra[100];
    unsigned char temp_fita[100];
}MT;

/*
*   Entrada dos dados da Maquina de Truing a ser simulada
*   
*   @param mt Variavel que referencia maquian de turing
*/
void entrada_dados(MT mt);

/*
*   Processa as palavras entradas em relação a MT, e escreve na tela se são validas ou não
*   
*   @param mt Maquina de Truing usada
*/
void processar_palavras(MT mt);

/*
*   Escreve uma string na tela até o primeiro espaco em branco
*
*   @param string Array de caracteres
*   @param size Tamanho do array de caracteres
*/
void print_s(char string[], int size);

/*
*   Verificar se o simbulo esta dentro do alfabeto
*   
*   @param alfabeto Array de caracteres representando o alfabeto da MT
*   @param size_alfabeto Tamanho do alfabeto
*   @param simbulo Caracter representando o simbulo lido
*
*   @return 1 Se encontrou o caracter | 0 Se não encontrou o caracter
*/
int alfabeto_contem(char alfabeto[], int size_alfabeto, char simbulo);

#endif