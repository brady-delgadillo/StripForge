#pragma once

#include <bitset>
#include <vector>
#include <map>

#define MAX_PAGES 8

struct CoreStrips {
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