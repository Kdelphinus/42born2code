#ifndef ADOG_HPP
#define ADOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class ADog : public AAnimal {
    private:
        Brain *idea;
    public:
        ADog();
        ADog(const ADog &aDog);
        ADog &operator=(const ADog &aDog);
        ~ADog();

        void makeSound() const;
        void setIdeas(int idx, std::string idea) const;
        std::string getIdeas(int idx) const;
};

#endif
