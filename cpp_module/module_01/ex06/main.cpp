#include "Harl.h"

int main(int argc, char **argv) {
	if (argc != 2)
        return 1;

    Harl harl_filter;
    harl_filter.complain(argv[1]);
	return (0);
}
