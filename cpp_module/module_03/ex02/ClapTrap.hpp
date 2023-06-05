#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

    public:
        ClapTrap();
		ClapTrap(std::string name);
        ClapTrap(const ClapTrap &ct);
        ClapTrap &operator=(const ClapTrap &ct);
        ~ClapTrap();

		std::string getName(void);
		void setName(std::string name);
		void setDamage(int damage);
		void setHitPoints(int hp);
		void setEnergyPoints(int ep);

		int getDamage(void);
		int getHitPoints(void);
		int getEnergyPoints(void);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
