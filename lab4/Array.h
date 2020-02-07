#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream>
#include "Iterator.h"

namespace ds 
{
    namespace it
    {
        template<class T>
        class Iterator : public IteratorInterface<T> // when inheriting, put the type of the class which is <T>
        {
        private:
            T* data;
            int cnt; // count
            int capacity;
        public:
            Iterator() : Iterator(NULL,0) {}

            Iterator(T* data,int capacity) : data(data), capacity(capacity), cnt(0) 
            {
                if(this->capacity < 0)   //arguments because users give garbage
                {
                    this->capacity = 0;
                }
            }

            bool HasNext() const //overrides inherited function
            {
                return (cnt < capacity);
            }

            T& Next() 
            {
                int c = cnt;
                cnt += 1;
                return data[c];
            }
        };
    }

    template<class T>
    class Array
    {
    private:
        T* data;
        int capacity;
    public:
        Array() : Array(100) {} // delegates job to overloaded constructor

        Array(int capacity) : capacity(capacity) // overloaded constuctor's capacity is set to 100, the data type capacity is assigning capacity to the field capacity
        {
            if(this->capacity <= 0)
            {
                this->capacity = 100;
            }

            data = new T[this->capacity]; // new keyword followed by data type <t>

            for(int i = 0;i < this->capacity;i += 1) // using this operator to avoid ambigious statements
            {
                data[i] = T();
            }
        }

        Array(const Array<T>& obj)
        {
            /*Deep Copy*/
            capacity = obj.capacity;
            data = new T[capacity];

            for(int i = 0;i < capacity;i += 1)
            {
                data[i] = obj.data[i]; // copies all the elements of the array 
            }
        }

        Array<T>& operator=(const Array<T>& rhs)
        {
            if(this != &rhs)
            {
                capacity = rhs.capacity;
                delete[] data;
                data = new T[capacity];

                for(int i = 0;i < capacity;i += 1)
                {
                    data[i] = rhs.data[i];
                }
            }
            return *this;
        }

        ~Array() {delete[] data;}

        const T& operator[](int idx) const   //subscript operator
        {
            if(idx < 0 || idx >= capacity)
            {
                throw "Out of bound";
            }
            return data[idx];
        }

        T& operator[](int idx)  
        {
            if(idx < 0 || idx >= capacity)
            {
                throw "Out of bound";
            }
            return data[idx];
        }

        int Length() const {return capacity;}

        std::string ToString() const 
        {
            std::stringstream out;

            out << "[";

            for(int i = 0;i < capacity;i += 1)
            {
                out << data[i];

                if(i + 1 < capacity)
                {
                    out << ",";
                }
            }

            out << "]";
            return out.str();
        }

        it::Iterator<T>* ToIterator() const 
        {
            return new it::Iterator<T>(data,capacity);
        }

        friend std::ostream& operator<<(std::ostream& out,const Array<T>& obj)
        {
            out << obj.ToString();
            return out;
        }
    };

}

#endif
