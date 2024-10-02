#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &brain) {
  for (int i = 0; i < 100; i++)
	this->ideas[i] = brain.ideas[i];
  std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain) {
  if (this != &brain) {
	for (int i = 0; i < 100; i++)
	  this->ideas[i] = brain.ideas[i];
  }
  std::cout << "Brain copy assignment operator called" << std::endl;
  return *this;
}

Brain::~Brain() {
  std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdeas(int idx, std::string idea) {
  if (idx >= 100 || idx < 0) {
	std::cout << "Invalid index" << std::endl;
	return;
  }
  this->ideas[idx] = idea;
}

std::string const Brain::getIdeas(int idx) const {
  if (idx >= 100 || idx < 0) {
	std::cout << "Invalid index" << std::endl;
	return "";
  }
  return this->ideas[idx];
}
