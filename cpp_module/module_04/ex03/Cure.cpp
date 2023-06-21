#include "Cure.hpp"

Cure::Cure() : {
    std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(const Cure &cure) : {
    std::cout << "Cure Copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &cure) {
    std::cout << "Cure Copy assignment operator called" << std::endl;

    return *this;
}

Cure::~Cure() {
    std::cout << "Cure Destructor called" << std::endl;
}

AMateria *Cure::clone() const {
    std::cout << "Cure clone" << std::endl;
    return AMateria(&this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
