#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource *src = new MateriaSource();
  AMateria *ice = new Ice();
  AMateria *cure = new Cure();
  src->learnMateria(ice);
  src->learnMateria(cure);

  ICharacter *me = new Character("me");

  AMateria *tmp1, *tmp2, *tmp3, *tmp4, *tmp5;
  tmp1 = src->createMateria("ice");
  me->equip(tmp1);
  tmp2 = src->createMateria("cure");
  me->equip(tmp2);
  tmp3 = src->createMateria("ice");
  me->equip(tmp3);
  tmp4 = src->createMateria("error");
  me->equip(tmp4);
  tmp5 = src->createMateria("ice");
  me->equip(tmp5);

  ICharacter *bob = new Character("bob");
  ICharacter *coc = new Character("coc");

  me->use(0, *bob);
  me->use(1, *bob);
  me->use(2, *coc);
  me->use(3, *coc);
  me->use(4, *coc);

  // Materia Source
  delete src;
  delete ice;
  delete cure;

  // Player
  delete bob;
  delete coc;
  delete me;

  // Materia
  delete tmp1;
  delete tmp2;
  delete tmp3;
  delete tmp4;
  delete tmp5;

  return 0;
}
