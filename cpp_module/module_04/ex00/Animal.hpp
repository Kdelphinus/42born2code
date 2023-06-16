#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string _type;
    public:
        Animal();
        Animal(const Animal &animal);
        Animal &operator=(const Animal &animal);
        ~Animal();

		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string type);
};

#endif
