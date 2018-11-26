#ifndef POSTMASTER_HEADER
#define POSTMASTER_HEADER

#include "stdafx.h"
#include <vector>

enum MessageType //All actions 
{
	Type1,
	Type2,
	Type3
};

class Postmaster
{
public:
	Postmaster();
	~Postmaster();
	
	static void RecieveMessage(MessageType aMessage);
	static void DeleteMessage(MessageType aMessageType, int aPosition);
	static bool GetMessage(MessageType aMessageType);

private:
	static std::vector<MessageType> myMessages;
};

#endif // !POSTMASTER_HEADER

