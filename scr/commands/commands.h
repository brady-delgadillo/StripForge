#pragma once

#include "command.h"

class AddCommand : public Command {
public:
	AddCommand() {
		regexCommand = R"(^add [A-Za-z0-9]+(\s([A-Za-z]+\s)+)[0-9]+$)";
		//Regex String only really need for the command name for syntax errors
		regexString = "add [A-Za-z0-9]+(\s([A-Za-z]+\s)+)[0-9]+$";
	}

	void run() override {
		std::cout << "Add Command Triggered" << std::endl;
	}
};
