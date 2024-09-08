#ifndef MAIN_H_
#define MAIN_H_

//Declaracao de variavel
unsigned char alfabeto[30];
unsigned short int qtdEstadoes;
unsigned short int qtdTransicoes;
unsigned short int nPalavras;
unsigned char fita[100];
unsigned char palavra[100];
unsigned char temp_fita[100];

//Declaracao de funcoes
int main();

/*
*   Entrada dos dados da Maquina de Truing a ser simulada
*/
void entrada_dados();

/*
*   Escreve uma string na tela até o primeiro espaco em branco
*/
void print_s(char string[], int size);

#endif