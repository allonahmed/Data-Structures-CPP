#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"
#include "Pair.h"

namespace ds
{
    template<class T>
    class IteratorInterface
    {
    public:
        virtual bool HasNext() const = 0;
        virtual T& Next() = 0;
    };

    template<class K,class V>
    class PairIteratorInterface
    {
    public:
        virtual bool HasNext() const = 0;
        virtual const Pair<K,V>& Next() = 0;
        virtual const K& NextKey() = 0;
        virtual V& NextValue() = 0;
    };

    namespace sn
    {
        template<class T>
        class Iterator : public IteratorInterface<T> 
        {
        private:
            Node<T>* data;
        public:
            Iterator() : Iterator(NULL) {}

            Iterator(Node<T>* data) : data(data) {}

            bool HasNext() const 
            {
                return (data != NULL);
            }

            T& Next() 
            {
                Node<T>* tmp = data;
                data = data->GetLink();
                return tmp->GetData();
            }
        };
    
        template<class K,class V>
        class PairIterator : public PairIteratorInterface<K,V> 
        {
        private:
            Node<Pair<K,V>>* data;
        public:
            PairIterator() : PairIterator(NULL) {}

            PairIterator(Node<Pair<K,V>>* data) : data(data) {}

            bool HasNext() const 
            {
                return (data != NULL);
            }

            const Pair<K,V>& Next() 
            {
                Node<Pair<K,V>>* tmp = data;
                data = data->GetLink();
                return tmp->GetData();
            }

            const K& NextKey() 
            {
                Node<Pair<K,V>>* tmp = data;
                data = data->GetLink();
                return tmp->GetData().GetKey();
            }

            V& NextValue()  
            {
                Node<Pair<K,V>>* tmp = data;
                data = data->GetLink();
                return tmp->GetData().GetValue();
            }
        };
    }

    namespace dn
    {
        template<class T>
        class Iterator : public IteratorInterface<T> 
        {
        private:
            Node<T>* data;
        public:
            Iterator() : Iterator(NULL) {}

            Iterator(Node<T>* data) : data(data) {}

            bool HasNext() const 
            {
                return (data != NULL);
            }

            T& Next() 
            {
                Node<T>* tmp = data;
                data = data->GetNext();
                return tmp->GetData();
            }
        };
    
        template<class K,class V>
        class PairIterator : public PairIteratorInterface<K,V> 
        {
        private:
            Node<Pair<K,V>>* data;
        public:
            PairIterator() : PairIterator(NULL) {}

            PairIterator(Node<Pair<K,V>>* data) : data(data) {}

            bool HasNext() const 
            {
                return (data != NULL);
            }

            const Pair<K,V>& Next() 
            {
                Node<Pair<K,V>>* tmp = data;
                data = data->GetNext();
                return tmp->GetData();
            }

            const K& NextKey()  
            {
                Node<Pair<K,V>>* tmp = data;
                data = data->GetNext();
                return tmp->GetData().GetKey();
            }

            V& NextValue() 
            {
                Node<Pair<K,V>>* tmp = data;
                data = data->GetNext();
                return tmp->GetData().GetValue();
            }
        };
    }

    namespace da
    {
        template<class T>
        class Iterator : public IteratorInterface<T> 
        {
        private:
            T* data;
            int cnt;
            int capacity;
        public:
            Iterator() : Iterator(NULL,0) {}

            Iterator(T* data,int capacity) : data(data), capacity(capacity), cnt(0) 
            {
                if(this->capacity < 0)
                {
                    this->capacity = 0;
                }
            }

            bool HasNext() const 
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

        template<class K,class V>
        class PairIterator : public PairIteratorInterface<K,V> 
        {
        private:
            Pair<K,V>* data;
            int cnt;
            int capacity;
        public:
            PairIterator() : PairIterator(NULL,0) {}

            PairIterator(Pair<K,V>* data,int capacity) : data(data), capacity(capacity), cnt(0) 
            {
                if(this->capacity < 0)
                {
                    this->capacity = 0;
                }
            }

            bool HasNext() const 
            {
                return (cnt < capacity);
            }

            const Pair<K,V>& Next() 
            {
                int c = cnt;
                cnt += 1;
                return data[c];
            }

            const K& NextKey() 
            {
                int c = cnt;
                cnt += 1;
                return data[c].GetKey();
            }

            V& NextValue()
            {
                int c = cnt;
                cnt += 1;
                return data[c].GetValue();
            }
        };
    }
}

#endif