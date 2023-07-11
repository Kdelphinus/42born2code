#include "Weapon.h"

Weapon::Weapon(std::string type): _type(type) {
	std::cout << this->_type << " type Weapon create" << std::endl;
}

Weapon::~Weapon() {
	std::cout << this->_type << " delete" << std::endl;
}

// subject 상 const reference 타입으로 반환해야 함
// 원문: A getType() member function that returns a const reference to type.
std::string Weapon::getType() const {
	return this->_type;
}

void Weapon::setType(std::string type) {
	if (type.size() == 0) {
		std::cout << "Invalid type" << std::endl;
		return;
	}
	this->_type = type;
}
