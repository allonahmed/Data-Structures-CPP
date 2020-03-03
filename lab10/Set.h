#ifndef SET_H
#define SET_H

#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"
#include "Iterator.h"

namespace ds 
{
    template <class T>
    class SetInterface 
    {
    public:
        virtual void Insert(const T&) = 0;
        virtual void Remove(const T&) = 0;
        virtual bool Contains(const T&) const = 0;
        virtual bool IsEmpty() const = 0;
        virtual int Size() const = 0;
    };

    namespace da
    {
        template <class T>
        class Set : public SetInterface<T> 
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
            Set() : Set(30) {}

            Set(int capacity) : capacity(capacity), size(0)
            {
                if(this->capacity <= 0)
                {
                    this->capacity = 30;
                }

                data = new T[this->capacity];
            }

            Set(const Set<T>& obj)
            {
                size = obj.size;
                capacity = obj.capacity;
                data = new T[capacity];

                for(int i = 0;i < size;i += 1)
                {
                    data[i] = obj.data[i];
                }
            }

            Set<T>& operator=(const Set<T>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    capacity = rhs.capacity;
                    delete[] data;
                    data = new T[capacity];

                    for(int i = 0;i < size;i += 1)
                    {
                        data[i] = rhs.data[i];
                    }
                }
                return *this;                
            }

            ~Set() 
            {
                delete[] data;
            }

            void Insert(const T& value)
            {
                int pos = 0;

                while(pos < size && data[pos] != value)
                {
                    pos += 1;
                }

                if(pos == size)
                {
                    if(size == capacity)
                    {
                        Resize(2 * capacity);
                    }
                    data[size] = value;
                    size += 1;
                }
            }

            void Remove(const T& value)
            {
                if(size != 0)
                {
                    int pos = 0;

                    while(pos < size && data[pos] != value)
                    {
                        pos += 1;
                    }

                    if(pos != size)
                    {
                        size -= 1;

                        for(int i = pos;i < size;i += 1)
                        {
                            data[i] = data[i+1];
                        }
                    }
                }
            }

            bool Contains(const T& value) const
            {
                if(size == 0)
                {
                    return false;
                }

                int pos = 0;

                while(pos < size && data[pos] != value)
                {
                    pos += 1;
                }
                return (pos != size);
            }

            bool IsEmpty() const
            {
                return (size == 0);
            }

            int Size() const
            {
                return size;
            }

            Iterator<T>* ToIterator() const 
            {
                return new Iterator<T>(data,size);
            }

            std::string ToString() const 
            {
                std::stringstream out;
                out << "{";
                
                for(int i = 0;i < size;i += 1)
			    {
				    out << data[i];
				
				    if((i + 1) != size)
				    {
					    out << ",";
				    }
			    }
			    out << "}";
			    return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Set<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }

    namespace sn
    {
        template <class T>
        class Set : public SetInterface<T> 
        {
        private:
            Node<T>* root;
            int size;

        public:
            Set() : root(NULL), size(0) {}

            Set(const Set<T>& obj)
            {
                size = obj.size;
                root = Copy(obj.root);
            }

            Set<T>& operator=(const Set<T>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    Clear(root);
                    root = Copy(rhs.root);
                }
                return *this;                
            }

            ~Set() 
            {
                Clear(root);
            }

            void Insert(const T& value)
            {
                if(root == NULL)
                {
                    root = new Node<T>(value);
                    size += 1;
                }
                else
                {
                    Node<T>* tmp = root;
                    Node<T>* prv = NULL;

                    while(tmp != NULL && tmp->GetData() != value)
                    {
                        prv = tmp;
                        tmp = tmp->GetLink();
                    }

                    if(tmp == NULL)
                    {
                        prv->SetLink(new Node<T>(value));
                        size += 1;
                    }
                }
            }

            void Remove(const T& value)
            {
                if(root != NULL)
                {
                    if(root->GetLink() == NULL && root->GetData() == value)
                    {
                        delete root;
                        root = NULL;
                        size -= 1;
                    }
                    else
                    {
                        Node<T>* tmp = root;
                        Node<T>* prv = NULL;

                        while(tmp != NULL && tmp->GetData() != value)
                        {
                            prv = tmp;
                            tmp = tmp->GetLink();
                        }

                        if(tmp != NULL && prv != NULL)
                        {
                            prv->SetLink(tmp->GetLink());
                            delete tmp;
                            tmp = NULL;
                            size -= 1;
                        }
                    }
                }
            }

            bool Contains(const T& value) const
            {
                Node<T>* tmp = root;

                while(tmp != NULL && tmp->GetData() != value)
                {
                    tmp = tmp->GetLink();
                }
                return (tmp != NULL);
            }

            bool IsEmpty() const
            {
                return (root == NULL);
            }

            int Size() const
            {
                return size;
            }

            Iterator<T>* ToIterator() const 
            {
                return new Iterator<T>(root);
            }

            std::string ToString() const 
            {
                std::stringstream out;
                out << "{";
                
                for(Node<T>* i = root;i != NULL;i = i->GetLink())
			    {
				    out << i->GetData();
				
				    if(i->GetLink() != NULL)
				    {
					    out << ",";
				    }
			    }
			    out << "}";
			    return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Set<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }
}

#endif