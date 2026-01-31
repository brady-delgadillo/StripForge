#pragma once
#include <vector>
#include "Strip.h"

class StripManager {
public:
	static StripManager& getInstance();

	std::vector<Strips::Strip> allStrips;

private:
	StripManager() = default;
	StripManager(const StripManager&) = delete;
	StripManager& operator=(const StripManager&) = delete;
};