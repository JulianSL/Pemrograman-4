//class RECEIVER
class IReceiver{
	public:
		char idAction;
		virtual void setAction(char _action)=0;
		virtual int getResult()=0;
};
