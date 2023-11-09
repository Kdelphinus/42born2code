#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
  int i = std::rand() % 3;

  std::cout << "Create: ";
  if (i == 0) {
	std::cout << "Type A" << std::endl;
	return new A();
  } else if (i == 1) {
	std::cout << "Type B" << std::endl;
	return new B();
  } else {
	std::cout << "Type C" << std::endl;
	return new C();
  }
}

void identify(Base *p) {
  std::cout << "Pointer: ";
  if (dynamic_cast<A *>(p))
	std::cout << "Type A" << std::endl;
  else if (dynamic_cast<B *>(p))
	std::cout << "Type B" << std::endl;
  else if (dynamic_cast<C *>(p))
	std::cout << "Type C" << std::endl;
  return;
}

void identify(Base &p) {
  std::cout << "Reference: ";
  try {
	A &a = dynamic_cast<A &>(p);
	(void)a;
	std::cout << "Type A" << std::endl;
  }
  catch (...) {}
  try {
	B &b = dynamic_cast<B &>(p);
	(void)b;
	std::cout << "Type B" << std::endl;
  }
  catch (...) {}
  try {
	C &c = dynamic_cast<C &>(p);
	(void)c;
	std::cout << "Type C" << std::endl;
  }
  catch (...) {}
}

int main() {
  std::srand(std::time(0));

  Base *p = generate();
  Base &r = *p;

  identify(p);
  identify(r);

  delete p;
  return 0;
}
