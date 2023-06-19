#ifndef ABSTRACTCAT_HPP
#define ABSTRACTCAT_HPP

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class AbstractCat : public AbstractAnimal {
    private:
        Brain *idea;
    public:
        AbstractCat();
        AbstractCat(const AbstractCat &abstractCat);
        AbstractCat &operator=(const AbstractCat &abstractCat);
        ~AbstractCat();

        void makeSound() const;
        void setIdeas(int idx, std::string idea) const;
        std::string getIdeas(int idx) const;
};

#endif
