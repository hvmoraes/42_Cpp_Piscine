#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {
	public:
		Point();
		~Point();
		Point(const float x, const float y);
		Point(Fixed const x, Fixed const y);
		Point(Point const &copy);
		Point &operator=(Point &copy);
		Fixed getX() const;
		Fixed getY() const;
	private:
		Fixed const x;
		Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif