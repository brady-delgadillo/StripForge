#pragma once

#include <regex>
#include <iostream>

enum matchStates {
	MATCHFULL,
	NOMATCH,
	MATCHPART
};

class Command {
protected:
	std::regex regexCommand;
	std::string regexString;
public:
	virtual void run() = 0;

	matchStates matchesPattern(std::string& compare) const;
};
