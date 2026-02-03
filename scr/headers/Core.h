#pragma once

#include <bitset>
#include <vector>
#include <map>

#include "../commands/command.h"
#include "Strip.h"

//Univeral Constants, never changes
#define MAX_PAGES 8


struct MasterStripHolder {
	std::vector<Strips::Strip> allStrips;

	//Int 1: Rail ID | Int 2: Page Number
	std::map<int, int> railHolderData;

public:
	void addStrip(Strips::Strip strip) { allStrips.push_back(strip); }
	void removeStrip(int pos) { allStrips.erase(allStrips.begin() + pos); }
	int getStripPos(Strips::Strip& strip) {
		int index = 0;
		for (Strips::Strip& strips : allStrips) {
			if (strip.equals(strips)) { return index; }
			index++;
		}
		return -1;
	}
};

class AppCore {
protected:
	/* Bits (From Left to Right) Bit 1 - Running, Bit 0 - Rendering*/
	std::bitset<2> runningFlags{ 00 };

	std::vector<std::unique_ptr<Command>> commandsList;

	//Page Rendering Settings (Can hold 2^3 pages, max 3 stripbars per page 3^p)
	int currentPageRender = 0;

	//Strip Header
	MasterStripHolder strips = MasterStripHolder();
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
	MasterStripHolder& getStrips() { return strips; }
};