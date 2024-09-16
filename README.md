# SIMULADOR DE MAQUINA DE TURING

Programa feito em C capaz de interpretar e simular uma dada máquina de Turing.

## Caracteristicas

O simulador possui algumas limitações em relação a sua quantidade de transições e tamanhos de fitas, sendo elas:

> [!WARNING]
>
> 1. O alfabeto pode ter no máximo 30 caracterers;
> 2. Pode ter no máximo 50 estados de transições;
> 3. A fita pode ter no máximo 100 caracteres;
> 4. O caracter "*-*" é reservado para a máquina;

## Uilização

Para se utilizar o simulador, se pode:

1. Baixar o executável;

    Basta fazer o download do executável dentro da pasta [/simulador](/simulador)
2. Compilar na própria máquina.

    Para compilar na própria máquina será necessário fazer o download deste repositório, e ter um ambiente C configurado.  
    Tendo isso basta rodar o comando:

    ```console
        gcc -o simulador main.c ./obj/tipos.c ./obj/mt.c
    ```

Tendo agora o executável em mãos, podemos abri-lo. Feito isso, será apresentada a seguinte interface em seu terminal:

```console
    ===SIMULADOR DE MT===
    1 - Nova simulacao
    0 - Sair
    ---------------------
    Opcao:
```

Agora podemos escolher oque fazer, se entrarmos com a opção **0** o programa será fechado, se escolhermos a **1**, iniciamos a simulação da máquinha de Truing.

### Simulando a máquina de Turing

Ao iniciarmos uma nova simulação, precisamos entrar com a configuração da máquina, nesse estado, o programa apresentara uma série de requisições de entrada, uma após a entrada da anterior:

```console
    Alfabeto: abxy
    Quantidade de Estados: 5
    Quantidade de Transicoes: 11
```

Assim que entrarmos com a qunatidade de transições, o mesmo pedira para entrarmos com as ditas transições, o programa ira enumera-las, para fácil entendimento.

> [!TIP]  
> As direções são:  
> D -> Direita;  
> E -> Esquerda;

```console
    1 -> 1 a x D 2
    2 -> 1 y y D 4
    .
    .
    .
    10 -> 4 y y D 4
    11 -> 4 - - D 5
```

> [!IMPORTANT]  
> O formata de entrada de uma transição é o seguinte:
> (Estado atual) (Caracter de leitura) (Caracter de escrita) (Direção do cabeçote) (Estado alvo), todos separados por 1 espaço.  
> Por exemplo, na transição **1 a x D 2**, temos, no estado *1*, lendo o caracter *a*, escrevemos *x*, movemos o cabeçote para a *direita* e vamos para o estado *2*.  
> O estado de aceitação deve sempre ser o de maior valor, e não ter transições saindo do mesmo, isto é, no exemplo a cima, o estado de aceitação é o 5, os estados de rejeição, ocorrem sempre que não temos uma transição para dado caracter de entrada em determinado estado.

Tendo entrado com as transições, agora precisamos informar as palavras que serão testadas. Primeiro informamos a quantidade de palavras e em seguida informamos as palavras, uma por linha.  

```console
    Numero de Palavras: 4
    aabb
    aaabbb
    abab
    bbaa
```

Assim que terminarmos de informar as palavras, a MT ira verificar se aceita ou rejeita as palavras e nos informar:  

```console
    ------------
    1 - aabb OK
    2 - aaabbb OK
    3 - abab not OK
    4 - bbaa not OK
```

E agora voltamos ao inicio do programa, onde podemos fecha-lo ou efetuar outra simulação.  
