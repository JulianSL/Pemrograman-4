#include "stdafx.h"
#include <stack>
#include <iostream>
#include "Invoker.h"

using namespace std;

void Invoker::setCommand(Command *_cmd) {
	Invoker::cmd = _cmd;
	Invoker::undos.push(cmd);
}

void Invoker::executeCommand() {
	Invoker::cmd->execute();
}

void Invoker::undoCommand() {
	Invoker::cmd = undos.top();
	Invoker::undos.pop();
	Invoker::cmd->undo();
}