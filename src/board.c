#include "board.h"

void Fill(char move[5], int moveint[4])
{
    moveint[0] = move[0] - 97;
    moveint[1] = move[1] - 49;
    moveint[2] = move[3] - 97;
    moveint[3] = move[4] - 49;
}

int check_figure(char deck[8][8], int move[4])
{
    if ((deck[move[1]][move[0]] == 'p') || (deck[move[1]][move[0]] == 'P')
        || (deck[move[1]][move[0]] == 'q') || (deck[move[1]][move[0]] == 'Q')
        || (deck[move[1]][move[0]] == 'r') || (deck[move[1]][move[0]] == 'R')
        || (deck[move[1]][move[0]] == 'H') || (deck[move[1]][move[0]] == 'h')
        || (deck[move[1]][move[0]] == 'B') || (deck[move[1]][move[0]] == 'b')
        || (deck[move[1]][move[0]] == 'K') || (deck[move[1]][move[0]] == 'k'))
        return 1;
    else
        return 0;
}

///////////////////////////////pawn

int Pawn(char deck[8][8], int move[4])
{
    if ((deck[move[3]][move[2]] == ' ') && (move[0] == move[2])
        && ((abs(move[1] - move[3]) == 1) || (abs(move[1] - move[3]) == 2)))
        return 1;
    else
        return 0;
}
//////////////////////////////////////////////////////////////////////////////////////
//// 0 1 2 3
//// a 2 a 2
///////////////Rook

int Rook(char deck[8][8], int moveInt[4])
{
    int Counter = 0;

    if ((moveInt[0] == moveInt[2]) || (moveInt[1] == moveInt[3])) {
        if (moveInt[0] == moveInt[2])
            for (int i = moveInt[1] + 1; i < moveInt[3]; i++) {
                if (deck[i][moveInt[0]] != ' ') {
                    if (abs(deck[moveInt[1]][moveInt[0]] - deck[i][moveInt[0]])
                        > 17)
                        deck[i][moveInt[0]] = ' ';
                    else
                        Counter = 1;
                }
            }
        else if (moveInt[1] == moveInt[3])
            for (int i = moveInt[0] + 1; i < moveInt[2]; i++) {
                if (deck[moveInt[1]][i] != ' ') {
                    if (abs(deck[moveInt[1]][moveInt[0]] - deck[moveInt[1]][i])
                        > 17)
                        deck[moveInt[1]][i] = ' ';
                    else
                        Counter = 1;
                }
            }

        if (Counter < 1 || Counter > 1)
            return 1;
    }
    return 0;
}

