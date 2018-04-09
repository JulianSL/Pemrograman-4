#include "IReceiver.h"
using namespace std;

//class command
class Command{
	public:
		IReceiver *receiver;
		Command(IReceiver *_receiver):receiver(_receiver){
			
		}
		virtual int execute()=0;
};


