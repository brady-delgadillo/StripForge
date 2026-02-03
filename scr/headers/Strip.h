#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;
namespace Strips {

	enum StripType {
		TERMINALARR,
		TERMINALDEP,
		TERMINALOVER,
		ENROUTE,
	};
	enum Standard {
		FAA,
		ICAO
	};
	//StripClass

	class Strip {
	public:
		StripType type;
		std::string callsign;
		std::string from;
		std::string to;
		std::string altitude;
		bool cleared = false;

		int ID;

		int currentRack = 1;
		//Func
		Strip(StripType stripType, string callsign, string from, string to, string alt);

		bool equals(Strip& compare);
	};
}