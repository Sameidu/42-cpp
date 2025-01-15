#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed s = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());
    Fixed t = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());

    if ((s < 0) != (t < 0) && s != 0 && t != 0)
        return false;

    Fixed d = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
    return d == 0 || (d < 0) == (s + t <= 0);
}

/*
public static bool PointInTriangle(Point p, Point p0, Point p1, Point p2)
{
    var s = (p0.X - p2.X) * (p.Y - p2.Y) - (p0.Y - p2.Y) * (p.X - p2.X);
    var t = (p1.X - p0.X) * (p.Y - p0.Y) - (p1.Y - p0.Y) * (p.X - p0.X);

    if ((s < 0) != (t < 0) && s != 0 && t != 0)
        return false;

    var d = (p2.X - p1.X) * (p.Y - p1.Y) - (p2.Y - p1.Y) * (p.X - p1.X);
    return d == 0 || (d < 0) == (s + t <= 0);
}
*/