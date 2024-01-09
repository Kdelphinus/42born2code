#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : source() {}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) : source(
	materiaSource.getSource()) {}

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
  if (type == "ice")
	return new Ice(type);
  else if (type == "cure")
	return new Cure(type);
  else
	return 0; // nullptr을 쓰라고 ide는 추천하지만 서브젝트 상에서 0을 반환해야 하므로 0 반환
}
