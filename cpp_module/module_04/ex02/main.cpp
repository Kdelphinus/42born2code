#include "Cat.hpp"
#include "Dog.hpp"
#include "AbstractCat.hpp"
#include "AbstractDog.hpp"

/*
 * Animal이 const로 선언되었기에 Animal에서 선언된 멤버들은 수정이 불가하다.
 * 이때, Animal 자체에 선언된 const가 아닌 멤버들은 불러오는게 불가능하다. (ex. setType() 함수)
 *
 * 여기서 우리가 만약 Cat, Dog 클래스에만 선언되어 있는 getIdeas(), setIdeas() 함수를 호출한다면 문제가 되기 시작한다.
 * 다형성을 사용하여 Animal 클래스에 가상 함수를 선언하고 오버라이딩하면 되지만 setIdeas() 함수 역시 위와 같은 문제로 const로 선언되어야 한다.
 *
 * 직접적으로 Cat, Dog 클래스의 값을 바꾸지 않고 Brain 클래스의 멤버를 바꾸는 것이기에 정상 동작이 되는 것은 확인할 수 있다.
*/

int main() {
//    추상 클래스이기에 컴파일 시, 에러
//    const AbstractAnimal *abstractAnimal = new AbstractAnimal();

    std::cout << "\n========ANIMAL========" << std::endl;
    std::cout << "<create>" << std::endl;
    const Animal *animal = new Animal();
    std::cout << "\ntype : " << animal->getType() << std::endl;
    std::cout << "sound: ";
    animal->makeSound();
    std::cout << "\n<delete>" << std::endl;
    delete animal;

    std::cout << "\n========DOG========" << std::endl;
    std::cout << "<create>" << std::endl;
    const Animal *dog = new Dog();
    std::cout << "\ntype : " << dog->getType() << std::endl;
    std::cout << "sound: ";
    dog->makeSound();
    dog->setIdeas(0, "Dog's idea");
    std::cout << "ideas: " << dog->getIdeas(0) << std::endl;
    std::cout << "\n<delete>" << std::endl;
    delete dog;

    std::cout << "\n========CAT========" << std::endl;
    std::cout << "<create>" << std::endl;
    const Animal *cat = new Cat();
    std::cout << "\ntype : " << cat->getType() << std::endl;
    std::cout << "sound: ";
    cat->makeSound();
    cat->setIdeas(0, "Cat's idea");
    std::cout << "ideas: " << cat->getIdeas(0) << std::endl;
    std::cout << "\n<delete>" << std::endl;
    delete cat;

    std::cout << "\n========ABSTRACT DOG========" << std::endl;
    std::cout << "<create>" << std::endl;
    const AbstractAnimal *abstractDog = new AbstractDog();
    std::cout << "\ntype : " << abstractDog->getType() << std::endl;
    std::cout << "sound: ";
    abstractDog->makeSound();
    abstractDog->setIdeas(0, "Abstract Dog's idea");
    std::cout << "ideas: " << abstractDog->getIdeas(0) << std::endl;
    std::cout << "\n<delete>" << std::endl;
    delete abstractDog;

    std::cout << "\n========ABSTRACT CAT========" << std::endl;
    std::cout << "<create>" << std::endl;
    const AbstractAnimal *abstractCat = new AbstractCat();
    std::cout << "\ntype : " << abstractCat->getType() << std::endl;
    std::cout << "sound: ";
    abstractCat->makeSound();
    abstractCat->setIdeas(0, "Abstract Cat's idea");
    std::cout << "ideas: " << abstractCat->getIdeas(0) << std::endl;
    std::cout << "\n<delete>" << std::endl;
    delete abstractCat;

    return 0;
}