int Queen(char deck[8][8], int moveInt[4])
{
    int Counter = 0;
    int i, j;

    if ((moveInt[0] == moveInt[2]) || (moveInt[1] == moveInt[3])
        || (abs(moveInt[0] - moveInt[2]) == abs(moveInt[1] - moveInt[3]))) {
        if (moveInt[0] == moveInt[2])
            for (i = moveInt[1] + 1; i < moveInt[3]; i++) {
                if (deck[i][moveInt[0]] != ' ') {
                    if (abs(deck[moveInt[1]][moveInt[0]] - deck[i][moveInt[0]])
                        > 17)
                        deck[i][moveInt[0]] = ' ';
                    else
                        Counter = 1;
                }
            }
        else if (moveInt[1] == moveInt[3])
            for (j = moveInt[0] + 1; j < moveInt[2]; j++) {
                if (deck[moveInt[1]][j] != ' ') {
                    if (abs(deck[moveInt[1]][moveInt[0]] - deck[moveInt[1]][j])
                        > 17)
                        deck[moveInt[1]][j] = ' ';
                    else
                        Counter = 1;
                }
            }
        if (abs(moveInt[0] - moveInt[2]) == abs(moveInt[1] - moveInt[3])) {
            for (i = moveInt[1] + 1, j = moveInt[0] + 1; i < moveInt[3];
                 i++, j++) {
                if (deck[i][j] != ' ') {
                    if (abs(deck[moveInt[1]][moveInt[0]] - deck[i][j]) > 17)
                        deck[i][j] = ' ';
                    else
                        Counter = 1;
                }
            }
        }
        if (Counter < 1 || Counter > 1)
            return 1;
    }

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////Bishop

int Bishop(char deck[8][8], char move[5], int moveInt[4]) //
{
    int Counter = 0;

    if (abs(moveInt[0] - moveInt[2]) == abs(moveInt[1] - moveInt[3])) {
        for (int i = moveInt[1] + 1, j = moveInt[0] + 1; i < moveInt[3];
             i++, j++) {
            if (deck[i][j] != ' ') {
                if (abs(deck[moveInt[1]][moveInt[0]] - deck[i][j]) > 17)
                    deck[i][j] = ' ';
                else
                    Counter = 1;
            }
        }
        if (Counter < 1 || Counter > 1)
            return 1;
    }

    return 0;
}

int Horse(char deck[8][8], int moveInt[4])
{
    if (((abs(moveInt[1] - moveInt[3]) == 1)
         && (abs(moveInt[0] - moveInt[2]) == 2))
        || ((abs(moveInt[1] - moveInt[3]) == 2)
            && (abs(moveInt[0] - moveInt[2]) == 1)))
        return 1;
    return 0;
}

int King(char deck[8][8], int moveInt[4])
{
    if (((abs(moveInt[3] - moveInt[1]) == 1)
         || (abs(moveInt[3] - moveInt[1]) == 0))
        && ((abs(moveInt[3] - moveInt[1]) == 1)
            || (abs(moveInt[3] - moveInt[1]) == 0)))
        return 1;
    return 0;
}

int Move(char deck[8][8], int l)
{
    char move[5];
    int moveInt[4];

    printf("%d.", ++l);
    scanf("%s", move);
    Fill(move, moveInt);

    if (check_figure(deck, moveInt) && CheckInput(moveInt)) {
        if (l % 2) {
            if ((deck[moveInt[1]][moveInt[0]] == 'p') && Pawn(deck, moveInt))
                makeMove(deck, moveInt);
            else if (
                    (deck[moveInt[1]][moveInt[0]] == 'r')
                    && Rook(deck, moveInt))
                makeMove(deck, moveInt);
            else if (
                    (deck[moveInt[1]][moveInt[0]] == 'q')
                    && Queen(deck, moveInt))
                makeMove(deck, moveInt);
            else if (
                    (deck[moveInt[1]][moveInt[0]] == 'b')
                    && Bishop(deck, move, moveInt))
                makeMove(deck, moveInt);
            else if (
                    (deck[moveInt[1]][moveInt[0]] == 'h')
                    && Horse(deck, moveInt))
                makeMove(deck, moveInt);
            else if (
                    (deck[moveInt[1]][moveInt[0]] == 'k')
                    && King(deck, moveInt))
                makeMove(deck, moveInt);
            else
                return 1;

        } else {
            if ((deck[moveInt[1]][moveInt[0]] == 'P') && Pawn(deck, moveInt))
                makeMove(deck, moveInt);
            else if (
                    (deck[moveInt[1]][moveInt[0]] == 'R')
                    && Rook(deck, moveInt))
                makeMove(deck, moveInt);
            else if (
                    (deck[moveInt[1]][moveInt[0]] == 'Q')
                    && Queen(deck, moveInt))
                makeMove(deck, moveInt);
            else if (
                    (deck[moveInt[1]][moveInt[0]] == 'B')
                    && Bishop(deck, move, moveInt))
                makeMove(deck, moveInt);
            else if (
                    (deck[moveInt[1]][moveInt[0]] == 'H')
                    && Horse(deck, moveInt))
                makeMove(deck, moveInt);
            else if (
                    (deck[moveInt[1]][moveInt[0]] == 'K')
                    && King(deck, moveInt))
                makeMove(deck, moveInt);
            else
                return 1;
        }
    } else
        exit(3);
    return 0;
}

void makeMove(char deck[S][S], int move[4])
{
    deck[move[3]][move[2]] = deck[move[1]][move[0]];
    deck[move[1]][move[0]] = ' ';
}

int CheckInput(int move[4])
{
    if ((move[0] < 0) || (move[0] > 7) || (move[1] < 0) || (move[1] > 7)
        || (move[2] < 0) || (move[2] > 7) || (move[3] < 0) || (move[3] > 7)) {
        return 0;
    } else {
        return 1;
    }
}
