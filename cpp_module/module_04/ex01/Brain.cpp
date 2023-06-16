#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &brain) {
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain) {
    if (this != &brain)
        this;
	std::cout << "Brain copy assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}