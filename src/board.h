#ifndef _BOARD_H
#define _BOARD_H
using namespace std;
#define S 8

#include "board_print_plain.h"
#include "board_read.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>

void readTxt();
void PrintBoard(char deck[S][S]);
void Move(char deck[8][8], int l);
void CheckInput(char a[], int& x1, int& x2, int& y1, int& y2);
#endif
