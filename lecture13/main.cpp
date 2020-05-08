#include <iostream>
#include "Pair.h"
#include <map>
#include "Vector.h"
using namespace std;



// template <class K, class V>
void LetterCount(string s){

    map < char, int > mymap; 
    char val;
    for ( int i = 0; i < s.size(); i++ ) 
    {
        val = s[i];
        mymap[val] ++;
    }
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
        cout << it->first << " => " << it->second << '\n';
    }

}

int main(){

    LetterCount("helloworld");
 


}