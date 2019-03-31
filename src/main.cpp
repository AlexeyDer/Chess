#include "board_print_plain.h"

using namespace std;

#define SIZE 8

int main()
{
    char deck[SIZE][SIZE] = {
            {"r", "n", "b", "q", "k", "b", "n", "r"},
            {"p", "p", "p", "p", "p", "p", "p", "p"},
            {" ", " ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " ", " "},
            {"p", "p", "p", "p", "p", "p", "p", "p"},
            {"R", "N", "B", "Q", "K", "B", "N", "R"},
    };

    PrintBoard(deck, SIZE, SIZE);

    return 0;
}
