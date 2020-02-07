#ifndef ITERATOR_H
#define ITERATOR_H

namespace ds
{
    template <class T> // keyword for generic function. written before the class
    class IteratorInterface
    {
    public:
        virtual bool HasNext() const = 0; // constant virtual method
        virtual T& Next() = 0; // t reference class, not const because fields are being modified
    };
}

#endif

/*side note:
  int max(int a, int b){
    return (a>b)?(a):(b);
  }

  string max(string a, string b){
    return (a==b)?(a):(b);   // ternary expression
  }

keyword: template (indicates you are starting a generic function)
 ex:template <typename t>
 if theres two typenames you would do template<typename T, typename S>

 T Max(Ta,Tb){
   return(a>=b)?(a):(b);
 } 
 #include <iostream>
using namespace std;


template <typename T>
T Max(T a,T b){
  return (a>=b)?(a):(b);
}




int main() {
  int a =4;
  int b =3;
  int max = Max <int> (a,b);
  cout << max;
  
}
*/
