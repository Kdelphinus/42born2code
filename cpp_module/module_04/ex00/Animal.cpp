#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) : _type(animal.getType()) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
    if (this != &animal)
	    this->_type = animal.getType();
    std::cout << "Animal copy assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::setType(std::string type) {
	if (this->_type != type)
		this->_type = type;
}

void Animal::makeSound() const {
    std::cout << "this is animal" << std::endl;
}
