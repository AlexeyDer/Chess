#define CTEST_MAIN
#define CTEST_COLOR_OK
#include "PrintBoard.h"
#include "board.h"
#include "ctest.h"

char deck[S][S] = {
        {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'},
};

CTEST(check_figure, Correct)
{
    int move[4];
    Fill("a2-a4", move);
    int res = check_figure(deck, move);
    int a = 1;
    ASSERT_EQUAL(a, res);
}

CTEST(check_Figure, Incorrect)
{
    int move[4];
    Fill("a3-a4", move);
    int res = check_figure(deck, move);
    int a = 0;
    ASSERT_EQUAL(a, res);
}

CTEST(pawn_move, Correct)
{
    int move[4], res = 0;
    Fill("a2-a4", move);
    if (check_figure(deck, move)
        && ((deck[move[1]][move[0]] == 'p') || (deck[move[1]][move[0]] == 'P')))
        res = Pawn(deck, move);
    int a = 1;
    ASSERT_EQUAL(a, res);
}

CTEST(pawn_move, Incorrect)
{
    int move[4], res = 0;
    Fill("a2-a5", move);
    if (check_figure(deck, move)
        && ((deck[move[1]][move[0]] == 'p') || (deck[move[1]][move[0]] == 'P')))
        res = Pawn(deck, move);
    int a = 0;
    ASSERT_EQUAL(a, res);
}

CTEST(PAWN_move, Correct)
{
    int move[4], res = 0;
    Fill("a7-a5", move);
    if (check_figure(deck, move)
        && ((deck[move[1]][move[0]] == 'p') || (deck[move[1]][move[0]] == 'P')))
        res = Pawn(deck, move);
    int a = 1;
    ASSERT_EQUAL(a, res);
}

CTEST(PAWN_move, Incorrect)
{
    int move[4], res = 0;
    Fill("a7-a4", move);
    if (check_figure(deck, move)
        && ((deck[move[1]][move[0]] == 'p') || (deck[move[1]][move[0]] == 'P')))
        res = Pawn(deck, move);
    int a = 0;
    ASSERT_EQUAL(a, res);
}

CTEST(check_input, Correct)
{
    int move[4], res = 0;
    Fill("a7-a4", move);
    res = CheckInput(move);
    int a = 1;
    ASSERT_EQUAL(a, res);
}

CTEST(check_input, Incorrect)
{
    int move[4], res = 0;
    Fill("a1-a9", move);
    res = CheckInput(move);
    int a = 0;
    ASSERT_EQUAL(a, res);
}

CTEST(check_input_2, Correct)
{
    int move[4], res = 0;
    Fill("a1-a8", move);
    res = CheckInput(move);
    int a = 1;
    ASSERT_EQUAL(a, res);
}

CTEST(check_input_2, Incorrect)
{
    int move[4], res = 0;
    Fill("a0-a8", move);
    res = CheckInput(move);
    int a = 0;
    ASSERT_EQUAL(a, res);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
