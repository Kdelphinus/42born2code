#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
        FragTrap(std::string name);
		FragTrap(const FragTrap &ft);
		FragTrap &operator=(const FragTrap &ft);
		~FragTrap();

		void highFivesGuys(void);
};

#endif
