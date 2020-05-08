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

        void Insert(const T& value)
        {
            if(size == capacity)
            {
                Resize(capacity * 2);
            }

            data[size] = value;
            size += 1;
        }

        void Insert(da::Iterator<T>* iter)
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

        bool IsEmpty() const 
        {
            return (size == 0);
        }

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

        void Clear() 
        {
            delete[] data;
            data = new T[capacity];
            size = 0;
        }

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

        void Assign(da::Iterator<T>* iter)
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

        da::Iterator<T>* ToIterator() const 
        {
            return new da::Iterator<T>(data,size);
        }

        friend std::ostream& operator<<(std::ostream& out,const Vector<T>& obj)
        {
            out << obj.ToString();
            return out;
        }
    };

}

#endif