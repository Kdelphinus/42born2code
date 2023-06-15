#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name(ClapTrap::_name) {
    ClapTrap::_name = _name + "_clap_name";
    std::cout << "Diamond Trap " << ClapTrap::_name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : ClapTrap(dt), FragTrap(dt), ScavTrap(dt), _name(dt.getName()) {
    std::cout << "Diamond Trap " << this->_name << " Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt) {
    if (this != &dt) {
        this->_name = dt.getName();
        this->_hitPoints = dt.getHitPoints();
        this->_energyPoints = dt.getEnergyPoints();
        this->_attackDamage = dt.getDamage();
    }
    std::cout << "Diamond Trap " << this->_name << " Copy assignment operator called" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "Diamond Trap " << this->_name << " Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "Who am i?" << std::endl;
}
