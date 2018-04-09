#include "Command.h"
class AddCommand : public Command{
	public:
		AddCommand(IReceiver *_receiver):Command(_receiver){
			
		}
		int execute(){
			receiver->setAction('+');
			return receiver->getResult();
		}
};

class SubstractCommand : public Command{
	public:
		SubstractCommand(IReceiver *_receiver):Command(_receiver){
			
		}
		int execute(){
			receiver->setAction('-');
			return receiver->getResult();
		}
};

class DivideCommand : public Command{
	public:
		DivideCommand(IReceiver *_receiver):Command(_receiver){
			
		}
		int execute(){
			receiver->setAction('/');
			return receiver->getResult();
		}
};

class MultiplyCommand : public Command{
	public:
		MultiplyCommand(IReceiver *_receiver):Command(_receiver){
			
		}
		int execute(){
			receiver->setAction('*');
			return receiver->getResult();
		}
};

//class calculator
class Calculator: public IReceiver{
	int x;
	int y;
	char currentIdAction;
	public:
		Calculator(int _x, int _y):x(_x),y(_y){}
		void setAction(char _action){
			currentIdAction = _action;
		}
		int getResult(){
			int result;
			if(currentIdAction == '+'){
				result = x + y;
			}else if(currentIdAction == '-'){
				result = x - y;
			}else if(currentIdAction == '/'){
				result = x / y;
			}else if(currentIdAction == '*'){
				result = x * y;
			}
			return result;
		}
};

