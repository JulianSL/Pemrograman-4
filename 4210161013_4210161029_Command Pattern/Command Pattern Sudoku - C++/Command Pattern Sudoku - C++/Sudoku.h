#pragma once

using namespace std;

class Sudoku {
private:
	int board[9][9] = {};
	int xPos;
	int yPos;
public:
	void initBoard();
	void printBoard();
	void fillCell(int _x, int _y, int _num);
	void removeCell(int _x, int _y);
};
