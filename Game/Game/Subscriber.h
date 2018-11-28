#ifndef SUBSCRIBER_HEADER
#define SUBSCRIBER_HEADER

enum MessageType //All actions 
{
	Type1,
	Type2,
	Type3
};

class Subscriber
{
public:
	Subscriber();
	virtual ~Subscriber();

	void SendMessage(const MessageType &aMessage);
	virtual void RecieveMessage(const MessageType &aMessage) = 0;
};

#endif // !SUBSCRIBER_HEADER

