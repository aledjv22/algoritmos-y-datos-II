#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

char get_winner_row(char board[3][3])
{
    char winner = '-';
    bool is_winner = false;

    for(unsigned int row = 0; row < 3; ++row) {
        is_winner = board[row][0] == board[row][1]; 

        for(unsigned int column = 1; column < 2; ++column) {
            is_winner = is_winner && (board[row][column] == board[row][column + 1]);
            if(!is_winner) break;   
        }
        
        if(is_winner && (board[row][0] != winner)) {
            winner = board[row][0];
            break;
        }
    }

    return winner;
}

char get_winner_column(char board[3][3])
{
    char winner = '-';
    bool is_winner = false;

    for(unsigned int column = 0; column < 3; ++column) {
        is_winner = board[0][column] == board[1][column]; 

        for(unsigned int row = 1; row < 2; ++row) {
            is_winner = is_winner && (board[row][column]== board[row + 1][column]);
            if(!is_winner) break;   
        }
        
        if(is_winner && (board[0][column] != winner)) {
            winner = board[0][column];
            break;
        }
    }

    return winner;
}

char get_winner(char board[3][3])
{
    char winner = '-';

    winner = get_winner_row(board);

    if(winner == '-') winner = get_winner_column(board);

    return winner;
}

bool has_free_cell(char board[3][3])
{
    bool free_cell=false;
    
    for(unsigned int row = 0; row < 3; ++row) {
        for(unsigned int column = 0; column < 3; ++column) {
            free_cell = board[row][column] == '-';
            printf("%d",free_cell);
            if(free_cell) break;
        }
        if(free_cell) break;
    }

    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
