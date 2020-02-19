#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <sstream>
#include "Iterator.h"

namespace ds
{
    template<class T>
    class Vector
    {
    private:
        T* data;
        int capacity;
        int size;

        /************************************************
         * Resize() - It resizes the vector to a given 
         * size and maintains the values that are in the 
         * new range.
         ***********************************************/  
        void Resize(int ncp)
        {
            if(ncp <= 0)
            {
                ncp = capacity * 2;
            }

            int tcp = (capacity < ncp)?(capacity):(ncp);

            T* tmp = new T[tcp];

            for(int i = 0;i < tcp;i += 1)
            {
                tmp[i] = data[i];
            }

            capacity = ncp;
            delete[] data;
            data = new T[capacity];

            for(int i = 0;i < tcp;i += 1)
            {
                data[i] = tmp[i];
            }
            delete[] tmp;
        }

    public:
        Vector() : Vector(50) {}

        Vector(int capacity) : capacity(capacity), size(0) 
        {
            if(this->capacity <= 0)
            {
                this->capacity = 50;
            }

            data = new T[this->capacity];
        }

        Vector(const Vector<T>& obj)
        {
            capacity = obj.capacity;
            size = obj.size;
            data = new T[capacity];

            for(int i = 0;i < size;i += 1)
            {
                data[i] = obj.data[i];
            }
        }

        Vector<T>& operator=(const Vector<T>& rhs)
        {
            if(this != &rhs)
            {
                capacity = rhs.capacity;
                size = rhs.size;
                delete[] data;
                data = new T[capacity];

                for(int i = 0;i < size;i += 1)
                {
                    data[i] = rhs.data[i];
                }
            }
            return *this;
        }

        ~Vector() {delete[] data;}

        /******************************************
         * Insert() - adds new element to the end
         * of data. Furthermore, it resizes data
         * when needed.
         *****************************************/
        void Insert(const T& value)
        {
            if(size == capacity)
            {
                Resize(capacity * 2);
            }

            data[size] = value;
            size += 1;
        }

        void Insert(it::Iterator<T>* iter)
        {
            while(iter->HasNext())
            {
                if(size == capacity)
                {
                    Resize(capacity * 2);
                }

                data[size] = iter->Next();
                size += 1;
            }
        }

        /******************************************
         * IsEmpty() - returns true if vector is
         * empty; otherwise, it returns false.
         *****************************************/
        bool IsEmpty() const 
        {
            return (size == 0);
        }

        /******************************************
         * Remove() - removes first instance of
         * parameter from data if present.
         *****************************************/
        void Remove(const T& value)
        {
            if(size > 0)
            {
                int idx = 0;
                while(idx < size && data[idx] != value)
                {
                    idx += 1;
                }

                if(idx != size)
                {
                    size -= 1;
                    for(int i = idx;i < size;i += 1)
                    {
                        data[i] = data[i+1];
                    }
                }
            }
        }

        /*******************************************
         * Clear() - removes all elements from the
         * vector.
         ******************************************/
        void Clear() 
        {
            delete[] data;
            data = new T[capacity];
            size = 0;
        }

        /*******************************************
         * Assign() - assigns values to the vector
         * that replaces the current values of the
         * vector.
         ******************************************/
        void Assign(int cnt,const T& value)
        {
            if(cnt > 0)
            {
                if(cnt > capacity)
                {
                    Resize(cnt * 2);
                }
                
                for(int i = 0;i < cnt;i += 1)
                {
                    data[i] = value;
                }
                size = cnt;
            }
        }

        void Assign(it::Iterator<T>* iter)
        {
            size = 0;
            while(iter->HasNext())
            {
                if(size == capacity)
                {
                    Resize(capacity * 2);
                }

                data[size] = iter->Next();
                size += 1;
            }
        }

        const T& operator[](int idx) const 
        {
            if(idx < 0 || idx >= size)
            {
                throw "Out of bound";
            }
            return data[idx];
        }

        T& operator[](int idx)  
        {
            if(idx < 0 || idx >= size)
            {
                throw "Out of bound";
            }
            return data[idx];
        }

        int Length() const {return size;}

        std::string ToString() const 
        {
            std::stringstream out;

            out << "[";

            for(int i = 0;i < size;i += 1)
            {
                out << data[i];

                if(i + 1 < size)
                {
                    out << ",";
                }
            }

            out << "]";
            return out.str();
        }

        it::Iterator<T>* ToIterator() const 
        {
            return new it::Iterator<T>(data,size);
        }

        friend std::ostream& operator<<(std::ostream& out,const Vector<T>& obj)
        {
            out << obj.ToString();
            return out;
        }
    };

}

#endif