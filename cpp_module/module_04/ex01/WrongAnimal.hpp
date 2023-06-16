#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &wrongAnimal);
        WrongAnimal &operator=(const WrongAnimal &wrongAnimal);
        virtual ~WrongAnimal(); // 가상 소멸자를 사용하지 않으면 기반 클래스의 소멸자만 호출됨

        void makeSound() const;
        std::string getType() const;
        void setType(std::string type);
};

#endif
