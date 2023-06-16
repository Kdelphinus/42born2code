#include "Dog.hpp"

Dog::Dog() : Animal() {
    Animal::type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal() {
    Animal::type = dog.getType();
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
    if (this != &dog)
        Animal::type = dog.getType();
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "멍멍!!" << std::endl;
}