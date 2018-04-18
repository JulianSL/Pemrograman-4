#pragma once
#include "Command.h"
#include "Sudoku.h"

class FillCommand : virtual public Command {
private:
	Sudoku * sudoku;
	int x;
	int y;
	int num;
public:
	FillCommand(Sudoku * _sudoku, int _x, int _y, int _num);
	void execute();
	void undo();
};

class RemoveCommand : virtual public Command {
private:
	Sudoku * sudoku;
	int x;
	int y;
	int num;
public:
	RemoveCommand(Sudoku * _sudoku, int _x, int _y);
	void execute();
	void undo();
};