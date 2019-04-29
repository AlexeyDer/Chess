#include "board.h"

void Fill(char move[5], int moveint[4])
{
    moveint[0] = move[0] - 97;
    moveint[1] = move[1] - 49;
    moveint[2] = move[3] - 97;
    moveint[3] = move[4] - 49;
}

int wPawn(char deck[8][8], int move[4])
{
    if ((deck[move[3]][move[2]] == ' ') && (deck[move[1]][move[0]] == 'p')
        && (move[0] == move[2])
        && (((move[3] - move[1]) == 1) || ((move[3] - move[1]) == 2)))
        return 0;
    else
        return 1;
}

int bPawn(char deck[8][8], int move[4])
{
    if ((deck[move[3]][move[2]] == ' ') && (deck[move[1]][move[0]] == 'P')
        && (move[0] == move[2])
        && (((move[1] - move[3]) == 1) || ((move[1] - move[3]) == 2)))
        return 0;
    else
        return 1;
}

void Move(char deck[8][8], int l, int step)
{
    char move[5];
    int moveInt[4];

    if (l % 2) {
    }

    if (!step) {
        printf("%d.", ++l);
        scanf("%s", move);
        Fill(move, moveInt);
    }

    for (int i = 0; i < 4; i++)
        printf("%d ", moveInt[i]);
    printf("\n");
    if (!CheckInput(moveInt))
        exit(3);

    makeMove(deck, moveInt);
    PrintBoard(deck);
}

void makeMove(char deck[S][S], int move[4])
{
    deck[move[3]][move[2]] = deck[move[1]][move[0]];
    deck[move[1]][move[0]] = ' ';
}

int CheckInput(int move[])
{
    if ((move[0] < 0) || (move[0] > 7) || (move[1] < 0) || (move[1] > 7)
        || (move[2] < 0) || (move[2] > 7) || (move[3] < 0) || (move[3] > 7)) {
        return 0;
    } else {
        return 1;
    }
}
