#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    WrongAnimal::type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal() {
    WrongAnimal::type = wrongCat.getType();
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
    if (this != &wrongCat)
        WrongAnimal::type = wrongCat.getType();
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "잘못된 고양이의 울음 소리" << std::endl;
}