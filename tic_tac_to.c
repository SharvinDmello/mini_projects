#include <stdio.h>

char board[3][3];
char player = 'X';

void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2){
            printf("  -+-+-\n");
        }
    }
}

int check_win() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;
    return 0;
}

int main() {
    init_board();
    int row, col;
    for (int i = 0; i < 9; i++) {
        print_board();
        printf("Player %c, enter row and column: ", player);
        scanf("%d %d", &row, &col);
        if (board[row][col] == ' ') {
            board[row][col] = player;
            if (check_win()) {
                print_board();
                printf("Player %c wins!\n", player);
                return 0;
            }
            player = (player == 'X') ? 'O' : 'X';
        } else {
            printf("Cell already occupied, try again.\n");
            i--;
        }
    }
    print_board();
    printf("It's a draw!\n");
    return 0;
}
