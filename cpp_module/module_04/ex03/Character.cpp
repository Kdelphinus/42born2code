#include "Character.hpp"

Character::Character() : name(), invenIdx() {
    for (int i = 0; i < 4; i++)
        this->invenIdx[i] = false;
}

Character::Character(const std::string &name) : name(name), invenIdx() {
    for (int i = 0; i < 4; i++)
        this->invenIdx[i] = false;
}

Character::Character(const Character &character) : name(character.getName()), invenIdx() {
    for (int i = 0; i < 4; i++) {
        if (character.getInvenIdx(i)) {
            this->inven[i] = character.getInven(i);
            this->invenIdx[i] = true;
        }
    }
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
    return *this;
}

Character::~Character() {}

const std::string &Character::getName() const {
    return this->name;
}

bool Character::getInvenIdx(int idx) const {
    return this->invenIdx[idx];
}

MateriaSource Character::getInven(int idx) const {
    if (idx < 0 || idx >= 4 || !this->invenIdx[idx]) {
        std::cout << "Invalid index" << std::endl;
        return this->inven[0];
    }
    return this->inven[idx];
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!this->invenIdx[i]) {
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

    if (this->inven[idx].getSource()->getType() == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    else if (this->inven[idx].getSource()->getType() == "cure")
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
