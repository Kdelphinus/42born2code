#include "Cat.hpp"

Cat::Cat() {
	this->setType("Cat");
}

Cat::Cat(const Cat &cat) {
    this->setType(cat.getType());
}

Cat &Cat::operator=(const Cat &cat) {
	this->setType(cat.getType());
    return (*this);
}

Cat::~Cat() {
}

void Cat::makeSound() const {
	std::cout << "멍멍!!" << std::endl;
}
