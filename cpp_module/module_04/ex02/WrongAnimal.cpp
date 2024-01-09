#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong animal") {
  std::cout << "Wrong animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) : type(wrongAnimal
																	.getType()) {
  std::cout << "Wrong animal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
  if (this != &wrongAnimal)
	this->type = wrongAnimal.getType();
  std::cout << "Wrong animal copy assignment operator called" << std::endl;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "Wrong animal destructor called" << std::endl;
}

std::string const &WrongAnimal::getType() const {
  return this->type;
}

void WrongAnimal::setType(std::string type) {
  if (this->type != type)
	this->type = type;
}

void WrongAnimal::makeSound() const {
  std::cout << "this is wrong animal" << std::endl;
}