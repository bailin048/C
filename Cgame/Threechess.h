#ifndef __Threechess_H__
#define __Threechess_H__
#include <stdio.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)
#define COL 3
#define ROW 3
#define Perchess 'X'
#define Comchess 'O'
#define Peace 'P'

void Board(char arr[][COL]);
void Player(char arr[][COL]);
char Judge(char arr[][COL]);
void Comp(char arr[][COL]);
void ThreeChess();

#endif
