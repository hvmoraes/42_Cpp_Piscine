#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &copy);
		int getRawBits() const;
		void setRawBits(int const rawBits);
		Fixed &operator=(Fixed const &copy);

		// ex01
		Fixed(int const intNum);
		Fixed(float const floatNum);
		float toFloat() const;
		int toInt() const;
	private:
		int fixedValue;
		static const int fractalBits = 8;
};

// ex01
std::ostream & operator<<( std::ostream &op, Fixed const &copy);

#endif