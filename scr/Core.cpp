#include "./headers/Core.h"

void AppCore::setRunning(bool setTo)
{
	if (setTo) {
		runningFlags.set(1, 1);
	}
	else {
		runningFlags.set(1, 0);
	}
}

void AppCore::setRendering(bool setTo)
{
	if (setTo) {
		runningFlags.set(0, 1);
	}
	else {
		runningFlags.set(0, 0);
	}
}

bool AppCore::isRunning()
{
	return runningFlags.test(1);
}

bool AppCore::isRendering()
{
	return runningFlags.test(0);
}

void AppCore::setPage(int page)
{
	if (page > MAX_PAGES) {
		std::cerr << "Out of bounds, " << page << ">8" << std::endl;
		std::cerr << "Will keep current page to " << getCurrentPage() << std::endl;
		return;
	}
	else if (page < 0) {
		std::cerr << "Out of bounds, " << page << "<0" << std::endl;
		std::cerr << "Will keep current page to " << getCurrentPage() << std::endl;
		return;
	}

	currentPageRender = page;
}

int AppCore::getCurrentPage()
{
	return currentPageRender;
}

void AppCore::addCommand(std::unique_ptr<Command> c)
{
	commandsList.push_back(std::move(c));
}

Command* AppCore::findCommand(std::string inputedCommand)
{
	for (auto& cmd : commandsList) {
		if (cmd->matchesPattern(inputedCommand) == MATCHFULL)
			return cmd.get();
		else if (cmd->matchesPattern(inputedCommand) == MATCHPART)
			std::cout << "Synatx Error" << std::endl;
			continue;
	}
	return nullptr;
}
