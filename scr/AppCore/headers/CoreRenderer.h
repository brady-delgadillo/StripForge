#pragma once

struct CoreRenderer {
	int currentPage = 0;
public:
	int getCurrentPage() { return currentPage; }
	void setCurrentPage(int to) {
		if (to > MAX_PAGES || to < 0)
			std::cerr << "OUT OF BOUNDS IN CORESTRIPS" << std::endl; return;
		currentPage = to;
	}
};