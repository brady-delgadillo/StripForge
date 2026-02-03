#pragma once
#include <iostream>
#include <string>
#include <cmath>

class Utils {
protected:
	static int currentID;
public:
	static std::string parseAltitudes(std::string alt);
	static double roundToDecimal(double value, int decimalPlaces);

	static int randomID();
};