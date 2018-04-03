using namespace std;

//class RECEIVER

class IReceiver{
	public:
		int idAction;
		virtual void setAction(int _action)=0;
		virtual int getResult()=0;
};

//class command
class Command{
	public:
		IReceiver *receiver;
		Command(IReceiver *_receiver):receiver(_receiver){
			
		}
		virtual int execute()=0;
};

class AddCommand : public Command{
	public:
		AddCommand(IReceiver *_receiver):Command(_receiver){
			
		}
		int execute(){
			receiver->setAction(1);
			return receiver->getResult();
		}
};

class SubstractCommand : public Command{
	public:
		SubstractCommand(IReceiver *_receiver):Command(_receiver){
			
		}
		int execute(){
			receiver->setAction(2);
			return receiver->getResult();
		}
};

//class calculator
class Calculator: public IReceiver{
	int x;
	int y;
	int currentIdAction;
	
	public:
		Calculator(int _x, int _y):x(_x),y(_y){
			
		}
		void setAction(int _action){
			currentIdAction = _action;
		}
		int getResult(){
			int result;
			if(currentIdAction == 1){
				result = x + y;
			}else if(currentIdAction == 2){
				result = x / y;
			}
			return result;
		}
};



