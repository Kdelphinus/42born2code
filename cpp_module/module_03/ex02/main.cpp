#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap a = FragTrap("HI");

	a.highFivesGuys();

	std::cout << "hp: " << a.getHitPoints() << " ep: " << a.getEnergyPoints() << " ad: " << a.getDamage() << std::endl;
}
