#include <iostream>
#include "Pair.h"
#include <map>
#include "Vector.h"
using namespace std;



// template <class K, class V>
void LetterCount(string s){

    // ds::Vector<ds::Pair<char,int>> map;
    

    // // std::map <char,int> mymap;
    // char val;
    // for(int i = 0; word[i]='\0';i+=1){

    //     if(word[i]>='a' && word[i]<='z'){
            
    //         val = word[i];
            
    //         // mymap.at(val) = i;
    //         map.push_back(Pair<char,int>(val,1));
    //         if(contains(val)){

    //             map[i].setValue(0);

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