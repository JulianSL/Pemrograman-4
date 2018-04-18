#include"stdafx.h"
#include <iostream>
#include "ConcreteCommand.h"

using namespace std;

FillCommand::FillCommand(Sudoku *_sudoku, int _x, int _y, int _num) {
	sudoku = _sudoku;
	x = _x;
	y = _y;
	num = _num;
}

void FillCommand::execute() {
	sudoku->fillCell(x, y, num);
}

void FillCommand::undo() {
	sudoku->removeCell(x, y);
}

RemoveCommand::RemoveCommand(Sudoku *_sudoku, int _x, int _y) {
	sudoku = _sudoku;
	x = _x;
	y = _y;
}

void RemoveCommand::execute() {
	sudoku->removeCell(x, y);
}

void RemoveCommand::undo() {

}

