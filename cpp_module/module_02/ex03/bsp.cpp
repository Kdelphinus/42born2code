#include "Point.hpp"

/*
 * 삼각형의 두 개의 점으로 직선을 만들고
 * 그 직선을 기준으로 남은 하나의 점과 내부에 있는지 확인하고 싶은 점이
 * 같은 사이드에 있는지 확인하면 삼각형 내부에 점이 있는지 확인할 수 있다.
 */

static bool lineEquation(Point const p, Point const a, Point const b) {
    Fixed zero = Fixed();
    Fixed ans = (b.getX() - a.getX()) * (p.getY() - b.getY()) - (b.getY() - a.getY()) * (p.getX() - b.getX());
    if (ans > zero)
        return true;
    return false;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    if (lineEquation(point, a, b) && lineEquation(point, b, c) && lineEquation(point, c, a))
        return true;
    return false;
}
