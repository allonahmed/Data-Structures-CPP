/******************************************
 * Lab 01: String Manipulation
 * Before you begin compile the code to
 * make sure the code is working properly.
 *****************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

std::string RandStr(int n)
{
    int l = (n <= 0)?(20):(n);
    std::string values = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*(){}:;,.?";
    std::string result = "";
    int m = values.length();
    for(int i = 0;i < l;i += 1)
    {
        result += values[rand() % m];
    }

    return result;
}

bool isLower(char p){
  if (p>='a' && p<='z'){
    return true;
  } else{
    return false;
  }
}

bool isUpper(char p){
   if (p>='A' && p<='Z'){
    return true;
  } else{
    return false;
  }
}

int LetterCount(string n){
  int size = n.length();
  int count = 0;
  for (int i = 0; i<size; i++){
    if ((n[i]>='a' && n[i]<='z')||(n[i]>='A' && n[i]<='Z')){
      count++;
    }
  }
  return count;
}

string ToLower(string p){
  int size = p.length();
  for(int i = 0; i<size; i++){
    if(p[i]>='A' && p[i]<='Z'){
      p[i] = p[i] + 32;   
    }
  }
  return p;
}

string ToUpper(string p){
  // string lc = "";
  int size = p.length();
  for(int i = 0; i<size; i++){
    if(p[i]>='a' && p[i]<='z'){
      p[i] = p[i] - 32;     
    }
  }
  return p;
}
string Substr(string str, char s, char e){
  int start, end;
  string subst = "";
  int size = str.length();
  for(int ind = 0; ind < size; ind++)
  {
    if(s==str[ind])
    {
      start = ind;
      continue;
    }
    if(e!=str[ind]){
      end = str.length();
    }
    else if(e==str[ind])
    {
      end = ind;
      break;
    }
  }
  if (start < 0){
    return subst;
  }
  for(int s = start; s<end; s++)
  {
    subst = subst + str[s];
  }

return subst;
}



int main()
{
    srand(time(NULL));
    std::string str = RandStr((rand() % 41 + 20));
    char s,e;
    s = 'a';
    e = 'z';

    std::cout << "The random string generated is\n" << str << "\n";
    
    std::cout << "The letter count is " << LetterCount(str) << std::endl;
    std::cout << "Substr: " << Substr(str, s, e) << std::endl;
    std::cout << "to lower: " << ToLower(str) << std::endl;
    std::cout << "to upper: " << ToUpper(str) << std::endl;
    

    return 0;
}
