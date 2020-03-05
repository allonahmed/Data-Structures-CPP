#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

class Point
{
public:
    double x;
    double y;

    Point() : Point(0,0) {}

    Point(double x, double y) : x(x), y(y) {}
    
    Point(const Point& obj)
    {
        x = obj.x;
        y = obj.y;
    }

    Point& operator=(const Point& rhs)
    {
        if(this != &rhs)
        {
            x = rhs.x;
            y = rhs.y;
        }
        return *this;
    }

    std::string ToString() const 
    {
        std::stringstream out;

        out << std::fixed << std::setprecision(2);
        out << "(" << x << "," << y << ")";
        return out.str();
    }

    friend std::ostream& operator<<(std::ostream& out,const Point& obj)
    {
        out << obj.ToString();
        return out;
    }
};

#endif