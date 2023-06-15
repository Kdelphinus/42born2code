#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : {
    std::cout << "Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : {
    std::cout << "Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
    std::cout << "Copy assignment operator called" << std::endl;

    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "Destructor called" << std::endl;
}
