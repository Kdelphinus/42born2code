#include "Dog.hpp"

Dog::Dog() {
	this->setType("Dog");
}

Dog::Dog(const Dog &dog) {
	this->setType(dog.getType());
}

Dog &Dog::operator=(const Dog &dog) {
	this->setType(dog.getType());
	return (*this);
}

Dog::~Dog() {
}

void Dog::makeSound() const {
	std::cout << "야옹~" << std::endl;
}