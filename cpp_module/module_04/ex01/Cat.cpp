#include "Cat.hpp"

Cat::Cat() : Animal() {
  Animal::type = "Cat";
  this->idea = new Brain();
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal() {
  Animal::type = cat.getType();
  this->idea = new Brain;
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
  if (this != &cat) {
	Animal::type = cat.getType();
	this->idea = cat.idea;
  }
  std::cout << "Cat copy assignment operator called" << std::endl;
  return *this;
}

Cat::~Cat() {
  delete this->idea;
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
  std::cout << "야옹~" << std::endl;
}

void Cat::setIdeas(int idx, std::string idea) const {
  this->idea->setIdeas(idx, idea);
}

std::string Cat::getIdeas(int idx) const {
  return this->idea->getIdeas(idx);
}
