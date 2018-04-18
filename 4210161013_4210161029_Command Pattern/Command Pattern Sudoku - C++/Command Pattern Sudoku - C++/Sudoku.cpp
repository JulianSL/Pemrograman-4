#include "stdafx.h"
#include "Sudoku.h"
#include <iostream>

using namespace std;

void Sudoku::initBoard() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			Sudoku::board[i][j] = 0;
		}
	};
}

void Sudoku::printBoard() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << Sudoku::board[i][j] << " ";
			if ((j + 1) % 3 == 0) {
				cout << "|";
			}
		}
		if (( i + 1 ) % 3 == 0) {
			cout << endl << "_____________________";
		}
		cout << endl;
	};
}

void Sudoku::fillCell(int _x, int _y, int _num) {
	if (board[_x][_y] == 0) {
		Sudoku::board[_x][_y] = _num;
	}
}

void Sudoku::removeCell(int _x, int _y) {
	if (board[_x][_y] != 0) {
		Sudoku::board[_x][_y] = 0;
	}
}