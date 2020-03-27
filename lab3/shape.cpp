#include <iostream>
#include "Shape.h"
using namespace std;

int main() {
  Square one(5);
  cout << one << endl;
  one.setSide(10);
  cout << one << endl;
  cout << one.Area() << endl;
}
