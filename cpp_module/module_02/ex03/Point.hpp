#ifndef POINT_HPP
#define POINT_HPP

class Point {
    public:
        Point();
        Point(const Point &point);
        Point &operator=(const Point &point);
        ~Point();
};

#endif
