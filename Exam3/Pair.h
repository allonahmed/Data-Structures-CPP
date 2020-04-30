#ifndef PART_H
#define PART_H

#include <iostream>
#include <sstream>
#include <string>

namespace ds
{
    template <class K,class V>
    class Pair
    {
    private:
        K key;
        V value;
    public:
        Pair() : key(K()), value(V()) {}

        Pair(const K& key,const V& value) : key(key), value(value) {}
        
        Pair(const Pair<K,V>& obj)
        {
            key = obj.key;
            value = obj.value;
        }

        Pair<K,V>& operator=(const Pair<K,V>& rhs)
        {
            if(this != &rhs)
            {
                key = rhs.key;
                value = rhs.value;
            }
            return *this;
        }

        ~Pair() {}

        K& GetKey() {return key;}

        const K& GetKey() const {return key;}

        V& GetValue() {return value;}

        const V& GetValue() const {return value;}

        void SetKey(const K& key)
        {
            this->key = key;
        }

        void SetValue(const V& value)
        {
            this->value = value;
        }

        std::string ToString() const
        {
            std::stringstream out;

            out << "(" << key << "," << value << ")";
            return out.str();
        }

        friend std::ostream& operator<<(std::ostream& out,const Pair<K,V>& obj)
        {
            out << obj.ToString();
            return out;
        }
    };
}
#endif