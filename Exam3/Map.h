#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"
#include "Pair.h"
#include "Iterator.h"

namespace ds
{
    template <class K,class V>
    class MapInterface
    {
    public:
        virtual void Put(const K&,const V&) = 0;
        virtual void Remove(const K&) = 0;
        virtual int Size() const = 0;
        virtual bool IsEmpty() const = 0;
        virtual bool Contains(const K&) const = 0;
        virtual V& Get(const K&) = 0;
        virtual const V& Get(const K&) const = 0;
        virtual V& operator[](const K&) = 0;
        virtual const V& operator[](const K&) const = 0;
    };

    namespace da 
    {
        template <class K,class V>
        class Map : public MapInterface<K,V>
        {
        private:
            Pair<K,V>* data;
            int size;
            int capacity;

            void Resize()
            {
                int ocp = capacity;
                capacity *= 2;
                Pair<K,V>* tmp = new Pair<K,V>[ocp];

                for(int i = 0;i < ocp;i += 1)
                {
                    tmp[i] = data[i];
                }
                delete[] data;
                data = new Pair<K,V>[capacity];

                for(int i = 0;i < ocp;i += 1)
                {
                    data[i] = tmp[i];
                }
                delete[] tmp;
            }
        public:
            Map() : size(0), capacity(50)
            {
                data = new Pair<K,V>[capacity];
            }

            Map(int value) : size(0), capacity(value)
            {
                if(capacity <= 0)
                {
                    capacity = 50;
                }
                data = new Pair<K,V>[capacity];
            }

            Map(const Map<K,V>& obj)
            {
                size = obj.size;
                capacity = obj.capacity;
                data = new Pair<K,V>[capacity];

                for(int i = 0;i < size;i += 1)
                {
                    data[i] = obj.data[i];
                }
            }

            Map<K,V>& operator=(const Map<K,V>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    capacity = rhs.capacity;
                    delete[] data;
                    data = new Pair<K,V>[capacity];

                    for(int i = 0;i < size;i += 1)
                    {
                        data[i] = rhs.data[i];
                    }
                }
                return *this;
            }

            ~Map() 
            {
                delete[] data;
            }

            void Put(const K& key,const V& value)
            {
                int idx = 0;

                while(idx < size && data[idx].GetKey() != key)
                {
                    idx += 1;
                }

                if(idx == size)
                {
                    if(size == capacity)
                    {
                        Resize();
                    }
                    data[size] = Pair<K,V>(key,value);
                    size += 1;
                }
            }

