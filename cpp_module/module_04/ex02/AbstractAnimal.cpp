#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal() : type("AbstractAnimal") {
    std::cout << "AbstractAnimal constructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &abstractAnimal) : type(abstractAnimal.getType()) {
    std::cout << "AbstractAnimal copy constructor called" << std::endl;
}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &abstractAnimal) {
    if (this != &abstractAnimal)
        this->type = abstractAnimal.getType();
    std::cout << "AbstractAnimal copy assignment operator called" << std::endl;
    return *this;
}

AbstractAnimal::~AbstractAnimal() {
    std::cout << "AbstractAnimal destructor called" << std::endl;
}

std::string AbstractAnimal::getType() const {
    return this->type;
}

void AbstractAnimal::setType(std::string type) {
    if (this->type != type)
        this->type = type;
}
