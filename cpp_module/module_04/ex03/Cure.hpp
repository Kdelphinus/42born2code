#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
    public:
        Cure();
        Cure(const Cure &cure);
        explicit Cure(const std::string &type);
        Cure &operator=(const Cure &cure);
        ~Cure();

        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif
