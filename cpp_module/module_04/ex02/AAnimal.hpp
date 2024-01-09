#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
 protected:
  std::string type;
 public:
  AAnimal();
  AAnimal(const AAnimal &aAnimal);
  AAnimal &operator=(const AAnimal &aAnimal);
  virtual ~AAnimal();

  std::string const &getType() const;
  void setType(std::string type);

  virtual void makeSound() const = 0;
  virtual void setIdeas(int idx, std::string idea) const = 0;
  virtual std::string getIdeas(int idx) const = 0;
};

#endif
