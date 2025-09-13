#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

/* Função para verificar se uma posição está dentro do tabuleiro */
int dentro_tabuleiro(int r, int c) {
    return (r >= 0 && r < ROWS && c >= 0 && c < COLS);
}

int main(void) {
    /* Tabuleiro: 0 = vazio, 1 = ocupado por navio */
    int board[ROWS][COLS] = {0};

    /* Variáveis para navio vertical */
    int v_start_row, v_start_col, v_length;

    /* Variáveis para navio horizontal */
    int h_start_row, h_start_col, h_length;

    /* Vetores para guardar coordenadas de cada parte dos navios */
    int v_coords[ROWS][2];
    int h_coords[COLS][2];

    printf("=== BATALHA NAVAL - NIVEL NOVATO (interativo) ===\n");
    printf("Tabuleiro %dx%d (indices de 0 a %d)\n\n", ROWS, COLS, ROWS-1);

    /* Entrada de dados do navio vertical */
    printf("Digite linha inicial do NAVIO VERTICAL (0-%d): ", ROWS-1);
    scanf("%d", &v_start_row);
    printf("Digite coluna inicial do NAVIO VERTICAL (0-%d): ", COLS-1);
    scanf("%d", &v_start_col);
    printf("Digite comprimento do NAVIO VERTICAL: ");
    scanf("%d", &v_length);

    /* Entrada de dados do navio horizontal */
    printf("\nDigite linha inicial do NAVIO HORIZONTAL (0-%d): ", ROWS-1);
    scanf("%d", &h_start_row);
    printf("Digite coluna inicial do NAVIO HORIZONTAL (0-%d): ", COLS-1);
    scanf("%d", &h_start_col);
    printf("Digite comprimento do NAVIO HORIZONTAL: ");
    scanf("%d", &h_length);

    /* Validações básicas */
    if (!dentro_tabuleiro(v_start_row, v_start_col) ||
        !dentro_tabuleiro(v_start_row + v_length - 1, v_start_col)) {
        printf("\nErro: navio vertical sai do tabuleiro.\n");
        return 1;
    }

    if (!dentro_tabuleiro(h_start_row, h_start_col) ||
        !dentro_tabuleiro(h_start_row, h_start_col + h_length - 1)) {
        printf("\nErro: navio horizontal sai do tabuleiro.\n");
        return 1;
    }

    /* Posicionar navio vertical */
    for (int i = 0; i < v_length; ++i) {
        int r = v_start_row + i;
        int c = v_start_col;
        if (board[r][c] != 0) {
            printf("\nErro: sobreposicao ao posicionar navio vertical em (%d,%d).\n", r, c);
            return 1;
        }
        board[r][c] = 1;
        v_coords[i][0] = r;
        v_coords[i][1] = c;
    }

    /* Posicionar navio horizontal */
    for (int i = 0; i < h_length; ++i) {
        int r = h_start_row;
        int c = h_start_col + i;
        if (board[r][c] != 0) {
            printf("\nErro: sobreposicao ao posicionar navio horizontal em (%d,%d).\n", r, c);
            return 1;
        }
        board[r][c] = 1;
        h_coords[i][0] = r;
        h_coords[i][1] = c;
    }

    /* Impressão organizada das coordenadas */
    printf("\nNavio VERTICAL (partes = %d):\n", v_length);
    for (int i = 0; i < v_length; ++i) {
        printf("  Parte %d -> (linha: %d, coluna: %d)\n", i+1, v_coords[i][0], v_coords[i][1]);
    }

    printf("\nNavio HORIZONTAL (partes = %d):\n", h_length);
    for (int i = 0; i < h_length; ++i) {
        printf("  Parte %d -> (linha: %d, coluna: %d)\n", i+1, h_coords[i][0], h_coords[i][1]);
    }

    /* Exibir o tabuleiro */
    printf("\nRepresentacao do tabuleiro ('.' = vazio, 'N' = navio):\n\n");
    printf("   ");
    for (int c = 0; c < COLS; ++c) printf("%2d ", c);
    printf("\n");

    for (int r = 0; r < ROWS; ++r) {
        printf("%2d ", r);
        for (int c = 0; c < COLS; ++c) {
            if (board[r][c] == 0) printf(" . ");
            else printf(" N ");
        }
        printf("\n");
    }

    printf("\nPosicionamento concluido com sucesso.\n");
    return 0;
}
