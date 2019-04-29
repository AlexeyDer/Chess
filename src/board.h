#ifndef _BOARD_H
#define _BOARD_H
#define S 8

#include "PrintBoard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintBoard(char deck[S][S]);
void Move(char deck[8][8], int l, int step);

int CheckInput(int move[]);
void Fill(char move[5], int moveint[4]);
void makeMove(char deck[S][S], int move[]);

#endif
