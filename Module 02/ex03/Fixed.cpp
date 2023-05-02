#include "Fixed.hpp"


// ex00
Fixed::Fixed() {
	//std::cout << "Default constructor called" << std::endl;
	this->fixedValue = 0;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

int Fixed::getRawBits() const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedValue);
}

void Fixed::setRawBits(int const rawBits) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->fixedValue = rawBits;
}

Fixed &Fixed::operator=(Fixed const &copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(copy.getRawBits());
	return (*this);
}


// ex01
Fixed::Fixed(int intNum) {
	//std::cout << "Int constructor called" << std::endl;
	this->setRawBits(intNum << this->fractalBits);
}

Fixed::Fixed(float floatNum) {
	//std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(floatNum * (1 << this->fractalBits)));
}

int Fixed::toInt() const {
	return (this->getRawBits() >> this->fractalBits);
}

float Fixed::toFloat() const {
	float result;

	result = (float)this->getRawBits() / (1 << this->fractalBits);
	return (result);
}

std::ostream &operator<<(std::ostream &op, Fixed const &copy) {
	op << copy.toFloat();
	return (op);
}


// ex02

int Fixed::operator>(Fixed const &copy) const {
	if (this->getRawBits() > copy.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator<(Fixed const &copy) const {
	if (this->getRawBits() < copy.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator>=(Fixed const &copy) const {
	if (this->getRawBits() >= copy.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator<=(Fixed const &copy) const {
	if (this->getRawBits() <= copy.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator==(Fixed const &copy) const {
	if (this->getRawBits() == copy.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator!=(Fixed const &copy) const {
	if (this->getRawBits() != copy.getRawBits())
		return 1;
	return 0;
}

Fixed Fixed::operator+(Fixed const &copy) const {
	Fixed result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed Fixed::operator-(Fixed const &copy) const {
	Fixed result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed Fixed::operator*(Fixed const &copy) const {
	Fixed result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed Fixed::operator/(Fixed const &copy) const {
	Fixed result(this->toFloat() / copy.toFloat());
	return (result);
}

Fixed &Fixed::operator++() {
	(this->fixedValue)++;
	return (*this);
}

Fixed &Fixed::operator--() {
	(this->fixedValue)--;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;

	(this->fixedValue)++;
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;

	(this->fixedValue)--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	return b;
}