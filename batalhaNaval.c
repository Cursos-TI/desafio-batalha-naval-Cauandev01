#include <stdio.h>

int main() {
    // Criação do tabuleiro 10x10, inicializado com água (0)
    int tabuleiro[10][10] = {0};

    // Vetores representando os navios (valor 3 indica parte de navio)
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Verificação se os navios cabem no tabuleiro
    if (coluna_horizontal + 3 > 10 || linha_vertical + 3 > 10) {
        printf("Erro: Navio fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verificação de sobreposição 
    int sobreposicao = 0;
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0 ||
            tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Erro: Os navios se sobrepõem!\n");
        return 1;
    }

    // Posicionamento do navio horizontal no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    // Posicionamento do navio vertical no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
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
