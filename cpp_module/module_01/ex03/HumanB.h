#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB {
	private:
		std::string _name;
		Weapon *_weapon = NULL;
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);
		~HumanB();
		void setWeapon(Weapon &weapon);
		std::string getWeapon() const;
		std::string getName() const;
		void attack();
};

#endif
