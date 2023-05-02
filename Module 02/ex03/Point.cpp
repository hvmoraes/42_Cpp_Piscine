#include "Point.hpp"

Point::Point(): x(0), y(0) {

}

Point::~Point() {

}

Point::Point(const float x, const float y): x(x), y(y) {

}

Point::Point(Fixed const x, Fixed const y): x(x), y(y) {

}

Point::Point(Point const &copy): x(copy.getX()), y(copy.getY()) {

}

Point &Point::operator=(Point &copy) {
	return (copy);
}

Fixed Point::getX() const {
	return (this->x);
}

Fixed Point::getY() const {
	return (this->y);
}