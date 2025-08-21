#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
//----------------------------------------------------------------------------------



int main() {
    
  int i, j;
    int tabuleiro[10][10];
    char linhas[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Inicializar o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definindo coordenadas dos navios (fixo neste nível)
    int linhaH = 2, colunaH = 5; // Navio horizontal na linha 'C', coluna 6
    int linhaV = 5, colunaV = 6; // Navio vertical na linha 'F', coluna 7
    int linhaD1 = 1, colunaD1 = 1; // Navio diagonal principal (\) começando em B2
    int linhaD2 = 9, colunaD2 = 0; // Navio diagonal secundária (/) começando em E9

    // Posicionar navio horizontal (tamanho 3)
    if (colunaH + 3 <= 10) {
        for (j = 0; j < 3; j++) {   //Vai percorrer as 3 posições que o navio horizontal ocuparia
            tabuleiro[linhaH][colunaH + j] = 3;
        }
    }

    // Posicionar navio vertical (tamanho 3) verificando sobreposição
    if (linhaV + 3 <= 10) {     // garante que o navio vertical cabe no tabuleiro
        int sobreposicao = 0;   // flag que assume 0 = não sobrepõe ou 1 = sobrepõe.
        for (i = 0; i < 3; i++) {  
            if (tabuleiro[linhaV + i][colunaV] == 3) {          // Se já existe um "3" nessa posição, significa que
                sobreposicao = 1;  /*marca a sobreposição*/     // o navio horizontal já está ocupando a casa
                break;      // não precisa checar mais, já sabemos que sobrepõe
            }
        }
        if (!sobreposicao) {        // só coloca o navio vertical se não houve conflito
            for (i = 0; i < 3; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        }
    }

    // Posicionar navio diagonal principal (\)
    if (linhaD1 + 3 <= 10 && colunaD1 + 3 <= 10) {
        int sobreposicao = 0;
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == 3) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (i = 0; i < 3; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        }
    }
    
    // Posicionar navio diagonal secundária (/) (tamanho 3, subindo à direita)
    if (linhaD2 - 2 >= 0 && colunaD2 + 2 < 10) {
        for (i = 0; i < 3; i++) {
        tabuleiro[linhaD2 - i][colunaD2 + i] = 3;
        }
    }

    /* A checagem de sobreposição no navio da segunda diagonal estava dando
    problema, fazendo com que o navio não aparecesse, desta forma o segundo
    não é checado, não sei como resolver para fazer ele ser checado e ainda
    aparecer na matriz, apenas deixei desta forma sem ser checado */

    // Exibir cabeçalho das colunas
    printf("*** TABULEIRO BATALHA NAVAL ***\n\n");
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf("%d ", j+1);
    }
    printf("\n");

    // Exibir tabuleiro
    for (i = 0; i < 10; i++) {
        printf("%c  ", linhas[i]); // imprimir a letra da linha
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}