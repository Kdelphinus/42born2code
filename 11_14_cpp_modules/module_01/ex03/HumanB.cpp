#include "HumanB.h"

HumanB::HumanB(std::string name): _name(name) {
	std::cout << this->_name << " create" << std::endl;
}

HumanB::HumanB(std::string name, Weapon &weapon): _name(name), _weapon(&weapon) {
	std::cout << this->_name << " create" << std::endl;
}

HumanB::~HumanB() {
	std::cout << this->_name << " delete" << std::endl;
}

void HumanB::attack() {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

std::string HumanB::getName() const {
	return (this->_name);
}

std::string HumanB::getWeapon() const {
	return (this->_weapon->getType());
}