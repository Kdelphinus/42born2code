#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

void ScavTrap::guardGate() {
	std::cout << this->_name << " is now in Gate keeper mode" << std::endl;
}