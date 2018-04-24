#include "stdafx.h"
#include <iostream>
#include "Board.h"

using namespace std;

void Board::initBoard() {
	for (int i = 0; i < 9; i++)
	{
		Board::square[i] = 'O';
	}
}

void Board::drawBoard() {
	for (int i = 0; i < 3; i++)
	{
		cout << Board::square[i*i] << " | " << Board::square[i*i + 1] << " | " << Board::square[i*i + 2] << " | ";
		cout << endl;
	}
}

void Board::attachPlayer(Player *_player) {
	Board::players.push_back(_player);
	cout << "new player attached. Total player "<<Board::players.size()<< endl;
}

void Board::notify() {
	for (vector<Player*>::const_iterator iter = players.begin(); iter != players.end(); ++iter)
	{
		if (*iter != 0)
		{
			(*iter)->update();
		}
	}
}