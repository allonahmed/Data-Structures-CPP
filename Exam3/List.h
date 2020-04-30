#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"
#include "Iterator.h"

namespace ds
{
    template <class T>
    class ListInterface
    {
    public:
        virtual void Insert(const T&) = 0;
        virtual void InsertAt(int,const T&) = 0;
        virtual void InsertFirst(const T&) = 0;
        virtual void InsertLast(const T&) = 0;
        virtual void Remove(const T&) = 0;
        virtual void RemoveAt(int) = 0;
        virtual void RemoveFirst() = 0;
        virtual void RemoveLast() = 0;
        virtual int Size() const = 0;
        virtual bool IsEmpty() const = 0;
        virtual int IndexOf(const T&) const = 0;
        virtual bool Contains(const T&) const = 0;
        virtual T& operator[](int) = 0;
        virtual const T& operator[](int) const = 0;
    };

    namespace da 
    {
        template <class T>
        class Vector : public ListInterface<T>
        {
        private:
            T* data;
            int size;
            int capacity;

            void Resize()
            {
                int ocp = capacity;
                capacity *= 2;
                T* tmp = new T[ocp];

                for(int i = 0;i < ocp;i += 1)
                {
                    tmp[i] = data[i];
                }
                delete[] data;
                data = new T[capacity];

                for(int i = 0;i < ocp;i += 1)
                {
                    data[i] = tmp[i];
                }
                delete[] tmp;
            }
        public:
            Vector() : size(0), capacity(50)
            {
                data = new T[capacity];
            }

            Vector(int value) : size(0), capacity(value)
            {
                if(capacity <= 0)
                {
                    capacity = 50;
                }
                data = new T[capacity];
            }

