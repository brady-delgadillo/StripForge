#pragma once
#include <iostream>
#include <string>
#include <cmath>

class Utils {
public:
	static std::string parseAltitudes(std::string alt);
	static double roundToDecimal(double value, int decimalPlaces);
};