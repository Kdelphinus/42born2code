#include "Harl.h"

int main() {
	Harl harl2;

	harl2.complain("DEBUG");
	harl2.complain("INFO");
	harl2.complain("WARNING");
	harl2.complain("ERROR");
	harl2.complain("WRONG CMD");

	return (0);
}
