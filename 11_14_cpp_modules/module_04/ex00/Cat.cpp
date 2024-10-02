#include "Cat.hpp"

Cat::Cat() : Animal() {
  Animal::type = "Cat";
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal() {
  Animal::type = cat.getType();
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
  if (this != &cat)
	Animal::type = cat.getType();
  std::cout << "Cat copy assignment operator called" << std::endl;
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
  std::cout << "야옹~" << std::endl;
}
