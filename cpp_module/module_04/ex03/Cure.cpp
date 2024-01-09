#include "Cure.hpp"

Cure::Cure() : AMateria() {}

Cure::Cure(const Cure &cure) : AMateria() {
  this->type = cure.getType();
}

Cure::Cure(const std::string &type) : AMateria(type) {}

Cure &Cure::operator=(const Cure &cure) {
  if (this != &cure)
	this->type = cure.getType();
  return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const {
  std::cout << "Cure clone" << std::endl;
  AMateria *cloneCure = new Cure(*this);
  return cloneCure;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
