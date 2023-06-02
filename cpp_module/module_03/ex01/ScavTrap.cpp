#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setDamage(20);
}

void ScavTrap::guardGate() {
	std::cout << this->getName() << " is now in Gate keeper mode" << std::endl;
}