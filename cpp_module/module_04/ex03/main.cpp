#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("error");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");
    ICharacter *coc = new Character("coc");

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *coc);
    me->use(3, *coc);
    me->use(4, *coc);

    delete bob;
    delete coc;
    delete me;
    delete src;

    return 0;
}
