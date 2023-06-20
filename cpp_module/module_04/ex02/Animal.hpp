#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &animal);
        Animal &operator=(const Animal &animal);
        virtual ~Animal(); // 가상 소멸자를 사용하지 않으면 기반 클래스의 소멸자만 호출됨

        virtual void makeSound() const;
        std::string const &getType() const;
        void setType(std::string type);

        virtual void setIdeas(int idx, std::string idea) const;
        virtual std::string getIdeas(int idx) const;
};

#endif
