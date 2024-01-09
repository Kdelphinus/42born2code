#include "Animal.hpp"

Animal::Animal() : type("Animal") {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) : type(animal.getType()) {
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
  if (this != &animal)
	this->type = animal.getType();
  std::cout << "Animal copy assignment operator called" << std::endl;
  return *this;
}

Animal::~Animal() {
  std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
  return this->type;
}

void Animal::setType(std::string type) {
  if (this->type != type)
	this->type = type;
}

void Animal::makeSound() const {
  std::cout << "this is animal" << std::endl;
}
