#include "sed.h"

std::string my_sed(std::string origin, std::string s1, std::string s2) {
	std::string repl;
	size_t start = 0;
	size_t pos = origin.find(s1);

	while (pos != std::string::npos) {
		if (pos == 0)
			repl += s2;
		else
			repl += origin.substr(start, pos) + s2;
		start += pos + s1.size();
		pos = origin.substr(start, origin.size()).find(s1);
	}
	if (origin.size() != start)
		repl += origin.substr(start, origin.size());
	return (repl);
}
