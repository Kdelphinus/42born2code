#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &aAnimal) : type(aAnimal.getType()) {
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &aAnimal) {
    if (this != &aAnimal)
        this->type = aAnimal.getType();
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string const &AAnimal::getType() const {
    return this->type;
}

void AAnimal::setType(std::string type) {
    if (this->type != type)
        this->type = type;
}
