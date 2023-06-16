#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << animal->getType() << " : " << std::endl;
    animal->makeSound();
	std::cout << dog->getType() << " : " << std::endl;
    dog->makeSound();
    std::cout << cat->getType() << " : " << std::endl;
    cat->makeSound();
    std::cout << wrongAnimal->getType() << " : " << std::endl;
    wrongAnimal->makeSound();
    std::cout << wrongCat->getType() << " : " << std::endl;
    wrongCat->makeSound();

    delete animal;
    delete dog;
    delete cat;
    delete wrongAnimal;
    delete wrongCat;
	return 0;
}