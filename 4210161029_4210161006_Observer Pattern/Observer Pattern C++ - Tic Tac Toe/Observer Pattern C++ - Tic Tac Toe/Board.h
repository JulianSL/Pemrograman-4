#pragma once

#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

class Board {
public:
	vector<Player*> players;
	char square[9];
	void initBoard();
	void attachPlayer(Player *_player);
	void drawBoard();
	bool checkWin();
	void notify();
};
