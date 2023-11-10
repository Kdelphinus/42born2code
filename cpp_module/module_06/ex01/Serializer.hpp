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
  Serializer();
  Serializer(const Serializer &se);
  Serializer &operator=(const Serializer &se);
  ~Serializer();
 public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif
