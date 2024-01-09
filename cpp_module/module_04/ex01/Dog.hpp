#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 private:
  Brain *idea;
 public:
  Dog();
  Dog(const Dog &dog);
  Dog &operator=(const Dog &dog);
  ~Dog();

  void makeSound() const;
  void setIdeas(int idx, std::string idea) const;
  std::string getIdeas(int idx) const;
};

#endif
