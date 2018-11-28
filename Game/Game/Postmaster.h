#ifndef POSTMASTER_HEADER
#define POSTMASTER_HEADER

#include "stdafx.h"
#include "Subscriber.h"
#include <vector>

class Postmaster
{
public:
	~Postmaster();
	
	static void Unsubscribe(Subscriber *aSubscriber);
	static void Subscribe(Subscriber *aSubscriber);
	static void GetMessage(const MessageType &aMessageType);

private:
	Postmaster() {};
	static std::vector<Subscriber*> mySubscribers;
};

#endif // !POSTMASTER_HEADER

