#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << this->_name << " requests a high fives" << std::endl;
}
