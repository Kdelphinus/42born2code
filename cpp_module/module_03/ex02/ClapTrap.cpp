#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct) : _name(ct.getName()), _hitPoints(ct.getHitPoints()), _energyPoints(ct.getEnergyPoints()),
                                         _attackDamage(ct.getDamage()) {
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ct) {
        this->_name = ct.getName();
        this->_hitPoints = ct.getHitPoints();
        this->_energyPoints = ct.getEnergyPoints();
        this->_attackDamage = ct.getDamage();
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::setName(std::string name) {
    if (name != this->_name)
        this->_name = name;
}

void ClapTrap::setDamage(int damage) {
    if (damage < 0) {
        std::cout << "Invalid damage" << std::endl;
        return;
    }
    this->_attackDamage = damage;
}

void ClapTrap::setEnergyPoints(int ep) {
    if (ep < 0) {
        std::cout << "Invalid energy points" << std::endl;
        return;
    }
    this->_energyPoints = ep;
}

void ClapTrap::setHitPoints(int hp) {
    if (hp < 0) {
        std::cout << "Invalid hit point" << std::endl;
        return;
    }
    this->_hitPoints = hp;
}

std::string ClapTrap::getName() {
    return this->_name;
}

int ClapTrap::getDamage() {
    return this->_attackDamage;
}

int ClapTrap::getHitPoints() {
    return this->_hitPoints;
}

int ClapTrap::getEnergyPoints() {
    return this->_energyPoints;
}

void ClapTrap::attack(const std::string &target) {
    if (this->_energyPoints == 0) {
        std::cout << this->_name << " has no energy point" << std::endl;
        return;
    }
    --this->_energyPoints;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
              << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " already dead" << std::endl;
        return;
    }
    this->_hitPoints -= amount;
    if (this->_hitPoints < 0)
        this->_hitPoints = 0;
    std::cout << this->_name << " is attacked by " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints == 0) {
        std::cout << this->_name << " has no energy point" << std::endl;
        return;
    }
    --this->_energyPoints;
    this->_hitPoints += amount;
    std::cout << this->_name << " repaired " << amount << std::endl;
}
