#include "PrintBoard.h"

void PrintBoard(char deck[S][S])
{
    printf("BIG is black, SMALL is white!\n");
    printf("  A B C D E F G H\n");
    for (int i = 0; i < S; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < S; j++)
            printf("%c ", deck[i][j]);
        printf("%d\n", i + 1);
    }
    printf("  A B C D E F G H\n");
}