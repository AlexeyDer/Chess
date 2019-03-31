#include "board_print_plain.h"

void PrintBoard(char** deck, int size_i, int size_j)
{
    ofstream myfile("/home/alexeyder/Documents/progs/Chess/hello.txt");
    for (int i = 0; i < size_i; i++) {
        for (int j = 0; j < size_j; j++)
            myfile << deck[i][j] << " ";
    }
    myfile << endl;
}
