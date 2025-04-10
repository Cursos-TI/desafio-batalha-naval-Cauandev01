#include <stdio.h>

int main() {
    // Criação do tabuleiro 10x10
    int tabuleiro[10][10] = {0};

    // Navios horizontais e verticais
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Navios diagonais 
    int navio_diagonal1[3] = {3, 3, 3};
    int navio_diagonal2[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios diagonais
    int linha_diag1 = 0, coluna_diag1 = 0;         
    int linha_diag2 = 0, coluna_diag2 = 9;         

    // Verificação de limites do tabuleiro
    if (coluna_horizontal + 3 > 10 || linha_vertical + 3 > 10 ||
        linha_diag1 + 3 > 10 || coluna_diag1 + 3 > 10 ||
        linha_diag2 + 3 > 10 || coluna_diag2 - 2 < 0) {
        printf("Erro: Navio fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verificação de sobreposição
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
        printf("Erro: Os navios se sobrepõem!\n");
        return 1;
    }

    // Posicionamento do navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    // Posicionamento do navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }

    // Posicionamento do navio diagonal principal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_diag1 + i][coluna_diag1 + i] = navio_diagonal1[i];
    }

    // Posicionamento do navio diagonal secundária
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_diag2 + i][coluna_diag2 - i] = navio_diagonal2[i];
    }

    // Exibição do tabuleiro
    printf("\n--- Tabuleiro Batalha Naval ---\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
