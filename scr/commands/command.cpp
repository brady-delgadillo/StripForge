#include "command.h"

matchStates Command::matchesPattern(std::string& compare) const
{
	if (std::regex_match(compare, regexCommand)) {
		return MATCHFULL;
	}
	else if (compare.substr(0, compare.find(' ')) == regexString.substr(0, regexString.find(' '))) {
		return MATCHPART;
	}
	return NOMATCH;
}
