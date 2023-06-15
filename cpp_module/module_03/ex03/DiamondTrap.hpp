#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        ClapTrap::_name;
        FragTrap::_hitPoint;
        ScavTrap::_energyPoints;
        FragTrap::attackDamage;
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &diamondTrap);
        DiamondTrap &operator=(const DiamondTrap &diamondTrap);
        ~DiamondTrap();

        void ClapTrap::attack(const std::string& target);

        void whoAmI()
};

#endif
