#include "stdafx.h"
#include "NCFReader.h"

std::vector<std::string> NCFReader::ReadUnfiltered(std::string aFileDirectory)
{
	std::vector<std::string> outputOfFile;
	std::string line;
	std::ifstream myFile(aFileDirectory);
	if (myFile.is_open()) 
	{
		while (getline(myFile, line)) 
		{
			outputOfFile.push_back(line);
		}
		myFile.close();
		return outputOfFile;
	}
	else
	{
		std::cout << "Unable to open file";
	}
}

std::vector<ConversationPart> NCFReader::ReadFiltered(std::string aFileDirectory)
{
	std::vector<std::string> outputOfFile;
	std::string line;
	std::ifstream myFile(aFileDirectory);
	if (myFile.is_open()) 
	{
		while (getline(myFile, line)) 
		{
			outputOfFile.push_back(line);
		}
		myFile.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}

	std::vector<ConversationPart> conversations;

	for (size_t i = 1; i < outputOfFile.size(); i++) 
	{
		std::stringstream stringToSplit(outputOfFile[i].substr(9, outputOfFile.size() - 11));
		std::string segment;
		ConversationPart conversationPart;

		int j = 0;

		while (getline(stringToSplit, segment, '-'))
		{
			std::string updatedSegment;

			switch (j) 
			{
			case 0:
				updatedSegment = segment.substr(9);
				break;
			case 1:
				updatedSegment = segment.substr(5);
				break;
			case 2:
				updatedSegment = segment.substr(9);
				break;
			}

			std::stringstream keywords(updatedSegment);
			std::string keyword;

			switch (j) 
			{
			case 0:
				while (getline(keywords, keyword, ',')) 
				{
					conversationPart.myKeywords.push_back(keyword);
				}
				break;
			case 1:
				conversationPart.myName = updatedSegment.substr(1, updatedSegment.length() - 2);
				break;
			case 2:
				conversationPart.myDialogue = updatedSegment.substr(1, updatedSegment.length() - 2);
				break;
			}
			j++;
		}
		conversations.push_back(conversationPart);
	}

	return conversations;
}

std::vector<ConversationPart> NCFReader::ReadFiltered(std::vector<std::string> anUnfilteredDialogueVector)
{
	return std::vector<ConversationPart>();
}
