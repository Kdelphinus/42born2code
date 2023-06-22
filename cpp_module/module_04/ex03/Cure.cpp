#include "Cure.hpp"

Cure::Cure() : AMateria() {
    std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(const Cure &cure) : AMateria() {
    this->type = cure.getType();
    std::cout << "Cure Copy constructor called" << std::endl;
}

Cure::Cure(const std::string &type) : AMateria(type) {
    std::cout << "Cure type constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &cure) {
    if (this != &cure)
        this->type = cure.getType();
    std::cout << "Cure Copy assignment operator called" << std::endl;
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure Destructor called" << std::endl;
}

AMateria *Cure::clone() const {
    std::cout << "Cure clone" << std::endl;
    AMateria *cloneCure = new Cure(*this);
    return cloneCure;
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
