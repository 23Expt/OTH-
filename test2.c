#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menentukan apakah suatu posisi valid di papan catur atau tidak
int isValidPosition(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

// Fungsi untuk menandai posisi yang dapat dicapai oleh kuda
void markAccessiblePositions(int i, int j, int *chessBoard) {
    // Daftar langkah yang mungkin dilakukan oleh kuda
    int moves[8][2] = {
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
        {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
    };

    // Memeriksa setiap langkah yang mungkin
    for (int k = 0; k < 8; k++) {
        int x = i + moves[k][0];
        int y = j + moves[k][1];
        if (isValidPosition(x, y)) {
            chessBoard[x * 8 + y] = 1; // Menandai posisi yang dapat dicapai
        }
    }
}

// Fungsi untuk mencetak papan catur
void printChessBoard(int *chessBoard) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", chessBoard[i * 8 + j]);
        }
        printf("\n");
    }
}

// Fungsi utama
void koboImaginaryChess(int i, int j, int *chessBoard) {
    // Mengosongkan papan catur
    for (int k = 0; k < 64; k++) {
        chessBoard[k] = 0;
    }

    // Menandai posisi yang dapat dicapai oleh kuda
    markAccessiblePositions(i, j, chessBoard);
}

int main() {
    int i, j;
    int chessBoard[64] = {0}; // Inisialisasi papan catur dengan nilai 0

    // Membaca posisi kuda
    scanf("%d %d", &i, &j);

    // Memeriksa dan menandai posisi yang dapat dicapai oleh kuda
    koboImaginaryChess(i, j, chessBoard);

    // Mencetak papan catur dengan posisi yang dapat dicapai oleh kuda
    printChessBoard(chessBoard);

    return 0;
}