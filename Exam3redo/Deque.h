#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"

namespace ds
{
    template <class T>
    class DequeInterface
    {
    public:
        virtual void InsertFirst(const T&) = 0;
        virtual void InsertLast(const T&) = 0;
        virtual void RemoveFirst() = 0;
        virtual void RemoveLast() = 0;
        virtual const T& First() const = 0;
        virtual const T& Last() const = 0;
        virtual int Size() const = 0;
        virtual bool IsEmpty() const = 0;
    };

    namespace da 
    {
        template <class T>
        class Deque : public DequeInterface<T>
        {
        private:
            T* data;
            int front;
            int back;
            int size;
            int capacity;

            void Resize()
            {
                int ocp = capacity;
                capacity *= 2;
                T* tmp = new T[ocp];

                for(int i = 0;i < ocp - 1;i += 1)
                {
                    tmp[i] = data[(front + i + 1) % ocp];
                }

                front = 0;
                back = ocp - 1;
                delete[] data;
                data = new T[capacity];

                for(int i = 1;i < ocp;i += 1)
                {
                    data[i] = tmp[i-1];
                }
                delete[] tmp;
            }
        public:
            Deque() : capacity(50), front(0), back(0), size(0)
            {
                data = new T[capacity];
            }

            Deque(const Deque<T>& obj)
            {
                front = obj.front;
                back = obj.back;
                capacity = obj.capacity;
                size = obj.size;
                data = new T[capacity];

    			for(int i = front;i != back;i = (i + 1) % capacity)
	    		{
		    		data[i] = obj.data[i];
			    }
            }

            Deque<T>& operator=(const Deque<T>& rhs)
		    {
			    if(this != &rhs)
			    {
				    front = rhs.front;
				    back = rhs.back;
				    capacity = rhs.capacity;
                    size = rhs.size;
				    delete[] data;
				    data = new T[capacity];
			
				    for(int i = front;i != back;i = (i + 1) % capacity)
				    {
					    data[i] = rhs.data[i];
				    }
			    }
			    return *this;
		    }

            ~Deque() 
            {
                delete[] data;
            }

            void InsertFirst(const T& value)
            {
                if(size + 1 == capacity)
                {
                    Resize();
                }
                data[front] = value;
                front = (front + capacity - 1) % capacity;
                size += 1; 
            }

            void InsertLast(const T& value)
            {
                if(size + 1 == capacity)
                {
                    Resize();
                }
                back = (back + 1) % capacity;
                data[back] = value;
                size += 1;
            }

            void RemoveFirst() 
            {
                if(size > 0)
                {
                    front = (front + 1) % capacity;
                    size -= 1;
                }
            }

            void RemoveLast() 
            {
                if(size > 0)
                {
                    back = (back + capacity - 1) % capacity;
                    size -= 1;
                }
            }

            const T& First() const 
            {
                if(size == 0)
                {
                    throw "Empty Deque";
                }
                return data[(front + 1) % capacity];
            }   

            const T& Last() const 
            {
                if(size == 0)
                {
                    throw "Empty Deque";
                }
                return data[back];
            }   

            bool IsEmpty() const
            {
                return (front == back);
            }

            int Size() const 
            {
                return size;
            }

            std::string ToString() const 
            {
                std::stringstream out;

                if(size > 0)
                {
                    out << data[(front + 1) % capacity] << " : " << data[back];
                }
                else
                {
                    out << "";
                }
			    return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Deque<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }

    namespace sn
    {
        template <class T>
        class Deque : public DequeInterface<T>
        {
        private:
            Node<T>* head;
            Node<T>* tail;
            int size;
        public:
            Deque() : head(NULL), tail(NULL), size(0) {}

            Deque(const Deque<T>& obj)
            {
                size = obj.size;
                head = Copy(obj.head);
                tail = head;

                while(tail != NULL && tail->GetLink() != NULL)
                {
                    tail = tail->GetLink();
                }
            }

            Deque<T>& operator=(const Deque<T>& rhs)
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

            ~Deque()
            {
                Clear(head);
                head = NULL;
                tail = NULL;
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

            const T& First() const 
            {
                if(head == NULL)
                {
                    throw "Empty Deque";
                }
                return head->GetData();
            }

            const T& Last() const 
            {
                if(tail == NULL)
                {
                    throw "Empty Deque";
                }
                return tail->GetData();
            }

            bool IsEmpty() const 
            {
                return (head == NULL);
            }

            int Size() const 
            {
                return size;
            }

            std::string ToString() const 
            {
                std::stringstream out;

                if(head != NULL)
                {
                    out << head->GetData() << " : " << tail->GetData();
                }
                else
                {
                    out << "";
                }
                return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Deque<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }

    namespace dn
    {
        template <class T>
        class Deque : public DequeInterface<T>
        {
        private:
            Node<T>* head;
            Node<T>* tail;
            int size;
        public:
            Deque() : head(NULL), tail(NULL), size(0) {}

            Deque(const Deque<T>& obj)
            {
                size = obj.size;
                head = Copy(obj.head);
                tail = head;

                while(tail != NULL && tail->GetNext() != NULL)
                {
                    tail = tail->GetNext();
                }
            }

            Deque<T>& operator=(const Deque<T>& rhs)
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

            ~Deque()
            {
                Clear(head);
                head = NULL;
                tail = NULL;
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

            const T& First() const 
            {
                if(head == NULL)
                {
                    throw "Empty Deque";
                }
                return head->GetData();
            }

            const T& Last() const 
            {
                if(tail == NULL)
                {
                    throw "Empty Deque";
                }
                return tail->GetData();
            }

            bool IsEmpty() const 
            {
                return (head == NULL);
            }

            int Size() const 
            {
                return size;
            }

            std::string ToString() const 
            {
                std::stringstream out;

                if(head != NULL)
                {
                    out << head->GetData() << " : " << tail->GetData();
                }
                else
                {
                    out << "";
                }
                return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Deque<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }
}

#endif