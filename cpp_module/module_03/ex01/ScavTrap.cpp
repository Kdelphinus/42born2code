#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap Default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap Name constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &st) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    this->_name = st.getName();
    this->_hitPoints = st.getHitPoints();
    this->_energyPoints = st.getEnergyPoints();
    this->_attackDamage = st.getDamage();
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &st) {
        this->_name = st.getName();
        this->_hitPoints = st.getHitPoints();
        this->_energyPoints = st.getEnergyPoints();
        this->_attackDamage = st.getDamage();
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (this->_energyPoints == 0) {
        std::cout << this->_name << " has no energy point" << std::endl;
        return;
    }
    --this->_energyPoints;
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
              << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << this->_name << " is now in Gate keeper mode" << std::endl;
}