            Vector(const Vector<T>& obj)
            {
                size = obj.size;
                capacity = obj.capacity;
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

            ~Vector() 
            {
                delete[] data;
            }

            void Insert(const T& value)
            {
                if(size == capacity)
                {
                    Resize();
                }
                data[size] = value;
                size += 1;
            }

            void InsertAt(int idx,const T& value)
            {
                if(idx >= 0 && idx < size)
                {
                    if(size == capacity)
                    {
                        Resize();
                    }

                    for(int i = size;i > idx;i -= 1)
                    {
                        data[i] = data[i-1];
                    }
                    data[idx] = value;
                    size += 1;
                }
            }

            void InsertFirst(const T& value)
            {
                if(size == capacity)
                {
                    Resize();
                }

                for(int i = size;i > 0;i -= 1)
                {
                    data[i] = data[i-1];
                }
                data[0] = value;
                size += 1;
            }

            void InsertLast(const T& value)
            {
                if(size == capacity)
                {
                    Resize();
                }
                data[size] = value;
                size += 1;
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

            void RemoveAt(int idx)
            {
                if(idx >= 0 && idx < size)
                {
                    size -= 1;

                    for(int i = idx;i < size;i += 1)
                    {
                        data[i] = data[i+1];
                    }
                }
            }

            void RemoveFirst()
            {
                if(size > 0)
                {
                    size -= 1;
                    
                    for(int i = 0;i < size;i += 1)
                    {
                        data[i] = data[i+1];
                    }
                }
            }

            void RemoveLast()
            {
                if(size > 0)
                {
                    size -= 1;
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

            int IndexOf(const T& value) const 
            {
                int idx = 0;

                while(idx < size && data[idx] != value)
                {
                    idx += 1;
                }
                return (idx == size)?(-1):(idx);
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

            T& operator[](int idx)
            {
                if(idx >= 0 && idx < size)
                {
                    return data[idx];
                }
                throw "Out of Bound";
            }

            const T& operator[](int idx) const
            {
                if(idx >= 0 && idx < size)
                {
                    return data[idx];
                }
                throw "Out of Bound";
            }
            
            da::Iterator<T>* ToIterator() const 
            {
                return new da::Iterator<T>(data,size);
            }

            std::string ToString() const 
            {
                std::stringstream out;

                out << "[";

                for(int i = 0;i < size;i += 1)
                {
                    out << data[i];

                    if((i + 1) != size)
                    {
                        out << ",";
                    }
                }
                out << "]";
                return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Vector<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }

    namespace sn
    {
        template <class T>
        class LinkedList : public ListInterface<T>
        {
        private:
            Node<T>* head;
            Node<T>* tail;
            int size;
        public:
            LinkedList() : head(NULL), tail(NULL), size(0) {}

            LinkedList(const LinkedList<T>& obj)
            {
                size = obj.size;
                head = Copy(obj.head);
                tail = head;

                while(tail != NULL && tail->GetLink() != NULL)
                {
                    tail = tail->GetLink();
                }
            }

            LinkedList<T>& operator=(const LinkedList<T>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    Clear(head);
                    head = Copy(rhs.head);
                    tail = head;

                    while(tail != NULL && tail->GetLink() != NULL)
                    {
                        tail = tail->GetLink();
                    }
                }
                return *this;
            }

            ~LinkedList()
            {
                Clear(head);
                head = NULL;
                tail = NULL;
            }

            void Insert(const T& value)
            {
                if(head == NULL)
                {
                    head = new Node<T>(value);
                    tail = head;
                }
                else 
                {
                    tail->SetLink(new Node<T>(value));
                    tail = tail->GetLink();
                }
                size += 1;
            }

            void InsertAt(int idx,const T& value)
            {
                if(idx >= 0 && idx < size)
                {
                    if(idx == 0)
                    {
                        Node<T>* tmp = new Node<T>(value);
                        tmp->SetLink(head);
                        head = tmp;
                    }
                    else if(idx == size - 1)
                    {
                        tail->SetLink(new Node<T>(value));
                        tail = tail->GetLink();
                    }
                    else 
                    {
                        Node<T>* prv = head;
                        idx -= 1;

                        for(int i = 0;i < idx;i += 1)
                        {
                            prv = prv->GetLink();
                        }
                        Node<T>* tmp = new Node<T>(value);
                        tmp->SetLink(prv->GetLink());
                        prv->SetLink(tmp);    
                    }
                    size += 1;
                }
            }

            void InsertFirst(const T& value)
            {
                if(head == NULL)
                {
                    head = new Node<T>(value);
                    tail = head;
                }
                else
                {
                    Node<T>* tmp = new Node<T>(value);
                    tmp->SetLink(head);
                    head = tmp;
                }
                size += 1;
            }

            void InsertLast(const T& value)
            {
                if(tail == NULL)
                {
                    tail = new Node<T>(value);
                    head = tail;
                }
                else
                {
                    tail->SetLink(new Node<T>(value));
                    tail = tail->GetLink();
                }
                size += 1;
            }

            void Remove(const T& value)
            {
                if(head != NULL)
                {
                    if(head == tail && head->GetData() == value)
                    {
                        delete head;
                        head = NULL;
                        tail = NULL;
                        size -= 1;
                    }
                    else if(head->GetData() == value)
                    {
                        Node<T>* tmp = head;
                        head = head->GetLink();
                        delete tmp;
                        tmp = NULL;
                    }
                    else 
                    {
                        Node<T>* tmp = head->GetLink();
                        Node<T>* prv = head;

                        while(tmp != NULL && tmp->GetData() != value)
                        {
                            prv = tmp;
                            tmp = tmp->GetLink();
                        }

                        if(tmp != NULL && prv != NULL)
                        {
                            if(tmp == tail)
                            {
                                tail = prv;
                            }
                            prv->SetLink(tmp->GetLink());
                            delete tmp;
                            tmp = NULL;
                            size -= 1;
                        }
                    }
                }
            }

            void RemoveAt(int idx)
            {
                if(idx >= 0 && idx < size)
                {
                    if(idx == 0)
                    {
                        if(head == tail)
                        {
                            delete head;
                            head = NULL;
                            tail = NULL;
                        }
                        else 
                        {
                            Node<T>* tmp = head;
                            head = head->GetLink();
                            delete tmp;
                            tmp = NULL;
                        }
                    }
                    else
                    {
                        Node<T>* prv = head;
                        Node<T>* tmp = head->GetLink();

                        for(int i = 1;i < idx;i += 1)
                        {
                            prv = tmp;
                            tmp = tmp->GetLink();
                        }

                        if(tmp == tail)
                        {
                            tail = prv;
                        }
                        prv->SetLink(tmp->GetLink());
                        delete tmp;
                        tmp = NULL;
                    }
                    size -= 1;
                }
            }         

            void RemoveFirst()
            {
                if(head != NULL)
                {
                    if(head == tail)
                    {
                        delete head;
                        head = NULL;
                        tail = NULL;
                    }
                    else
                    {
                        Node<T>* tmp = head;
                        head = head->GetLink();
                        delete tmp;
                        tmp = NULL;
                    }
                    size -= 1;
                }
            }

            void RemoveLast()
            {
                if(tail != NULL)
                {
                    if(head == tail)
                    {
                        delete tail;
                        tail = NULL;
                        head = NULL;
                    }
                    else 
                    {
                        Node<T>* prv = head;

                        while(prv->GetLink() != tail)
                        {
                            prv = prv->GetLink();
                        }
                        prv->SetLink(NULL);
                        delete tail;
                        tail = prv;
                    }
                    size -= 1;
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

            int IndexOf(const T& value) const 
            {
                Node<T>* tmp = head;
                int idx = 0;

                while(tmp != NULL && tmp->GetData() != value)
                {
                    tmp = tmp->GetLink();
                    idx += 1;
                }
                return (tmp == NULL)?(-1):(idx);
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

            T& operator[](int idx)
            {
                if(idx >= 0 && idx < size)
                {
                    Node<T>* tmp = head;
                    for(int i = 0;i < idx;i += 1)
                    {
                        tmp = tmp->GetLink();
                    }
                    return tmp->GetData();
                }
                throw "Out of Bound";
            }

            const T& operator[](int idx) const
            {
                if(idx >= 0 && idx < size)
                {
                    Node<T>* tmp = head;
                    for(int i = 0;i < idx;i += 1)
                    {
                        tmp = tmp->GetLink();
                    }
                    return tmp->GetData();
                }
                throw "Out of Bound";
            }

            sn::Iterator<T>* ToIterator() const 
            {
                return new sn::Iterator<T>(head);
            }

            std::string ToString() const 
            {
                std::stringstream out;

                out << "[";

                for(Node<T>* t = head;t != NULL;t = t->GetLink())
                {
                    out << t->GetData();

                    if(t->GetLink() != NULL)
                    {
                        out << ",";
                    }
                }
                out << "]";
                return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const LinkedList<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }

    namespace dn
    {
        template <class T>
        class LinkedList : public ListInterface<T>
        {
        private:
            Node<T>* head;
            Node<T>* tail;
            int size;
        public:
            LinkedList() : head(NULL), tail(NULL), size(0) {}

            LinkedList(const LinkedList<T>& obj)
            {
                size = obj.size;
                head = Copy(obj.head);
                tail = head;

                while(tail != NULL && tail->GetNext() != NULL)
                {
                    tail = tail->GetNext();
                }
            }

            LinkedList<T>& operator=(const LinkedList<T>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    Clear(head);
                    head = Copy(rhs.head);
                    tail = head;

                    while(tail != NULL && tail->GetNext() != NULL)
                    {
                        tail = tail->GetNext();
                    }
                }
                return *this;
            }

            ~LinkedList()
            {
                Clear(head);
                head = NULL;
                tail = NULL;
            }

            void Insert(const T& value)
            {
                if(head == NULL)
                {
                    head = new Node<T>(value);
                    tail = head;
                }
                else 
                {
                    tail->SetNext(new Node<T>(value));
                    tail->GetNext()->SetPrev(tail);
                    tail = tail->GetNext();
                }
                size += 1;
            }

            void InsertAt(int idx,const T& value)
            {
                if(idx >= 0 && idx < size)
                {
                    if(idx == 0)
                    {
                        head->SetPrev(new Node<T>(value));
                        head->GetPrev()->SetNext(head);
                        head = head->GetPrev();
                    }
                    else if(idx == size - 1)
                    {
                        tail->SetNext(new Node<T>(value));
                        tail->GetNext()->SetPrev(tail);
                        tail = tail->GetNext();
                    }
                    else 
                    {
                        Node<T>* tmp = head->GetNext();

                        for(int i = 1;i < idx;i += 1)
                        {
                            tmp = tmp->GetNext();
                        }
                        Node<T>* ntp = new Node<T>(value);
                        ntp->SetNext(tmp);
                        ntp->SetPrev(tmp->GetPrev());
                        ntp->GetPrev()->SetNext(ntp);
                        tmp->SetPrev(ntp);    
                    }
                    size += 1;
                }
            }

            void InsertFirst(const T& value)
            {
                if(head == NULL)
                {
                    head = new Node<T>(value);
                    tail = head;
                }
                else
                {
                    head->SetPrev(new Node<T>(value));
                    head->GetPrev()->SetNext(head);
                    head = head->GetPrev();
                }
                size += 1;
            }

            void InsertLast(const T& value)
            {
                if(tail == NULL)
                {
                    tail = new Node<T>(value);
                    head = tail;
                }
                else
                {
                    tail->SetNext(new Node<T>(value));
                    tail->GetNext()->SetPrev(tail);
                    tail = tail->GetNext();
                }
                size += 1;
            }

            void Remove(const T& value)
            {
                if(head != NULL)
                {
                    if(head == tail && head->GetData() == value)
                    {
                        delete head;
                        head = NULL;
                        tail = NULL;
                        size -= 1;
                    }
                    else if(head->GetData() == value)
                    {
                        Node<T>* tmp = head;
                        head = head->GetNext();
                        delete tmp;
                        tmp = NULL;

                        if(head != NULL)
                        {
                            head->SetPrev(NULL);
                        }
                    }
                    else 
                    {
                        Node<T>* tmp = head->GetNext();

                        while(tmp != NULL && tmp->GetData() != value)
                        {
                            tmp = tmp->GetNext();
                        }

                        if(tmp != NULL)
                        {
                            if(tmp == tail)
                            {
                                tmp->GetPrev()->SetNext(NULL);
                                tail = tmp->GetPrev();
                            }
                            else
                            {
                                tmp->GetPrev()->SetNext(tmp->GetNext());
                                tmp->GetNext()->SetPrev(tmp->GetPrev());
                            }
                            delete tmp;
                            tmp = NULL;
                            size -= 1;
                        }
                    }
                }
            }

            void RemoveAt(int idx)
            {
                if(idx >= 0 && idx < size)
                {
                    if(idx == 0)
                    {
                        if(head == tail)
                        {
                            delete head;
                            head = NULL;
                            tail = NULL;
                        }
                        else 
                        {
                            Node<T>* tmp = head;
                            head = head->GetNext();
                            delete tmp;
                            tmp = NULL;

                            if(head != NULL)
                            {
                                head->SetPrev(NULL);
                            }
                        }
                    }
                    else if(idx == size - 1)
                    {
                        Node<T>* tmp = tail;
                        tail->GetPrev()->SetNext(NULL);
                        tail = tail->GetPrev();
                        delete tmp;
                        tmp = NULL;
                    }
                    else 
                    {
                        Node<T>* tmp = head->GetNext();

                        for(int i = 1;i < idx;i += 1)
                        {
                            tmp = tmp->GetNext();
                        }
                        tmp->GetPrev()->SetNext(tmp->GetNext());
                        tmp->GetNext()->SetPrev(tmp->GetPrev());
                        delete tmp;
                        tmp = NULL;
                    }
                    size -= 1;
                }
            }         

            void RemoveFirst()
            {
                if(head != NULL)
                {
                    if(head == tail)
                    {
                        delete head;
                        head = NULL;
                        tail = NULL;
                    }
                    else
                    {
                        Node<T>* tmp = head;
                        head = head->GetNext();
                        delete tmp;
                        tmp = NULL;

                        if(head != NULL)
                        {
                            head->SetPrev(NULL);
                        }
                    }
                    size -= 1;
                }
            }

            void RemoveLast()
            {
                if(tail != NULL)
                {
                    if(head == tail)
                    {
                        delete tail;
                        tail = NULL;
                        head = NULL;
                    }
                    else 
                    {
                        Node<T>* tmp = tail;
                        tail->GetPrev()->SetNext(NULL);
                        tail = tail->GetPrev();
                        delete tmp;
                        tmp = NULL;
                    }
                    size -= 1;
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

            int IndexOf(const T& value) const 
            {
                Node<T>* tmp = head;
                int idx = 0;

                while(tmp != NULL && tmp->GetData() != value)
                {
                    tmp = tmp->GetNext();
                    idx += 1;
                }
                return (tmp == NULL)?(-1):(idx);
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

            T& operator[](int idx)
            {
                if(idx >= 0 && idx < size)
                {
                    Node<T>* tmp = head;
                    for(int i = 0;i < idx;i += 1)
                    {
                        tmp = tmp->GetNext();
                    }
                    return tmp->GetData();
                }
                throw "Out of Bound";
            }

            const T& operator[](int idx) const
            {
                if(idx >= 0 && idx < size)
                {
                    Node<T>* tmp = head;
                    for(int i = 0;i < idx;i += 1)
                    {
                        tmp = tmp->GetNext();
                    }
                    return tmp->GetData();
                }
                throw "Out of Bound";
            }

            dn::Iterator<T>* ToIterator() const 
            {
                return new dn::Iterator<T>(head);
            }

            std::string ToString() const 
            {
                std::stringstream out;

                out << "[";

                for(Node<T>* t = head;t != NULL;t = t->GetNext())
                {
                    out << t->GetData();

                    if(t->GetNext() != NULL)
                    {
                        out << ",";
                    }
                }
                out << "]";
                return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const LinkedList<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }
}
#endif