#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap a = ClapTrap();
    ScavTrap b = ScavTrap("b");
    ScavTrap c;
    FragTrap f;

    c = b;
    c.setName("c");

    b.guardGate();
    c.guardGate();

    std::cout << "hp: " << a.getHitPoints() << " ep: " << a.getEnergyPoints() << " ad: " << a.getDamage() << std::endl;
    std::cout << "hp: " << b.getHitPoints() << " ep: " << b.getEnergyPoints() << " ad: " << b.getDamage() << std::endl;
    std::cout << "hp: " << c.getHitPoints() << " ep: " << c.getEnergyPoints() << " ad: " << c.getDamage() << std::endl;
}
