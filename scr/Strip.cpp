#include "./headers/Strip.h"

Strips::Strip::Strip(StripType stripType, string callsign, string from, string to, string alt) {
	this->type = stripType;
	this->callsign = callsign;
	this->from = from;
	this->to = to;
	this->altitude = alt;
	this->ID = Utils::randomID();

	cout << "ID: " << this->ID << endl;
}

bool Strips::Strip::equals(Strip& compare)
{
	return compare.ID == this->ID;
}
