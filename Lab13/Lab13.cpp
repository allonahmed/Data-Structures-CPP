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

// bool ifNumber(char s){
//     if (isdigit(s) == false && isdigit(s)==0) {
//       return false; 
//     }
//     int x =s-48;
//     if (x>=0){
//       return true;
//     }
//     else {
//       return false;
//     }
//   }


bool IsPattern(std::string str)
{  
  int counta = 0, countb = 0;

  for(int i = 0; i<str.size()/2; i++){
    if(str[i]!='a'){
      return false;
    }
    else{
      counta++;
    }
  }
  for(int i = str.size()-1; i>=str.size()/2; i--){
    if(str[i]!='b'){
      return false;
    }
    else{
      countb++;
    }
  }

  if(countb == counta){
    return true;
  }
  else{
    return false;
  }
}

int main()
 {
//     std::ofstream Allon;
//     Allon.open("sample.txt");
//     Allon << "hello world!\n";
//     Allon.close();

  std::string test= "abcdefg";
  std::string name = "abbbba";
  std::string ext = "";
  std::string ext1 = "aaaaaaaaabbbbbbbbb";


  

  cout << boolalpha;
  cout << IsPattern(name) << endl;
  cout << IsPattern(test) << endl;
  cout << IsPattern(ext) << endl;
  cout << IsPattern(ext1) << endl;
    

    return 0; 
}
