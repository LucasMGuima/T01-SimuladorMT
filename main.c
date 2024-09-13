#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "obj/tipos.h"
#include "obj/mt.h"

int main(){
    MT mt;
    entrada_dados(mt);  
    processar_palavras(mt);
}