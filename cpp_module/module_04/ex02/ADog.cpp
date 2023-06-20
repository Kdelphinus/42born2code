#include "ADog.hpp"

ADog::ADog() : AAnimal() {
    AAnimal::type = "ADog";
    this->idea = new Brain();
    std::cout << "ADog constructor called" << std::endl;
}

ADog::ADog(const ADog &aDog) : AAnimal() {
    AAnimal::type = aDog.getType();
    this->idea = new Brain;
    std::cout << "ADog copy constructor called" << std::endl;
}

ADog &ADog::operator=(const ADog &aDog) {
    if (this != &aDog) {
        AAnimal::type = aDog.getType();
        this->idea = aDog.idea;
    }
    std::cout << "ADog copy assignment operator called" << std::endl;
    return *this;
}

ADog::~ADog() {
    delete this->idea;
    std::cout << "ADog destructor called" << std::endl;
}

void ADog::makeSound() const {
    std::cout << "추상 멍멍!!" << std::endl;
}

void ADog::setIdeas(int idx, std::string idea) const {
    this->idea->setIdeas(idx, idea);
}

std::string ADog::getIdeas(int idx) const {
    return this->idea->getIdeas(idx);
}
