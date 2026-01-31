#include "./headers/Utils.h"

std::string Utils::parseAltitudes(std::string alt)
{
	double inputedNum = 0;
	try {
		inputedNum = std::stoi(alt);
	}
	catch (const std::exception& e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return alt;
	}
	//Below 100
	if (inputedNum / 100 < 1) {
		return "Alt " + std::to_string(static_cast<int>(inputedNum));
	}
	//Below 1000
	else if ((inputedNum / 1000) < 1) {
		return "A00" + std::to_string(static_cast<int>(roundToDecimal(inputedNum / 1000, 1) * 10));
	}
	//Above 1000 but below 10000
	else if ((inputedNum / 1000) < 10){
		return "A0" + std::to_string(static_cast<int>(roundToDecimal(inputedNum / 10000, 1) * 100));
	}
	else {
		return "A" + std::to_string(static_cast<int>(roundToDecimal(inputedNum / 100000, 3) * 1000));
	}
	return std::string();
}

double Utils::roundToDecimal(double value, int decimalPlaces) {
	const double multiplier = std::pow(10.0, decimalPlaces);
	// Multiply by 10^n, round to nearest integer, then divide by 10^n
	return std::round(value * multiplier) / multiplier;
}
