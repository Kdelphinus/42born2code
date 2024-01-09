#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat &wrongCat);
  WrongCat &operator=(const WrongCat &wrongCat);
  ~WrongCat();

  void makeSound() const;
};

#endif
