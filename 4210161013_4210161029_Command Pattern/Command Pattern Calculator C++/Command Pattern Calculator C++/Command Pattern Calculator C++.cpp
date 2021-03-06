// Command Pattern Calculator C++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Command.h"
#include "Calculator.h"
#include "Controller.h"
#include "ConcreteCommand.h"
#include <iostream>
#include <cstdio>

using namespace std;

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

