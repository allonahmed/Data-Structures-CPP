#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include "Stack.h"
using namespace std;

void ReverseContent(std::ifstream& in,std::ofstream& out)
{

    return;
}

bool ifNumber(char s){
    if (isdigit(s) == false && isdigit(s)==0) {
      return false; 
    }
    int x =s-48;
    if (x>=0){
      return true;
    }
    else {
      return false;
    }
  }


bool IsPattern(std::string str)
{  
  char arrow = '^';
  char letter = 'a';
  int size = str.size();
  if(size%3!=0){
      return false;
  }
  for(int i = 0; i<str.size(); i+=3){
      while(str[i]!=letter){            
          return false;
      }
      if(str[i+1]!=arrow){
          return false;
      }
      if(ifNumber(str[i+2])==false){
          return false;
      } 
      letter++;
  }
  return true;
}

int main()
 {
//     std::ofstream Allon;
//     Allon.open("sample.txt");
//     Allon << "hello world!\n";
//     Allon.close();

    std::string test= "a^2b^92c^4d^5";
    std::string name = "a^3b^3c^5d^6";
    string ext = "a^3b^3c^0d^-1";

  

  cout << boolalpha;
  cout << IsPattern(name) << endl;
   cout << IsPattern(test) << endl;
   cout << IsPattern(ext) << endl;
    

    return 0; 
}
