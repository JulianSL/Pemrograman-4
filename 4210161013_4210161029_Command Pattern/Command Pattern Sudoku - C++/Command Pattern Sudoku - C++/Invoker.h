#pragma once
#include <iostream>
#include <stack>
#include "Command.h"

using namespace std;

class Invoker {
private:
	stack<Command*> undos;
	Command *cmd;
public:
	void setCommand(Command *_cmd);
	void executeCommand();
	void undoCommand();
};