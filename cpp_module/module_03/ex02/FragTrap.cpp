#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " Name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft) {
	this->_name = ft.getName();
	this->_hitPoints = ft.getHitPoints();
	this->_energyPoints = ft.getEnergyPoints();
	this->_attackDamage = ft.getDamage();
	std::cout << "FragTrap " << this->_name << " Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ft) {
	if (this != &ft) {
		this->_name = ft.getName();
		this->_hitPoints = ft.getHitPoints();
		this->_energyPoints = ft.getEnergyPoints();
		this->_attackDamage = ft.getDamage();
	}
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " Destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << this->_name << " requests a high fives" << std::endl;
}
