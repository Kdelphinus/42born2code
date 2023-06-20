#ifndef ABSTRACTANIMAL_HPP
#define ABSTRACTANIMAL_HPP

#include <iostream>

class AbstractAnimal {
    protected:
        std::string type;
    public:
        AbstractAnimal();
        AbstractAnimal(const AbstractAnimal &abstractAnimal);
        AbstractAnimal &operator=(const AbstractAnimal &abstractAnimal);
        virtual ~AbstractAnimal();

        std::string const &getType() const;
        void setType(std::string type);

        virtual void makeSound() const = 0;
        virtual void setIdeas(int idx, std::string idea) const = 0;
        virtual std::string getIdeas(int idx) const = 0;
};

#endif
