#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
 private:
  std::string name;
  bool invenIdx[4];
  AMateria *inven[4];
 public:
  Character();
  explicit Character(const std::string &name);
  Character(const Character &character);
  Character &operator=(const Character &character);
  ~Character();

  std::string const &getName() const;
  bool getInvenIdx(int idx) const;
  AMateria *getInven(int idx) const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif
