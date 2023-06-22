#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "MateriaSource.hpp"

class Character : public ICharacter {
    private:
        std::string name;
        bool invenIdx[4] = {false, false, false, false};
        MateriaSource inven[4];
    public:
        Character();
        Character(const std::string &name);
        Character(const Character &character);
        Character &operator=(const Character &character);
        ~Character();

        std::string const &getName() const;
        bool getInvenIdx(int idx) const;
        MateriaSource getInven(int idx) const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif
