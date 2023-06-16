#include "Dog.hpp"

Dog::Dog() : Animal() {
    Animal::_type = "Dog";
}

Dog::Dog(const Dog &dog) : Animal() {
    Animal::_type = dog.getType();
}

Dog &Dog::operator=(const Dog &dog) {
    Animal::_type = dog.getType();
    return *this;
}

Dog::~Dog() {}

void Dog::makeSound() const {
    std::cout << "멍멍!!" << std::endl;
}