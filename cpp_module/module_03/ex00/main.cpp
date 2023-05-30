#include "ClapTrap.hpp"

int main() {
	ClapTrap a = ClapTrap();
	ClapTrap b = ClapTrap("tmp");

	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	b.beRepaired(1);
	std::cout << "name: " << a.getName() << " damage: " << a.getDamage() << " hp: " << a.getHitPoints() << " energy: " << a.getEnergyPoints() << std::endl;
	std::cout << "name: " << b.getName() << " damage: " << b.getDamage() << " hp: " << b.getHitPoints() << " energy: " << b.getEnergyPoints() << std::endl;
}
