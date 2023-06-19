#ifndef ABSTRACTDOG_HPP
#define ABSTRACTDOG_HPP

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class AbstractDog : public AbstractAnimal {
    private:
        Brain *idea;
    public:
        AbstractDog();
        AbstractDog(const AbstractDog &abstractDog);
        AbstractDog &operator=(const AbstractDog &abstractDog);
        ~AbstractDog();

        void makeSound() const;
        void setIdeas(int idx, std::string idea) const;
        std::string getIdeas(int idx) const;
};

#endif
