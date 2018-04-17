#pragma once
#include "Command.h"
#include "Calculator.h"

class AddCommand :virtual public Command {
private:
	Calculator * calc;
	int x;
public:
	AddCommand(Calculator *_calc, int _x) :calc(_calc), x(_x) {}
	void execute() {
		calc->add(x);
	}
	void undo() {
		calc->substract(x);
	}
};

class SubstractCommand :virtual public Command {
private:
	Calculator * calc;
	int x;
public:
	SubstractCommand(Calculator *_calc, int _x) :calc(_calc), x(_x) {}
	void execute() {
		calc->substract(x);
	}
	void undo() {
		calc->add(x);
	}
};

class DivideCommand :virtual public Command {
private:
	Calculator * calc;
	int x;
public:
	DivideCommand(Calculator *_calc, int _x) :calc(_calc), x(_x) {}
	void execute() {
		calc->divide(x);
	}
	void undo() {
		calc->multiply(x);
	}
};

class MultiplyCommand :virtual public Command {
private:
	Calculator * calc;
	int x;
public:
	MultiplyCommand(Calculator *_calc, int _x) :calc(_calc), x(_x) {}
	void execute() {
		calc->multiply(x);
	}
	void undo() {
		calc->divide(x);
	}
};
