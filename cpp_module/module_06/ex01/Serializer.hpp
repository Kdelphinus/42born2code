#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data {
  int n;
  std::string s1;
  std::string s2;
};

class Serializer {
 private:
  Serializer(const Serializer &se);
  Serializer &operator=(const Serializer &se);
 public:
  Serializer();
  ~Serializer();

  uintptr_t serialize(Data *ptr);
  Data *deserialize(uintptr_t raw);
};

#endif
