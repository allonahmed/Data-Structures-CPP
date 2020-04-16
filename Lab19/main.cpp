#include <iostream>
#include <string>

template<class K,class V>
struct Map
{
	K keys[100];
	V values[100];
	int size;
};

template<class K,class V>
void Initialize(Map<K,V>& map)
{
	map.size = 0;
}

template<class K,class V>
void Put(Map<K,V>& map,const K& key,const V& value)
{
    int ind = 0;
    while(ind<map.size && map.keys[ind]!=key){
        ind=ind+1;
    }
    if(ind==map.size && map.size<100){
        map.keys[map.size] = key;
        map.values[map.size] = value;
        map.size+=1;
    }
}

template<class K,class V>
V& Get(Map<K,V>& map, const K& key)
{
    int i = 0;
    while(map.keys[i]!=key && i<map.size){
        i+=1;
    }
    if(map.keys[i]==key){
        return map.values[i];
    }
    throw "Key Does Not Exists";     
}

template<class K,class V>
bool Contains(Map<K,V>& map,const K& key)
{
    int i = 0;
    while(i< map.size && map.keys[i]!=key){
        i+=1;
    }
    if(i==map.size){
        return false;
    }
    else{
        return true;
    }

}

template<class K,class V>
void Remove(Map<K,V>& map,const K& key)
{
    int ind = 0;
    while(ind<map.size && map.keys[ind]!=key){
        ind=ind+1;
    }
    if(ind!=map.size){
        for(int j = ind; j<map.size-1; j++){
            map.values[j] = map.values[j+1];
            map.keys[j] = map.keys[j+1];
        }
        map.size = map.size-1;
    }
}

int main()
{
    Map<char,int> m;
    Initialize(m);
    Put(m,'a',1);
    Put(m,'b',2);
    Put(m,'c',3);
    Put(m,'d',4);
    
    Remove(m,'a');

    for(int i= 0; i < m.size; i++){
        std::cout << m.keys[i] << " => " << m.values[i] << std::endl;
    }
    std::cout << std::boolalpha << Contains(m, 'e') << "\n";

    std::cout << Get(m,'d') << "\n";
    
	return 0;
}