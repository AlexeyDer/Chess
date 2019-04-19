#include "board.h"

int check_symbol(char a[], int n)
{
    switch (a[n]) {
    case 'a':
        return 0;
    case 'b':
        return 1;
    case 'c':
        return 2;
    case 'd':
        return 3;
    case 'e':
        return 4;
    case 'f':
        return 5;
    case 'g':
        return 6;
    case 'h':
        return 7;
    }
    return -1;
}

int check_reg(char one, char two)
{
    if ((one <= 'Z' && one >= 'A') && (two <= 'Z' && two >= 'A')) {
        return 0;
    }
    if ((one <= 'z' && one >= 'a') && (two <= 'z' && two >= 'a')) {
        return 0;
    }
    return 1;
}
