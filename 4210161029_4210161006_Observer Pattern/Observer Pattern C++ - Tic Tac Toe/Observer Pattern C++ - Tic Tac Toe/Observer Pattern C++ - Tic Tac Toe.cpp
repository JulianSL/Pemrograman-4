// Observer Pattern C++ - Tic Tac Toe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
	Player *player1 = new Player;
	Player *player2 = new Player;
	player1->name = "julian";
	player2->name = "akbar";
	Board board;
	board.initBoard();
	board.attachPlayer(player1);
	board.attachPlayer(player2);
	board.drawBoard();
	board.notify();
	getchar();
}

