#include <stdio.h>
#include <stdlib.h>


#define TAM 10
#define TAM_HAB 5

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linha_tab = origem_linha - offset + i;
                int coluna_tab = origem_coluna - offset + j;

                if (linha_tab >= 0 && linha_tab < TAM && coluna_tab >= 0 && coluna_tab < TAM) {
                    if (tabuleiro[linha_tab][coluna_tab] == 0) {
                        tabuleiro[linha_tab][coluna_tab] = 5;
                    }
                }
            }
        }
    }
}

void criarHabilidadeCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = 0;
        }
    }
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = TAM_HAB / 2 - i; j <= TAM_HAB / 2 + i; j++) {
            if (j >= 0 && j < TAM_HAB) habilidade[i][j] = 1;
        }
    }
}

void criarHabilidadeCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = (i == TAM_HAB / 2 || j == TAM_HAB / 2) ? 1 : 0;
        }
    }
}

void criarHabilidadeOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = 0;
        }
    }
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                habilidade[i][j] = 1;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    int linha_horizontal = 2, coluna_horizontal = 4;
    int linha_vertical = 5, coluna_vertical = 7;

    int navio_diagonal1[3] = {3, 3, 3};
    int navio_diagonal2[3] = {3, 3, 3};

    int linha_diag1 = 0, coluna_diag1 = 0;
    int linha_diag2 = 0, coluna_diag2 = 9;

    if (coluna_horizontal + 3 > TAM || linha_vertical + 3 > TAM ||
        linha_diag1 + 3 > TAM || coluna_diag1 + 3 > TAM ||
        linha_diag2 + 3 > TAM || coluna_diag2 - 2 < 0) {
        printf("Erro: Navio fora dos limites do tabuleiro.\n");
        return 1;
    }

    int sobreposicao = 0;
    for (int i = 0; i < 3; i++) {
        if (
            tabuleiro[linha_horizontal][coluna_horizontal + i] != 0 ||
            tabuleiro[linha_vertical + i][coluna_vertical] != 0 ||
            tabuleiro[linha_diag1 + i][coluna_diag1 + i] != 0 ||
            tabuleiro[linha_diag2 + i][coluna_diag2 - i] != 0
        ) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Erro: Os navios se sobrep\u00f5em!\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
        tabuleiro[linha_diag1 + i][coluna_diag1 + i] = navio_diagonal1[i];
        tabuleiro[linha_diag2 + i][coluna_diag2 - i] = navio_diagonal2[i];
    }

    // Criando habilidades
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    // Aplicando habilidades
    aplicarHabilidade(tabuleiro, cone, 7, 2);       // cone no ponto (7,2)
    aplicarHabilidade(tabuleiro, cruz, 4, 4);       // cruz no ponto (4,4)
    aplicarHabilidade(tabuleiro, octaedro, 6, 6);   // octaedro no ponto (6,6)

    // Exibindo o tabuleiro
    printf("\n--- Tabuleiro com Habilidades Especiais ---\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
