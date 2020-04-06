#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream>
#include "Iterator.h"

namespace ds
{
    template<class T>
    class Array
    {
    private:
        T* data;
        int capacity;
    public:
        Array() : Array(100) {}

        Array(int capacity) : capacity(capacity) 
        {
            if(this->capacity <= 0)
            {
                this->capacity = 100;
            }

            data = new T[this->capacity];

            for(int i = 0;i < this->capacity;i += 1)
            {
                data[i] = T();
            }
        }

        Array(const Array<T>& obj)
        {
            capacity = obj.capacity;
            data = new T[capacity];

            for(int i = 0;i < capacity;i += 1)
            {
                data[i] = obj.data[i];
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

        const T& operator[](int idx) const 
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

        int Size() const {return capacity;}

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

        da::Iterator<T>* ToIterator() const 
        {
            return new da::Iterator<T>(data,capacity);
        }

        friend std::ostream& operator<<(std::ostream& out,const Array<T>& obj)
        {
            out << obj.ToString();
            return out;
        }
    };
}

#endif