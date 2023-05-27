#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _num;
		static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed();

		explicit Fixed(const int num);
		explicit Fixed(const float num);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;

//		&operator<<();
};

#endif
