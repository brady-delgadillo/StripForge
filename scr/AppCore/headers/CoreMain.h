#pragma once

#include <bitset>
#include <vector>
#include <map>

#include "../commands/command.h"
#include "Strip.h"

#include "CoreStrips.h"
#include "CoreRenderer.h"

class AppCore {
protected:
	/* Bits (From Left to Right) Bit 1 - Running, Bit 0 - Rendering*/
	std::bitset<2> runningFlags{ 00 };

	std::vector<std::unique_ptr<Command>> commandsList;

	//Page Rendering Settings (Can hold 2^3 pages, max 3 stripbars per page 3^p)
	int currentPageRender = 0;

	//Strip Header
	CoreStrips strips = CoreStrips();
	CoreRenderer renderer = CoreRenderer();
public:
	//Running Flags Setters
	void setRunning(bool setTo);
	void setRendering(bool setTo);

	bool isRunning();
	bool isRendering();

	//Page Rendering Setting Setters
	void setPage(int page);
	int getCurrentPage();

	//Command Functions
	void addCommand(std::unique_ptr<Command> c);
	//Finds the command that works based on the inputed item.
	Command* findCommand(std::string inputedCommand);

	//StripGetting
	CoreStrips& getStrips() { return strips; }
	CoreRenderer& getRenderer() { return renderer; }
};