#include "Character.hpp"

Character::Character() : name("") {
    std::cout << "Character Default constructor called" << std::endl;
}

Character::Character(const Character &character) : name(character.getName()) {
    std::cout << "Character Copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &character) {
    if (this != &character)
        this->name = character.getName();
    std::cout << "Character Copy assignment operator called" << std::endl;
    return *this;
}

Character::~Character() {
    std::cout << "Character Destructor called" << std::endl;
}

const std::string &Character::getName() const {
    return this->name;
}

void Character::equip(AMateria *m) {

}
