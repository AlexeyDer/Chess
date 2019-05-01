#include "board.h"

int main()
{
    char deck[S][S] = {
            {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'},
    };

    PrintBoard(deck);

    int k = 0;
    while (1) {
        if (!Move(deck, k)) {
            PrintBoard(deck);
            k++;
        } else
            printf("Ups! Try Again!\n");
    }

    return 0;
}
