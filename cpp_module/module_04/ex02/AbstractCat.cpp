#include "AbstractCat.hpp"

AbstractCat::AbstractCat() : AbstractAnimal() {
    AbstractAnimal::type = "AbstractCat";
    this->idea = new Brain();
    std::cout << "AbstractCat constructor called" << std::endl;
}

AbstractCat::AbstractCat(const AbstractCat &abstractCat) : AbstractAnimal() {
    AbstractAnimal::type = abstractCat.getType();
    this->idea = new Brain;
    std::cout << "AbstractCat copy constructor called" << std::endl;
}

AbstractCat &AbstractCat::operator=(const AbstractCat &abstractCat) {
    if (this != &abstractCat) {
        AbstractAnimal::type = abstractCat.getType();
        this->idea = abstractCat.idea;
    }
    std::cout << "AbstractCat copy assignment operator called" << std::endl;
    return *this;
}

AbstractCat::~AbstractCat() {
    delete this->idea;
    std::cout << "AbstractCat destructor called" << std::endl;
}

void AbstractCat::makeSound() const {
    std::cout << "추상 야옹~" << std::endl;
}

void AbstractCat::setIdeas(int idx, std::string idea) const {
    this->idea->setIdeas(idx, idea);
}

std::string AbstractCat::getIdeas(int idx) const {
    return this->idea->getIdeas(idx);
}
