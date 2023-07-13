#include "DiamondTrap.hpp"

// ClapTrap -> FragTrap -> ScavTrap 순으로 생성자 호출
// 그렇기에 최종적으로 ScavTrap의 속성으로 초기화되어 있음
// FragTrap으로 바꿔야 하는 것은 변경할 것
DiamondTrap::DiamondTrap() : _name(ClapTrap::_name) {
	ClapTrap::_name = _name + "_clap_name";
	ClapTrap::_hitPoints = 100;
	ClapTrap::_attackDamage = 30;
	std::cout << "DiamondTrap " << ClapTrap::_name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name) {
	ClapTrap::_name = _name + "_clap_name";
	ClapTrap::_hitPoints = 100;
	ClapTrap::_attackDamage = 30;
	std::cout << "DiamondTrap " << this->_name << " Name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : ClapTrap(dt), FragTrap(dt), ScavTrap(dt), _name(dt.getName()) {
	this->_hitPoints = dt.getHitPoints();
	this->_energyPoints = dt.getEnergyPoints();
	this->_attackDamage = dt.getDamage();
	std::cout << "DiamondTrap " << this->_name << " Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt) {
	if (this != &dt) {
		this->_name = dt.getName();
		this->_hitPoints = dt.getHitPoints();
		this->_energyPoints = dt.getEnergyPoints();
		this->_attackDamage = dt.getDamage();
	}
	std::cout << "DiamondTrap " << this->_name << " Copy assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "Who am i?" << std::endl;
}
