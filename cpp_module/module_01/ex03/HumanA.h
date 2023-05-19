#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA {
	private:
		std::string _name;
		Weapon &_weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		std::string getWeapon() const;
		std::string getName() const;
		void attack();

};

#endif
