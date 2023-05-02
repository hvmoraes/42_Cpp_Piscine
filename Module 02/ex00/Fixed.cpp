#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->fixedValue = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(copy.getRawBits());
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedValue);
}

void Fixed::setRawBits(int const rawBits) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedValue = rawBits;
}