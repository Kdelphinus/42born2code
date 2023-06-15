#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) {
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ft) {
    this->_name = ft.getName();
    this->_hitPoints = ft.getHitPoints();
    this->_energyPoints = ft.getEnergyPoints();
    this->_attackDamage = ft.getDamage();
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ft) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &ft) {
        this->_name = ft.getName();
        this->_hitPoints = ft.getHitPoints();
        this->_energyPoints = ft.getEnergyPoints();
        this->_attackDamage = ft.getDamage();
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << this->_name << " requests a high fives" << std::endl;
}
