#include "board.h"

int main()
{
    char deck[S][S] = {{'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'},
                       {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                       {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'}};

    PrintBoard(deck);

    int k = 0;
    while (1) {
        Move(deck, k, 0);
        PrintBoard(deck);
        k++;
    }

    return 0;
}
