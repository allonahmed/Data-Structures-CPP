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
        virtual int Size() const = 0;
        virtual bool IsEmpty() const = 0;
        virtual bool Contains(const T&) const = 0;
    };

    namespace da 
    {
        template <class T>
        class Set : public SetInterface<T>
        {
        private:
            T* data;
            int size;
            int capacity;

            void Resize(int ncp)
            {
                if(ncp <= 0)
                {
                    ncp = 2 * capacity;
                }

                int tcp = (ncp < capacity)?(ncp):(capacity);
                T* tmp = new T[tcp];

                for(int i = 0;i < tcp;i += 1)
                {
                    tmp[i] = data[i];
                }
                delete[] data;
                data = new T[ncp];

                for(int i = 0;i < tcp;i += 1)
                {
                    data[i] = tmp[i];
                }
                delete[] tmp;
            }
        public:
            Set() : size(0), capacity(50)
            {
                data = new T[capacity];
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
                int idx = 0;

                while(idx < size && data[idx] != value)
                {
                    idx += 1;
                }

                if(idx == size)
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

            int Size() const 
            {
                return size;
            }

            bool IsEmpty() const 
            {
                return (size == 0);
            }

            bool Contains(const T& value) const
            {
                int idx = 0;

                while(idx < size && data[idx] != value)
                {
                    idx += 1;
                }
                return (idx != size);
            }
            
            da::Iterator<T>* ToIterator() const 
            {
                return new da::Iterator<T>(data,size);
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
            Node<T>* head;
            int size;
        public:
            Set() : head(NULL), size(0) {}

            Set(const Set<T>& obj)
            {
                size = obj.size;
                head = Copy(obj.head);
            }

            Set<T>& operator=(const Set<T>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    Clear(head);
                    head = Copy(rhs.head);
                }
                return *this;
            }

            ~Set()
            {
                Clear(head);
                head = NULL;
            }

            void Insert(const T& value)
            {
                if(head == NULL)
                {
                    head = new Node<T>(value);
                    size += 1;
                }
                else 
                {
                    Node<T>* tmp = head;
                    Node<T>* prv = NULL;
                    
                    while(tmp != NULL && tmp->GetData() != value)
                    {
                        prv = tmp;
                        tmp = tmp->GetLink();
                    }

                    if(tmp == NULL && prv != NULL)
                    {
                        prv->SetLink(new Node<T>(value));
                        size += 1;
                    }
                }
            }

            void Remove(const T& value)
            {
                if(head != NULL)
                {
                    if(head->GetData() == value)
                    {
                        delete head;
                        head = NULL;
                        size -= 1;
                    }
                    else
                    {
                        Node<T>* tmp = head;
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

            bool IsEmpty() const 
            {
                return (head == NULL);
            }

            int Size() const 
            {
                return size;
            }

            bool Contains(const T& value) const 
            {
                Node<T>* tmp = head;

                while(tmp != NULL && tmp->GetData() != value)
                {
                    tmp = tmp->GetLink();
                }
                return (tmp != NULL);
            }

            sn::Iterator<T>* ToIterator() const 
            {
                return new sn::Iterator<T>(head);
            }

            std::string ToString() const 
            {
                std::stringstream out;

                out << "{";

                for(Node<T>* t = head;t != NULL;t = t->GetLink())
                {
                    out << t->GetData();

                    if(t->GetLink() != NULL)
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

    namespace dn
    {
        template <class T>
        class Set : public SetInterface<T>
        {
        private:
            Node<T>* head;
            int size;
        public:
            Set() : head(NULL), size(0) {}

            Set(const Set<T>& obj)
            {
                size = obj.size;
                head = Copy(obj.head);
            }

            Set<T>& operator=(const Set<T>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    Clear(head);
                    head = Copy(rhs.head);
                }
                return *this;
            }

            ~Set()
            {
                Clear(head);
                head = NULL;
            }

            void Insert(const T& value)
            {
                if(head == NULL)
                {
                    head = new Node<T>(value);
                    size += 1;
                }
                else 
                {
                    Node<T>* tmp = head;

                    while(tmp->GetNext() != NULL && tmp->GetData() != value)
                    {
                        tmp = tmp->GetNext();
                    }

                    if(tmp->GetNext() == NULL && tmp->GetData() != value)
                    {
                        tmp->SetNext(new Node<T>(value));
                        tmp->GetNext()->SetPrev(tmp);
                        size += 1;
                    }
                }
            }

            void Remove(const T& value)
            {
                if(head != NULL)
                {
                    if(head->GetData() == value)
                    {
                        delete head;
                        head = NULL;
                        size -= 1;
                    }
                    else
                    {
                        Node<T>* tmp = head;

                        while(tmp != NULL && tmp->GetData() != value)
                        {
                            tmp = tmp->GetNext();
                        }

                        if(tmp != NULL)
                        {
                            if(tmp->GetPrev() != NULL)
                            {
                                tmp->GetPrev()->SetNext(tmp->GetNext());
                            }

                            if(tmp->GetNext() != NULL)
                            {
                                tmp->GetNext()->SetPrev(tmp->GetPrev());
                            }
                            delete tmp;
                            tmp = NULL;
                            size -= 1;
                        }
                    }
                }
            }

            bool IsEmpty() const 
            {
                return (head == NULL);
            }

            int Size() const 
            {
                return size;
            }

            bool Contains(const T& value) const 
            {
                Node<T>* tmp = head;

                while(tmp != NULL && tmp->GetData() != value)
                {
                    tmp = tmp->GetNext();
                }
                return (tmp != NULL);
            }

            dn::Iterator<T>* ToIterator() const 
            {
                return new dn::Iterator<T>(head);
            }

            std::string ToString() const 
            {
                std::stringstream out;

                out << "{";

                for(Node<T>* t = head;t != NULL;t = t->GetNext())
                {
                    out << t->GetData();

                    if(t->GetNext() != NULL)
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