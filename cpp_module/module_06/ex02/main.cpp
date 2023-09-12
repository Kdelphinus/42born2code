#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	std::srand(std::time(0));
	int i = std::rand() % 3;
	switch (i) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return new A();
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

// TODO : dynamic_cast 안에 <A *>는 포인터를 쓰지 않았다고 할 수 있는가?
void identify(Base &p) {
	std::cout << "Reference: ";
	if (dynamic_cast<A *>(&p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "Type C" << std::endl;
}

int main() {
	Base *p = generate();
	Base &r = *p;

	identify(p);
	identify(r);

	delete p;
	return 0;
}