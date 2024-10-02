#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << this->_name << " create" << std::endl;
}

HumanA::~HumanA() {
	std::cout << this->_name << " delete" << std::endl;
}

void HumanA::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
