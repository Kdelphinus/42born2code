#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *idea;
    public:
        Cat();
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);
        ~Cat();

        void makeSound() const;
        void setIdeas(int idx, std::string idea) const;
        std::string getIdeas(int idx) const;
};

#endif
