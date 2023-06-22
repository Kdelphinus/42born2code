#include "Character.hpp"

Character::Character() : name() {
    std::cout << "Character Default constructor called" << std::endl;
}

Character::Character(const std::string &name) : name(name) {
    std::cout << "Character name constructor called" << std::endl;
}

Character::Character(const Character &character) : name(character.getName()) {
    std::cout << "Character Copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &character) {
    if (this != &character) {
        this->name = character.getName();
        for (int i = 0; i < 4; i++) {
            if (character.getInvenIdx(i)) {
                this->inven[i] = character.getInven(i);
                this->invenIdx[i] = true;
            }
        }
    }
    std::cout << "Character Copy assignment operator called" << std::endl;
    return *this;
}

Character::~Character() {
    std::cout << "Character Destructor called" << std::endl;
}

const std::string &Character::getName() const {
    return this->name;
}

bool Character::getInvenIdx(int idx) const {
    return this->invenIdx[idx];
}

MateriaSource Character::getInven(int idx) const {
    if (idx < 0 || idx >= 4 || this->invenIdx[idx] == false) {
        std::cout << "Invalid index" << std::endl;
        return this->inven[0];
    }
    return this->inven[idx];
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (this->invenIdx[i] == false) {
            this->inven[i].setSource(m);
            this->invenIdx[i] = true;
            return;
        }
    }
    std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !this->invenIdx[idx]) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    this->invenIdx[idx] = false;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx >= 4 || !this->invenIdx[idx]) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    target.equip(this->inven[idx].getSource());
}
