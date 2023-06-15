#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name(ClapTrap::_name) {
    std::cout << "Diamond Trap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : {
    std::cout << "Diamond Trap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt) {
    std::cout << "Diamond Trap Copy assignment operator called" << std::endl;

    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "Diamond Trap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "Who am i?" << std::endl;
}
