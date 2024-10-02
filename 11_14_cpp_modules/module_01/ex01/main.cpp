#include "Zombie.hpp"

int main() {
	Zombie *test1 = zombieHorde(5, "test1");
	for (int i = 0; i < 5; i++)
		test1[i].announce();
	delete[] test1;

	Zombie *test2 = zombieHorde(3, "test2");
	for (int i = 0; i < 3; i++)
		test2[i].announce();
	delete[] test2;

	return (0);
}
