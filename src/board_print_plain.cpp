#include "board_print_plain.h"

void PrintBoard(char deck[S][S])
{
    ofstream myfile("/home/alexeyder/Documents/progs/Chess/output.txt");
    myfile << "BIG is white, SMALL is black!\n";
    myfile << "  A B C D E F G H\n";
    for (int i = 0; i < S; i++) {
        myfile << i + 1 << " ";
        for (int j = 0; j < S; j++)
            myfile << deck[i][j] << " ";
        myfile << i + 1 << endl;
    }
    myfile << "  A B C D E F G H\n";
    myfile.close();
}
