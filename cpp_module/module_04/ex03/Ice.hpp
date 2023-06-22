#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice();
        Ice(const Ice &ice);
        Ice(const std::string &type);
        Ice &operator=(const Ice &ice);
        ~Ice();

        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif
