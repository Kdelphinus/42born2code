#include "Serializer.hpp"

int main() {
  static Serializer se;
  Data *ptr = new Data;
  ptr->n = 42;
  ptr->s1 = "Hello";
  ptr->s2 = "World";
  uintptr_t raw = se.serialize(ptr);
  Data *ptr2 = se.deserialize(raw);
  std::cout << ptr2->n << std::endl;
  std::cout << ptr2->s1 << std::endl;
  std::cout << ptr2->s2 << std::endl;
  delete ptr;
  return 0;
}