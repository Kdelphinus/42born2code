#include "Cat.hpp"

Cat::Cat() : Animal() {
	Animal::_type = "Cat";
}

Cat::Cat(const Cat &cat) : Animal() {
    Animal::_type = cat.getType();
}

Cat &Cat::operator=(const Cat &cat) {
	Animal::_type = cat.getType();
    return *this;
}

Cat::~Cat() {}

void Cat::makeSound() const {
	std::cout << "야옹~" << std::endl;
}
