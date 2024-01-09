#include "AMateria.hpp"

AMateria::AMateria() : type("material") {}

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::AMateria(const AMateria &aMateria) : type(aMateria.getType()) {}

AMateria &AMateria::operator=(const AMateria &aMateria) {
  if (this != &aMateria)
	this->type = aMateria.getType();
  return *this;
}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const {
  return this->type;
}

void AMateria::use(ICharacter &target) {
  std::cout << "You can't use AMateria " << target.getName() << std::endl;
}
