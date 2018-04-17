#pragma once
#include <stack>
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
