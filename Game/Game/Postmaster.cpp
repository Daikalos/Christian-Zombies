#include "stdafx.h"
#include "Postmaster.h"

std::vector<MessageType> Postmaster::myMessages;

Postmaster::Postmaster()
{

}

Postmaster::~Postmaster()
{

}

void Postmaster::RecieveMessage(MessageType aMessage)
{
	myMessages.push_back(aMessage);
}

void Postmaster::DeleteMessage(MessageType aMessageType, int aPosition)
{
	myMessages.erase(myMessages.begin() + aPosition);
}

bool Postmaster::GetMessage(MessageType aMessageType)
{
	for (size_t i = myMessages.size(); i > 0; i--)
	{
		if (myMessages[i - 1] == aMessageType)
		{
			DeleteMessage(myMessages[i - 1], (i- 1));
			return true;
		}
	}
	return false;
}
