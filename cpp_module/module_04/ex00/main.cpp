#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
    std::cout << meta->getType() << " : " << std::endl;
    meta->makeSound();
	std::cout << dog->getType() << " : " << std::endl;
    dog->makeSound();
    std::cout << cat->getType() << " : " << std::endl;
    cat->makeSound();
	return 0;
}