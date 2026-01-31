#pragma once

#include <bitset>
#include <vector>

#include "../commands/command.h"

class AppCore {
protected:
	/* Bits (From Left to Right) Bit 1 - Running, Bit 0 - Rendering*/
	std::bitset<2> runningFlags{ 00 };

	std::vector<std::unique_ptr<Command>> commandsList;

public:
	//Running Flags Setters
	void setRunning(bool setTo);
	void setRendering(bool setTo);

	bool isRunning();
	bool isRendering();

	void addCommand(std::unique_ptr<Command> c);
	//Finds the command that works based on the inputed item.
	Command* findCommand(std::string inputedCommand);
};
