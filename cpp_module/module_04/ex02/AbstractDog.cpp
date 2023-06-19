#include "AbstractDog.hpp"

AbstractDog::AbstractDog() : AbstractAnimal() {
    AbstractAnimal::type = "AbstractDog";
    this->idea = new Brain();
    std::cout << "AbstractDog constructor called" << std::endl;
}

AbstractDog::AbstractDog(const AbstractDog &abstractDog) : AbstractAnimal() {
    AbstractAnimal::type = abstractDog.getType();
    this->idea = new Brain;
    std::cout << "AbstractDog copy constructor called" << std::endl;
}

AbstractDog &AbstractDog::operator=(const AbstractDog &abstractDog) {
    if (this != &abstractDog) {
        AbstractAnimal::type = abstractDog.getType();
        this->idea = abstractDog.idea;
    }
    std::cout << "AbstractDog copy assignment operator called" << std::endl;
    return *this;
}

AbstractDog::~AbstractDog() {
    delete this->idea;
    std::cout << "AbstractDog destructor called" << std::endl;
}

void AbstractDog::makeSound() const {
    std::cout << "추상 멍멍!!" << std::endl;
}

void AbstractDog::setIdeas(int idx, std::string idea) const {
    this->idea->setIdeas(idx, idea);
}

std::string AbstractDog::getIdeas(int idx) const {
    return this->idea->getIdeas(idx);
}
