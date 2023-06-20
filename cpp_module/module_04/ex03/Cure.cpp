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
