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


/*
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
                sobreposicao = 1;  //marca a sobreposição    // o navio horizontal já está ocupando a casa
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

    // A checagem de sobreposição no navio da segunda diagonal estava dando
    // problema, fazendo com que o navio não aparecesse, desta forma o segundo
    // não é checado, não sei como resolver para fazer ele ser checado e ainda
    // aparecer na matriz, apenas deixei desta forma sem ser checado

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
*/

//----------------------------------------------------------------------------------

#include <stdio.h>

#define N 10   // tamanho do tabuleiro
#define H 5    // tamanho das matrizes de habilidade

int main() {
    int i, j;
    int tabuleiro[N][N];
    char linhas[N] = {'A','B','C','D','E','F','G','H','I','J'};

    // Inicializar o tabuleiro com água
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // =========================
    // NAVIOS FIXOS
    // =========================

    // Navio horizontal (linha 2, colunas 2-4) -> letra C
    for (j = 2; j < 5; j++) {
        tabuleiro[2][j] = 3;
    }

    // Navio vertical (coluna 4, linhas 5-7) -> letra F
    for (i = 5; i < 8; i++) {
        tabuleiro[i][4] = 3;
    }

    // Navio diagonal (começa em linha 7, coluna 1 -> H2 até J4)
    for (i = 0; i < 3; i++) {
        tabuleiro[7+i][1+i] = 3;
    }

    // =========================
    // MATRIZES DE HABILIDADE
    // =========================
    int cone[H][H];
    int cruz[H][H];
    int octaedro[H][H];

    // Cone (aponta para baixo)
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            if (j >= H/2 - i && j <= H/2 + i) 
                cone[i][j] = 1;
            else 
                cone[i][j] = 0;
        }
    }

    // Cruz
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            if (i == H/2 || j == H/2) 
                cruz[i][j] = 1;
            else 
                cruz[i][j] = 0;
        }
    }

    // Octaedro (losango) sem usar abs
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            if (i <= H/2) {
                if (j >= (H/2 - i) && j <= (H/2 + i))
                    octaedro[i][j] = 1;
                else
                    octaedro[i][j] = 0;
            } else {
                if (j >= (i - H/2) && j < H - (i - H/2))
                    octaedro[i][j] = 1;
                else
                    octaedro[i][j] = 0;
            }
        }
    }

    // =========================
    // SOBREPOR NO TABULEIRO
    // =========================
    int origemLinha = 6, origemColuna = 6;  // centro da habilidade (vai atingir só a linha 6, coluna 6)
    int habilidade[H][H];

    // Escolher qual matriz usar (exemplo: cruz para acertar só uma casa do navio)
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            habilidade[i][j] = cruz[i][j];   // <- pode trocar para cone ou octaedro
        }
    }

    // Aplicar a habilidade no tabuleiro
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            if (habilidade[i][j] == 1) {
                int linhaT = origemLinha + (i - H/2);
                int colunaT = origemColuna + (j - H/2);
                if (linhaT >= 0 && linhaT < N && colunaT >= 0 && colunaT < N) {
                    // agora permite sobrescrever o navio (só 1 casa será atingida)
                    tabuleiro[linhaT][colunaT] = 5;
                }
            }
        }
    }

    // =========================
    // EXIBIR TABULEIRO
    // =========================
    printf("*** TABULEIRO BATALHA NAVAL ***\n\n");
    printf("   ");
    for (j = 0; j < N; j++) {
        printf("%d ", j+1);
    }
    printf("\n");

    for (i = 0; i < N; i++) {
        printf("%c  ", linhas[i]);
        for (j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

