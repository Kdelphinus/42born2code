#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &st);
		ScavTrap &operator=(const ScavTrap &st);
		~ScavTrap();

        void attack(const std::string &target);
		void guardGate();
};

#endif
