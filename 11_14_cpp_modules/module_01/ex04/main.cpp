#include "sed.h"

void my_error(int num) {
	if (num == ARG)
		std::cout << "Argument error" << std::endl;
	else if (num == OPEN)
		std::cout << "No search file" << std::endl;
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
	if (argc != 4)
		my_error(ARG);
	std::string replace = ".replace";
	std::ifstream openFile(argv[1]);
	if (!openFile.is_open())
		my_error(OPEN);
	std::ofstream writeFile(argv[1] + replace);
	if (!writeFile.is_open()) {
		openFile.close();
		my_error(OPEN);
	}

	std::string line;
	while (std::getline(openFile, line))
		writeFile << my_sed(line, argv[2], argv[3]) << "\n";
	openFile.close();
	writeFile.close();

	return (EXIT_SUCCESS);
}
