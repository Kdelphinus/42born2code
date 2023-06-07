#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong animal") {}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) : type(wrongAnimal.getType()) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
    this->type = wrongAnimal.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal() {}

const std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::setType(std::string type) {
    if (this->type != type)
        this->type = type;
}

void WrongAnimal::makeSound() const {
    std::cout << "this is wrong animal" << std::endl;
}