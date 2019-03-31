#include "board_print_plain.h"

void PrintBoard(char deck[size][size])
{
    ofstream myfile("/home/alexeyder/Documents/progs/Chess/hey.txt");
    myfile << "A B C D E F G H\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            myfile << deck[i][j] << " ";
        myfile << i + 1 << endl;
    }
    myfile.close();
}
