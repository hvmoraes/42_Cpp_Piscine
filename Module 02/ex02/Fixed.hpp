#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		// ex00
		Fixed();
		~Fixed();
		Fixed &operator=(Fixed const &copy);
		int getRawBits() const;
		void setRawBits(int const rawBits);

		// ex01
		Fixed(Fixed const &copy);
		Fixed(int const intNum);
		Fixed(float const floatNum);
		float toFloat() const;
		int toInt() const;

		// ex02
		int operator>(Fixed const &copy) const;
		int operator<(Fixed const &copy) const;
		int operator>=(Fixed const &copy) const;
		int operator<=(Fixed const &copy) const;
		int operator==(Fixed const &copy) const;
		int operator!=(Fixed const &copy) const;
		Fixed operator+(Fixed const &copy) const;
		Fixed operator-(Fixed const &copy) const;
		Fixed operator*(Fixed const &copy) const;
		Fixed operator/(Fixed const &copy) const;
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int nbr);
		Fixed operator--(int nbr);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
	private:
		int fixedValue;
		static const int fractalBits = 8;
};

// ex01
std::ostream & operator<<( std::ostream &op, Fixed const &copy);

#endif