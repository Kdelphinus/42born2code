#include "Ice.hpp"

Ice::Ice() : {
    std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : {
    std::cout << "Ice Copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &ice) {
    std::cout << "Ice Copy assignment operator called" << std::endl;

    return *this;
}

Ice::~Ice() {
    std::cout << "Ice Destructor called" << std::endl;
}

AMateria *Ice::clone() const {
    std::cout << "Ice clone" << std::endl;
    return AMateria(&this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}