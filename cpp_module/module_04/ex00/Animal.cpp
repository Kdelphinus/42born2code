#include "Animal.hpp"

Animal::Animal() : _type("Animal") {}

Animal::Animal(const Animal &animal) : _type(animal.getType()) {}

Animal &Animal::operator=(const Animal &animal) {
	this->_type = animal.getType();
	return *this;
}

Animal::~Animal() {}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::setType(std::string type) {
	if (this->_type != type)
		this->_type = type;
}

void Animal::makeSound() const {}