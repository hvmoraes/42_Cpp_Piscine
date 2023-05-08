#include "Point.hpp"

// Formula used from: https://www.youtube.com/watch?v=HYAgJN3x4GA
// w1 = vector proportion of the first side of triangle
//     		 (Ax * (Cy - Ay)) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay))
// w1 = ---------------------------------------------------------------
//						(By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay)
Fixed	*get_w1( Point const a, Point const b, Point const c, Point const p)
{
	Fixed Ax = a.getX();
	Fixed Ay = a.getY();
	Fixed Bx = b.getX();
	Fixed By = b.getY();
	Fixed Cx = c.getX();
	Fixed Cy = c.getY();
	Fixed Px = p.getX();
	Fixed Py = p.getY();


	Fixed	num = (Ax * (Cy - Ay)) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay);
	Fixed	denum = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
	Fixed	f = num / denum;
	Fixed *w1 = new Fixed(f);

	return (w1);
}

// Formula used from: https://www.youtube.com/watch?v=HYAgJN3x4GA
// w2 = vector proportion of the second side of triangle
// 			Py - Ay - w1 * (By - Ay)
// w2 = ------------------------
//							Cy - Ay
Fixed	*get_w2( Fixed w1, Point const a, Point const b, Point const c, Point const p)
{
	Fixed Ay = a.getY();
	Fixed By = b.getY();
	Fixed Cy = c.getY();
	Fixed Py = p.getY();

	Fixed	num = Py - Ay - w1 * (By - Ay);
	Fixed	denum = Cy - Ay;
	Fixed *w2 = new Fixed(num / denum);

	return (w2);
}

bool bsp( Point const a, Point const b, Point const c, Point const p)
{
	Fixed *w1 = get_w1(a, b, c, p);
	Fixed *w2 = get_w2(*w1, a, b, c, p);
	bool	result = true;

	if (*w1 > 0 && *w2 > 0 && (*w1 + *w2) < 1)
		result = true;
	else
		result = false;
	delete w1;
	delete w2;
	return (result);
}