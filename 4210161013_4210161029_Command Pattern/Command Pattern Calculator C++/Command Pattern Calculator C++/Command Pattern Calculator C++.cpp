// Command Pattern Calculator C++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class Calculator {
public:
	Calculator() {
		current = 0;
	}
	int current;
	void add(int _x) {
		current += _x;
		cout << "hasil : "<<current << endl;
	}
	void substract(int _x) {
		current -= _x;
		cout << "hasil : " << current << endl;
	}
	void divide(int _x) {
		current = current / _x;
		cout << "hasil : " << current << endl;
	}
	void multiply(int _x) {
		current = current * _x;
		cout << "hasil : " << current << endl;
	}
};

class AddCommand :virtual public Command {
private:
	Calculator * calc;
	int x;
public:
	AddCommand(Calculator *_calc, int _x):calc(_calc),x(_x) {}
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

class Controller {
private:
	stack<Command*> undos;
	Command * cmd;
public:
	void setCommand(Command *_cmd) {
		cmd = _cmd;
		undos.push(cmd);
	}
	void executeCommand() {
		cmd->execute();
	}
	void undoCommand() {
		cout << "undo" << endl;
		cmd = undos.top();
		undos.pop();
		cmd->undo();
	}
};

int main()
{
	//receiver
	Calculator *calc = new Calculator;

	//invoker
	Controller *control = new Controller;

	//concrete commands object
	Command *cmd;

	//calculation operation
	cmd = new AddCommand(calc, 5);
	control->setCommand(cmd);
	control->executeCommand();
	control->undoCommand();

	cmd = new AddCommand(calc, 10);
	control->setCommand(cmd);
	control->executeCommand();

	cmd = new SubstractCommand(calc, 3);
	control->setCommand(cmd);
	control->executeCommand();

	cmd = new MultiplyCommand(calc, 2);
	control->setCommand(cmd);
	control->executeCommand();

	cmd = new DivideCommand(calc, 2);
	control->setCommand(cmd);
	control->executeCommand();
	getchar();
    return 0;
}

