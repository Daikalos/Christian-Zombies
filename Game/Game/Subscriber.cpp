#include "stdafx.h"
#include "Subscriber.h"
#include "Postmaster.h"

Subscriber::Subscriber()
{

}

Subscriber::~Subscriber()
{

}

void Subscriber::SendMessage(const MessageType &aMessage)
{
	Postmaster::GetMessage(aMessage);
}
