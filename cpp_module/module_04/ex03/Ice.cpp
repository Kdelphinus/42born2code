#include "Ice.hpp"

Ice::Ice() : AMateria() {}

Ice::Ice(const Ice &ice) : AMateria(ice) {
    this->type = ice.getType();
}

Ice::Ice(const std::string &type) : AMateria(type) {}

Ice &Ice::operator=(const Ice &ice) {
    if (this != &ice)
        this->type = ice.getType();
    return *this;
}

Ice::~Ice() {
}

AMateria *Ice::clone() const {
    std::cout << "Ice clone" << std::endl;
    AMateria *cloneIce = new Ice(*this);
    return cloneIce;
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}