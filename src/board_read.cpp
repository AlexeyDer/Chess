#include "board_read.h"

void readTxt()
{
    string line;
    ifstream in("/home/alexeyder/Documents/progs/Chess/output.txt");

    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close(); 
}