#ifndef NCF_H
#define NCF_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "stdafx.h"

struct ConversationPart 
{
	std::vector<std::string> myKeywords;
	std::string myName;
	std::string myDialogue;
};

class NCFReader
{
public:
	std::vector<std::string> ReadUnfiltered(std::string aFileDirectory);
	std::vector<ConversationPart> ReadFiltered(std::string aFileDirectory);
	std::vector<ConversationPart> ReadFiltered(std::vector<std::string> anUnfilteredDialogueVector);
};

#endif
