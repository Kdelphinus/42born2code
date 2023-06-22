#include "Ice.hpp"

Ice::Ice() : AMateria() {
    std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria() {
    this->type = ice.getType();
    std::cout << "Ice Copy constructor called" << std::endl;
}

Ice::Ice(const std::string &type) : AMateria(type) {
    std::cout << "Ice type constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &ice) {
    if (this != &ice)
        this->type = ice.getType();
    std::cout << "Ice Copy assignment operator called" << std::endl;
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice Destructor called" << std::endl;
}

AMateria *Ice::clone() const {
    std::cout << "Ice clone" << std::endl;
    AMateria *cloneIce = new Ice(*this);
    return cloneIce;
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}