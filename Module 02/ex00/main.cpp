#include "Fixed.hpp"

int main( void )
{
	// Default constructor (raw bits initialized at 0)
	Fixed a;
	Fixed c;

	// Copy constructor
	Fixed b(a);
	std::cout << "Fixed 'b' raw bits value: (copy constructor)\n" << b.getRawBits() << std::endl;
	

	// Setter
	b.setRawBits(18);

	// '=' operator overload
	c = b;

	// Getters
	std::cout << "Fixed 'a' raw bits value:\n" << a.getRawBits() << std::endl << std::endl;
	std::cout << "Fixed 'b' raw bits value:\n" << b.getRawBits() << std::endl << std::endl;
	std::cout << "Fixed 'c' raw bits value:\n" << c.getRawBits() << std::endl << std::endl;
	return 0;
}