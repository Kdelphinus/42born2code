#include <iostream>

int	main(int argc, char **argv)
{
	std::string str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++)
				str += static_cast<char>(std::toupper(argv[i][j]));
		}
		std::cout << str << std::endl;
	}
	return (0);
}
