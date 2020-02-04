#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <sstream>


class Shape{
  double Perimeter() const;
  double Area() const;
};

class Square : public Shape{
  private:
    double side;

  public:
    Square(int squareSide =1){
      side = squareSide;
    }
    Square(double p)
    {
      if(p>0)
      {
        side = p;
      }
      else
      {
        side = 1;
      }
    }
    Square(const Square& obj ){
      side = obj.side;
    }
    Square& operator=(const Square& rhs){
      if(this != &rhs)
      {
        side = rhs.side;
      }

      return *this;
    }

    ~Square(){}

    double getSide() const{
      return side;
      }

    void setSide(double side)
    {
       if(side<0)
       {
         throw "invalid input";
       } 
    }

    double Perimeter(){
      double per = side*4;
      return per;
    }
    double Area()
    {
      double area = side *side;
      return area;
    }

    std::string ToString() const{
      std::stringstream out;
      out << "the square has a length of " << side;
      return out.str();
    }

    friend std::ostream& operator<<(std::ostream& out, const Square& obj)
    {
      out << obj.ToString();
      return out;
    }

    
};

#endif
