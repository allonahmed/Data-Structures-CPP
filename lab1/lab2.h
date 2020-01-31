#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Circle{
  private:
    double radius;
  public:
    double const PI = 3.141592;

    Circle() : radius(1){}

    Circle(double l){
      if(l>=0){
        radius = l;
      }
      else{
        radius =1;
      }
    }

    Circle(const Circle& obj)
    {
      radius = obj.radius;
    }

    Circle& operator=(const Circle& obj){
      radius = obj.radius;
      return *this;
    }

    ~Circle(){}

    int GetRadius() const{
      return radius;
    }
     int GetRadius(){
      return radius;
    }
    void SetRadius(double rad){
      this->radius=rad;
    }

    double GetDiameter() const{
      double diameter = radius*2;
      return diameter;
    }

    double GetCircumference() const{
      double Circumference = 2*radius*PI;
      return Circumference;
    }

    double GetArea() const{
      double area = radius * radius * PI;
      return area;
    }
    std::string ToString() const{
      std::stringstream out;

      out <<std::fixed << std::setprecision(1);
      out << "Radius: "<< radius << "\n";
      out << "Circumference: " << GetCircumference() << "\n";
      out << "Area: " << GetArea() << "\n";
      out << "Diameter: " << GetDiameter() << "\n";

      return out.str();

    }
    friend std::ostream& operator<<(std::ostream& out, const Circle& obj){
      out <<obj.ToString();
      return out;
    }
};

#endif
