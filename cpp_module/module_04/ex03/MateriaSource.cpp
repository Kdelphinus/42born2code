#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : source() {
    std::cout << "MateriaSource Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) : source(materiaSource.getSource()) {
    std::cout << "MateriaSource Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
    if (this != &materiaSource)
        this->source = materiaSource.getSource();
    std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource Destructor called" << std::endl;
}

AMateria *MateriaSource::getSource() const {
    return this->source;
}

void MateriaSource::setSource(AMateria *m) {
    this->source = m;
}

void MateriaSource::learnMateria(AMateria *materia) {
    this->source = materia;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    AMateria *clone;
    if (type == "ice")
        clone = new Ice(type);
    if (type == "cure")
        clone = new Cure(type);
    return clone;
}
