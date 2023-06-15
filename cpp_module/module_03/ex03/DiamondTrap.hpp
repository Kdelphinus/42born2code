#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &dt);
        DiamondTrap &operator=(const DiamondTrap &dt);
        ~DiamondTrap();

        void whoAmI();
};

#endif
