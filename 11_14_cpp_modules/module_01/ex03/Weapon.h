#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon();
		std::string getType() const;
		void setType(std::string type);
};

#endif
