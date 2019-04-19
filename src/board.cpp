#include "board.h"

void Move(char deck[8][8], int l)
{
    char fir[6], sec[6];
    int x1, x2, y1, y2;
    cout << ++l << ".";
    cin >> fir >> sec;

    CheckInput(fir, x1, x2, y1, y2);
    deck[x2][y2] = deck[x1][y1];
    deck[x1][y1] = 32;

    cout << ++l << ".";
    cin >> fir;
    cout << endl;
    PrintBoard(deck);
    readTxt();

    CheckInput(sec, x1, x2, y1, y2);
    deck[x2][y2] = deck[x1][y1];
    deck[x1][y1] = 32;

    cin >> fir;
    cout << endl;
    PrintBoard(deck);
    readTxt();
}

void CheckInput(char a[], int& x1, int& x2, int& y1, int& y2)
{
    x1 = (int)a[1] - 49;
    x2 = (int)a[4] - 49;
    y1 = (int)a[0] - 97;
    y2 = (int)a[3] - 97;

    if ((x1 < 0) || (x1 > 7) || (x2 < 0) || (x2 > 7) || (y1 < 0) || (y1 > 7)
        || (y2 < 0) || (y2 > 7)) {
        cout << "Ups, you are around the board!\n";
        exit(-1);
    }
}
