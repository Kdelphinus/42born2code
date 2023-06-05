#include "Animal.hpp"

Animal::Animal() : type("Animal") {}

Animal::Animal(const Animal &animal) : type(animal.getType()) {}

Animal &Animal::operator=(const Animal &animal) {
	this->type = animal.getType();
	return (*this);
}

Animal::~Animal() {}

const std::string Animal::getType() const {
	return this->type;
}

void Animal::setType(std::string type) {
	if (this->type != type)
		this->type = type;
}

void Animal::makeSound() const {
	std::cout << "this is Animal" << std::endl;
}