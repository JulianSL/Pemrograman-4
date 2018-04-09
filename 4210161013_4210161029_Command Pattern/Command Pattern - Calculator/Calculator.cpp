#include <iostream>
#include <queue>
#include "Calculator.h"
using namespace std;

int main(){
	int firstOperand, secondOperand;
	char idOperation;
	cout<<"masukkan operand :";
	cin>>firstOperand;
	cout<<"masukakn operator ( x , - , / , * ):";
	cin>>idOperation;
	cout<<"masukkan operand :";
	cin>>secondOperand;
	Calculator calculator(firstOperand,secondOperand);
	Command *command(0);
	AddCommand			addCmd(&calculator);
	SubstractCommand	strCmd(&calculator);
	DivideCommand		divCmd(&calculator);
	MultiplyCommand		mltyCmd(&calculator);
	switch(idOperation){
		case '+':
			command = &addCmd;
			break;
		case '-':
			command = &strCmd;
			break;
		case '/':
			command = &divCmd;
			break;
		case '*':
			command = &mltyCmd;
			break;
	}
	
	int result = command->execute();
	cout<<result<<endl;
}
