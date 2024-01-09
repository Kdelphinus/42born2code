#include "Dog.hpp"

Dog::Dog() : Animal() {
  Animal::type = "Dog";
  this->idea = new Brain();
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal() {
  Animal::type = dog.getType();
  this->idea = new Brain;
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
  if (this != &dog) {
	Animal::type = dog.getType();
	this->idea = dog.idea;
  }
  std::cout << "Dog copy assignment operator called" << std::endl;
  return *this;
}

Dog::~Dog() {
  delete this->idea;
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
  std::cout << "멍멍!!" << std::endl;
}

void Dog::setIdeas(int idx, std::string idea) const {
  this->idea->setIdeas(idx, idea);
}

std::string Dog::getIdeas(int idx) const {
  return this->idea->getIdeas(idx);
}
