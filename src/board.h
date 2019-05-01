#ifndef _BOARD_H
#define _BOARD_H
#define S 8

#include "PrintBoard.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintBoard(char deck[S][S]);
int Move(char deck[8][8], int l);

int CheckInput(int move[]);
void Fill(char move[5], int moveint[4]);
void makeMove(char deck[S][S], int move[]);

int wPawn(char deck[8][8], int move[4]);
int bPawn(char deck[8][8], int move[4]);
int Rook(char deck[8][8], int moveInt[4]);
int Queen(char deck[8][8], int moveInt[4]);
int Horse(char deck[8][8], int moveInt[4]);
int King(char deck[8][8], int moveInt[4]);

int check_figure(char deck[8][8], int move[4]);

#endif
