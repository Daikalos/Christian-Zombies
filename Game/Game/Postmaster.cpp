#include "stdafx.h"
#include "Postmaster.h"

std::vector<Subscriber*> Postmaster::mySubscribers;

Postmaster::~Postmaster()
{

}

void Postmaster::Unsubscribe(Subscriber *aSubscriber)
{
	for (size_t i = mySubscribers.size(); i > 0; i--)
	{
		if (mySubscribers[i - 1] == aSubscriber)
		{
			mySubscribers[i - 1] = NULL;
			delete mySubscribers[i - 1];

			mySubscribers.erase(mySubscribers.begin() + (i - 1));
		}
	}
}

void Postmaster::Subscribe(Subscriber *aSubscriber)
{
	mySubscribers.push_back(aSubscriber);
}
	
void Postmaster::GetMessage(const MessageType &aMessageType)
{
	for (size_t i = mySubscribers.size(); i > 0; i--)
	{
		mySubscribers[i - 1]->RecieveMessage(aMessageType);
	}
}
