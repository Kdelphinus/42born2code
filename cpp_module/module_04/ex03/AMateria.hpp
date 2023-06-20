#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(const AMateria &aMateria);
        AMateria(std::string const &type);
        AMateria &operator=(const AMateria &aMateria);
        virtual ~AMateria();

        std::string const &getType() const;

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif
