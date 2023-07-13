#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap a = DiamondTrap("test");

	std::cout << "name: " << a.getName() << " (_clap_name)\n"
			  << "hp: " << a.getHitPoints() << " (FragTrap: 100)\n"
			  << "ep: " << a.getEnergyPoints() << " (ScavTrap: 50)\n"
			  << "damage: " << a.getDamage() << " (FragTrap: 30)" << std::endl;

	int num;
	num = 3;
	std::cout << num << std::endl;
	{
		int num;
		num = 5;
		std::cout << num << std::endl;
	}
}
