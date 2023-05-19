#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie \"default\" create." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Zombie \"" << this->_name << "\" create." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie \"" << this->_name << "\" delete." << std::endl;
}

void Zombie::setName(std::string name) {
	if (name.length() == 0)
		std::cout << "Invaild name." << std::endl;
	else
		this->_name = name;
}

void Zombie::announce(void) {
	std::cout << "\"" << this->_name << "\" : BraiiiiiiinnnzzzZ..." << std::endl;
}