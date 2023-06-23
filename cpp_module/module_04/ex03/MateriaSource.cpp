#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : source() {}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) : source(materiaSource.getSource()) {}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
    if (this != &materiaSource)
        this->source = materiaSource.getSource();
    return *this;
}

MateriaSource::~MateriaSource() {}

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
