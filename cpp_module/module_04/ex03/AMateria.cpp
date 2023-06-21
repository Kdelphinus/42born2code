#include "AMateria.hpp"

AMateria::AMateria() : type("material") {
    std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) : type(type){
    std::cout << "AMaterial string constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &aMateria) : type(aMateria.getType()) {
    std::cout << "AMateria Copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &aMateria) {
    if (this != &aMateria)
        this->type = aMateria.getType();
    std::cout << "AMateria Copy assignment operator called" << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria Destructor called" << std::endl;
}

const std::string &AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter &target) {
    std::cout << "You can't use AMateria" << std::endl;
}