            void Remove(const K& key)
            {
                int idx = 0;

                while(idx < size && data[idx].GetKey() != key)
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

            int Size() const 
            {
                return size;
            }

            bool IsEmpty() const 
            {
                return (size == 0);
            }

            bool Contains(const K& key) const
            {
                int idx = 0;

                while(idx < size && data[idx].GetKey() != key)
                {
                    idx += 1;
                }
                return (idx != size);
            }

            V& Get(const K& key)
            {
                int idx = 0;

                while(idx < size && data[idx].GetKey() != key)
                {
                    idx += 1;
                }

                if(idx != size)
                {
                    return data[idx].GetValue();
                }
                throw "Invalid Key";
            }

            const V& Get(const K& key) const
            {
                int idx = 0;

                while(idx < size && data[idx].GetKey() != key)
                {
                    idx += 1;
                }

                if(idx != size)
                {
                    return data[idx].GetValue();
                }
                throw "Invalid Key";
            }

            V& operator[](const K& key)
            {
                int idx = 0;

                while(idx < size && data[idx].GetKey() != key)
                {
                    idx += 1;
                }

                if(idx != size)
                {
                    return data[idx].GetValue();
                }
                throw "Invalid Key";
            }

            const V& operator[](const K& key) const
            {
                int idx = 0;

                while(idx < size && data[idx].GetKey() != key)
                {
                    idx += 1;
                }

                if(idx != size)
                {
                    return data[idx].GetValue();
                }
                throw "Invalid Key";
            }
            
            da::PairIterator<K,V>* ToIterator() const 
            {
                return new da::PairIterator<K,V>(data,size);
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

            friend std::ostream& operator<<(std::ostream& out,const Map<K,V>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }

    namespace sn
    {
        template <class K,class V>
        class Map : public MapInterface<K,V>
        {
        private:
            Node<Pair<K,V>>* head;
            int size;
        public:
            Map() : head(NULL), size(0) {}

            Map(const Map<K,V>& obj)
            {
                size = obj.size;
                head = Copy(obj.head);
            }

            Map<K,V>& operator=(const Map<K,V>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    Clear(head);
                    head = Copy(rhs.head);
                }
                return *this;
            }

            ~Map()
            {
                Clear(head);
                head = NULL;
            }

            void Put(const K& key,const V& value)
            {
                if(head == NULL)
                {
                    head = new Node<Pair<K,V>>(Pair<K,V>(key,value));
                    size += 1;
                }
                else 
                {
                    Node<Pair<K,V>>* tmp = head;

                    while(tmp->GetLink() != NULL && tmp->GetData().GetKey() != key)
                    {
                        tmp = tmp->GetLink();
                    }

                    if(tmp->GetLink() == NULL && tmp->GetData().GetKey() != key)
                    {
                        tmp->SetLink(new Node<Pair<K,V>>(Pair<K,V>(key,value)));
                        size += 1;
                    }
                }
            }

            void Remove(const K& key)
            {
                if(head != NULL)
                {
                    if(head->GetLink() == NULL && head->GetData().GetKey() == key)
                    {
                        delete head;
                        head = NULL;
                        size -= 1;
                    }
                    else if(head->GetData().GetKey() == key)
                    {
                        Node<Pair<K,V>>* tmp = head;
                        head = head->GetLink();
                        delete tmp;
                        tmp = NULL;
                        size -= 1;
                    }
                    else 
                    {
                        Node<Pair<K,V>>* tmp = head->GetLink();
                        Node<Pair<K,V>>* prv = head;

                        while(tmp != NULL && tmp->GetData().GetKey() != key)
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

            bool Contains(const K& key) const 
            {
                Node<Pair<K,V>>* tmp = head;

                while(tmp != NULL && tmp->GetData().GetKey() != key)
                {
                    tmp = tmp->GetLink();
                }
                return (tmp != NULL);
            }

            V& operator[](const K& key)
            {
                Node<Pair<K,V>>* tmp = head;

                while(tmp != NULL && tmp->GetData().GetKey() != key)
                {
                    tmp = tmp->GetLink();
                }

                if(tmp != NULL)
                {
                    return tmp->GetData().GetValue();
                }
                throw "Invalid Key";
            }

            const V& operator[](const K& key) const
            {
                Node<Pair<K,V>>* tmp = head;

                while(tmp != NULL && tmp->GetData().GetKey() != key)
                {
                    tmp = tmp->GetLink();
                }

                if(tmp != NULL)
                {
                    return tmp->GetData().GetValue();
                }
                throw "Invalid Key";
            }

            V& Get(const K& key)
            {
                Node<Pair<K,V>>* tmp = head;

                while(tmp != NULL && tmp->GetData().GetKey() != key)
                {
                    tmp = tmp->GetLink();
                }

                if(tmp != NULL)
                {
                    return tmp->GetData().GetValue();
                }
                throw "Invalid Key";
            }

            const V& Get(const K& key) const
            {
                Node<Pair<K,V>>* tmp = head;

                while(tmp != NULL && tmp->GetData().GetKey() != key)
                {
                    tmp = tmp->GetLink();
                }

                if(tmp != NULL)
                {
                    return tmp->GetData().GetValue();
                }
                throw "Invalid Key";
            }

            sn::PairIterator<K,V>* ToIterator() const 
            {
                return new sn::PairIterator<K,V>(head);
            }

            std::string ToString() const 
            {
                std::stringstream out;

                out << "{";

                for(Node<Pair<K,V>>* t = head;t != NULL;t = t->GetLink())
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

            friend std::ostream& operator<<(std::ostream& out,const Map<K,V>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }

    namespace dn
    {
        template <class K,class V>
        class Map : public MapInterface<K,V>
        {
        private:
            Node<Pair<K,V>>* head;
            int size;
        public:
            Map() : head(NULL), size(0) {}

            Map(const Map<K,V>& obj)
            {
                size = obj.size;
                head = Copy(obj.head);
            }

            Map<K,V>& operator=(const Map<K,V>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    Clear(head);
                    head = Copy(rhs.head);
                }
                return *this;
            }

            ~Map()
            {
                Clear(head);
                head = NULL;
            }

            void Put(const K& key,const V& value)
            {
                if(head == NULL)
                {
                    head = new Node<Pair<K,V>>(Pair<K,V>(key,value));
                    size += 1;
                }
                else 
                {
                    Node<Pair<K,V>>* tmp = head;

                    while(tmp->GetNext() != NULL && tmp->GetData().GetKey() != key)
                    {
                        tmp = tmp->GetNext();
                    }

                    if(tmp->GetNext() == NULL && tmp->GetData().GetKey() != key)
                    {
                        tmp->SetNext(new Node<Pair<K,V>>(Pair<K,V>(key,value)));
                        tmp->GetNext()->SetPrev(tmp);
                        size += 1;
                    }
                }
            }

            void Remove(const K& key)
            {
                if(head != NULL)
                {
                    if(head->GetNext() == NULL && head->GetData().GetKey() == key)
                    {
                        delete head;
                        head = NULL;
                        size -= 1;
                    }
                    else if(head->GetData().GetKey() == key)
                    {
                        Node<Pair<K,V>>* tmp = head;
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
                        Node<Pair<K,V>>* tmp = head->GetNext();

                        while(tmp != NULL && tmp->GetData().GetKey() != key)
                        {
                            tmp = tmp->GetNext();
                        }

                        if(tmp != NULL)
                        {
                            tmp->GetPrev()->SetNext(tmp->GetNext());

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

            bool Contains(const K& key) const 
            {
                Node<Pair<K,V>>* tmp = head;

                while(tmp != NULL && tmp->GetData().GetKey() != key)
                {
                    tmp = tmp->GetNext();
                }
                return (tmp != NULL);
            }

            V& Get(const K& key)
            {
                Node<Pair<K,V>>* tmp = head;

                while(tmp != NULL && tmp->GetData().GetKey() != key)
                {
                    tmp = tmp->GetNext();
                }

                if(tmp == NULL)
                {
                    throw "Invalid Key";
                }
                return tmp->GetData().GetValue();
            }

            const V& Get(const K& key) const
            {
                Node<Pair<K,V>>* tmp = head;

                while(tmp != NULL && tmp->GetData().GetKey() != key)
                {
                    tmp = tmp->GetNext();
                }

                if(tmp == NULL)
                {
                    throw "Invalid Key";
                }
                return tmp->GetData().GetValue();
            }

            V& operator[](const K& key)
            {
                Node<Pair<K,V>>* tmp = head;

                while(tmp != NULL && tmp->GetData().GetKey() != key)
                {
                    tmp = tmp->GetNext();
                }

                if(tmp == NULL)
                {
                    throw "Invalid Key";
                }
                return tmp->GetData().GetValue();
            }

            const V& operator[](const K& key) const
            {
                Node<Pair<K,V>>* tmp = head;

                while(tmp != NULL && tmp->GetData().GetKey() != key)
                {
                    tmp = tmp->GetNext();
                }

                if(tmp == NULL)
                {
                    throw "Invalid Key";
                }
                return tmp->GetData().GetValue();
            }

            dn::PairIterator<K,V>* ToIterator() const 
            {
                return new dn::PairIterator<K,V>(head);
            }

            std::string ToString() const 
            {
                std::stringstream out;

                out << "{";

                for(Node<Pair<K,V>>* t = head;t != NULL;t = t->GetNext())
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

            friend std::ostream& operator<<(std::ostream& out,const Map<K,V>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }
}
#endif