#include "Zombie.hpp"

int main()
{
	Zombie zombie1 = Zombie("Zombie1");
	Zombie zombie2 = Zombie("Zombie2");
	Zombie* zombie3 = newZombie("Zombie3");
	Zombie* zombie4 = new Zombie("Zombie4");

	zombie1.announce();
	zombie2.announce();
	zombie3->announce();
	zombie4->announce();

	delete zombie3;
	delete zombie4;

	randomChump("random1");
	randomChump("random2");
	randomChump("random3");

}
