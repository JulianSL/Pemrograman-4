// Command Pattern Calculator C++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>

using namespace std;

class Command {
public:
	virtual void execute() = 0;
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
	void substract() {
		cout << "substract" << endl;
	}
	void divide() {
		cout << "divide" << endl;
	}
	void multiply() {
		cout << "multiply" << endl;
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
};

class Controller {
private:
	Command * cmd;
public:
	void setCommand(Command *_cmd) {
		cmd = _cmd;
	}
	void executeCommand() {
		cmd->execute();
	}
};

int main()
{
	//receiver
	Calculator *calc = new Calculator;

	//concrete commands object
	Command *cmd = new AddCommand(calc, 5);

	//invoker
	Controller *control = new Controller;

	control->setCommand(cmd);
	control->executeCommand();
	getchar();
    return 0;
}

