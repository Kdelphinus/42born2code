#ifndef ACAT_HPP
#define ACAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class ACat : public AAnimal {
    private:
        Brain *idea;
    public:
        ACat();
        ACat(const ACat &aCat);
        ACat &operator=(const ACat &aCat);
        ~ACat();

        void makeSound() const;
        void setIdeas(int idx, std::string idea) const;
        std::string getIdeas(int idx) const;
};

#endif
