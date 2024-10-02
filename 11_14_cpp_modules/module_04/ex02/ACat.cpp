#include "ACat.hpp"

ACat::ACat() : AAnimal() {
  AAnimal::type = "ACat";
  this->idea = new Brain();
  std::cout << "ACat constructor called" << std::endl;
}

ACat::ACat(const ACat &aCat) : AAnimal() {
  AAnimal::type = aCat.getType();
  this->idea = new Brain;
  std::cout << "ACat copy constructor called" << std::endl;
}

ACat &ACat::operator=(const ACat &aCat) {
  if (this != &aCat) {
	AAnimal::type = aCat.getType();
	this->idea = aCat.idea;
  }
  std::cout << "ACat copy assignment operator called" << std::endl;
  return *this;
}

ACat::~ACat() {
  delete this->idea;
  std::cout << "ACat destructor called" << std::endl;
}

void ACat::makeSound() const {
  std::cout << "추상 야옹~" << std::endl;
}

void ACat::setIdeas(int idx, std::string idea) const {
  this->idea->setIdeas(idx, idea);
}

std::string ACat::getIdeas(int idx) const {
  return this->idea->getIdeas(idx);
}
